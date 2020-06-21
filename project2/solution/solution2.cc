#include <iostream>
#include <fstream>
#include <string>
#include "json/json.h"

struct array{
	char name;
	int bracket, pos, last;
	int range[5];
	char var[5][10];
}arr[10];

void MainLoop(int number) {
	std::string filename = std::string("./cases/case") + std::to_string(number) + std::string(".json");
	std::ifstream is(filename, std::ios::binary);
	std::string filename1 = std::string("./kernels/grad_case") + std::to_string(number) + std::string(".cc");
	std::ofstream ofile(filename1);
	Json::Reader reader;
	Json::Value root;
	std::string name;
	std::string gradto[10];
	std::string type;
	std::string main_kernel;
	int gradtosize = 0;
	if (reader.parse(is, root))
	{
		name = root["name"].asString();
		type = root["data_type"].asString();
		main_kernel = root["kernel"].asString();
		gradtosize = root["grad_to"].size();
		for (int i = 0; i < gradtosize; i++)
			gradto[i] = root["grad_to"][i].asString();
	}
	is.close();
	char resource[1000], temp_resource[1000];
	strcpy(temp_resource, main_kernel.data());
	int pos = 0;
	int cpos = 0;
	while (pos < strlen(temp_resource)) {
		if (temp_resource[pos] == ' ') {
			pos++;
			continue;
		}
		resource[cpos++] = temp_resource[pos++];
	}
	resource[cpos] = '\0';
	int len = cpos, flag = -1, last = 0, cnt = 0;
	pos = 0;
	cpos = 0;
	memset(arr, 0 ,sizeof(arr));
	while (pos < len) {
		if (resource[pos] >= 'A' && resource[pos] <= 'Z') {
			arr[++cnt].name = resource[pos];
			arr[cnt].bracket = flag;
			arr[cnt].pos = pos;
			arr[cnt].last = last;
			char temp[10];
			pos += 2;
			cpos = 0;
			int num = 0;
			while (1) {
				if (resource[pos] == ',') {
					temp[cpos] = 0;
					arr[cnt].range[++num] = atoi(temp);
					pos++;
					cpos = 0;
				}
				else if (resource[pos] == '>') {
					temp[cpos] = 0;
					arr[cnt].range[++num] = atoi(temp);
					arr[cnt].range[0] = num;
					pos++;
					break;
				}
				else temp[cpos++] = resource[pos++];
			}
			pos++;
			cpos = 0;
			num = 0;
			while (1) {
				if (resource[pos] == ',') {
					temp[cpos] = 0;
					memcpy(arr[cnt].var[++num], temp, 10);
					pos++;
					cpos = 0;
				}
				else if (resource[pos] == ']') {
					temp[cpos] = 0;
					memcpy(arr[cnt].var[++num], temp, 10);
					pos++;
					break;
				}
				else temp[cpos++] = resource[pos++];
			}
		}
		else {
			if (resource[pos] == '(') {
				flag = pos;
				last=cnt+1;
			}
			else if (resource[pos] == ')') {
				flag = -1;
				last=cnt+1;
			}
			else if (resource[pos] == '+' || resource[pos] == '=') last = cnt + 1;
			pos++;
		}
	}
	std::string code;
	int used[26];
	memset(used, 0, sizeof(used));
	for (int i = 0; i < gradtosize; ++i) {
		char allstmt[1000];
		int l1 = 0, l2 = 0;
		for (int j = 1; j <= cnt; ++j) {
			if (gradto[i][0] == arr[j].name) {
				l2 = j;
				char stmt[50];
				char cond[50];
				pos = 0;
				cpos = 0;
				used[arr[j].name - 'A'] |= 2;
				if (arr[j].bracket > 0 && resource[arr[j].bracket - 1] != '+' && resource[arr[j].bracket - 1] != '=') {
					int flag1 = 0;
					int flag2 = 0;
					int m = arr[j].bracket - 1;
					while (1) {
						if (resource[m] == ')') flag1 = 1;
						else if (resource[m] == '(') flag1 = 0;
						else if (resource[m] == ']') flag2 = 1;
						else if (resource[m] == '[') flag2 = 0;
						else if (!flag1 && !flag2 && (resource[m] == '+' || resource[m] == '=')) break;
						else if (resource[m] >= 'A' && resource[m] <= 'Z') used[resource[m] - 'A'] |= 1;
						--m;
					}
					memcpy(stmt, resource + m + 1, arr[j].bracket - m - 1);
					cpos = arr[j].bracket - m - 1;
				}
				for (int k = arr[j].last; arr[k].last == arr[j].last; ++k) {
					if (k != arr[k].last) stmt[cpos++] = resource[arr[k].pos - 1];
					if (k == j) {
						stmt[cpos++] = 'd';
						stmt[cpos++] = arr[1].name;
						used[arr[1].name - 'A'] |= 2;
						for (int l = 1; l <= arr[1].range[0]; ++l) {
							int m;
							for (m = 1; m <= arr[j].range[0]; ++m)
								if (arr[1].var[l][0] == arr[j].var[m][0]) break;
							if (m > arr[j].range[0]) {
								stmt[cpos++] = '[';
								stmt[cpos++] = arr[1].var[l][0];
								stmt[cpos++] = ']';
							}
							else if (arr[j].var[m][1] == '/') {
								int x = 3, y = 0;
								char div[10];
								while (arr[j].var[m][x] != 0) div[y++] = arr[j].var[m][x++];
								div[y] = 0;
								int n = 1;
								for (n = 1; n <= arr[j].range[0]; ++n)
									if (arr[j].var[n][1] == '%') break;
								stmt[cpos++] = '[';
								stmt[cpos++] = m + 118;
								stmt[cpos++] = '*';
								y = 0;
								while (div[y] != 0) stmt[cpos++] = div[y++];
								stmt[cpos++] = '+';
								stmt[cpos++] = n + 118;
								stmt[cpos++] = ']';
							}
							else if (arr[j].var[m][1] == '+') {
								int x = 2, y = 0;
								char plus[10];
								while (arr[j].var[m][x] != 0) plus[y++] = arr[j].var[m][x++];
								plus[y] = 0;
								stmt[cpos++] = '[';
								stmt[cpos++] = m + 118;
								stmt[cpos++] = '-';
								y = 0;
								while (plus[y] != 0) stmt[cpos++] = plus[y++];
								stmt[cpos++] = ']';
								if (pos != 0) {
									cond[pos++] = ' ';
									cond[pos++] = '&';
									cond[pos++] = '&';
									cond[pos++] = ' ';
								}
								cond[pos++] = m + 118;
								cond[pos++] = '-';
								memcpy(cond + pos, plus, y);
								pos += y;
								cond[pos++] = '>';
								cond[pos++] = '=';
								cond[pos++] = '0';
								cond[pos++] = ' ';
								cond[pos++] = '&';
								cond[pos++] = '&';
								cond[pos++] = ' ';
								cond[pos++] = m + 118;
								cond[pos++] = '-';
								memcpy(cond + pos, plus, y);
								pos += y;
								cond[pos++] = '<';
								if (arr[1].range[l] >= 10) cond[pos++] = arr[1].range[l] / 10 + 48;
								cond[pos++] = arr[1].range[l] % 10 + 48;
							}
							else {
								stmt[cpos++] = '[';
								stmt[cpos++] = m + 118;
								stmt[cpos++] = ']';
								if (pos != 0) {
									cond[pos++] = ' ';
									cond[pos++] = '&';
									cond[pos++] = '&';
									cond[pos++] = ' ';
								}
								cond[pos++] = m + 118;
								cond[pos++] = '>';
								cond[pos++] = '=';
								cond[pos++] = '0';
								cond[pos++] = ' ';
								cond[pos++] = '&';
								cond[pos++] = '&';
								cond[pos++] = ' ';
								cond[pos++] = m + 118;
								cond[pos++] = '<';
								if (arr[1].range[l] >= 10) cond[pos++] = arr[1].range[l] / 10 + 48;
								cond[pos++] = arr[1].range[l] % 10 + 48;
							}
						}
					}
					else {
						stmt[cpos++] = arr[k].name;
						used[arr[k].name - 'A'] |= 1;
						for (int l = 1; l <= arr[k].range[0]; ++l) {
							int m;
							for (m = 1; m <= arr[j].range[0]; ++m)
								if (arr[k].var[l][0] == arr[j].var[m][0]) break;
							if (m > arr[j].range[0]) {
								stmt[cpos++] = '[';
								stmt[cpos++] = arr[k].var[l][0];
								stmt[cpos++] = ']';
							}
							else if (arr[j].var[m][1] == '/') {
								int x = 3, y = 0;
								char div[10];
								while (arr[j].var[m][x] != 0) div[y++] = arr[j].var[m][x++];
								div[y] = 0;
								int n = 1;
								for (n = 1; n <= arr[j].range[0]; ++n)
									if (arr[j].var[n][1] == '%') break;
								stmt[cpos++] = '[';
								stmt[cpos++] = m + 118;
								stmt[cpos++] = '*';
								y = 0;
								while (div[y] != 0) stmt[cpos++] = div[y++];
								stmt[cpos++] = '+';
								stmt[cpos++] = n + 118;
								stmt[cpos++] = ']';
							}
							else if (arr[j].var[m][1] == '+') {
								int x = 2, y = 0;
								char plus[10];
								while (arr[j].var[m][x] != 0) plus[y++] = arr[j].var[m][x++];
								plus[y] = 0;
								stmt[cpos++] = '[';
								stmt[cpos++] = m + 118;
								stmt[cpos++] = '-';
								y = 0;
								while (plus[y] != 0) stmt[cpos++] = plus[y++];
								stmt[cpos++] = ']';
								if (pos != 0) {
									cond[pos++] = ' ';
									cond[pos++] = '&';
									cond[pos++] = '&';
									cond[pos++] = ' ';
								}
								cond[pos++] = m + 118;
								cond[pos++] = '-';
								memcpy(cond + pos, plus, y);
								pos += y;
								cond[pos++] = '>';
								cond[pos++] = '=';
								cond[pos++] = '0';
								cond[pos++] = ' ';
								cond[pos++] = '&';
								cond[pos++] = '&';
								cond[pos++] = ' ';
								cond[pos++] = m + 118;
								cond[pos++] = '-';
								memcpy(cond + pos, plus, y);
								pos += y;
								cond[pos++] = '<';
								if (arr[k].range[l] >= 10) cond[pos++] = arr[k].range[l] / 10 + 48;
								cond[pos++] = arr[k].range[l] % 10 + 48;
							}
							else {
								stmt[cpos++] = '[';
								stmt[cpos++] = m + 118;
								stmt[cpos++] = ']';
								if (pos != 0) {
									cond[pos++] = ' ';
									cond[pos++] = '&';
									cond[pos++] = '&';
									cond[pos++] = ' ';
								}
								cond[pos++] = m + 118;
								cond[pos++] = '>';
								cond[pos++] = '=';
								cond[pos++] = '0';
								cond[pos++] = ' ';
								cond[pos++] = '&';
								cond[pos++] = '&';
								cond[pos++] = ' ';
								cond[pos++] = m + 118;
								cond[pos++] = '<';
								if (arr[k].range[l] >= 10) cond[pos++] = arr[k].range[l] / 10 + 48;
								cond[pos++] = arr[k].range[l] % 10 + 48;
							}
						}
					}
				}
				if (arr[j].bracket > 0) {
					int m = arr[j].pos, n;
					while (resource[m] != ')') ++m;
					++m;
					n = m;
					int flag1 = 0;
					int flag2 = 0;
					while (1) {
						if (resource[m] == '(') flag1 = 1;
						else if (resource[m] == ')') flag1 = 0;
						else if (resource[m] == '[') flag2 = 1;
						else if (resource[m] == ']') flag2 = 0;
						else if (!flag1 && !flag2 && (resource[m] == '+' || resource[m] == ';')) break;
						else if (resource[m] >= 'A' && resource[m] <= 'Z') used[resource[m] - 'A'] |= 1;
						++m;
					}
					memcpy(stmt + cpos, resource + n, m - n);
					cpos += m - n;
				}
				stmt[cpos] = 0;
				cond[pos] = 0;
				if (l1 != 0) allstmt[l1++] = '+';
				if (pos > 0) {
					allstmt[l1++] = '(';
					memcpy(allstmt + l1, cond, pos);
					l1 += pos;
					allstmt[l1++] = '?';
					memcpy(allstmt + l1, stmt, cpos);
					l1 += cpos;
					allstmt[l1++] = ':';
					allstmt[l1++] = '0';
					allstmt[l1++] = '.';
					allstmt[l1++] = '0';
					allstmt[l1++] = ')';
				}
				else {
					memcpy(allstmt + l1, stmt, cpos);
					l1 += cpos;
				}
			}
		}
		int tab = 1;
		int vis[26];
		memset(vis, 0 ,sizeof(vis));
		for (int i = 1; i <= arr[l2].range[0]; ++i) {
			vis[arr[l2].var[i][0] - 'a'] = 1;
			vis[i + 21] = 1;
			for (int j = 1; j <= tab; ++j) code += '\t';
			++tab;
			code += "for (int ";
			code += i + 118;
			code += "=0;";
			code += i + 118;
			code += '<';
			if (arr[l2].range[i] >= 10) code += arr[l2].range[i] / 10 + 48;
			code += arr[l2].range[i] % 10 + 48;
			code += ";++";
			code += i + 118;
			code += ")\n";
		}
		for (int i = 1; i <= cnt; ++i)
			for (int j = 1; j <= arr[i].range[0]; ++j)
				if (!vis[arr[i].var[j][0] - 'a']) {
					vis[arr[i].var[j][0] - 'a'] = 1;
					for (int k = 1; k <= tab; ++k) code += '\t';
					++tab;
					code += "for (int ";
					code += arr[i].var[j][0];
					code += "=0;";
					code += arr[i].var[j][0];
					code += '<';
					if (arr[i].range[j] >= 10) code += arr[i].range[j] / 10 + 48;
					code += arr[i].range[j] % 10 + 48;
					code += ";++";
					code += arr[i].var[j][0];
					code += ")\n";
				}
		for (int i = 1; i <= tab; ++i) code += '\t';
		code += 'd';
		code += arr[l2].name;
		for (int i = 1; i <= arr[l2].range[0]; ++i) {
			code += '[';
			code += i + 118;
			code += ']';
		}
		code += "+=";
		allstmt[l1++] = ';';
		allstmt[l1++] = '\n';
		allstmt[l1] = 0;
		code += allstmt;
	}
	std::string tempCode = "";
	tempCode += "#include \"../run2.h\"\nvoid grad_case";
	if (number == 10) tempCode += "10";
	else tempCode += number + 48;
	tempCode += '(';
	flag = 0;
	for (int i = 1; i <= cnt; ++i)
		if (used[arr[i].name - 'A'] & 1) {
			if (flag) tempCode += ',';
			used[arr[i].name - 'A'] ^= 1;
			flag = 1;
			tempCode += "float (&";
			tempCode += arr[i].name;
			tempCode += ')';
			for (int j = 1; j <= arr[i].range[0]; ++j) {
				tempCode += '[';
				if (arr[i].range[j] >= 10) tempCode += arr[i].range[j] / 10 + 48;
				tempCode += arr[i].range[j] % 10 + 48;
				tempCode += ']';
			}
		}
	for (int i = 1; i <= cnt; ++i)
		if (used[arr[i].name - 'A'] & 2) {
			if (flag) tempCode += ',';
			used[arr[i].name - 'A'] ^= 2;
			flag = 1;
			tempCode += "float (&d";
			tempCode += arr[i].name;
			tempCode += ')';
			for (int j = 1; j <= arr[i].range[0]; ++j) {
				tempCode += '[';
				if (arr[i].range[j] >= 10) tempCode += arr[i].range[j] / 10 + 48;
				tempCode += arr[i].range[j] % 10 + 48;
				tempCode += ']';
			}
		}
	code = tempCode + "){\n" + code + "}";
	ofile << code;
	ofile.close();
}

int main() {
	for (int number = 1; number <= 10; number++) MainLoop(number);
	return 0;
}


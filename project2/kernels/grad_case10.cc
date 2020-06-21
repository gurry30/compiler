#include "../run2.h"
void grad_case10(float (&dA)[8][8],float (&dB)[10][8]){
	for (int w=0;w<10;++w)
		for (int x=0;x<8;++x)
			dB[w][x]+=(w>=0 && w<8 && x>=0 && x<8?dA[w][x]/3.0:0.0)+(w-1>=0 && w-1<8 && x>=0 && x<8?dA[w-1][x]/3.0:0.0)+(w-2>=0 && w-2<8 && x>=0 && x<8?dA[w-2][x]/3.0:0.0);
}
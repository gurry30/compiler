#include "../run2.h"
void grad_case3(float (&B)[16][16],float (&dC)[4][16],float (&dA)[4][16]){
	for (int w=0;w<4;++w)
		for (int x=0;x<16;++x)
			for (int j=0;j<16;++j)
				dA[w][x]+=(w>=0 && w<4 && x>=0 && x<16?dC[w][j]*B[x][j]:0.0);
}
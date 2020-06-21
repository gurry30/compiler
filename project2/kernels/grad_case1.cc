#include "../run2.h"
void grad_case1(float (&B)[4][16],float (&dC)[4][16],float (&dA)[4][16]){
	for (int w=0;w<4;++w)
		for (int x=0;x<16;++x)
			dA[w][x]+=(w>=0 && w<4 && x>=0 && x<16 && w>=0 && w<4 && x>=0 && x<16?dC[w][x]*B[w][x]:0.0);
}
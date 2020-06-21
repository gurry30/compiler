#include "../run2.h"
void grad_case2(float (&A)[4][16],float (&dB)[4][16],float (&dA)[4][16]){
	for (int w=0;w<4;++w)
		for (int x=0;x<16;++x)
			dA[w][x]+=(w>=0 && w<4 && x>=0 && x<16 && w>=0 && w<4 && x>=0 && x<16?dB[w][x]*A[w][x]:0.0)+(w>=0 && w<4 && x>=0 && x<16 && w>=0 && w<4 && x>=0 && x<16?A[w][x]*dB[w][x]:0.0);
}
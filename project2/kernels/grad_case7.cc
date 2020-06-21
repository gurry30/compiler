#include "../run2.h"
void grad_case7(float (&dB)[16][32],float (&dA)[32][16]){
	for (int w=0;w<32;++w)
		for (int x=0;x<16;++x)
			dA[w][x]+=(x>=0 && x<16 && w>=0 && w<32?dB[x][w]:0.0);
}
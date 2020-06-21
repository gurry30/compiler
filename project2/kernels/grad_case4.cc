#include "../run2.h"
void grad_case4(float (&B)[16][32],float (&C)[32][32],float (&dA)[16][32],float (&dB)[16][32],float (&dC)[32][32]){
	for (int w=0;w<16;++w)
		for (int x=0;x<32;++x)
			for (int j=0;j<32;++j)
				dB[w][x]+=(w>=0 && w<16 && x>=0 && x<32?dA[w][j]*C[x][j]:0.0);
	for (int w=0;w<32;++w)
		for (int x=0;x<32;++x)
			for (int i=0;i<16;++i)
				dC[w][x]+=(w>=0 && w<32 && x>=0 && x<32?B[i][w]*dA[i][x]:0.0);
}
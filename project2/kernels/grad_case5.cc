#include "../run2.h"
void grad_case5(float (&C)[32][32],float (&D)[4][32],float (&dA)[16][32],float (&dB)[16][32][4]){
	for (int w=0;w<16;++w)
		for (int x=0;x<32;++x)
			for (int y=0;y<4;++y)
				for (int j=0;j<32;++j)
					dB[w][x][y]+=(w>=0 && w<16 && x>=0 && x<32 && y>=0 && y<4?dA[w][j]*C[x][j]*D[y][j]:0.0);
}
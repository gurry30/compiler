#include "../run2.h"
void grad_case6(float (&C)[8][16][3][3],float (&dA)[2][8][5][5],float (&dB)[2][16][7][7]){
	for (int w=0;w<2;++w)
		for (int x=0;x<16;++x)
			for (int y=0;y<7;++y)
				for (int z=0;z<7;++z)
					for (int k=0;k<8;++k)
						for (int r=0;r<3;++r)
							for (int s=0;s<3;++s)
								dB[w][x][y][z]+=(w>=0 && w<2 && y-r>=0 && y-r<5 && z-s>=0 && z-s<5 && x>=0 && x<16?dA[w][k][y-r][z-s]*C[k][x][r][s]:0.0);
}
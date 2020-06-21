#include "../run2.h"
void grad_case8(float (&dB)[32],float (&dA)[2][16]){
	for (int w=0;w<2;++w)
		for (int x=0;x<16;++x)
			dA[w][x]+=dB[w*16+x];
}
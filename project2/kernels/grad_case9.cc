#include "../run2.h"
void grad_case9(float (&dB)[4][6],float (&dA)[4]){
	for (int w=0;w<4;++w)
		for (int j=0;j<6;++j)
			dA[w]+=(w>=0 && w<4?dB[w][j]:0.0);
}
#include <stdio.h>
#include <immintrin.h>

#define UC unsigned char

#define S 3706710
#define H 122


int main()
{
	FILE* img_in = fopen("mario.bmp", "rb");
	FILE* img_out = fopen("output.bmp", "wb+");

	int size = (S-H)/2;

	char*  header =    	(char*) malloc(H*sizeof(char));
	UC* data_in_e = 	(UC*) malloc(size * sizeof(UC));
	UC* data_in_o = 	(UC*) malloc(size * sizeof(UC));
	UC* data_out  =		(UC*) malloc(size * sizeof(UC));

	int width = 858*4;
	int s = 0;
	int e = 0;
	int o = 0;
	int i;


	for(i=0; i<H; i++)
		header[i] = fgetc(img_in);


	for(i=0; i<(S-H); i++)
	{
		if(i%width == 0)
		{
			if(!s)
				s = 1;
			else
				s = 0;
		}
		
		if(s)
			data_in_e[e++] = (UC)fgetc(img_in);
		else
			data_in_o[o++] = (UC)fgetc(img_in);
	}


	for(i=0; i<size; i+=32)
	{
		__m256i mm_even = _mm256_loadu_si256((__m256i *)&(data_in_e[i]));
		__m256i mm_odd = _mm256_loadu_si256((__m256i *)&(data_in_o[i]));
		
		__m256i mm_out = _mm256_avg_epu8(mm_even, mm_odd);

		_mm256_storeu_si256((__m256i*)&(data_out[i]), mm_out);
	}

	header[22] = (char)0x1C;
	header[23] = (char)0x2;


	for(i=0; i < H; i++)
		fputc(header[i], img_out);

	for(i=0; i < size; i++)
		fputc((char)data_out[i], img_out);


	fclose(img_in);
	fclose(img_out);

	free(header);
	free(data_in_e);
	free(data_in_o);
	free(data_out);

	return 0;
}

#include <stdio.h>
#include <immintrin.h>
#include <math.h>

#define S 3706710
#define H 122

int main()
{
	FILE* img_in = fopen("mario.bmp", "rb");
	FILE* img_out = fopen("output.bmp", "wb+");


	char*  header =     (char*) malloc(H*sizeof(char));
	float* data_in =    (float*) malloc((S-H)*sizeof (float));
	float* data_out =   (float*) malloc((S-H)*sizeof (float));
	int i;

	__m256 mm_nan = _mm256_set1_ps(0.0/0.0);

	for(i=0; i<H; i++)
		header[i] = fgetc(img_in);

	for(i=0; i<(S-H); i++)
		data_in[i] = (float)fgetc(img_in);


	__m256 mm_mul = _mm256_set1_ps(.75f);

	for(i=0; i<(S-H); i+=8)
	{
		__m256 mm_in = _mm256_loadu_ps(&(data_in[i]));
		__m256 mm_out = _mm256_mul_ps(mm_in, mm_mul);
		_mm256_storeu_ps(&(data_out[i]), mm_out);
	}

	for(i=0; i < H; i++)
		fputc(header[i], img_out);

	for(i=0; i < S-H; i++)
		fputc((char)data_out[i], img_out);


	fclose(img_in);
	fclose(img_out);

	free(header);
	free(data_in);
	free(data_out);

	return 0;
}

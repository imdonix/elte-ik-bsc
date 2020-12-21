#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
void computeLPSArray(char* pat, int M, std::vector<int>&);

void KMPSearch(char* pat, char* txt, std::vector<int>& S)
{
	int M = strlen(pat);
	int N = strlen(txt);

	std::vector<int> lps(M);
	computeLPSArray(pat, M, lps);
	std::cout << "P[j]=\t";
	for (int i = 0; i < M; ++i)
	{
		std::cout << pat[i] << "\t";
	}
	std::cout << std::endl << "j=\t";
	for (int i = 0; i < M; ++i)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl << "next[j]\t";
	for (int i = 0; i < M; ++i)
	{
		std::cout << lps[i] << "\t";
	}
	std::cout << std::endl << std::endl;

	int counter = 0;

	int i = 0;
	int j = 0;

	int innercount = 0;
	while (i < N) {
		// std::cout << "i=" << i << "\t";
		if (pat[j] == txt[i]) {
			++counter;
			++innercount;
			j++;
			i++;
		}

		if (j == M) {
			if (std::none_of(S.begin(), S.end(), [=](int k) { return k == i - j; }))
				S.push_back(i - j);
			//std::printf("Found pattern at index %d\n", i - j);
			j = lps[j - 1];
			std::cout << "i=" << i + 1 << "\tH.SZ=" << innercount << std::endl;
			innercount = 0;
		}

		else if (i < N && pat[j] != txt[i]) {
			++innercount;
			std::cout << "i=" << i + 1<< "\tH.SZ=" << innercount << std::endl;
			innercount = 0;
			
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			
			if (j != 0)
			{
				
				j = lps[j - 1];
				++counter;
			}
			else
			{
				
				i = i + 1;
				++counter;
			}
		}
		
	}
	std::cout << "i=" << N << "\tH.SZ.=" << innercount << std::endl;
	std::cout << "S contains:\t";
	for (auto i : S)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	std::cout << "Összehasonlítások száma: " << counter << std::endl;
}

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, std::vector<int>& lps)
{
	// length of the previous longest prefix suffix 
	int len = 0;

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len]) 
		{
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment 
				// i here 
			}
			else // if (len == 0) 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Driver program to test above function 
int main()
{
	char txt[] = "ABABABAABABAABABABAABABBABA";
	char pat[] = "BABAABAB";
	std::vector<int> S;
	KMPSearch(pat, txt, S);
	return 0;
}

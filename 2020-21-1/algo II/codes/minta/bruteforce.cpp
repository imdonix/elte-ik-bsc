#include <iostream>
#include <string>
#include <vector>

void print_results(std::vector<int> S)
{
    std::cout << "Talalatok:";
    for (int i = 0; i < S.size(); i++)
    {
        std::cout << " " << S[i];
    }
    std::cout << std::endl;
}

void Bruteforce(const std::string& T, const std::string& P)
{
    std::cout << "Bruteforce algoritmus" << std::endl << std::endl;
    std::vector<int> S;
    int n = T.length(), m = P.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && T[i+j] == P[j])
        {
            j++;
        }
        if (j == m)
        {
            S.push_back(i);
        }
    }
    print_results(S);
}

int main()
{
	std::string txt("ADABACACACABADABABADABABA");
	std::string pat("ADABABA");
	Bruteforce(txt, pat);
	return 0;
}
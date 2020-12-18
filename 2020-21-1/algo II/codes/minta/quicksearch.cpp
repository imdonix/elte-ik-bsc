#include <iostream>
#include <vector>
#include <string>
#include <map>


void print_results(std::vector<int> S)
{
    std::cout << "Talalatok:";
    for (int i = 0; i < S.size(); i++)
    {
        std::cout << " " << S[i];
    }
    std::cout << std::endl;
}

void initShift(const std::string& T, const std::string& P, std::map<char, int>& shift)
{
    int i, n = T.length(), m = P.length();
    for (i = 0; i < n; i++)
    {
        shift[T[i]] = m + 1;
    }
    for (i = 0; i < m; i++)
    {
        shift[P[i]] = m - i;
    }
    std::cout << "SHIFT:" << std::endl;
    std::map<char, int>::iterator it;
    for (it = shift.begin(); it != shift.end(); it++) std::cout << it->first << "\t";
    std::cout << std::endl;
    for (it = shift.begin(); it != shift.end(); it++) std::cout << it->second << "\t";
    std::cout << std::endl;
}

void QuickSearch(const std::string& T, const std::string& P)
{
    std::cout << "Quick Search algoritmus" << std::endl << std::endl;
    std::map<char, int> shift;
    initShift(T, P, shift);
    int n = T.length();
	int	m = P.length();
    std::vector<int> S;
    int s = 0, i, elromlas = 0, hasonlitasok = 0;
    while (s + m <= n && elromlas < 30)
    {
		std::string sub1 = T.substr(s, (s + m) + 1 - (s + 1));
		std::string sub2 = P.substr(0, m);
		std::cout << "sub: " << sub2 << std::endl;
		int i = 0;
		bool same = true;
        while (same && i < sub1.size())
        {
			if (sub1[i] != sub2[i])
				same = false;
			++hasonlitasok;
            ++i;
        }
		if (sub1 == sub2)
        {
            S.push_back(s);
        }
        if (s + m < n)
        {
            std::cout << ++elromlas << ". elromlas: " << T[s + i] << "-" << P[i] << "\tA minta utani elem (" << s + m + 1 << ".): " << T[s + m] << " shift(" << T[s + m] << ") = " << shift[T[s + m]] << std::endl;
            s += shift[T[s + m]];
        }
        else
        {
            break;
        }
    }
    print_results(S);
    std::cout << "Hasonlitasok szama: " << hasonlitasok << std::endl;
}

int main()
{
	char txt[] = "ADABACACACABADABABADABABA";
	char pattern[] = "ADABABA";
	std::cout << "Text is: \"" << txt << "\"" << std::endl << "Pattern is: \"" << pattern << "\"" << std::endl << std::endl;
	std::vector<int> S;
	QuickSearch(txt, pattern);
	return 0;
}
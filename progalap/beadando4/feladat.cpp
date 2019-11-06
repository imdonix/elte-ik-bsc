#include <iostream>

using namespace std;

typedef struct Word
{
    char s;
    char e;
    string word;
};

char GetFirstChar(string str)
{
    return str[0];
}

char GetLastChar(string str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return str[i-1];
}

int main()
{
    int N;
    cin >> N;
    Word words[N];

    //Read
    for(int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        Word newWord;
        newWord.s = GetFirstChar(word);
        newWord.e = GetLastChar(word);
        newWord.word = word;
        words[i] = newWord;
    }

    //Find first
    Word last;
    for(int x = 0; x < N; x++)
    {
        int c = 1;
        for(int y = 0; y < N; y++)
            if(words[x].s == words[y].e)
                c = 0;

        if(c)
            last = words[x];
    }
    cout << last.word << endl;

    //Find left
    int left = N - 1;
    while (left > 0)
        for(int i = 0; i < N; i++)
            if(words[i].s == last.e)
            {
                cout << words[i].word << endl;
                last = words[i];
                left--;
            }

    return 0;
}

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <string>

using namespace std;

struct utasitas{
	string tipus;
	int szamlalo;
	string cimke;
	int sorszam;
};

int main(int argc, char* argv[]){
  if(argc == 1) return 1;
  ifstream f;
  f.open(argv[1]);
  string s;
  list<utasitas> utlist;
  utlist.clear();
  utasitas ut;
  int sorsz = 0;
  int max_szamlalo = argc - 2;
  if(f.is_open()){
    while(f >> s){
	if(s == "INC"){
		ut.tipus = s;
		f >> s;
		ut.szamlalo = stoi(s);
		if(ut.szamlalo > max_szamlalo) max_szamlalo = ut.szamlalo;
		ut.cimke = "";
		ut.sorszam = sorsz;
		++sorsz;
	}
	else if(s == "DEC"){
		ut.tipus = s;
		f >> s;
		ut.szamlalo = stoi(s);
		if(ut.szamlalo > max_szamlalo) max_szamlalo = ut.szamlalo;
		ut.cimke = "";
		ut.sorszam = sorsz;
		++sorsz;
	}
	else if(s == "HALT"){
		ut.tipus = s;
		ut.szamlalo = -1;
		ut.cimke = "";
		ut.sorszam = sorsz;
		++sorsz;
	}
	else if(s == "WAIT"){
		ut.tipus = s;
		ut.szamlalo = -1;
		ut.cimke = "";
		ut.sorszam = sorsz;
		++sorsz;
	}
	else if(s == "JMP"){
		ut.tipus = s;
		ut.szamlalo = -1;
		f >> s;
		ut.cimke = s;
		ut.sorszam = sorsz;
		++sorsz;
	}
	else if(s == "JMPZ"){
		ut.tipus = s;
		f >> s;
		ut.szamlalo = stoi(s);
		if(ut.szamlalo > max_szamlalo) max_szamlalo = ut.szamlalo;
		f >> s;
		ut.cimke = s;
		ut.sorszam = sorsz;
		++sorsz;
	}
	else{
		ut.tipus = "cimke";
		ut.szamlalo = -1;
		ut.cimke = s;
		ut.sorszam = sorsz;
		++sorsz;
	}
	utlist.push_back(ut);
    }
    f.close();
  } else return 2;
  bool l = true;
  int szamlalok[max_szamlalo+1];
  szamlalok[0] = 0;
  for(int i = 1; i <= argc - 2; ++i) szamlalok[i] = stoi(argv[i+1]);
  for(int i = argc - 1; i <= max_szamlalo; ++i) szamlalok[i] = 0;
  sorsz = 0;
  int lepesszam = 0;
  list<utasitas>::iterator iter,ator;
  while(l){
    iter = utlist.begin();
    while((*iter).sorszam != sorsz) ++iter;
    l = (lepesszam <= 5000000);
    ++lepesszam;
    if((*iter).tipus == "cimke"){
	++sorsz;
	--lepesszam;
    }
    else if((*iter).tipus == "HALT") l = false;
    else if((*iter).tipus == "WAIT"){
	for(int i = 1; i <= max_szamlalo; ++i) cout << szamlalok[i] << " ";
	cin.ignore(1,'*');
	cout << endl;
	++sorsz;
    }
    else if((*iter).tipus == "INC"){
	szamlalok[(*iter).szamlalo] = szamlalok[(*iter).szamlalo]+1;
	++sorsz;
    } else if((*iter).tipus == "DEC"){
	if(szamlalok[(*iter).szamlalo] > 0) szamlalok[(*iter).szamlalo] = szamlalok[(*iter).szamlalo] - 1;
	++sorsz;
    } else if((*iter).tipus == "JMP"){
	s = (*iter).cimke;
	ator = utlist.begin();
	while((*ator).tipus != "cimke" || (*ator).cimke != s) ++ator;
	sorsz = (*ator).sorszam;
    } else{
	if(szamlalok[(*iter).szamlalo] == 0){
	  s = (*iter).cimke;
	  ator = utlist.begin();
	  while((*ator).tipus != "cimke" || (*ator).cimke != s) ++ator;
	  sorsz = (*ator).sorszam;
	} else ++sorsz;
    }
  }
  for(int i = 1; i <= max_szamlalo; ++i) cout << szamlalok[i] << " ";
  cout << endl << lepesszam << endl;
  return 0;
}

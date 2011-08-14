/*
ID: ivan.bu1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

char *ch[] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY" };
set<string> S;
string W;
string cur;
bool haveOne;

void go(int pos, ofstream &fout) {
	if (pos == (int)W.size()) {
		if (S.count(cur)) {
			fout << cur << '\n';
			haveOne = true;
		}
		return;
	}
	for (int i=0; i<3; ++i) {
		cur[pos] = ch[W[pos]-'0'][i];
		go(pos+1, fout);
	}
}
int main() {
	ifstream fin("namenum.in");
    ofstream fout("namenum.out");

	S.clear();
	{
		ifstream dict("dict.txt");
		string w;
		while (dict >> w)
			S.insert(w);
	}

	fin >> W;
	cur.assign(W.size(), ' ');
	haveOne = false;
	go(0, fout);

	if (!haveOne)
		fout << "NONE\n";

	return 0;
}

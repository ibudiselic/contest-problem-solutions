/*
ID: ivan.bu1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define next(i, N) (((i)+1)%(N))
#define prev(i, N) (((i)+(N)-1)%(N))
int calc(const string &s, int cut) {
	char color = s[cut];
	int l = cut;
	int ret = 1;
	while (true) {
		l = prev(l, s.size());
		if (l == cut)
			break;
		if (color == 'w') {
			if (s[l] != 'w')
				color = s[l];
		} else {
			if (s[l]!='w' && s[l]!=color)
				break;
		}
		++ret;
	}

	if (l == cut)
		return ret;
	l = next(l, s.size());

	int r = next(cut, s.size());
	++ret;
	color = s[r];
	while (true) {
		r = next(r, s.size());
		if (r == l)
			break;
		if (color == 'w') {
			if (s[r] != 'w')
				color = s[r];
		} else {
			if (s[r]!='w' && s[r]!=color)
				break;
		}
		++ret;
	}

	return ret;
}
int main() {
	ifstream fin("beads.in");
    ofstream fout("beads.out");

	int N;
	string s;
	fin >> N >> s;

	int sol = 0;
	for (int i=0; i<N; ++i)
		if (s[i] != s[next(i, N)])
			sol = max(sol, calc(s, i));

	if (sol == 0)
		sol = N;

	fout << sol << '\n';
	return 0;
}

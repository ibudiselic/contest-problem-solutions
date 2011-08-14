/*
ID: ivan.bu1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

bool isPalin[3][20000];
int main() {
	ifstream fin("calfflac.in");
    ofstream fout("calfflac.out");
	string s;

	string S_;
	while (getline(fin, s))
		S_ += s + '\n';

	string S;
	vector<int> orig;

	for (int i=0; i<(int)S_.size(); ++i)
		if (isalpha(S_[i])) {
			S += tolower(S_[i]);
			orig.push_back(i);
		}

	int n = S.size();
	for (int i=0; i<n; ++i)
		isPalin[1][i] = true;

	int maxLen = 0;
	int start = 0;
	const int lim = min(2000, n);
	for (int l=1; l<lim; ++l) {
		for (int i=0; i+l<n; ++i)
			if ((l==1 || isPalin[0][i+1]) && S[i]==S[i+l]) {
				isPalin[2][i] = true;
				if (l > maxLen) {
					maxLen = l;
					start = i;
				}
			}
		memcpy(isPalin[0], isPalin[1], sizeof isPalin[0]);
		memcpy(isPalin[1], isPalin[2], sizeof isPalin[1]);
		memset(isPalin[2], 0, sizeof isPalin[2]);
	}

	fout << maxLen+1 << '\n';
	fout << S_.substr(orig[start], orig[start+maxLen] - orig[start] + 1) << '\n';

	return 0;
}

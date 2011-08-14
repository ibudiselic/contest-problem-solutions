/*
ID: ivan.bu1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool hasCow[200];
int nStalls;
int dp[200][51];
int go(int stall, int boardsLeft) {
	if (stall == nStalls)
		return 0;

	int &ret = dp[stall][boardsLeft];
	if (ret != -1)
		return ret;

	ret = 1234567890;
	if (hasCow[stall] && boardsLeft==0) // must cover it but I'm out of boards!
		return ret;

	if (!hasCow[stall]) // don't need to cover it
		ret = min(ret, go(stall+1, boardsLeft));

	if (boardsLeft > 0) {
		// cover some number of stalls [stall, i)
		for (int i=stall+1; i<=nStalls; ++i)
			ret = min(ret, (i-stall) + go(i, boardsLeft-1));
	}

	return ret;
}
int main() {
	ifstream fin("barn1.in");
    ofstream fout("barn1.out");

	int nBoards, nCows;
	fin >> nBoards >> nStalls >> nCows;
	memset(hasCow, 0, sizeof hasCow);
	for (int i=0; i<nCows; ++i) {
		int x;
		fin >> x;
		hasCow[x-1] = true;
	}
	memset(dp, 0xff, sizeof dp);

	fout << go(0, nBoards) << '\n';

	return 0;
}

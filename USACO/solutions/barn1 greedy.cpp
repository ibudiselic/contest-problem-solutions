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
#include <queue>
#include <cassert>

using namespace std;

bool hasCow[200];
struct Rem {
	int l, r, len;
	Rem(int l_, int r_, int len_): l(l_), r(r_), len(len_) {}
};
bool operator<(const Rem &a, const Rem &b) {
	if (a.len != b.len)
		return a.len < b.len;
	else if (a.l != b.l)
		return a.l < b.l;
	else
		return a.r < b.r;
}
bool operator==(const Rem &a, const Rem &b) {
	return !(a<b) && !(b<a);
}
bool operator!=(const Rem &a, const Rem &b) {
	return !(a==b);
}

struct Board {
	int l, r;
	Rem rem;
	Board(int l_, int r_, const Rem &rem_): l(l_), r(r_), rem(rem_) {}
};
bool operator<(const Board &a, const Board &b) {
	if (a.rem != b.rem)
		return a.rem < b.rem;
	else if (a.l != b.l)
		return a.l < b.l;
	else
		return a.r < b.r;
}

Rem getRem(int L, int R) {
	// assume that the edges both have cows
	assert(hasCow[L] && hasCow[R]);

	int start = -1;
	int longest = 0;
	int l=-1, r=-1;
	for (int i=L; i<=R; ++i)
		if (!hasCow[i]) {
			if (start == -1)
				start = i;
		} else {
			if (start != -1)
				if (i-start > longest) {
					longest = i-start;
					l = start;
					r = i-1;
				}
			start = -1;
		}

	return Rem(l, r, longest);
}

int main() {
	ifstream fin("barn1.in");
    ofstream fout("barn1.out");

	int nBoards, nStalls, nCows;
	fin >> nBoards >> nStalls >> nCows;
	memset(hasCow, 0, sizeof hasCow);
	int leftmost=nStalls-1, rightmost=0;

	for (int i=0; i<nCows; ++i) {
		int x;
		fin >> x;
		hasCow[x-1] = true;
		leftmost = min(leftmost, x-1);
		rightmost = max(rightmost, x-1);
	}

	priority_queue<Board> PQ;
	Rem t = getRem(leftmost, rightmost);
	int covered = rightmost-leftmost+1;
	PQ.push(Board(leftmost, rightmost, t));
	while (--nBoards) {
		const Board b = PQ.top();
		PQ.pop();

		if (b.rem.len == 0)
			break;

		covered -= b.rem.len;
		PQ.push(Board(b.l, b.rem.l-1, getRem(b.l, b.rem.l-1)));
		PQ.push(Board(b.rem.r+1, b.r, getRem(b.rem.r+1, b.r)));
	}

	fout << covered << '\n';

	return 0;
}

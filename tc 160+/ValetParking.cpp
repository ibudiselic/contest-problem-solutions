#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct State {
	int i, j, ei, ej;
	State(int i_, int j_, int ei_, int ej_): i(i_), j(j_), ei(ei_), ej(ej_) {}
};
bool operator<(const State &a, const State &b) {
	if (a.i != b.i)
		return a.i < b.i;
	if (a.j != b.j)
		return a.j < b.j;
	if (a.ei != b.ei)
		return a.ei < b.ei;
	return a.ej < b.ej;
}

unsigned char done[12500000];
inline bool testBit(int b) {
	return (done[b/8] & (1<<(b&7))) != 0;
}
inline void setBit(int b) {
	done[b/8] |= (1<<(b&7));
}
inline bool isCached(int i, int j, int ei, int ej) {
	return testBit(i*1000000 + j*10000 + ei*100 + ej);
}
inline void cache(int i, int j, int ei, int ej) {
	setBit(i*1000000 + j*10000 + ei*100 + ej);
}
bool valid(int i, int j) {
	if (i<0 || j<0 || i>=100 || j>=100)
		return false;
	return true;
}
int Si, Sj;
int bfs(int i, int j, int ei, int ej) {
	queue<State> Q;
	cache(i, j, ei, ej);
	Q.push(State(i, j, ei, ej));

	int sol = -1;
	int t = 0;
	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++sol;
		}

		i = Q.front().i;
		j = Q.front().j;
		ei = Q.front().ei;
		ej = Q.front().ej;
		Q.pop();
		--t;

		if (i==0 && j==0)
			return sol;

		if ((i!=Si || j!=Sj) && (abs(i-ei)>2 || abs(j-ej)>2))
			continue;

		if (abs(i-ei) + abs(j-ej) == 1) {
			if (!isCached(ei, ej, i, j)) {
				cache(ei, ej, i, j);
				Q.push(State(ei, ej, i, j));
			}
		}

		for (int di=-1; di<=1; ++di)
			for (int dj=-1; dj<=1; ++dj)
				if (abs(di) + abs(dj) == 1) {
					int r = ei + di;
					int c = ej + dj;
					if (valid(r, c) && (r!=i || c!=j) && !isCached(i, j, r, c)) {
						cache(i, j, r, c);
						Q.push(State(i, j, r, c));
					}
				}
	}

	return -1;
}

class ValetParking {
	public:
	int minMoves(int emptyRow, int emptyCol, int cusRow, int cusCol) {
		memset(done, 0, sizeof done);
		Si = cusRow;
		Sj = cusCol;
		return bfs(cusRow, cusCol, emptyRow, emptyCol);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 50; int Arg1 = 22; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; verify_case(0, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 0; int Arg4 = 1; verify_case(1, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 5; verify_case(2, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 80; int Arg1 = 15; int Arg2 = 40; int Arg3 = 7; int Arg4 = 252; verify_case(3, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ValetParking ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int S[4][4], T[4][4];
int I[16], J[16];
bool used[4][4];
int sol;

void calc() {
	memset(used, 0, sizeof used);
	int cur = 0;
	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			if (!used[i][j] && S[i][j]!=T[i][j]) {
				const int x = S[i][j];
				int cyc = 0;
				int r = i;
				int c = j;
				used[r][c] = 1;
				while (x != T[r][c]) {
					++cyc;
					const int rr = I[T[r][c]];
					const int cc = J[T[r][c]];
					r = rr;
					c = cc;
					used[r][c] = 1;
				}
				cur += cyc;
			}
	sol = min(sol, cur);
}

bool test(int i, int j) {
	if (S[i][j] != -1)
		return false;
	for (int r=0; r<i; ++r)
		if (S[r][j] == -1)
			return false;
	for (int c=0; c<j; ++c)
		if (S[i][c] == -1)
			return false;

	return true;
}
void go(int x) {
	if (x == 15) {
		calc();
		return;
	}
	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			if (test(i, j)) {
				S[i][j] = x;
				I[x] = i; J[x] = j;
				go(x+1);
				S[i][j] = -1;
			}
}
class QuickTableau {
	public:
	int numSwaps(vector <int> table) {
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				T[i][j] = table[i*4 + j]-1;

		memset(S, 0xff, sizeof S);
		S[0][0] = 0;
		S[3][3] = 15;
		I[0] = 0; J[0] = 0;
		I[15] = 3; J[15] = 3;
		sol = 1234567890;
		go(1);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {
 1,  2,  3,  4,
 5,  6,  7,  8,
 9, 10, 11, 12,
13, 14, 15, 16
}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, numSwaps(Arg0)); }
	void test_case_1() { int Arr0[] = {
16, 15, 14, 13,
12, 11, 10,  9,
 8,  7,  6,  5,
 4,  3,  2,  1
}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, numSwaps(Arg0)); }
	void test_case_2() { int Arr0[] = {
 2,  1,  3,  4,
 5,  6,  7,  8,
 9, 10, 11, 12,
13, 14, 15, 16
}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, numSwaps(Arg0)); }
	void test_case_3() { int Arr0[] = {
 4,  3,  2,  1,
 5,  6,  7,  8,
 9, 10, 11, 12,
13, 14, 15, 16
}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, numSwaps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    QuickTableau ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

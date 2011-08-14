#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int T[10000];
bool used[10000];
class Transpose {
	public:
	int numSwaps(int M, int N) {
		int n = 0;
		for (int j=0; j<N; ++j)
			for (int i=0; i<M; ++i)
				T[n++] = i*N + j;

		memset(used, 0, sizeof used);

		int sol = 0;
		for (int i=0; i<n; ++i)
			if (!used[i]) {
				int cycSz = 0;
				int x = i;

				while (!used[x]) {
					++cycSz;
					used[x] = 1;
					x = T[x];
				}
				sol += cycSz-1;
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 3; verify_case(0, Arg2, numSwaps(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, numSwaps(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 10; verify_case(2, Arg2, numSwaps(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 50; int Arg2 = 1225; verify_case(3, Arg2, numSwaps(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 49; int Arg1 = 51; int Arg2 = 2492; verify_case(4, Arg2, numSwaps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Transpose ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

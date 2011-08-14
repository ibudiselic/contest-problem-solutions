#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool have[1001], will[1001];
class ChangingSounds {
	public:
	int maxFinal(vector <int> C, int L, int M) {
		memset(have, 0, sizeof have);
		have[L] = 1;
		for (int i=0; i<(int)C.size(); ++i) {
			memset(will, 0, sizeof will);
			for (int j=0; j<=M; ++j)
				if (have[j]) {
					if (j-C[i] >= 0) will[j-C[i]] = 1;
					if (j+C[i] <= M) will[j+C[i]] = 1;
				}
			memcpy(have, will, sizeof have);
		}

		for (int i=M; i>=0; --i)
			if (have[i])
				return i;
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 10; int Arg3 = 10; verify_case(0, Arg3, maxFinal(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {15, 2, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 20; int Arg3 = -1; verify_case(1, Arg3, maxFinal(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {74,39,127,95,63,140,99,96,154,18,137,162,14,88}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; int Arg2 = 243; int Arg3 = 238; verify_case(2, Arg3, maxFinal(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChangingSounds ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool used[50];
class PScores {
	public:
	int howMany(vector <int> nexts, int score) {
		int n = nexts.size();

		int sol = 0;
		for (int i=0; i<n; ++i) {
			memset(used, 0, sizeof used);
			int p = i;
			used[p] = true;
			while (!used[nexts[p]]) {
				p = nexts[p];
				used[p] = true;
			}
			sol += (p==score);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,6,7,8,9,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 14; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,11,25,29,9,18,0,3,18,19,6,23,25,6,3,9,2,26,10,4,14,10,20,23,26,23,6,16,12,24}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; int Arg2 = 9; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PScores ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

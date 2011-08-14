#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;

class MostLikely {
	public:
	int likelyRank(vector <int> sc, int low, int high) {
		int sol = -1;
		int val = 0;

		sort(sc.begin(), sc.end(), greater<int>());
		sc.push_back(-10);

		for (int r=0; r<(int)sc.size(); ++r) {
			if (high < low)
				break;

			int cur = high - max(low, sc[r]) + 1;
			if (cur > val) {
				sol = r+1;
				val = cur;
			} else if (cur == val) {
				sol = -1;
			}

			high = min(high, sc[r]-1);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,12,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 8; int Arg3 = 2; verify_case(0, Arg3, likelyRank(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] =  {3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 7; int Arg3 = 1; verify_case(1, Arg3, likelyRank(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] =  {3,4,5} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; int Arg3 = -1; verify_case(2, Arg3, likelyRank(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MostLikely ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

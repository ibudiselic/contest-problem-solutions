#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MooingCows {
	public:
	int dissatisfaction(vector <string> farmland) {
		int best = 1000000000;
		for (int i=0; i<(int)farmland.size(); ++i)
			for (int j=0; j<(int)farmland[i].size(); ++j)
				if (farmland[i][j] == 'C') {
					int cur = 0;
					for (int r=0; r<(int)farmland.size(); ++r)
						for (int c=0; c<(int)farmland[r].size(); ++c)
							if (farmland[r][c] == 'C')
								cur += (i-r)*(i-r) + (j-c)*(j-c);
					best = min(best, cur);
				}
		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"C..",
 ".C.",
 ".C."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, dissatisfaction(Arg0)); }
	void test_case_1() { string Arr0[] = {"CCCC",
 "CCCC",
 "CCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(1, Arg1, dissatisfaction(Arg0)); }
	void test_case_2() { string Arr0[] = {"C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, dissatisfaction(Arg0)); }
	void test_case_3() { string Arr0[] = {"CCC....",
 "C......",
 "....C.C",
 ".C.CC..",
 "C......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 81; verify_case(3, Arg1, dissatisfaction(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MooingCows ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

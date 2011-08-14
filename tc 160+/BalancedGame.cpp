#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool test(const string &s, int p, int q) {
	int w=0, l=0;
	for (int i=0; i<(int)s.size(); ++i)
		if (s[i] == 'W')
			++w;
		else if (s[i] == 'L')
			++l;

	return p*(s.size()-1)<=w*100 && q*(s.size()-1)<=l*100;
}
class BalancedGame {
	public:
	int result(vector <string> conflicts, int p, int q) {
		int n = conflicts.size();
		for (int i=0; i<n; ++i)
			if (!test(conflicts[i], p, q))
				return i;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"TWWW",
 "LTWW",
 "LLTW",
 "LLLT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 20; int Arg3 = 0; verify_case(0, Arg3, result(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"TWWW",
 "LTWW",
 "LLTW",
 "LLLT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = -1; verify_case(1, Arg3, result(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"TTT",
 "TTT",
 "TTT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(2, Arg3, result(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"TLLLLLTWWWWTLLWWWT",
 "WTTWTTLLWLLWWLTLWW",
 "WTTWWTLWTWLWWWWLTW",
 "WLLTLTWWWTWLWLLWLT",
 "WTLWTLWWWWLLWLLWTW",
 "WTTTWTWLLWTLLWWWLW",
 "TWWLLLTLLWTWWWLLWW",
 "LWLLLWWTWLLWWLLLWT",
 "LLTLLWWLTTWLTWTLWT",
 "LWLTLLLWTTTLLLLWTW",
 "LWWLWTTWLTTTLLWWLL",
 "TLLWWWLLWWTTLWTTLL",
 "WLLLLWLLTWWWTWLLWW",
 "WWLWWLLWLWWLLTTWLL",
 "LTLWWLWWTWLTWTTTWT",
 "LWWLLLWWWLLTWLTTLW",
 "LLTWTWLLLTWWLWLWTW",
 "TLLTLLLTTLWWLWTLLT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; int Arg2 = 6; int Arg3 = 17; verify_case(3, Arg3, result(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BalancedGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

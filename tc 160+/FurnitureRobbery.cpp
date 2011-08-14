#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FurnitureRobbery {
	public:
	int leastPushes(vector <string> plan) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"......",
 ".BBB.X",
 ".B.B.X",
 "DDCC.Y",
 "..AAAY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(0, Arg1, leastPushes(Arg0)); }
	void test_case_1() { string Arr0[] = {"......",
 ".BBB.X",
 ".B.B.X",
 "....YY",
 "..AAAY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(1, Arg1, leastPushes(Arg0)); }
	void test_case_2() { string Arr0[] = {"...C.C",
 "BBBCCC",
 "B.B...",
 ".XX..Y",
 "..AAAY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, leastPushes(Arg0)); }
	void test_case_3() { string Arr0[] = {"......",
 "ZBBBXY",
 "ZBBBXY",
 "EAAACC",
 "E.DDCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(3, Arg1, leastPushes(Arg0)); }
	void test_case_4() { string Arr0[] = {"......",
 "BBB...",
 "BCBC..",
 ".CCC.Y",
 "..AAAY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(4, Arg1, leastPushes(Arg0)); }
	void test_case_5() { string Arr0[] = {".C",
 "BC",
 "BC",
 "B.",
 "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, leastPushes(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FurnitureRobbery ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

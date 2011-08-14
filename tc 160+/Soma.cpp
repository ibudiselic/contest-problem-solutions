#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Soma {
	public:
	int letMeCountTheWays(vector <string> pattern) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"333",
 "333",
 "333"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11520; verify_case(0, Arg1, letMeCountTheWays(Arg0)); }
	void test_case_1() { string Arr0[] = {"345",
 "234",
 "123"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2800; verify_case(1, Arg1, letMeCountTheWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"3330000",
 "0033300",
 "0000333"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(2, Arg1, letMeCountTheWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"21111111",
 "21111111",
 "21111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, letMeCountTheWays(Arg0)); }
	void test_case_4() { string Arr0[] = {"67",
 "77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1520; verify_case(4, Arg1, letMeCountTheWays(Arg0)); }
	void test_case_5() { string Arr0[] = {"010000000000000000000000000",
 "110000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000000",
 "000000000000000000000000022",
 "000000000000000000000000022",
 "000000000000000000000002222",
 "000000000000000000000002222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 76; verify_case(5, Arg1, letMeCountTheWays(Arg0)); }
	void test_case_6() { string Arr0[] = {"11100110001",
 "01001100111",
 "00000000000",
 "20002012011",
 "11011001001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, letMeCountTheWays(Arg0)); }
	void test_case_7() { string Arr0[] = {"121",
 "222",
 "121",
 "121",
 "333"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 78; verify_case(7, Arg1, letMeCountTheWays(Arg0)); }
	void test_case_8() { string Arr0[] = {"020",
 "010",
 "010",
 "020",
 "343",
 "353"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; verify_case(8, Arg1, letMeCountTheWays(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Soma ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

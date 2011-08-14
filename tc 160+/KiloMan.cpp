#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class KiloMan {
	public:
	int hitsTaken(vector <int> pattern, string jumps) {
		int sol = 0;
		for (int i=0; i<(int)pattern.size(); ++i)
			sol += (jumps[i]=='J' && pattern[i]>2) + (jumps[i]=='S' && pattern[i]<=2);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,2,3,3,1,2,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "JJSSSJSSJ"; int Arg2 = 4; verify_case(0, Arg2, hitsTaken(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,
 4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "SSSSSSSSSSSSSSJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ"; int Arg2 = 49; verify_case(1, Arg2, hitsTaken(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "SJJS"; int Arg2 = 2; verify_case(2, Arg2, hitsTaken(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "J"; int Arg2 = 0; verify_case(3, Arg2, hitsTaken(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    KiloMan ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

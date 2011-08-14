#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class AdditionGame {
	public:
	int getMaximumPoints(int A, int B, int C, int N) {
		vector<int> t;
        t.push_back(A);
        t.push_back(B);
        t.push_back(C);
        sort(t.begin(), t.end());
        int sol = 0;
        while (N-- && t.back()>0) {
            sol += t.back();
            --(t.back());
            sort(t.begin(), t.end());
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 5; int Arg3 = 3; int Arg4 = 13; verify_case(0, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 8; int Arg4 = 3; verify_case(1, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 48; int Arg3 = 40; int Arg4 = 1140; verify_case(2, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 36; int Arg1 = 36; int Arg2 = 36; int Arg3 = 13; int Arg4 = 446; verify_case(3, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 2; int Arg2 = 6; int Arg3 = 13; int Arg4 = 57; verify_case(4, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AdditionGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

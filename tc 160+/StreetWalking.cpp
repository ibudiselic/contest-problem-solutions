#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class StreetWalking {
	public:
	long long minTime(int x, int y, long long w, long long s) {
	    long long sol = (x+y) * w;

        long long M = max(x, y);
        long long m = min(x, y);
        long long alt = m*s + (M-m)*w;
        alt = min(alt, m*s + (M-m)/2 * 2*s + ((M-m)%2==1 ? w : 0LL));

        return min(sol, alt);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 3; int Arg3 = 10; long long Arg4 = 18LL; verify_case(0, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 3; int Arg3 = 5; long long Arg4 = 16LL; verify_case(1, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 12; int Arg3 = 10; long long Arg4 = 20LL; verify_case(2, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 25; int Arg1 = 18; int Arg2 = 7; int Arg3 = 11; long long Arg4 = 247LL; verify_case(3, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 24; int Arg1 = 16; int Arg2 = 12; int Arg3 = 10; long long Arg4 = 240LL; verify_case(4, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 10000000; int Arg1 = 50000000; int Arg2 = 800; int Arg3 = 901; long long Arg4 = 41010000000LL; verify_case(5, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 135; int Arg1 = 122; int Arg2 = 43; int Arg3 = 29; long long Arg4 = 3929LL; verify_case(6, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StreetWalking ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

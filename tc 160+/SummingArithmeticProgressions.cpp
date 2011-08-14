#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int gcd(int m, int n) {
	return m==0 ? n : gcd(n%m, m);
}

class SummingArithmeticProgressions {
	public:
	int howMany(int left, int right, int k) {
		int A = k;
		int B = k*(k-1)/2;
		
		int g = gcd(A, B);
		A /= g;
		B /= g;
		left = (left + g-1)/g;
		right = right/g;
		
		int sol = 0;
		for (int x=1; x<=B; ++x) {
			int L = max(1, left-x*A);
			int R = right - x*A;
			if (R >= L) {
				sol += R/B - (L-1)/B;
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 12; int Arg2 = 3; int Arg3 = 3; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 2; int Arg3 = 8; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 4; int Arg3 = 6; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 4; int Arg3 = 0; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 13; int Arg2 = 4; int Arg3 = 1; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SummingArithmeticProgressions ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

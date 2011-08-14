#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class ProductOfDigits {
	public:
	int smallestNumber(int N) {
        if (N < 10) {
            return 1;
        }
        vector<int> d(10, 0);
        for (int i=2; i<10; ++i) {
            while (N%i == 0) {
                N /= i;
                ++d[i];
            }
        }
        
        if (N > 1) {
            return -1;
        }
        
        d[8] = d[2]/3;
        d[2] -= d[8]*3;
        d[4] = d[2]/2;
        d[2] -= d[4]*2;
        d[9] = d[3]/2;
        d[3] -= d[9]*2;
        d[6] = min(d[2], d[3]);
        d[2] -= d[6];
        d[3] -= d[6];
        
        return accumulate(d.begin(), d.end(), 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, smallestNumber(Arg0)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 2; verify_case(1, Arg1, smallestNumber(Arg0)); }
	void test_case_2() { int Arg0 = 26; int Arg1 = -1; verify_case(2, Arg1, smallestNumber(Arg0)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 3; verify_case(3, Arg1, smallestNumber(Arg0)); }
	void test_case_4() { int Arg0 = 2520; int Arg1 = 4; verify_case(4, Arg1, smallestNumber(Arg0)); }
	void test_case_5() { int Arg0 = 864; int Arg1 = 4; verify_case(5, Arg1, smallestNumber(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ProductOfDigits ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

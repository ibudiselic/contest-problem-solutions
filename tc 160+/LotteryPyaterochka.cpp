#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double C(int n, int k) {
    int ret = 1;
    for (int i=0; i<k; ++i) {
        ret = ret*(n-i)/(i+1);
    }
    return double(ret);
}
class LotteryPyaterochka {
	public:
	double chanceToWin(int N) {
        if (N <= 2) {
            return 1.0;
        }
		
        return N*(C(5, 3)*C(5*(N-1), 2) + C(5, 4)*5*(N-1) + 1)/C(5*N, 5);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; double Arg1 = 1.0; verify_case(0, Arg1, chanceToWin(Arg0)); }
	void test_case_1() { int Arg0 = 2; double Arg1 = 1.0; verify_case(1, Arg1, chanceToWin(Arg0)); }
	void test_case_2() { int Arg0 = 3; double Arg1 = 0.5004995004995004; verify_case(2, Arg1, chanceToWin(Arg0)); }
	void test_case_3() { int Arg0 = 6; double Arg1 = 0.13161551092585574; verify_case(3, Arg1, chanceToWin(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LotteryPyaterochka ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

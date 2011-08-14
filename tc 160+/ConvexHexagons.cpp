#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1000000007;
class ConvexHexagons {
	public:
	int find(int N) {
		long long sol = 0;
        for (long long n=3; n<=N; ++n) {
            const long long a = (n-1) / 2;
            long long add = a + 
                            3*a*(a-1)/2 + 
                            3*(a-1)*a + 
                            (!(n&1)) * 3*a*a;
            add %= mod;
            if (a > 2) {
                add = (add + a*(a+1)%mod*(2*a+1) - 30 - 18*(a*(a+1)/2 - 3) + 12*(a-2)) % mod;
            }
            const long long cnt = (N-n+1)*(N-n+2)/2 % mod;
            add = add*cnt % mod;
            sol = (sol + add)%mod;
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 7; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 232; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 104; int Arg1 = 635471838; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 0; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ConvexHexagons ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long cnt[1000001], expire[1000001];
const long long mod = 1000000009;
class BunnySequence {
	public:
	int getNumber(int m, int n) {
		memset(cnt, 0, sizeof cnt);
        memset(expire, 0, sizeof cnt);
        cnt[0] = 1;
        cnt[1] = 1;
        expire[m] = 1;
        for (int i=2; i<=n; ++i) {
            cnt[i] = (2*cnt[i-1] + mod - expire[i]) % mod;
            if (i+m <= n) {
                expire[i+m] = cnt[i-1];
            }
        }
        
        return cnt[n];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 487; int Arg1 = 0; int Arg2 = 1; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 19; int Arg1 = 10; int Arg2 = 512; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 6; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 487; int Arg2 = 829515032; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BunnySequence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

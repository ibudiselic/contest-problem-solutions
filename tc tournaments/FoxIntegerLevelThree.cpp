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

int fun(long long x) {
    return (x-1)%9 + 1;
}
int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
int lcm(int m, int n) {
    return m/gcd(m, n)*n;
}
int MAGIC_NUMBER = 1;
int section_sz = 6088;
long long cnt(long long lim) {
    long long ret = lim/MAGIC_NUMBER*section_sz;
    for (long long x=lim/MAGIC_NUMBER*MAGIC_NUMBER + 1; x<=lim; ++x) {
        bool ok = false;
        for (int d=1; d<10; ++d) {
            if (x%d==0 && fun(x/d)==d) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ++ret;
        }
    }
    return ret;
}
class FoxIntegerLevelThree {
	public:
	long long count(long long min, long long max) {
        MAGIC_NUMBER = 1;
        for (int i=1; i<=9; ++i) {
            MAGIC_NUMBER = lcm(MAGIC_NUMBER, i);
        }
        MAGIC_NUMBER *= 9;
        return cnt(max) - cnt(min - 1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 16LL; long long Arg2 = 2LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 123LL; long long Arg1 = 123LL; long long Arg2 = 0LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 160LL; long long Arg1 = 160LL; long long Arg2 = 1LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 47LL; long long Arg1 = 58LL; long long Arg2 = 4LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 123456789LL; long long Arg1 = 9876543210LL; long long Arg2 = 2618024258LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxIntegerLevelThree ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

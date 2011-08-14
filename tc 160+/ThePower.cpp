#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

unsigned long long lim;
unsigned long long to_the(unsigned long long n, int k) {
    if (n == 0) {
        return 0;
    }
    unsigned long long ret = 1;
    while (k > 0) {
        if (k & 1) {
            if (n < lim/ret) {
                ret *= n;
            } else {
                return lim;
            }
        }
        if (n < lim/n) {
            n *= n;
        } else {
            n = lim;
        }
        k >>= 1;
    }
    return ret;
}
unsigned long long kth_root(unsigned long long n, int k) {
    unsigned long long lo = 0;
    unsigned long long hi = n+1;
    while (lo < hi) {
        unsigned long long m = lo + (hi-lo+1)/2;
        if (to_the(m, k) <= n) {
            lo = m;
        } else {
            hi = m-1;
        }
    }
    return lo;
}
unsigned long long go(unsigned long long n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    unsigned long long ret = n-1;
    
    for (int i=2; ; ++i) {
        unsigned long long t = kth_root(n, i);
        if (t==n || t+1==n) {
            continue;
        }
        ret = min(ret, 1 + n-to_the(t, i) + go(t));
        ret = min(ret, 1 + to_the(t+1, i)-n + go(t+1));
        if (t == 1) {
            break;
        }
    }
    return ret;
}
class ThePower {
	public:
	int count(unsigned long long n) {
		lim = 2*n + 1;
        return (int)go(n);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 8LL; int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { long long Arg0 = 1LL; int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { long long Arg0 = 80LL; int Arg1 = 4; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { long long Arg0 = 123456789LL; int Arg1 = 2566; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ThePower ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

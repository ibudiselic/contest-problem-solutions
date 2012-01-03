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

vector<long long> L;
void L_gen(long long x, long long lim) {
    if (x <= lim) {
        L.push_back(x);
        L_gen(x*10 + 4, lim);
        L_gen(x*10 + 7, lim);
    }
}

bool lte(long long cand, long long a, long long b, long long c, long long n) {
    return a<=n/cand && a*cand<=n/cand && b<=(n-a*cand*cand)/cand && a*cand*cand+b*cand+c<=n;
}

long long bs(long long a, long long b, long long c, long long lo, long long n) {
    long long hi = lo;
    while (lte(hi, a, b, c, n)) {
        hi *= 2;
    }
    while (lo < hi) {
        long long mid = lo + (hi-lo+1)/2;
        if (lte(mid, a, b, c, n)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

class TheLuckyBasesDivOne {
	public:
	long long find(long long n) {
	    L.clear();
        L_gen(4, n);
        L_gen(7, n);
        sort(L.begin(), L.end());
        if (L.back() == n) {
            return -1;
        }
        
        long long sol = 0;
        long long base = 2;
        while (1) { // 4 or more digits
            if (n/base/base < base) {
                break;
            }
            long long x = n;
            bool ok = true;
            while (x > 0) {
                long long d = x % base;
                if (*lower_bound(L.begin(), L.end(), d) != d) {
                    ok = false;
                    break;
                }
                x /= base;
            }
            sol += ok;
            ++base;
        }
        
        // 3 digits
        for (int ai=0; ai<(int)L.size(); ++ai) {
            const long long a = L[ai];
            long long u = a+1;
            if (a>n/u || a*u>n/u) {
                break;
            }
            for (int bi=0; bi<(int)L.size(); ++bi) {
                const long long b = L[bi];
                u = max(u, b+1);
                if (a>n/u || a*u>n/u || b>(n-a*u*u)/u) {
                    break;
                }
                
                long long last_maxbase = -1;
                for (int ci=0; ci<(int)L.size(); ++ci) {
                    const long long c = L[ci];
                    const long long uu = max(u, c+1);
                    if (a>n/uu || a*uu>n/uu || b>(n-a*uu*uu)/uu || a*uu*uu+b*uu+c>n) {
                        break; // just adding c can't overflow because at least 2*n will fit in long long
                    }
                    
                    // we know this doesn't overflow due to the previous iteration, and by the above argument about adding c
                    if (last_maxbase!=-1 && a*last_maxbase*last_maxbase+b*last_maxbase+c<n) {
                        continue; // since we couldn't increase last_maxbase for the last c to get <= n, we can't do it now either
                    }
                    last_maxbase = bs(a, b, c, uu, n);
                    if (a*last_maxbase*last_maxbase + b*last_maxbase + c == n) {
                        ++sol;
                    }
                }
            }
        }
        
        // 2 digits
        for (int ai=0; ai<(int)L.size(); ++ai) {
            const long long a = L[ai];
            long long u = a+1;
            if (a > n/u) {
                break;
            }
            for (int bi=0; bi<(int)L.size(); ++bi) {
                const long long b = L[bi];
                u = max(u, b+1);
                if (a>n/u || a*u+b>n) {
                    break;
                }
                if ((n-b)%a == 0) {
                    const long long x = (n-b) / a;
                    sol += (x>=u);
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 255LL; long long Arg1 = 2LL; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { long long Arg0 = 474LL; long long Arg1 = -1LL; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 0LL; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { long long Arg0 = 4748LL; long long Arg1 = 5LL; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLuckyBasesDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

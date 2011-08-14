#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class StrongEconomy {
	public:
	long long earn(long long n, long long k, long long price, long long target) {
	    if (n > k) {
        	swap(n, k);
        }
        
        if (price >= target) {
            if (n > 1000000) {
                return 1;
            }
            long long add = n*k;
            return (target+add-1)/add;
        }
        
        long long cur = 0;
        long long rounds = 0;
        long long sol = 1234567890123456LL;
        while (cur<target && rounds<sol) {
            if (n > 1000000) {
                return min(sol, rounds + 1);
            }
            long long add = n*k;
            // no buys
            sol = min(sol, rounds + (target-cur+add-1)/add);
            // buy all
            long long can_buy = cur/price;
            long long ncur = cur - can_buy*price;
            long long nn, nk;
            if (n < k) {
                long long diff = k - n;
                long long x = min(diff, can_buy);
                nn = n + x;
                nk = k;
                can_buy -= x;
            } else {
                nn = n;
                nk = k;
            }
            nn += can_buy/2;
            nk += (can_buy+1)/2;
            if (nn > 1000000) {
                return min(sol, rounds + 1);
            }
            long long nadd = nn*nk;
            long long to_next_buy = (price-ncur+nadd-1)/nadd;
            rounds += to_next_buy;
            cur = ncur + to_next_buy * nadd;
            n = nn;
            k = nk;
        }
        
        return min(sol, rounds);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 1LL; long long Arg2 = 2LL; long long Arg3 = 10LL; long long Arg4 = 4LL; verify_case(0, Arg4, earn(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 2LL; long long Arg1 = 1LL; long long Arg2 = 2LL; long long Arg3 = 9LL; long long Arg4 = 3LL; verify_case(1, Arg4, earn(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 500000LL; long long Arg3 = 1000002LL; long long Arg4 = 1000001LL; verify_case(2, Arg4, earn(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 5LL; long long Arg1 = 4LL; long long Arg2 = 15LL; long long Arg3 = 100LL; long long Arg4 = 5LL; verify_case(3, Arg4, earn(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StrongEconomy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

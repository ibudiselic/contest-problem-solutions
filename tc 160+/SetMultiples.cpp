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

class SetMultiples {
	public:
	long long smallestSubset(long long A, long long B, long long C, long long D) {
        long long sol = D - max(C-1, D/2);
        
        A = max(A, D-C+1);
        A = max(A, B/2 + 1);
        if (A > B) {
            return sol;
        }
        
        for (long long K=B; K>=A; --K) {
            long long lo = 1;
            long long hi = 2;
            while (hi*K <= D) {
                hi <<= 1;
            }
            while (lo < hi) {
                long long mid = lo + (hi-lo)/2;
                if (mid*K > D) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            assert(lo > 1);
            if ((lo-1)*K >= C) {
                long long can = ((lo-1)*K - C) / (lo-1);
                K -= can;
            } else {
                long long cant = (lo*K - (D+1)) / lo;
                cant = min(cant, K-A);
                sol += cant + 1;
                K -= cant;
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 2LL; long long Arg3 = 2LL; long long Arg4 = 1LL; verify_case(0, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; long long Arg3 = 4LL; long long Arg4 = 2LL; verify_case(1, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 2LL; long long Arg1 = 3LL; long long Arg2 = 5LL; long long Arg3 = 7LL; long long Arg4 = 3LL; verify_case(2, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 10LL; long long Arg2 = 100LL; long long Arg3 = 1000LL; long long Arg4 = 500LL; verify_case(3, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 1000000000LL; long long Arg1 = 2000000000LL; long long Arg2 = 9000000000LL; long long Arg3 = 10000000000LL; long long Arg4 = 1254365078LL; verify_case(4, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SetMultiples ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

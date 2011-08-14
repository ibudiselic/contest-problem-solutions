#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long inf = 1234567890123456LL;
long long choose(long long n, long long k) {
    long long ret = 1;
    for (long long i=0; i<k; ++i) {
        ret = ret * (n-i) / (i+1);
    }
    return ret;
}
long long low(long long N, long long K) {
    long long ret = 0;
    for (long long i=0; i<=K; ++i) {
        long long ways = choose(K, i);
        if (ways >= N) {
            ret += N * i;
            return ret;
        } else {
            N -= ways;
            ret += ways * i;
        }
    }
    return inf;
}
class NumberMagic {
	public:
	int theMin(long long N, long long M) {
		int lo = 0;
        int hi = N-1;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            long long L = low(N, mid);
            if (L > M*mid) {
                lo = mid + 1;
            } else {
                long long H = N*mid - L;
                if (H < M*mid) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
        }
        
        return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 16; int Arg1 = 8; int Arg2 = 4; verify_case(0, Arg2, theMin(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, theMin(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 2; verify_case(2, Arg2, theMin(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NumberMagic ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

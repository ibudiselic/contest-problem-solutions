#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const long long MAX_VAL = 200000;
long long cnt[MAX_VAL+1];
long long dist[MAX_VAL+1];
const long long mod = 1000000007;

void change(long long x, long long by, long long *A) {
    assert(x > 0);
    while (x <= MAX_VAL) {
        A[x] += by;
        x = (x | (x-1)) + 1;
    }
}

long long get_sum_lte(long long x, long long *A) {
    long long sum = 0;
    while (x > 0) {
        sum += A[x];
        x &= x - 1;
    }
    return sum;
}
long long get_sum(long long l, long long r, long long *A) {
    return l > r ? 0LL : get_sum_lte(r, A) - get_sum_lte(l-1, A);
}
class ProductOfPrices {
	public:
	int product(int N, int L, int X0, int A, int B) {
        memset(cnt, 0, sizeof cnt);
        memset(dist, 0, sizeof dist);
        long long x = X0 % L;
        change(x+1, 1, cnt);
        change(x+1, x+1, dist);
        long long sol = 1;
        
        for (int i=1; i<N; ++i) {
            x = (x*A + B) % L;
            long long price = (x+1) * (get_sum(1, x, cnt) - get_sum(x+2, L, cnt)) - get_sum(1, x, dist) + get_sum(x+2, L, dist);
            price %= mod;
            sol = (sol * price) % mod;
            change(x+1, 1, cnt);
            change(x+1, x+1, dist);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 3; int Arg3 = 1; int Arg4 = 1; int Arg5 = 180; verify_case(0, Arg5, product(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 20; int Arg2 = 5; int Arg3 = 2; int Arg4 = 3; int Arg5 = 64; verify_case(1, Arg5, product(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 21; int Arg2 = 1; int Arg3 = 7; int Arg4 = 1; int Arg5 = 3087; verify_case(2, Arg5, product(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 100; int Arg2 = 4; int Arg3 = 37; int Arg4 = 11; int Arg5 = 591860767; verify_case(3, Arg5, product(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 200000; int Arg2 = 999999999; int Arg3 = 123456789; int Arg4 = 987654321; int Arg5 = 499739175; verify_case(4, Arg5, product(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ProductOfPrices ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

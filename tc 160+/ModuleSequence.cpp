#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

// great editorial

long long block;
long long mem[100001];
long long cnt_j_times_K(long long upper) {
    if (upper < mem[0]) {
        return 0;
    }
    if (upper >= mem[block-1]) {
        return block;
    }
    int lo = 0;
    int hi = block;
    while (lo+1 < hi) {
        int mid = lo + (hi-lo)/2;
        if (mem[mid] <= upper) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo + 1;
}
long long get_cnt(long long K, long long N, long long B, long long upper) {
    if (B < 0) {
        return 0;
    }
    if (K == 0) {
        return B + 1;
    }
    
    long long cnt = 0;
    long long x = 0;
    for (long long i=0; i<B/block; ++i) {
        // these two sets are disjoint since
        // the constraints guarantee that upper < N
        cnt += cnt_j_times_K(upper - x);
        cnt += cnt_j_times_K(upper + N - x) - cnt_j_times_K(N - x - 1);
        x = (x + block*K) % N;
    }
    for (long long i=0; i<=B%block; ++i) {
        cnt += (x <= upper);
        x += K;
        if (x >= N) {
            x -= N;
        }
    }
    
    return cnt;
}
long long get_cnt(long long K, long long N, long long A, long long B, long long upper) {
    if (upper < 0) {
        return 0;
    }
    return get_cnt(K, N, B, upper) - get_cnt(K, N, A-1, upper);
}
class ModuleSequence {
	public:
	long long countElements(long long K, long long N, long long A, long long B, long long lower, long long upper) {
        K %= N;
        block = sqrt(B + 1);
        long long x = 0;
        for (int i=0; i<block; ++i) {
            mem[i] = x;
            x += K;
            if (x >= N) {
                x -= N;
            }
        }
        sort(mem, mem+block);
		return get_cnt(K, N, A, B, upper) - get_cnt(K, N, A, B, lower-1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 7LL; long long Arg2 = 1LL; long long Arg3 = 5LL; long long Arg4 = 2LL; long long Arg5 = 5LL; long long Arg6 = 3LL; verify_case(0, Arg6, countElements(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { long long Arg0 = 9LL; long long Arg1 = 1LL; long long Arg2 = 0LL; long long Arg3 = 7LL; long long Arg4 = 0LL; long long Arg5 = 0LL; long long Arg6 = 8LL; verify_case(1, Arg6, countElements(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { long long Arg0 = 20LL; long long Arg1 = 12LL; long long Arg2 = 21LL; long long Arg3 = 30LL; long long Arg4 = 1LL; long long Arg5 = 11LL; long long Arg6 = 6LL; verify_case(2, Arg6, countElements(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { long long Arg0 = 30LL; long long Arg1 = 89LL; long long Arg2 = 112LL; long long Arg3 = 200LL; long long Arg4 = 80LL; long long Arg5 = 88LL; long long Arg6 = 9LL; verify_case(3, Arg6, countElements(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { long long Arg0 = 890LL; long long Arg1 = 1000LL; long long Arg2 = 1000LL; long long Arg3 = 10000LL; long long Arg4 = 456LL; long long Arg5 = 980LL; long long Arg6 = 4770LL; verify_case(4, Arg6, countElements(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ModuleSequence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

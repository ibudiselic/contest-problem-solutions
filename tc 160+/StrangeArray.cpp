#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int gcd(int m, int n) {
	return m==0 ? n : gcd(n%m, m);
}
int lcm(int m, int n) {
	return m/gcd(m, n) * n;
}

long long mod = 1000000007;
int L, K;

long long fastexp(long long a, long long n) {
	long long ret = 1;
	while (n > 0) {
		if (n & 1) {
			ret = (ret * a) % mod;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return ret;
}

long long T(long long c, long long a, long long b) {
	if (c == 0) {
		return fastexp(a, b);
	}
	if (c & 1) {
		return (1 + fastexp(a, (c+1)/2 * K)) * T((c-1)/2, a, b) % mod;
	} else {
		return (fastexp(a, b) + (fastexp(a, K) * T(c-1, a, b)) % mod) % mod;
	}
}

class StrangeArray {
	public:
	int calculateSum(vector <int> A, vector <int> B, string N_) {
		L = lcm(A.size(), B.size());
		K = L / B.size();
		long long N;
		istringstream is(N_);
		is >> N;

		long long sol = 0;
		long long total_cols = min((long long)L, N);
		long long short_len = N / total_cols;
		long long long_len = short_len + 1;
		long long long_col = N - short_len*total_cols;

		for (int t=0; t<total_cols; ++t) {
			int i = t % A.size();
			int j = t % B.size();
			if (t < long_col) {
				sol = (sol + T(long_len-1, A[i], B[j] + t/B.size())) % mod;
			} else {
				sol = (sol + T(short_len-1, A[i], B[j] + t/B.size())) % mod;
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "2"; int Arg3 = 17; verify_case(0, Arg3, calculateSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "3"; int Arg3 = 95; verify_case(1, Arg3, calculateSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "5"; int Arg3 = 192; verify_case(2, Arg3, calculateSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1000000000"; int Arg3 = 607570807; verify_case(3, Arg3, calculateSum(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StrangeArray ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

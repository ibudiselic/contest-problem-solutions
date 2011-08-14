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

map<int, int> S_, G_;
int mod;
int mul(long long a, long long b) {
	return int(a*b % mod);
}
int add(long long a, long long b) {
	return int((a+b) % mod);
}
int sub(long long a, long long b) {
	return int((a+2LL*mod-b) % mod);
}
int fastexp(int x, int n) {
	int ret = 1;
	while (n > 0) {
		if (n & 1) {
			ret = mul(ret, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return ret;
}
int G(int, int);
int S(int n, int x) {
	if (n == 0) {
		return 1;
	}
	int &ret = S_[n];
	if (ret != 0) {
		return ret;
	}
	if (n & 1) {
		int k = (n+1)/2;

		ret = mul(S(k-1, x), add(1, fastexp(x, k)));
		ret = add(ret, mul(k, mul(fastexp(x, k), G(k-1, x))));
	} else {
		ret = add(S(n-1, x), mul(n+1, fastexp(x, n)));
	}

	return ret;
}

int G(int n, int x) {
	if (n == 0) {
		return 1;
	}
	int &ret = G_[n];
	if (ret != 0) {
		return ret;
	}
	if (n & 1) {
		int k = (n+1)/2;

		ret = mul(G(k-1, x), add(1, fastexp(x, k)));
	} else {
		ret = add(1, mul(x, G(n-1, x)));
	}

	return ret;
}

class AlienLanguage {
	public:
	int getNumberOfWords(int P, int Q, int N, int M) {
		mod = M;

		S_.clear();
		G_.clear();
		int p = S(N, P);

		S_.clear();
		G_.clear();
		int q = S(N, Q);

		return sub(mul(p, q), 1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 9; int Arg4 = 8; verify_case(0, Arg4, getNumberOfWords(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 2; int Arg3 = 1000; int Arg4 = 577; verify_case(1, Arg4, getNumberOfWords(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1000000000; int Arg3 = 1000000000; int Arg4 = 0; verify_case(2, Arg4, getNumberOfWords(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 456; int Arg2 = 789; int Arg3 = 987654321; int Arg4 = 345494202; verify_case(3, Arg4, getNumberOfWords(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AlienLanguage ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

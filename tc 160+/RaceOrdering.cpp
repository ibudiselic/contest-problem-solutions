#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long mul(long long x, long long y) {
	return x*y % 1000003;
}
long long add(long long x, long long y) {
	return (x+y) % 1000003;
}

vector<int> A, B;
int N;
int K;
int dp[31][1<<16];

int calc_mask(int k, int mask) {
	for (int i=0; i<K; ++i) {
		if (A[i] == A[k]) {
			mask |= (1<<i);
		}
	}
	return mask;
}

bool disabled[30];
int go(int n, int mask) {
	if (n == 0) {
		return 1;
	}
	int &ret = dp[n][mask];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	vector<bool> disabled(N, 0);
	for (int i=0; i<K; ++i) {
		if (mask & (1<<i)) {
			disabled[A[i]] = 1;
		} 
	}

	int cnt = n;
	for (int i=0; i<K; ++i) {
		if (!(mask & (1<<i))) {
			if (!disabled[B[i]]) {
				--cnt;
				disabled[B[i]] = 1;
			}
		}
	}
	for (int i=0; i<K; ++i) {
		if (!disabled[A[i]]) {
			disabled[A[i]] = 1;
			ret = (int)add(ret, go(n-1, calc_mask(i, mask)));
			--cnt;
		}
	}

	if (cnt >= 0) {
		ret = (int)add(ret, mul(cnt, go(n-1, mask)));
	} else {
		ret = 0;
	}

	return ret;
}

class RaceOrdering {
	public:
	int countOrders(int n, vector <int> first, vector <int> second) {
		N = n;
		A = first;
		K = A.size();
		B = second;

		memset(dp, 0xff, sizeof dp);
		return go(N, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, countOrders(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(1, Arg3, countOrders(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 3, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, countOrders(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 30; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 90317; verify_case(3, Arg3, countOrders(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RaceOrdering ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

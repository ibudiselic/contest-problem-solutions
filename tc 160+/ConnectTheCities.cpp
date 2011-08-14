#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[52][101];
vector<int> P;
int F, D, R;
int go(int p, int last) {
	if (p+1 == (int)P.size()) {
		return 0;
	}
	int &ret = dp[p][last];
	if (ret != -1) {
		return ret;
	}

	ret = 123456789;
	for (int t=last; t<=D; ++t) {
		if (t-last<=R && (p+2<(int)P.size() || D-t<=R)) {
			ret = min(ret, abs(t-P[p]) + go(p+1, t));
		}
	}

	return ret;
}

bool can_do(int range) {
	memset(dp, 0xff, sizeof dp);
	R = range;
	return go(1, 0) <= F;
}

class ConnectTheCities {
	public:
	int minimalRange(int distance, int funds, vector <int> position) {
		int lo=1, hi=100;

		D = distance;
		F = funds;
		P = position;
		P.push_back(0);
		sort(P.begin(), P.end());
		P.push_back(D+1);
		while (lo < hi) {
			int mid = lo + (hi-lo)/2;
			if (can_do(mid)) {
				hi = mid;
			} else {
				lo = mid + 1;
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
	void test_case_0() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = { 3, 7, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, minimalRange(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 100; int Arr2[] = { 0, 0, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, minimalRange(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 63; int Arg1 = 19; int Arr2[] = { 34, 48, 19, 61, 24 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(2, Arg3, minimalRange(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ConnectTheCities ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

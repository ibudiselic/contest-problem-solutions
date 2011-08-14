#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[31][31][1024]; // [i][j][k] is it possible to cover exactly k length with j pieces with index atleast i
vector<int> P;

int ok(int start, int cnt, int L) {
	int &ret = dp[start][cnt][L];
	if (ret != -1) return ret;
	if (cnt == 0) return ret = (L==0);
	if (L == 0) return ret = (cnt==0);
	if (start == n) return ret = (cnt==0 && L==0);
	if (ok(start+1, cnt, L)) return ret = 1;
	if (P[start]<=L && ok(start+1, cnt-1, L-P[start])) return ret = 1;
	return ret = 0;
}
class PlacingPieces {
	public:
	int optimalPlacement(int L, vector <int> pieces) {
		sort(pieces.begin(), pieces.end());
		while (pieces.size()>0 && pieces.back()>L)
			pieces.pop_back();
		P = pieces;
		n = pieces.size();
		if (n == 0)
			return 0;
		vector<int> sum = pieces;
		for (int i=1; i<n; ++i)
			sum[i] += sum[i-1];
		pieces.push_back(L+1);

		memset(dp, 0xff, sizeof dp);
		int sol = 1234567890;
		for (int small=0; small<=n; ++small) {
			const int r = L - (small==0 ? 0:sum[small-1]);
			if (r >= 0)
				for (int large=0; large<=n-small; ++large) {
					const int l = max(0, r - (small+large+1)*pieces[small]+1);
					for (int rem=l; rem<=r; ++rem)
						if (ok(small, large, rem))
							sol = min(sol, small+large);
				}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arr1[] = {1, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 36; int Arr1[] = {1, 1, 5, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 37; int Arr1[] = {1, 1, 5, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 18; int Arr1[] = {2, 2, 2, 9, 9, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 703; int Arr1[] = {73, 76, 90, 42, 84, 13, 57, 88, 80, 45, 80, 1, 78, 41, 73, 40, 97, 42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(5, Arg2, optimalPlacement(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PlacingPieces ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

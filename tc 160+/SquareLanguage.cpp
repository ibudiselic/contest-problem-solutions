#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int B[4][2];
long long dp[2][5][101][2][5];
long long go(bool right, int lastTaken, int cntLast, bool fromLeft, int next) {
	if (next == 4)
		return right ? 1 : go(1, lastTaken, cntLast, fromLeft, 0);

	if (dp[right][lastTaken][cntLast][fromLeft][next] != -1)
		return dp[right][lastTaken][cntLast][fromLeft][next];

	if (!right) {
		dp[0][lastTaken][cntLast][fromLeft][next] = 0;

		for (int cnt=B[next][0]; cnt<=B[next][1]; ++cnt)
			dp[0][lastTaken][cntLast][fromLeft][next] += go(0, (cnt>0 ? next:lastTaken), (cnt>0 ? cnt:cntLast), (cnt>0 || fromLeft), next+1);
	} else {
		dp[1][lastTaken][cntLast][fromLeft][next] = 0;
		if (!fromLeft && lastTaken==4)
			return 0; // empty left not allowed

		if (lastTaken<next && fromLeft) // could have taken some of next on the left but didn't => can't take here either
			return B[next][0]==0 ? go(1, lastTaken, cntLast, fromLeft, next+1) : 0;

		if (lastTaken != next) { // take as many as you like
			for (int cnt=B[next][0]; cnt<=B[next][1]; ++cnt)
				dp[1][lastTaken][cntLast][fromLeft][next] += go(1, (cnt>0 ? next:lastTaken), (cnt>0 ? cnt:cntLast), (cnt==0 && fromLeft), next+1);
		} else {
			if (cntLast < B[next][1]) { // if left hasn't maxed out, take only the min amount
				dp[1][lastTaken][cntLast][fromLeft][next] = go(1, (B[next][0]>0 ? next:lastTaken), (B[next][0]>0 ? B[next][0]:cntLast), (B[next][0]>0 ? 0:fromLeft), next+1);
			} else { // otherwise take as many as you like
				for (int cnt=B[next][0]; cnt<=B[next][1]; ++cnt)
					dp[1][lastTaken][cntLast][fromLeft][next] += go(1, (cnt>0 ? next:lastTaken), (cnt>0 ? cnt:cntLast), (cnt==0 && fromLeft), next+1);
			}
		}
	}

	return dp[right][lastTaken][cntLast][fromLeft][next];
}
void parse(const vector<int> &s, int *v) {
	v[0] = s[0];
	v[1] = s[1];
}
class SquareLanguage {
	public:
	long long howMany(vector <int> abounds, vector <int> bbounds, vector <int> cbounds, vector <int> dbounds) {
		parse(abounds, B[0]);
		parse(bbounds, B[1]);
		parse(cbounds, B[2]);
		parse(dbounds, B[3]);

		memset(dp, 0xff, sizeof dp);

		return go(0, 4, 0, 0, 0) + (B[0][0]+B[1][0]+B[2][0]+B[3][0] == 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 201LL; verify_case(0, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 12LL; verify_case(1, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,90}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,80}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {30,70}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 410390615610000LL; verify_case(2, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,47}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1641220888605LL; verify_case(3, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SquareLanguage ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

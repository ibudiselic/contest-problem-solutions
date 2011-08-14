#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long choose[51][6];
long long C(int n, int k) {
	if (n<k || n<0) return 0;
	if (n==0 || k==0) return 1;
	if (choose[n][k] != -1)
		return choose[n][k];

	return (choose[n][k] = C(n-1, k-1) + C(n-1, k));
}
long long F[6];
int fact(int n) {
	if (F[n] != -1)
		return F[n];

	int ret = 1;
	for (int x=2; x<=n; ++x)
		ret *= x;

	return (F[n] = ret);
}

long long sol;
vector<int> v;
int cntA, cntB, cntC, D;
long long dp[51][6];

long long makeB(int pos, int B) {
	if (B == 0)
		return 1;
	if (pos == cntA)
		return 0;
	if (dp[pos][B] != -1)
		return dp[pos][B];

	long long ret = makeB(pos+1, B);
	for (int i=1; i<=B; ++i) {
		long long c = C(v[pos+1]-v[pos]-1 - 2*D, i);
		if (c == 0)
			break;
		ret += c*C(B, i)*fact(i)*makeB(pos+1, B-i);
	}

	return (dp[pos][B] = ret);
}
void makeA(int pos, int A) {
	if (A == cntA) {
		memset(dp, 0xff, sizeof dp);
		sol += makeB(0, cntB);
		return;
	}
	if (pos == cntC)
		return;

	makeA(pos+1, A);
	v[A] = pos;
	makeA(pos+1, A+1);
}
class RoundTable {
	public:
	long long arrangements(int countA, int countB, int chairs, int minDistance) {
		memset(choose, 0xff, sizeof choose);
		memset(F, 0xff, sizeof F);
		sol = 0;
		v.assign(countA+1, -1);
		v[0] = 0;
		v[countA] = chairs;

		cntA = countA;
		cntB = countB;
		cntC = chairs;
		D = minDistance-1;

		makeA(1, 1);

		return sol*chairs*fact(cntA-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 1; long long Arg4 = 90LL; verify_case(0, Arg4, arrangements(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 2; long long Arg4 = 70LL; verify_case(1, Arg4, arrangements(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 7; int Arg3 = 3; long long Arg4 = 14LL; verify_case(2, Arg4, arrangements(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 7; int Arg3 = 1; long long Arg4 = 0LL; verify_case(3, Arg4, arrangements(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 11; int Arg3 = 3; long long Arg4 = 0LL; verify_case(4, Arg4, arrangements(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 3; int Arg3 = 1; long long Arg4 = 6LL; verify_case(5, Arg4, arrangements(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 20; int Arg3 = 4; long long Arg4 = 180000LL; verify_case(6, Arg4, arrangements(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RoundTable ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

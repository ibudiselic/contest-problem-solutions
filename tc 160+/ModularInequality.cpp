#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> A;
vector<int> cnt;
int bs1(int cntX, long long lo, long long hi, long long P) {
	long long left = lo;

	++hi;
	while (lo < hi) {
		long long mid = lo + (hi-lo)/2;
		if (cntX*mid <= P)
			lo = mid+1;
		else
			hi = mid;
	}
	return lo-left;
}
int bs2(int cntX, long long lo, long long hi, long long P) {
	long long right = hi;

	--lo;
	while (lo < hi) {
		long long mid = lo + (hi-lo+1)/2;
		if (cntX*mid <= P)
			hi = mid-1;
		else
			lo = mid;
	}
	return right-lo;
}
int go(int n, int cntX, long long P, long long left, long long right) {
	if (n == (int)A.size())
		return (cntX>=0 ? bs1(cntX, left, right, P) : bs2(cntX, left, right, P));

	long long cur = P;
	long long curX = cntX;
	for (int i=n; i<(int)A.size(); ++i) {
		cur -= (long long)cnt[i]*A[i];
		curX -= cnt[i];
	}

	return (curX>=0 ? bs1(curX, left, A[n], cur):bs2(curX, left, A[n], cur)) + go(n+1, cntX+cnt[n], P+(long long)cnt[n]*A[n], A[n]+1, right);
}
class ModularInequality {
	public:
	int countSolutions(vector <int> A_, int P) {
		A = A_;
		sort(A.begin(), A.end());
		cnt.clear();
		for (int i=0; i<(int)A.size(); ++i) {
			int j = i;
			cnt.push_back(0);
			while (j<(int)A.size() && A[i]==A[j]) {
				++cnt.back();
				++j;
			}
			i = j-1;
		}
		A.erase(unique(A.begin(), A.end()), A.end());

		return go(0, 0, P, -60000000000ll, 60000000000ll);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 5; verify_case(0, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 30, 15, -1, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; int Arg2 = 7; verify_case(1, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 2, 3, -5, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; int Arg2 = 0; verify_case(2, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-693}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1265; int Arg2 = 2531; verify_case(3, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {965, -938, -396, -142, 926, 31, -720}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6495; int Arg2 = 1781; verify_case(4, Arg2, countSolutions(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ModularInequality ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

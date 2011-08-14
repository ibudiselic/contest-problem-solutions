#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> a;
long long absolute(long long x) {
	if (x < 0)
		return -x;
	else return x;
}
class Equidistance {
	public:
	long long eval(int fix, long long d) {
		long long ret = 0;
		for (int i=0; i<(int)a.size(); ++i)
			if (i != fix)
				ret += absolute(a[fix] + (i-fix)*d - a[i]);
		return ret;
	}
	long long solve(int fix) {
		long long l = 1;
		long long h = 4000000100LL;

		while (h-l > 20) {
			long long lmid = (2*l+h)/3;
			long long hmid = (l+2*h)/3;

			if (eval(fix, lmid) < eval(fix, hmid))
				h = hmid;
			else
				l = lmid;
		}
		long long ret = eval(fix, l);
		for (long long i=l+1; i<=h; ++i)
			ret = min(ret, eval(fix, i));

		return ret;
	}
	long long minimumEffort(vector <int> initial) {
		a = initial;

		sort(a.begin(), a.end());

		long long sol = 1LL<<62;
		for (int i=0; i<(int)a.size(); ++i)
			sol = min(sol, solve(i));


		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 4, 7, 10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(0, Arg1, minimumEffort(Arg0)); }
	void test_case_1() { int Arr0[] = { 4, 3, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, minimumEffort(Arg0)); }
	void test_case_2() { int Arr0[] = { 3, 3, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(2, Arg1, minimumEffort(Arg0)); }
	void test_case_3() { int Arr0[] = { -2000000000, 2000000000 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, minimumEffort(Arg0)); }
	void test_case_4() { int Arr0[] = { 2, 3, 4, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(4, Arg1, minimumEffort(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Equidistance ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

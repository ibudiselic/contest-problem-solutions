#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool ok[10];
bool isOk(int x) {
	if (x == 0)
		return ok[0];
	while (x > 0) {
		if (!ok[x%10])
			return false;
		x /= 10;
	}
	return true;
}
int dCnt(int x) {
	if (x == 0)
		return 1;
	int cnt = 0;
	while (x > 0) {
		++cnt;
		x /= 10;
	}
	return cnt;
}
class BrokenButtons {
	public:
	int minPresses(int page, vector <int> broken) {
		int sol = abs(page - 100);
		memset(ok, 1, sizeof ok);
		for (int i=0; i<(int)broken.size(); ++i)
			ok[broken[i]] = 0;

		int x = 0;
		for (x=page; x>=0 && page-x<sol; --x)
			if (isOk(x))
				break;
		if (x>=0 && isOk(x))
			sol = min(sol, page-x + dCnt(x));

		for (x=page+1; x-page<sol; ++x)
			if (isOk(x))
				break;
		if (isOk(x))
			sol = min(sol, x-page + dCnt(x));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5457; int Arr1[] = { 6, 7, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = { 1, 0, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 14124; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 80000; int Arr1[] = { 8, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2228; verify_case(4, Arg2, minPresses(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BrokenButtons ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

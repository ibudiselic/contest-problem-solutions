#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

long long fact(long long x) {
	long long ret = 1;
	while (x) {
		ret *= x;
		--x;
	}
	return ret;
}
vector<int> v;
long long calcPal() {
	vector<int> halfs(v.size(), 0);

	for (int i=0; i<(int)v.size(); ++i)
		if (v[i] & 1)
			return 0;
		else
			halfs[i] = v[i]/2;

	long long ret = fact(accumulate(halfs.begin(), halfs.end(), 0));

	for (int i=0; i<(int)v.size(); ++i)
		ret /= fact(halfs[i]);

	return ret;
}
class TinSoldiers {
	public:
	int lineUps(vector <int> rankCounts) {
		v = rankCounts;
		int sum = accumulate(v.begin(), v.end(), 0);
		long long x = fact(sum);

		for (int i=0; i<(int)v.size(); ++i)
			x /= fact(v[i]);

		long long cntPal = 0;
		if ((sum & 1) == 0) {
			cntPal = calcPal();
		} else {
			for (int i=0; i<(int)v.size(); ++i) {
				--v[i];
				cntPal += calcPal();
				++v[i];
			}
		}

		return (x-cntPal)/2 + cntPal;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, lineUps(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 48; verify_case(1, Arg1, lineUps(Arg0)); }
	void test_case_2() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, lineUps(Arg0)); }
	void test_case_3() { int Arr0[] = {5, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, lineUps(Arg0)); }
	void test_case_4() { int Arr0[] = {4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 66; verify_case(4, Arg1, lineUps(Arg0)); }
	void test_case_5() { int Arr0[] = {4, 2, 2, 5, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 643245120; verify_case(5, Arg1, lineUps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TinSoldiers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

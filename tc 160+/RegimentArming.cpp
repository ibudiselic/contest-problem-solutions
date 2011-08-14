#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class RegimentArming {
	public:
	int chooseGuns(vector <int> counts, vector <int> powers, int N) {
		int total = 0;
		for (int i=0; i<(int)counts.size(); ++i)
			total += counts[i];

		if (N == total) {
			int ret = 0;
			for (int i=0; i<(int)counts.size(); ++i)
				ret += counts[i]*powers[i];
			return ret;
		}

		int sol = 0;

		int cur = 0;
		int l = 0;
		int lCnt = counts[0];

		int r = 0;
		while (counts[r] <= N) {
			cur += counts[r]*powers[r];
			N -= counts[r++];
		}
		int rCnt = counts[r] - N;
		cur += N * powers[r];

		while (true) {
			sol = max(sol, cur);

			if (r == (int)counts.size())
				return sol;

			cur += powers[r] - powers[l];

			if (--lCnt == 0)
				lCnt = counts[++l];
			if (--rCnt == 0)
				rCnt = counts[++r];
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 37, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 65; verify_case(0, Arg3, chooseGuns(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5, 37, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 96; verify_case(1, Arg3, chooseGuns(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5, 37, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 46; int Arg3 = 215; verify_case(2, Arg3, chooseGuns(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {761,263,698,811,201,493,385,621,626,171}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {204,464,251,438,241,351,181,915,473,589}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2515; int Arg3 = 1264085; verify_case(3, Arg3, chooseGuns(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RegimentArming ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

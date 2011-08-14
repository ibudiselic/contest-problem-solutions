#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int best[51][51];
int best2[51][51];
vector<int> V;

int me(int, int);

int you(int l, int r) {
	if (l == r)
		return 0;
	int &ret = best2[l][r];
	if (ret != -1)
		return ret;
	ret = 1234568790;
	for (int i=l; i<r; ++i)
		ret = min(ret, me(l, i) + me(i+1, r));

	return ret;
}

int me(int l, int r) {
	if (l == r)
		return 0;
	int &ret = best[l][r];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i=l; i<r; ++i)
		ret = max(ret, V[i] + you(l, i) + you(i+1, r));

	return ret;
}

class PickGuitars {
	public:
	int maxValue(vector <int> g) {
		int sol = 0;
		for (int i=0; i<(int)g.size(); ++i) {
			memset(best, 0xff, sizeof best);
			memset(best2, 0xff, sizeof best2);
			V.clear();
			if (i+1 < (int)g.size())
				copy(g.begin()+i+1, g.end(), back_inserter(V));
			copy(g.begin(), g.begin()+i, back_inserter(V));
			sol = max(sol, g[i] + you(0, V.size()));
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,5,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, maxValue(Arg0)); }
	void test_case_1() { int Arr0[] = {4,8,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, maxValue(Arg0)); }
	void test_case_2() { int Arr0[] = {2,1,4,1,2,1,8,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, maxValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PickGuitars ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

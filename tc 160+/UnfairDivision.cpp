#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class UnfairDivision {
	public:
	int albertsShare(vector <int> assets) {
		assets.insert(assets.begin(), 0);
		int n = assets.size();
		for (int i=1; i<n; ++i)
			assets[i] += assets[i-1];
		int sol = 0;
		for (int i=1; i<n-1; ++i) {
			int best = 0;
			int albert = 0;
			for (int j=1; j<n-1; ++j)
				if (j < i) {
					vector<int> cur(3);
					cur[0] = assets[j]-assets[0];
					cur[1] = assets[i]-assets[j];
					cur[2] = assets[n-1]-assets[i];
					sort(cur.begin(), cur.end());
					if (cur[1] > best) {
						best = cur[1];
						albert = cur[0];
					} else if (cur[1] == best) {
						albert = min(albert, cur[0]);
					}
				} else if (j > i) {
					vector<int> cur(3);
					cur[0] = assets[i]-assets[0];
					cur[1] = assets[j]-assets[i];
					cur[2] = assets[n-1]-assets[j];
					sort(cur.begin(), cur.end());
					if (cur[1] > best) {
						best = cur[1];
						albert = cur[0];
					} else if (cur[1] == best) {
						albert = min(albert, cur[0]);
					}
				}
			sol = max(sol, albert);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 50, 90, 10, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(0, Arg1, albertsShare(Arg0)); }
	void test_case_1() { int Arr0[] = { 5, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, albertsShare(Arg0)); }
	void test_case_2() { int Arr0[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, albertsShare(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, albertsShare(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UnfairDivision ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

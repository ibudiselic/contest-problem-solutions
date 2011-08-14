#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <cmath>

using namespace std;

vector< pair<int, int> > B, O;

bool doneBomb[100];
bool doneObj[100];
double dSqr;

inline int sqr(int x) { return x*x; }
inline double distSqr(const pair<int, int> &a, const pair<int, int> &b) {
	return sqr(a.first-b.first) + sqr(a.second-b.second);
}
int dfs(int b) {
	doneBomb[b] = true;
	int ret = 0;

	for (int i=0; i<(int)O.size(); ++i)
		if (!doneObj[i] && distSqr(B[b], O[i]) <= dSqr) {
			doneObj[i] = true;
			++ret;
		}

	for (int i=0; i<(int)B.size(); ++i)
		if (!doneBomb[i] && distSqr(B[b], B[i]) <= dSqr)
			ret += dfs(i);

	return ret;
}

int calc(double dSqr_) {
	int sol = 1234567890;
	dSqr = dSqr_;
	for (int i=0; i<(int)B.size(); ++i) {
		memset(doneBomb, 0, sizeof doneBomb);
		memset(doneObj, 0, sizeof doneObj);
		sol = min(sol, dfs(i));
	}

	return sol;
}
class SecurityBunker {
	public:
	double chooseBomb(vector <string> field) {
		B.clear();
		O.clear();
		for (int i=0; i<(int)field.size(); ++i)
			for (int j=0; j<(int)field[i].size(); ++j)
				if (field[i][j] == '*')
					B.push_back(make_pair(i, j));
				else if (field[i][j] == '?')
					O.push_back(make_pair(i, j));

		double lo = 1;
		double hi = 71*71;

		for (int t=0; t<100; ++t) {
			double mid = (lo+hi)/2;
			if (calc(mid) < (int)O.size())
				lo = mid;
			else
				hi = mid;
		}

		return sqrt((lo+hi)/2);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"*.*",
 ".?.",
 "*.*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.4142135623730951; verify_case(0, Arg1, chooseBomb(Arg0)); }
	void test_case_1() { string Arr0[] = {"*****",
 ".?.?.",
 "..?..",
 ".?.?.",
 "*****"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(1, Arg1, chooseBomb(Arg0)); }
	void test_case_2() { string Arr0[] = {"*****",
 "....*",
 "....*",
 ".?..*",
 "....*",
 "*...*",
 "*****"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.23606797749979; verify_case(2, Arg1, chooseBomb(Arg0)); }
	void test_case_3() { string Arr0[] = {"*.*.*.*",
 ".?.?.?."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.0; verify_case(3, Arg1, chooseBomb(Arg0)); }
	void test_case_4() { string Arr0[] = {"?*..*?....?",
 "...........",
 "....*......",
 "...?.......",
 ".*....**?..",
 "*......?...",
 ".......*...",
 ".......?.*.",
 "..*.......*",
 "?........?.",
 "......?*?.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.0; verify_case(4, Arg1, chooseBomb(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SecurityBunker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

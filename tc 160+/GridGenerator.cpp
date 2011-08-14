#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class GridGenerator {
	public:
	int generate(vector <int> row, vector <int> col) {
		int m = col.size();
		int n = row.size();

		vector< vector<int> > g(m, vector<int> (n, 0));
		for (int i=0; i<m; ++i)
			g[i][0] = col[i];
		for (int j=0; j<n; ++j)
			g[0][j] = row[j];

		for (int i=1; i<m; ++i)
			for (int j=1; j<n; ++j)
				g[i][j] = g[i-1][j] + g[i][j-1] + g[i-1][j-1];

		return g[m-1][n-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0,3,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,1,0,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 579; verify_case(0, Arg2, generate(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {9,9,9,9,9,9,9,9,9,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,9,9,9,9,9,9,9,9,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 13163067; verify_case(1, Arg2, generate(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, generate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GridGenerator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

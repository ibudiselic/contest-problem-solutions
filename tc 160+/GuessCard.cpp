#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

class GuessCard {
	public:
	int whichRow(int n, int m, vector <int> columns) {
		vector<int> order;

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				order.push_back(i*n + j);
		set<int> S(order.begin(), order.end());

		vector< vector<int> > v(m, vector<int>(n, 0));
		for (int t=0; t<(int)columns.size(); ++t) {
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j)
					v[i][j] = order[i*n+j];

			set<int> next;
			for (int i=0; i<m; ++i)
				if (S.count(v[i][columns[t]]))
					next.insert(v[i][columns[t]]);

			S = next;
			for (int j=0; j<n; ++j)
				for (int i=0; i<m; ++i)
					order[j*m+i] = v[i][j];
		}

		if (S.size() != 1)
			return -1;

		for (int i=0; i<m; ++i)
			if (v[i][columns.back()] == *S.begin())
				return i;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; int Arr2[] = {2, 1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, whichRow(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 7; int Arr2[] = {2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, whichRow(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 10; int Arr2[] = {0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(2, Arg3, whichRow(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 1; int Arr2[] = {4, 4, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, whichRow(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GuessCard ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

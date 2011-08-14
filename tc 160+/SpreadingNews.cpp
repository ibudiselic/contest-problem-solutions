#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;

class SpreadingNews {
	public:
	int minTime(vector <int> supervisors) {
		vector< vector<int> > tree(supervisors.size(), vector<int>());
		for (int i=1; i<(int)supervisors.size(); ++i)
			tree[supervisors[i]].push_back(i);

		vector<int> t(supervisors.size(), 0);
		for (int i=(int)supervisors.size()-1; i>=0; --i) {
			vector<int> v;
			t[i] = 1;
			for (int j=0; j<(int)tree[i].size(); ++j)
				v.push_back(t[tree[i][j]]);
			sort(v.begin(), v.end(), greater<int>());
			for (int j=0; j<(int)v.size(); ++j)
				t[i] = max(t[i], v[j]+j+1);
		}

		return t[0]-1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, 0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 12, 13, 14, 16, 16, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, minTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SpreadingNews ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

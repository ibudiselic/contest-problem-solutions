#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MatrixTransforming {
	public:
	int minPushes(vector <string> a, vector <string> b) {
		int cnt = 0;
		for (int i=0; i<(int)a.size()-2; ++i)
			for (int j=0; j<(int)a[0].size()-2; ++j)
				if (a[i][j] != b[i][j]) {
					++cnt;
					for (int r=i; r<i+3; ++r)
						for (int c=j; c<j+3; ++c)
							a[r][c] = (a[r][c]=='0' ? '1':'0');
				}

		for (int i=0; i<(int)a.size(); ++i)
			for (int j=0; j<(int)a[0].size(); ++j)
				if (a[i][j] != b[i][j])
					return -1;

		return cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111","111","111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000","000","000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minPushes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, minPushes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"001","100","100","000","011","010","100","100","010",
"010","010","110","101","101","000","110","000","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"001","100","011","000","100","010","011","100","101",
"101","010","001","010","010","111","110","111","001"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, minPushes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {
"0000",
"0010",
"0000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {
"1001",
"1011",
"1001"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minPushes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MatrixTransforming ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int best[15][15]; /* folder, worker */
int t[15][15];
const int INF = 1000000;
class FairWorkload {
	public:
	int getMostWork(vector <int> folders, int workers) {
		int n = folders.size();
		for (int i=0; i<(int)folders.size(); ++i)
			t[i][i] = folders[i];
		for (int i=0; i<(int)folders.size()-1; ++i)
			for (int j=i+1; j<(int)folders.size(); ++j)
				t[i][j] = (t[i][j-1]>folders[j] ? t[i][j-1]:folders[j]);
		vector<int> sum(n, 0);
		sum[0] = folders[0];
		for (int i=1; i<n; ++i)
			sum[i] = sum[i-1] + folders[i];

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				best[i][j] = INF;
		for (int i=0; i<workers; ++i)
			best[i][i] = t[0][i];
		for (int i=0; i<n; ++i)
			best[i][0] = sum[i];

		for (int i=1; i<n; ++i)
			for (int j=1; j<=i && j<workers; ++j)
				for (int k=j-1; k<i; ++k)
					best[i][j] <?= max(best[k][j-1], sum[i]-sum[k]);

		return best[n-1][workers-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 170; verify_case(0, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 110; verify_case(1, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1785; verify_case(2, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1000; verify_case(3, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 50, 50, 50, 50, 50, 50, 50 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 200; verify_case(4, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 100; verify_case(5, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = { 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 950; verify_case(6, Arg2, getMostWork(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FairWorkload ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool knows[100][100];
class Party {
	public:
	double averageNames(int n, vector <int> personA, vector <int> personB) {
		memset(knows, 0, sizeof knows);
		for (int i=0; i<(int)personA.size(); ++i) {
			int a = personA[i];
			int b = personB[i];
			knows[a][b] = knows[b][a] = 1;
			for (int k=0; k<n; ++k) {
				if (knows[a][k])
					knows[b][k] = 1;
				if (knows[b][k])
					knows[a][k] = 1;
			}
		}

		int sum = 0;
		for (int i=0; i<n; ++i) {
			int cnt = 0;
			for (int j=0; j<n; ++j)
				if (j != i)
					cnt += knows[i][j];
			sum += cnt;
		}

		return double(sum)/n;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 2.25; verify_case(0, Arg3, averageNames(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {0,0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,3,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 4.0; verify_case(1, Arg3, averageNames(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arr1[] = {52,19,52,19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {19,52,19,52}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.02; verify_case(2, Arg3, averageNames(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 25; int Arr1[] = {14, 14, 16, 4, 14, 16, 2, 16, 8, 15, 17, 17, 3, 3, 19, 17, 20, 4, 24, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {16, 2, 23, 16, 11, 8, 5, 19, 15, 20, 19, 18, 14, 12, 22, 9, 0, 7, 23, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 4.44; verify_case(3, Arg3, averageNames(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Party ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

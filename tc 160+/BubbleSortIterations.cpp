#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

class BubbleSortIterations {
	public:
	int numIterations(vector <int> X, vector <int> Y, int L0, int M, int n) {
		vector<pair<long long, int> > L(n);
		L[0] = make_pair(L0, 0);
		for (int i=1; i<n; ++i)
    		L[i] = make_pair((L[i-1].first * X[i % X.size()] + Y[i % Y.size()]) % M, i);

		sort(L.begin(), L.end());
		int sol = 0;
		for (int i=0; i<(int)L.size(); ++i)
			if (L[i].second > i)
				sol = max(sol, L[i].second-i);

		return sol+1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 1, 5, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 100; int Arg4 = 5; int Arg5 = 3; verify_case(0, Arg5, numIterations(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 5, 7, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 100; int Arg4 = 5; int Arg5 = 1; verify_case(1, Arg5, numIterations(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {999998}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {500000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 500000; int Arg3 = 1000000; int Arg4 = 100; int Arg5 = 1; verify_case(2, Arg5, numIterations(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {234, 56, 567, 3147, 23464, 57128, 1254, 45, 23247, 1347, 145, 123}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3413, 171, 58, 569, 40, 467, 2456, 246, 2684, 5, 61, 8, 258, 24524, 2, 58, 245, 674}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 99991; int Arg4 = 100000; int Arg5 = 99228; verify_case(3, Arg5, numIterations(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BubbleSortIterations ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

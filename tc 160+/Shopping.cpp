#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

class Shopping {
	public:
	int minNumber(int x, vector <int> v) {
		sort(v.begin(), v.end());
		if (v[0] != 1)
			return -1;

		int sum = 0;
		int sol = 0;
		int i = 0;
		while (sum < x) {
			for (i=(int)v.size()-1; v[i]>sum+1; --i)
				;
			sum += v[i];
			++sol;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arr1[] = {1, 2, 5, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arr1[] = {2, 4, 1, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {2,4,6,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 600; int Arr1[] = {1,2,3,10,11,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; verify_case(3, Arg2, minNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Shopping ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

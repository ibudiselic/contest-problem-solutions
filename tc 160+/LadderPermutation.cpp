#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool can_cont(int n, int m, int k) {
	return m+k-1<=n && n<=m*k;
}
class LadderPermutation {
	public:
	vector <int> createLadder(int n, int m, int k) {
		if (!can_cont(n, m, k))
			return vector<int>();

		vector<int> sol(n);
		for (int i=0; i<n; ++i)
			sol[i] = i+1;

		int block_sz = 1;
		for (int l=0; l<n; ++l) {
			if (m == 1) {
				reverse(sol.begin()+l, sol.end());
				break;
			}
			for (int r=l+1; r<=n && (r-l)<=k; ++r)
				if (can_cont(n-r, m-1, k)) {
					reverse(sol.begin()+l, sol.begin()+r);
					--m;
					l = r-1;
					break;
				}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; int Arr3[] = {2, 1, 4, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, createLadder(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arr3[] = {1, 3, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, createLadder(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, createLadder(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 2; int Arr3[] = {2, 1, 4, 3, 6, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, createLadder(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 3; int Arr3[] = {3, 2, 1, 6, 5, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, createLadder(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 4; int Arr3[] = {1, 2, 3, 7, 6, 5, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, createLadder(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LadderPermutation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BinarySearchable {
	public:
	int howMany(vector <int> sequence) {
		vector<bool> ok(sequence.size(), true);
		int n = sequence.size();
		int t = sequence[0];

		for (int i=1; i<n; ++i) {
			if (t > sequence[i])
				ok[i] = false;
			t = max(t, sequence[i]);
		}
		t = sequence[n-1];
		for (int i=n-2; i>=0; --i) {
			if (t < sequence[i])
				ok[i] = false;
			t = min(t, sequence[i]);
		}

		int sol = 0;
		for (int i=0; i<n; ++i)
			sol += ok[i];
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 3, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arr0[] = { 3, 2, 1, 10, 23, 22, 21 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arr0[] = { 1, 5, 7, 11, 12, 18 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arr0[] = { 5, 4, 3, 2, 1, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { int Arr0[] = { 1, 3, 2, 4, 5, 7, 6, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BinarySearchable ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

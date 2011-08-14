#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int in[1<<20], out[1<<20];

class ScheduleResources {
	public:
	int schedule(vector <int> A, vector <int> B) {
		int n = A.size();
		fill(out, out+(1<<n), 1234567890);

		in[0] = 0;
		out[0] = 0;
		for (unsigned m=0; m<(1u<<n); ++m)
			for (int i=0; i<n; ++i)
				if (m & (1u<<i)) {
					in[m] = in[m ^ (1u<<i)] + A[i];
					out[m] = min(out[m], max(out[m ^ (1u<<i)], in[m]) + B[i]);
				}

		return out[(1u<<n)-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,6,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,7,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; verify_case(0, Arg2, schedule(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {8,1,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,6,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(1, Arg2, schedule(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 21; verify_case(2, Arg2, schedule(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(3, Arg2, schedule(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ScheduleResources ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

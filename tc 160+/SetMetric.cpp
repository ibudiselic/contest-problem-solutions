#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int bc[1<<20];
class SetMetric {
	public:
	int nearness(vector <int> target, vector <int> candidate) {
		sort(target.begin(), target.end());
		sort(candidate.begin(), candidate.end());

		bc[0] = 0;
		for (int m=1; m<(1<<20); ++m)
			bc[m] = bc[m>>1] + (m&1);

		int sol = 1234567890;
		for (int m=0; m<(1<<(int)candidate.size()); ++m)
			if (bc[m] == (int)target.size()) {
				int j = 0;
				int cur = 0;
				for (int i=0; i<(int)candidate.size(); ++i)
					if (m & (1<<i)) {
						cur += abs(candidate[i] - target[j]);
						++j;
					}
				sol = min(sol, cur);
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,9,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,1,2,3,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, nearness(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,-1000,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, nearness(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000,-1000,0,5,289,-40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30,821,-777,-52,91,444,-134,85}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 679; verify_case(2, Arg2, nearness(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SetMetric ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

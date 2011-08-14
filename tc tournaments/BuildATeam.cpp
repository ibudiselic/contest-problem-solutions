#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class BuildATeam {
	public:
	int maximalStrength(vector <int> skills, int teams) {
		vector<int> str(teams, 0);

		sort(skills.begin(), skills.end());

		for (int r=0; skills.size()>0; ++r)
			if (r & 1)
				for (int i=teams-1; i>=0 && skills.size()>0; --i) {
					str[i] += skills.back();
					skills.pop_back();
				}
			else
				for (int i=0; i<teams && skills.size()>0; ++i) {
					str[i] += skills.back();
					skills.pop_back();
				}

		return *max_element(str.begin(), str.end());
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 9, 7, 3, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 12; verify_case(0, Arg2, maximalStrength(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 21; verify_case(1, Arg2, maximalStrength(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 10, 10, 9, 8, 8, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 31; verify_case(2, Arg2, maximalStrength(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10, 8, 10, 1, 10, 9, 3, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 31; verify_case(3, Arg2, maximalStrength(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {98, 19, 11, 11, 11, 11, 23, 55, 1, 4, 3, 4, 6, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 99; verify_case(4, Arg2, maximalStrength(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BuildATeam ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

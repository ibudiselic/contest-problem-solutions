#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CandyBoxes {
	public:
	int remainingCandies(vector <int> candies) {
		while (1) {
			int m = *min_element(candies.begin(), candies.end());

			int Mpos = max_element(candies.begin(), candies.end()) - candies.begin();

			if (candies[Mpos] == m)
				break;

			candies[Mpos] -= m;
		}

		return candies[0];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, remainingCandies(Arg0)); }
	void test_case_1() { int Arr0[] = {7, 21, 14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, remainingCandies(Arg0)); }
	void test_case_2() { int Arr0[] = {3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, remainingCandies(Arg0)); }
	void test_case_3() { int Arr0[] = {366, 549, 915, 183, 549, 549, 183, 366, 915, 549, 915, 366}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 183; verify_case(3, Arg1, remainingCandies(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CandyBoxes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

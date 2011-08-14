#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BasketsWithApples {
	public:
	int removeExcess(vector <int> apples) {
		sort(apples.begin(), apples.end());
		apples.push_back(0);

		int best = 0;
		for (int i=0; i<(int)apples.size()-1; ++i) {
			if (((int)apples.size()-1-i)*apples[i] > best)
				best = ((int)apples.size()-1-i)*apples[i];
		}
		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, removeExcess(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 0, 30, 14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(1, Arg1, removeExcess(Arg0)); }
	void test_case_2() { int Arr0[] = {51, 8, 38, 49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 114; verify_case(2, Arg1, removeExcess(Arg0)); }
	void test_case_3() { int Arr0[] = {24, 92, 38, 0, 79, 45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 158; verify_case(3, Arg1, removeExcess(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BasketsWithApples ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

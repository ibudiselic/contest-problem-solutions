#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;

vector<int> C;
int gap[50][50];
class CardStraights {
	public:
	int longestStraight(vector <int> cards) {
		C = cards;
		sort(C.begin(), C.end(), greater<int>());
		int jokers = 0;
		for (int i=(int)C.size()-1; C[i]==0 && i>=0; ++jokers, C.pop_back(), --i)
			;

		C.erase(unique(C.begin(), C.end()), C.end());
		reverse(C.begin(), C.end());

		if (C.size() == 0)
			return jokers;

		memset(gap, 0, sizeof gap);
		for (int l=1; l<(int)C.size(); ++l)
			for (int i=0; i+l<(int)C.size(); ++i)
				gap[i][i+l] = gap[i][i+l-1] + (C[i+l]-C[i+l-1]-1);

		int sol = 0;
		for (int i=0; i<(int)C.size(); ++i)
			for (int j=i; j<(int)C.size(); ++j) {
				int left = jokers-gap[i][j];
				if (left < 0)
					continue;
				if (left == 0) {
					sol = max(sol, C[j]-C[i]+1);
					continue;
				}
				int lfree = C[i]-1;
				int rfree = 1000000-C[j];
				sol = max(sol, C[j]-C[i]+1 + min(left, lfree+rfree));
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,6,5,10,3,0,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, longestStraight(Arg0)); }
	void test_case_1() { int Arr0[] = {100,100,100,101,100,99,97,103}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, longestStraight(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,2,6,8,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, longestStraight(Arg0)); }
	void test_case_3() { int Arr0[] = {1,9,5,7,3,4,0,0,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, longestStraight(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CardStraights ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ScoreRecomposition {
	public:
	int minError(string questions, int score) {
		vector<int> val(questions.size(), 0);
		for (int i=0; i<(int)questions.size(); ++i)
			val[i] = i+1;

		int sol = 1000000000;;
		do {
			int cur = 0;
			for (int i=0; i<(int)questions.size(); ++i)
				cur += (questions[i]=='C')*val[i];
			if (cur != score) continue;
			cur = 0;
			for (int i=0; i<(int)questions.size(); ++i)
				cur = max(cur, abs(i+1 - val[i]));
			sol = min(sol, cur);
		} while (next_permutation(val.begin(), val.end()));
		return sol==1000000000 ? -1 : sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "CCC"; int Arg1 = 5; int Arg2 = -1; verify_case(0, Arg2, minError(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "WCWW"; int Arg1 = 4; int Arg2 = 2; verify_case(1, Arg2, minError(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "CWW"; int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, minError(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CWCC"; int Arg1 = 6; int Arg2 = 2; verify_case(3, Arg2, minError(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "WWCC"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, minError(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "CWCCWWCWCC"; int Arg1 = 55; int Arg2 = -1; verify_case(5, Arg2, minError(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "CWWCWCCWWC"; int Arg1 = 37; int Arg2 = 3; verify_case(6, Arg2, minError(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ScoreRecomposition ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

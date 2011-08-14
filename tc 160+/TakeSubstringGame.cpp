#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int choice[1000001];

class TakeSubstringGame {
	public:
	int winningMove(int n) {
	for (int x=0; x<=n; ++x) {
		if (x < 10) {
			choice[x] = -1;
			continue;
		}

		vector<int> d;
		int t = x;
		while (t > 0) {
			d.push_back(t%10);
			t /= 10;
		}
		int sol = 1234567890;
		for (int i=(int)d.size()-1; i>=0; --i) {
			t = 0;
			for (int j=i; j-(i==(int)d.size()-1)>=0; --j) {
				t = t*10 + d[j];
				if (t > 0) {
					int e = choice[x-t];
					if (e == -1)
						sol = min(sol, t);
				}
			}
		}

		choice[x] = (sol==1234567890 ? -1 : sol);
	}
	return choice[n];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = -1; verify_case(0, Arg1, winningMove(Arg0)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; verify_case(1, Arg1, winningMove(Arg0)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = -1; verify_case(2, Arg1, winningMove(Arg0)); }
	void test_case_3() { int Arg0 = 239; int Arg1 = 9; verify_case(3, Arg1, winningMove(Arg0)); }
	void test_case_4() { int Arg0 = 566; int Arg1 = 66; verify_case(4, Arg1, winningMove(Arg0)); }
	void test_case_5() { int Arg0 = 23900; int Arg1 = -1; verify_case(5, Arg1, winningMove(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TakeSubstringGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

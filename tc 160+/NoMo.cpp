#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class NoMo {
	public:
	int tot;
	void go(int a, int b, int last, int cur, bool add) {
		if (0==a && 0==b) {
			tot += cur;
			return;
		}

		int x = 0;
		if (a > 0) {
			if (add)
				x = last==0 ? 1:-1;
			go(a-1, b, 0, cur+x, true);
		}
		x = 0;
		if (b > 0) {
			if (add)
				x = last==1 ? 1:-1;
			go(a, b-1, 1, cur+x, true);
		}
	}
	double momentum(string game) {
		int n = game.size();

		int na=0, nb=0;
		for (int i=0; i<n; ++i)
			if ('A' == game[i])
				++na;
			else
				++nb;
		tot=0;
		double t = 1.0;
		for (int i=1; i<=min(na, nb); ++i)
			t *= (double)(n-i+1)/i;

		int x = 0;
		for (int i=1; i<n; ++i)
			if (game[i] == game[i-1])
				++x;
			else
				--x;

		go(na, nb, -1, 0, false);
		return x - tot/t;
	}





// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAAAA"; double Arg1 = 0.0; verify_case(0, Arg1, momentum(Arg0)); }
	void test_case_1() { string Arg0 = "AAB"; double Arg1 = 0.6666666666666666; verify_case(1, Arg1, momentum(Arg0)); }
	void test_case_2() { string Arg0 = "AAABBBBB"; double Arg1 = 5.5; verify_case(2, Arg1, momentum(Arg0)); }
	void test_case_3() { string Arg0 = ""; double Arg1 = 0.0; verify_case(3, Arg1, momentum(Arg0)); }
	void test_case_4() { string Arg0 = "ABABABABABABABABABABABABA"; double Arg1 = -23.04; verify_case(4, Arg1, momentum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NoMo ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

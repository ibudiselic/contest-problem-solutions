#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int my_round(double x) {
	if ((int)x != (int)(x+0.5))
		return int(x+1);
	else
		return int(x);
}
class Percents {
	public:
	int minSamples(string percent) {
		int x, y, p;
		char c;
		istringstream is(percent);
		is >> x >> c >> y;
		p = x*100 + y;

		for (int sol=1; sol<=10000; ++sol) {
			int yes = p*sol/10000;
			if (my_round(yes*10000.0/sol) == p)
				return sol;
			yes = (p*sol + 9999)/10000;
			if (my_round(yes*10000.0/sol) == p)
				return sol;
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "25.00%"; int Arg1 = 4; verify_case(0, Arg1, minSamples(Arg0)); }
	void test_case_1() { string Arg0 = "66.67%"; int Arg1 = 3; verify_case(1, Arg1, minSamples(Arg0)); }
	void test_case_2() { string Arg0 = "66.66%"; int Arg1 = 2858; verify_case(2, Arg1, minSamples(Arg0)); }
	void test_case_3() { string Arg0 = "71.43%"; int Arg1 = 7; verify_case(3, Arg1, minSamples(Arg0)); }
	void test_case_4() { string Arg0 = "00.00%"; int Arg1 = 1; verify_case(4, Arg1, minSamples(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Percents ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class JarBox {
	public:
	int numJars(int radius, int woodlength) {
		int sol = 0;

		for (int i=2; 2*i*radius <= woodlength-2*2*radius; ++i) {
			const int cnt = i/2; /* broj elemenata u doljnjem redu */
			const int side = woodlength-2*i*radius-2*2*radius;
			const int redova = (int)((double)side/(2*sqrt(3.0)*radius));

			int t = cnt;
			if (i%2 == 0) /* doljnji red je pun */
				 t += redova/2 * (cnt + cnt-1) + ((redova%2!=0)?(cnt-1):0);
			else
				 t += redova/2 * (cnt + cnt) + ((redova%2!=0)?(cnt):0);

			sol >?= t;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 8; int Arg2 = 1; verify_case(0, Arg2, numJars(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 16; int Arg2 = 3; verify_case(1, Arg2, numJars(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 18; int Arg2 = 4; verify_case(2, Arg2, numJars(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 45; int Arg2 = 32; verify_case(3, Arg2, numJars(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 1269; int Arg2 = 784; verify_case(4, Arg2, numJars(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    JarBox ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

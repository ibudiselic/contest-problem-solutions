#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class WordNumber {
	public:
	string theWord(int alpha, int n) {
		--n;

		int dCnt = 0;
		long long cnt = 1;
		while (true) {
			++dCnt;
			cnt *= alpha;
			if (cnt <= n)
				n -= cnt;
			else
				break;
		}

		string sol;
		while (dCnt--) {
			cnt /= alpha;
			sol += char('a' + n/cnt);
			n %= cnt;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; string Arg2 = "ab"; verify_case(0, Arg2, theWord(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 13; string Arg2 = "aaa"; verify_case(1, Arg2, theWord(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 26; int Arg1 = 2000000000; string Arg2 = "flhomvx"; verify_case(2, Arg2, theWord(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 26; int Arg1 = 456; string Arg2 = "qn"; verify_case(3, Arg2, theWord(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordNumber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

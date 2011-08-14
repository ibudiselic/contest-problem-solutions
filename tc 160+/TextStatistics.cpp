#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

class TextStatistics {
	public:
	double averageLength(string text) {
		int sum = 0;
		int cnt = 0;

		int cur = 0;
		text += ' ';
		for (int i=0; i<(int)text.size(); ++i) {
			if (isalpha(text[i])) {
				++cur;
			} else if (cur > 0) {
				sum += cur;
				++cnt;
				cur = 0;
			}
		}
		return cnt==0 ? 0.0 : double(sum)/cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "This is div2 easy problem."; double Arg1 = 4.0; verify_case(0, Arg1, averageLength(Arg0)); }
	void test_case_1() { string Arg0 = "Hello, world!"; double Arg1 = 5.0; verify_case(1, Arg1, averageLength(Arg0)); }
	void test_case_2() { string Arg0 = "Simple"; double Arg1 = 6.0; verify_case(2, Arg1, averageLength(Arg0)); }
	void test_case_3() { string Arg0 = ""; double Arg1 = 0.0; verify_case(3, Arg1, averageLength(Arg0)); }
	void test_case_4() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; double Arg1 = 50.0; verify_case(4, Arg1, averageLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TextStatistics ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

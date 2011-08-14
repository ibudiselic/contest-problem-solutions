#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string ones[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string tens[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

int dist(const string &a, const string &b) {
	if (a.size() != b.size())
		return 1234567890;
	int ret = 0;
	for (int i=0; i<(int)a.size(); ++i)
		ret += (a[i] != b[i]);

	return ret;
}
class Speller {
	public:
	int value(string number) {
		int minDist = 1234567891;
		int cnt = 0;
		int num = -1;

		for (int i=0; i<9; ++i) {
			int t = dist(ones[i], number);
			if (t <= minDist) {
				if (t < minDist)
					cnt = 0;
				++cnt;
				num = i+1;
				minDist = t;
			}
		}
		for (int i=0; i<10; ++i) {
			int t = dist(teens[i], number);
			if (t <= minDist) {
				if (t < minDist)
					cnt = 0;
				++cnt;
				num = 10+i;
				minDist = t;
			}
		}
		for (int i=0; i<8; ++i) {
			int x = dist(tens[i], number);
			if (x <= minDist) {
				if (x < minDist)
					cnt = 0;
				++cnt;
				num = (i+2)*10;
				minDist = x;
			}
			for (int j=0; j<9; ++j) {
				int t = dist(tens[i] + "-" + ones[j], number);
				if (t <= minDist) {
					if (t < minDist)
						cnt = 0;
					++cnt;
					num = (i+2)*10 + j+1;
					minDist = t;
				}
			}
		}

		if (cnt == 1)
			return num;
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "forty-two"; int Arg1 = 42; verify_case(0, Arg1, value(Arg0)); }
	void test_case_1() { string Arg0 = "FORTY-TWO"; int Arg1 = -1; verify_case(1, Arg1, value(Arg0)); }
	void test_case_2() { string Arg0 = "eightene"; int Arg1 = 18; verify_case(2, Arg1, value(Arg0)); }
	void test_case_3() { string Arg0 = "fi"; int Arg1 = -1; verify_case(3, Arg1, value(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Speller ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

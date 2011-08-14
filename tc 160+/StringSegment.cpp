#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class StringSegment {
	public:
	double average(string s) {
		int cur = 0;
		int cnt = 0;
		int sum = 0;
		for (int i=0; i<(int)s.size(); ++i) {
			int j=i;
			while (j<(int)s.size() && s[i]==s[j]) {
				++cur;
				++j;
			}
			i = j-1;
			sum += cur;
			cur = 0;
			++cnt;
		}

		return double(sum)/cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaabbaaac"; double Arg1 = 2.25; verify_case(0, Arg1, average(Arg0)); }
	void test_case_1() { string Arg0 = "aabbccdd"; double Arg1 = 2.0; verify_case(1, Arg1, average(Arg0)); }
	void test_case_2() { string Arg0 = "abba"; double Arg1 = 1.3333333333333333; verify_case(2, Arg1, average(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StringSegment ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

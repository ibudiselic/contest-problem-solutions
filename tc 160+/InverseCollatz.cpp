#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class InverseCollatz {
	public:
	string getForm(string s) {
		long long a = 1;
		long long b = 0;

		for (int i=s.size()-1; i>=0; --i) {
			if (s[i] == 'E') {
				a *= 2;
				b *= 2;
			} else {
				long long firstdiv3 = b;
				while ((firstdiv3-1)%3 || (firstdiv3-1)/3 % 2 == 0)
					firstdiv3 += a;
				long long seconddiv3 = firstdiv3 + a;
				while ((seconddiv3-1) % 3 || (seconddiv3-1)/3 % 2 == 0)
					seconddiv3 += a;
				b = (firstdiv3-1)/3;
				a = (seconddiv3-1)/3 - b;
			}
		}
		ostringstream os;
		os << a << "k+" << b;
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "EEE"; string Arg1 = "8k+0"; verify_case(0, Arg1, getForm(Arg0)); }
	void test_case_1() { string Arg0 = "OE"; string Arg1 = "2k+1"; verify_case(1, Arg1, getForm(Arg0)); }
	void test_case_2() { string Arg0 = "OEO"; string Arg1 = "4k+3"; verify_case(2, Arg1, getForm(Arg0)); }
	void test_case_3() { string Arg0 = "EEEEOEEEEOEEEEOEEEEOEEEEOEEEEOEEEEOEEEEOEEEEOEEEEO"; string Arg1 = "2199023255552k+1014933810256"; verify_case(3, Arg1, getForm(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InverseCollatz ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

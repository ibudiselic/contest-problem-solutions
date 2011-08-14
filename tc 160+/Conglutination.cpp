#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int actSz(const string &s) {
	for (int i=0; i<(int)s.size(); ++i)
		if (s[i] != '0')
			return s.size()-i;
	return 0;
}
long long calc(const string &s) {
	if (actSz(s) > 10)
		return 1234567890;
	long long ret = 0;
	for (int i=0; i<(int)s.size(); ++i)
		ret = ret*10 + s[i]-'0';

	return ret;
}
class Conglutination {
	public:
	string split(string a, int e) {
		for (int i=1; i<(int)a.size(); ++i)
			if (calc(a.substr(0, i)) + calc(a.substr(i)) == e)
				return a.substr(0, i) + '+' + a.substr(i);

		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "22"; int Arg1 = 4; string Arg2 = "2+2"; verify_case(0, Arg2, split(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "536"; int Arg1 = 41; string Arg2 = "5+36"; verify_case(1, Arg2, split(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "123456000789"; int Arg1 = 1235349; string Arg2 = "1234560+00789"; verify_case(2, Arg2, split(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "123456789"; int Arg1 = 4245; string Arg2 = ""; verify_case(3, Arg2, split(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "112"; int Arg1 = 13; string Arg2 = "1+12"; verify_case(4, Arg2, split(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Conglutination ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

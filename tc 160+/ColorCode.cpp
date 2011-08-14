#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string color[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

int get(const string &s) {
	int i=0;
	while (color[i] != s)
		++i;
	return i;
}
long long mult(const string &s) {
	int k = get(s);

	long long ret = 1;
	while (k--)
		ret *= 10;

	return ret;
}
class ColorCode {
	public:
	long long getOhms(vector <string> code) {
		long long val = 0;
		val = get(code[0])*10 + get(code[1]);
		return val*mult(code[2]);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "yellow", "violet", "red" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4700LL; verify_case(0, Arg1, getOhms(Arg0)); }
	void test_case_1() { string Arr0[] = { "orange", "red", "blue" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 32000000LL; verify_case(1, Arg1, getOhms(Arg0)); }
	void test_case_2() { string Arr0[] = { "white", "white", "white" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 99000000000LL; verify_case(2, Arg1, getOhms(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ColorCode ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool calc(int &a, int b) {
	int x = 1;
	for (int i=1; i<=a; ++i) {
		if (x < int((1u<<31)-1)/i)
			x *= i;
		else
			return true;
		if (x > b)
			return true;
	}
	a = x;
	return false;
}
class ExtraordinarilyLarge {
	public:
	string compare(string x, string y) {
		int a, b;
		istringstream(x) >> a;
		istringstream(y) >> b;

		int ac=0, bc=0;
		for (int i=(int)x.size()-1; i>=0 && x[i]=='!'; --i, ++ac);
		for (int i=(int)y.size()-1; i>=0 && y[i]=='!'; --i, ++bc);

		if (a==0 && ac)
			a = 1;
		if (b==0 && bc)
			b = 1;

		const int t = min(ac, bc);
		ac -= t;
		bc -= t;

		while (ac--)
			if (calc(a, b))
				return "x>y";
		while (bc--)
			if (calc(b, a))
				return "x<y";

		if (a < b)
			return "x<y";
		else if (a > b)
			return "x>y";
		else
			return "x=y";
		return ":cry";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0!"; string Arg1 = "1"; string Arg2 = "x=y"; verify_case(0, Arg2, compare(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "9!"; string Arg1 = "999999999"; string Arg2 = "x<y"; verify_case(1, Arg2, compare(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "9!!"; string Arg1 = "999999999"; string Arg2 = "x>y"; verify_case(2, Arg2, compare(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "456!!!"; string Arg1 = "123!!!!!!"; string Arg2 = "x<y"; verify_case(3, Arg2, compare(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "5!"; string Arg1 = "120"; string Arg2 = "x=y"; verify_case(4, Arg2, compare(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ExtraordinarilyLarge ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

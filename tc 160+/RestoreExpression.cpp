#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;


string A, B, C;
int len;
struct sol_repr {
	string a, b, c;
};
sol_repr none;
bool operator==(const sol_repr &a, const sol_repr &b) {
	return a.a==b.a && a.b==b.b && a.c==b.c;
}
void update(sol_repr &lhs, const sol_repr &rhs) {
	if (lhs==none || (rhs.c>lhs.c || (rhs.c==lhs.c && rhs.a>lhs.a)))
		lhs = rhs;
}

map<int, sol_repr> M[2];

bool can(const string &s, int pos, int dig) {
	pos -= len-s.size();
	if (pos < 0)
		return dig==0;
	else if (s.size()>1 && pos==0)
		return s[pos]=='?' ? dig!=0 : dig==s[pos]-'0';
	else
		return s[pos]=='?' || dig==s[pos]-'0';
}
sol_repr go(int d, int carry) {
	if (d == len)
		return carry ? none:sol_repr();

	if (M[carry].count(d))
		return M[carry][d];

	sol_repr &ret = M[carry][d];

	for (int c=9; c>=0; --c) if (can(C, d, c))
		for (int a=9; a>=0; --a) if (can(A, d, a))
			for (int b=9; b>=0; --b) if (can(B, d, b))
				if (a+b+1==10*carry+c) {
					sol_repr t = go(d+1, 1);
					if (t == none) continue;
					t.c = char('0'+c) + t.c;
					t.a = char('0'+a) + t.a;
					t.b = char('0'+b) + t.b;
					update(ret, t);
				} else if (a+b==10*carry+c) {
					sol_repr t = go(d+1, 0);
					if (t == none) continue;
					t.c = char('0'+c) + t.c;
					t.a = char('0'+a) + t.a;
					t.b = char('0'+b) + t.b;
					update(ret, t);
				}
	if (ret == sol_repr())
		ret = none;
	return ret;
}
string trim(string s) {
	while (s.size()>1 && s[0]=='0')
		s.erase(s.begin());
	return s;
}
class RestoreExpression {
	public:
	string restore(string expression) {
		expression[expression.find('+')] = ' ';
		expression[expression.find('=')] = ' ';

		istringstream is(expression);
		is >> A >> B >> C;
		len = max(max(A.size(), B.size()), C.size());
		M[0].clear();
		M[1].clear();
		none.a = none.b = none.c = "NONE";

		const sol_repr sol = go(0, 0);

		return sol==none ? "no solution" : trim(sol.a) + '+' + trim(sol.b) + '=' + trim(sol.c);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "5+?=?4"; string Arg1 = "5+9=14"; verify_case(0, Arg1, restore(Arg0)); }
	void test_case_1() { string Arg0 = "?+?=4"; string Arg1 = "4+0=4"; verify_case(1, Arg1, restore(Arg0)); }
	void test_case_2() { string Arg0 = "?2+?2=4"; string Arg1 = "no solution"; verify_case(2, Arg1, restore(Arg0)); }
	void test_case_3() { string Arg0 = "??+1=1?"; string Arg1 = "18+1=19"; verify_case(3, Arg1, restore(Arg0)); }
	void test_case_4() { string Arg0 = "???+?=???0"; string Arg1 = "999+1=1000"; verify_case(4, Arg1, restore(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RestoreExpression ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

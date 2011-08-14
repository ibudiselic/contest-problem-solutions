#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(vector<string> &exp) {
	for (int j=0; j<(int)exp[0].size(); ++j) {
		for (int i=0; i<(int)exp.size(); ++i)
			if (exp[i][j] != ' ')
				goto DESNO;

		for (int i=0; i<(int)exp.size(); ++i)
			exp[i] = exp[i].substr(1);
		--j;
	}
	DESNO:
	for (int j=(int)exp[0].size()-1; j>=0; --j) {
		for (int i=0; i<(int)exp.size(); ++i)
			if (exp[i][j] != ' ')
				goto GOTOVO;

		for (int i=0; i<(int)exp.size(); ++i)
			exp[i] = exp[i].substr(0, exp[i].size()-1);
	}
	GOTOVO:
	const int m = exp.size();
	const int n = exp[0].size();
	/*for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j)
			cerr << exp[i][j];
		cerr << '|' << '\n';
	}
	cerr << string(n, '*') << '\n';*/
	const string div(n, '-');
	for (int i=0; i<m; ++i)
		if (exp[i] == div) {
			vector<string> num(exp.begin(), exp.begin()+i);
			vector<string> denom(exp.begin()+i+1, exp.end());
			return calc(num) / calc(denom);
		}

	for (int j=0; j<n; ++j) {
		int pcnt = 0;
		for (int i=0; i<m; ++i)
			if (exp[i][j] == '+') {
				++pcnt;
			} else if (exp[i][j] != ' ') {
				goto FAIL;
			}
		if (pcnt == 1) {
			vector<string> left;
			vector<string> right;
			for (int i=0; i<m; ++i) {
				left.push_back(exp[i].substr(0, j-1));
				right.push_back(exp[i].substr(j+2));
			}
			return calc(left) + calc(right);
		}

		FAIL: ;
	}

	for (int i=0; i<m; ++i) {
		int val = 0;
		for (int j=0; j<n; ++j)
			if (exp[i][j] != ' ')
				val = (val*10 + exp[i][j]-'0');
		if (val != 0)
			return val;
	}

	return -1;
}

class Untypeset {
	public:
	int evaluate(vector <string> expression) {
		return calc(expression);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "2801" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2801; verify_case(0, Arg1, evaluate(Arg0)); }
	void test_case_1() { string Arr0[] = { "  625       ",
  "------------",
  "        5   " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 125; verify_case(1, Arg1, evaluate(Arg0)); }
	void test_case_2() { string Arr0[] = { "       ",
  "500    ",
  "       ",
  "    +  ",
  "       ",
  "       ",
  "      1",
  "       ",
  "       " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 501; verify_case(2, Arg1, evaluate(Arg0)); }
	void test_case_3() { string Arr0[] = { "   120   ",
  "  -----  ",
  "    10   ",
  "---------",
  "    6    ",
  "   ---   ",
  "    2    " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, evaluate(Arg0)); }
	void test_case_4() { string Arr0[] = { "       24       ",
  " 31 + ----      ",
  "       12   + 16",
  "-----------     ",
  "   5 + 6        " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(4, Arg1, evaluate(Arg0)); }
	void test_case_5() { string Arr0[] = {"3 + 4 + 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(5, Arg1, evaluate(Arg0)); }
	void test_case_6() { string Arr0[] = { " 1     4     9 ",
  "--- + --- + ---",
  " 1     2     3 " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(6, Arg1, evaluate(Arg0)); }
	void test_case_7() { string Arr0[] =
{ "34      ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "   +    ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "        ",
  "     924" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 958; verify_case(7, Arg1, evaluate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Untypeset ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

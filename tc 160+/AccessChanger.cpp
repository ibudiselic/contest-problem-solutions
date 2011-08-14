#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class AccessChanger {
	public:
	vector <string> convert(vector <string> program) {
		for (int i=0; i<(int)program.size(); ++i) {
			program[i] += ' ';
			for (int j=0; j+2<(int)program[i].size(); ++j)
				if (program[i][j]=='/' && program[i][j+1]=='/')
					break;
				else if (program[i][j]=='-' && program[i][j+1]=='>')
					program[i] = program[i].substr(0, j) + '.' + program[i].substr(j+2);

			program[i].resize(program[i].size()-1);
		}

		return program;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Test* t = new Test();",
 "t->a = 1;",
 "t->b = 2;",
 "t->go(); // a=1, b=2 --> a=2, b=3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Test* t = new Test();", "t.a = 1;", "t.b = 2;", "t.go(); // a=1, b=2 --> a=2, b=3" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, convert(Arg0)); }
	void test_case_1() { string Arr0[] = {"---> // the arrow --->",
 "---",
 "> // the parted arrow"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"--. // the arrow --->", "---", "> // the parted arrow" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, convert(Arg0)); }
	void test_case_2() { string Arr0[] = {"->-> // two successive arrows ->->"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".. // two successive arrows ->->" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, convert(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AccessChanger ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

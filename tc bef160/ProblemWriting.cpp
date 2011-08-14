#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

enum {
	NUM, DOT, OP
};
class ProblemWriting {
	public:
	string myCheckData(string s) {
		if (s.size()>25 || s.size()==0) return "dotForm must contain between 1 and 25 characters, inclusive.";

		string a[3][3];
		a[NUM][NUM] = "error";
		a[OP][NUM]  = "+-*/.";
		a[DOT][NUM] = "+-*/.";
		a[NUM][DOT] = ".+-*/";
		a[OP][DOT]  = "1234567890.";
		a[DOT][DOT] = "error";
		a[NUM][OP]  = "1234567890.";
		a[OP][OP]		= "error";
		a[DOT][OP]	= "1234567890.";

		if (!isdigit(s[0])) return "dotForm is not in dot notation, check character 0.";
		int cur, prev;
		cur = NUM;
		prev = DOT; /* or OP... arbitrary */
		for (string::size_type i=1; i<s.size(); ++i) {
			if (a[prev][cur].find(s[i]) == string::npos)
				return "dotForm is not in dot notation, check character "+to_str<string::size_type>(i)+'.';
			int t;
			if (isdigit(s[i])) t = NUM;
			else if (s[i]=='.') t = DOT;
			else if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') t = OP;
			else t = -1;
			if (t==-1) return "dotForm is not in dot notation, check character "+to_str<string::size_type>(i)+'.';

			if (t!=cur) {
				prev = cur;
				cur = t;
			}
		}
		if (!isdigit(s[s.size()-1])) return "dotForm is not in dot notation, check character "+to_str<string::size_type>(s.size())+'.';

		return string();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "3+5"; string Arg1 = ""; verify_case(0, Arg1, myCheckData(Arg0)); }
	void test_case_1() { string Arg0 = "9..+.5...*....3"; string Arg1 = ""; verify_case(1, Arg1, myCheckData(Arg0)); }
	void test_case_2() { string Arg0 = "5.3+4"; string Arg1 = "dotForm is not in dot notation, check character 2."; verify_case(2, Arg1, myCheckData(Arg0)); }
	void test_case_3() { string Arg0 = "9*9*9*9*9*9*9*9*9*9*9*9*9*9"; string Arg1 = "dotForm must contain between 1 and 25 characters, inclusive."; verify_case(3, Arg1, myCheckData(Arg0)); }
	void test_case_4() { string Arg0 = "3.........../...........4"; string Arg1 = ""; verify_case(4, Arg1, myCheckData(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ProblemWriting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

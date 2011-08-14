#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>

using namespace std;
template<class T>
vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}
template<class T>
string to_str(T x) {
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

map<string, int> var;
class Calculate {
	public:
	int eval_exp(const string &s) {
		int i=0;
		int pc=0;

		for (i=s.size()-1, pc=0; i>=0 && (pc || s[i]!='+'&&s[i]!='-'); --i)
			pc += (s[i]==')') - (s[i]=='(');
		if (i > -1) {
			int a = eval_exp(s.substr(0, i));
			int b = eval_exp(s.substr(i+1));
			if (s[i]=='+') return a+b; else return a-b;
		}
		for (i=s.size()-1, pc=0; i>=0 && (pc || s[i]!='*'&&s[i]!='/'); --i)
			pc += (s[i]==')') - (s[i]=='(');
		if (i > -1) {
			int a = eval_exp(s.substr(0, i));
			int b = eval_exp(s.substr(i+1));
			if (s[i]=='*') return a*b; else return a/b;
		}
		for (i=s.size()-1, pc=0; i>=0 && (pc || s[i]!='^'); --i)
			pc += (s[i]==')') - (s[i]=='(');
		if (i > -1) {
			int a = eval_exp(s.substr(0, i));
			int b = eval_exp(s.substr(i+1));
			if (a == 0) return 0;
			if (a == 1) return 1;
			if (a == -1) return (b%2==0 ? 1:-1);
			int ret = 1;
			while (b--)
				ret *= a;
			return ret;
		}
		if (s[0]=='(') return eval_exp(s.substr(1, s.size()-2));
		if (isdigit(s[0])) return atoi(s.c_str());
		else return var[s];
	}
	int calc(string expression, vector <string> variables) {
		var.clear();
		for (int i=0; i<(int)variables.size(); ++i) {
			vector<string> t = tokenize<string>(variables[i]);
			var[t[0]] = atoi(t[1].c_str());
		}

		return eval_exp(expression);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "x*y+3*x"; string Arr1[] = {"x 1", "y 11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "x^p*2^(2^p)/t^p^t+xx*n^v"; string Arr1[] = {"x 53", "xx 32", "p 3","t 2","n -1","v -21"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 595476; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "t^003^t"; string Arr1[] = {"t 00000000000002","a 999999999"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 64; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "(8*(Aa^(aA-1230))-aA^2+((00)))*(0-1)"; string Arr1[] = {"aA 01234","Aa 98"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -736371772; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "0-2+t^30+t^30+1"; string Arr1[] = {"t 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2147483647; verify_case(4, Arg2, calc(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "1+(0-t)^31-1"; string Arr1[] = {"t 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -2147483648; verify_case(5, Arg2, calc(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "((5-x+1^x))"; string Arr1[] = {"x -100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 106; verify_case(6, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Calculate ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

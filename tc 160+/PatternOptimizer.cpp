#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;
template<class T> vector<T> tokenize(string s, const string &delim=" ") {
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
class PatternOptimizer {
	public:
	string optimize(string pattern) {
		string a = pattern;
		string b = pattern;

		for (int i=0; i<(int)a.size(); ++i)
			if (isalpha(pattern[i]))
				a[i] = ' ';
			else
				b[i] = ' ';

		vector<string> x = tokenize<string>(a);
		vector<string> y = tokenize<string>(b);

		for (int i=0; i<(int)x.size(); ++i) {
			int u = count(x[i].begin(), x[i].end(), '*');
			int v = count(x[i].begin(), x[i].end(), '?');
			assert(u+v == (int)x[i].size());

			x[i] = (u>0 ? string(1, '*') : "") + string(v, '?');
		}

		string sol;
		int cnt = max(x.size(), y.size());
		if (a[0] != ' ') {
			for (int i=0; i<cnt; ++i) {
				if (i < (int)x.size())
					sol += x[i];
				if (i < (int)y.size())
					sol += y[i];
			}
		} else {
			for (int i=0; i<cnt; ++i) {
				if (i < (int)y.size())
					sol += y[i];
				if (i < (int)x.size())
					sol += x[i];
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "*??*a"; string Arg1 = "*??a"; verify_case(0, Arg1, optimize(Arg0)); }
	void test_case_1() { string Arg0 = "*b**a*"; string Arg1 = "*b*a*"; verify_case(1, Arg1, optimize(Arg0)); }
	void test_case_2() { string Arg0 = "cla??"; string Arg1 = "cla??"; verify_case(2, Arg1, optimize(Arg0)); }
	void test_case_3() { string Arg0 = "*?*?*?*"; string Arg1 = "*???"; verify_case(3, Arg1, optimize(Arg0)); }
	void test_case_4() { string Arg0 = "T***nd?*"; string Arg1 = "T*nd*?"; verify_case(4, Arg1, optimize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PatternOptimizer ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <functional>
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
string to_str(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
struct Term {
	int c, x, y, z;
	Term(const vector<string> &v): c(0), x(0), y(0), z(0) {
		for (int i=0; i<(int)v.size(); ++i)
			if (isdigit(v[i][0])) {
				assert(v[i].size() == 1);
				c = v[i][0]-'0';
			} else {
				switch (v[i][0]) {
					case 'x': x = (v[i].size()>1 ? (assert(v[i].size()==3 && v[i][1]=='^'), v[i][2]-'0') : 1); break;
					case 'y': y = (v[i].size()>1 ? (assert(v[i].size()==3 && v[i][1]=='^'), v[i][2]-'0') : 1); break;
					case 'z': z = (v[i].size()>1 ? (assert(v[i].size()==3 && v[i][1]=='^'), v[i][2]-'0') : 1); break;
					default: cerr << v[i][0] << '\n'; assert(0); break;
				}
			}
			if (c == 0)
				c = 1;
	}
	string str() const {
		if (x+y+z == 0)
			return to_str(c);
		string ret;
		if (c > 1)
			ret += to_str(c) + '*';
		if (x > 0) {
			ret += 'x';
			if (x > 1)
				ret += '^'+to_str(x);
			if (y+z != 0)
				ret += '*';
		}
		if (y > 0) {
			ret += 'y';
			if (y > 1)
				ret += '^'+to_str(y);
			if (z != 0)
				ret += '*';
		}
		if (z > 0) {
			ret += 'z';
			if (z > 1)
				ret += '^'+to_str(z);
		}

		return ret;
	}
};
bool operator<(const Term &a, const Term &b) {
	if (a.x+a.y+a.z != b.x+b.y+b.z)
		return a.x+a.y+a.z < b.x+b.y+b.z;
	else if (a.x != b.x)
		return a.x < b.x;
	else if (a.y != b.y)
		return a.y < b.y;
	else
		return a.z < b.z;
}
bool operator>(const Term &a, const Term &b) {
	return b<a;
}
struct Fun {
	vector<Term> terms;
	void dodaj(const Term &t) {
		for (int i=0; i<(int)terms.size(); ++i)
			if (!(t<terms[i]) && !(terms[i]<t)) {
				terms[i].c += t.c;
				return;
			}
		terms.push_back(t);
	}
	Fun() {}
	Fun(const string &s) {
		istringstream is(s);
		string t;

		while (is >> t) {
			vector<string> v = tokenize<string>(t, "*");
			dodaj(Term(v));
			is >> t;
		}
		finalize();
	}
	void finalize() {
		sort(terms.begin(), terms.end(), greater<Term>());
		for (int i=0; i<(int)terms.size(); ++i)
			if (terms[i].c == 0)
				terms.erase(terms.begin()+i--);
	}
	string str() const {
		string ret;
		bool flag = 0;
		for (int i=0; i<(int)terms.size(); ++i) {
			if (flag) ret += " + ";
			flag = 1;
			ret += terms[i].str();
		}
		return ret;
	}
};
void der(Fun &f, Term t, char var) {
	switch (var) {
		case 'x': t.c *= t.x; --t.x; break;
		case 'y': t.c *= t.y; --t.y; break;
		case 'z': t.c *= t.z; --t.z; break;
		default: assert(0); break;
	}
	f.dodaj(t);
}
Fun der(const Fun &f, char var) {
	Fun ret;
	for (int i=0; i<(int)f.terms.size(); ++i)
		der(ret, f.terms[i], var);

	ret.finalize();
	return ret;
}
class Partial {
	public:
	string derivative(string expr, string vars) {
		Fun f(expr);

		for (int i=0; i<(int)vars.size(); ++i)
			f = der(f, vars[i]);

		const string sol = f.str();
		return (sol.size()>0 ? sol:"0");
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "7*x"; string Arg1 = "x"; string Arg2 = "7"; verify_case(0, Arg2, derivative(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "x + z + 9*z^2 + y*z^3"; string Arg1 = "z"; string Arg2 = "3*y*z^2 + 18*z + 1"; verify_case(1, Arg2, derivative(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "x^2*y^2*z^2"; string Arg1 = "xy"; string Arg2 = "4*x*y*z^2"; verify_case(2, Arg2, derivative(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "y*8*z*x^3 + x^5 + y*2*x^4 + 9*x^4*z + x^5*5"; string Arg1 = ""; string Arg2 = "6*x^5 + 2*x^4*y + 9*x^4*z + 8*x^3*y*z"; verify_case(3, Arg2, derivative(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "9*x^9*y^9*z^9 + x^2*y^2*z^2"; string Arg1 = "xyzzy"; string Arg2 = "419904*x^8*y^7*z^7 + 8*x"; verify_case(4, Arg2, derivative(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "x + y + z"; string Arg1 = "yy"; string Arg2 = "0"; verify_case(5, Arg2, derivative(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "9*x^9 + 9*x^9 + 9*x^9 + 9*x^9 + 9*x^9 + 9*x^9"; string Arg1 = ""; string Arg2 = "54*x^9"; verify_case(6, Arg2, derivative(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Partial ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

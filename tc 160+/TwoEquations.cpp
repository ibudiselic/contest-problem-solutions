#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b ? b:1;
	else return gcd(b%a, a);
}
struct Frac {
	int n, d;
	Frac(int nn, int dd): n(nn), d(dd) {}
	void norm() {
		int sign = 1;
		if (n < 0) {
			sign *= -1;
			n = -n;
		}
		if (d < 0) {
			sign *= -1;
			d = -d;
		}
		this->reduce();
		n *= sign;
	}
	void reduce() {
		int t = gcd(n, d);
		n /= t; d /= t;
	}
};
class TwoEquations {
	public:
	void parse(const string &s, int *a, int *b, int *r) {
		string t;
		for (int i=0; i<(int)s.size(); ++i)
			if (s[i]!=')' && s[i]!='(')
				t += s[i];
		sscanf(t.c_str(), "%d*X + %d*Y = %d", a, b, r);
	}
	string solve(string first, string second) {
		int a, b, r1, c, d, r2;
		parse(first, &a, &b, &r1);
		parse(second, &c, &d, &r2);

		if (a*d - b*c != 0) {
			int nom, denom, sign;
			sign = 1;
			nom = d*r1 - b*r2;
			denom = a*d - b*c;
			if (nom < 0) {
				nom = -nom;
				sign *= -1;
			}
			if (denom < 0) {
				denom = -denom;
				sign *= -1;
			}
			int t = gcd(nom, denom);
			nom /= t;
			denom /= t;
			ostringstream os;
			if (sign == 1 || nom==0) {
				os << "X=" << nom << '/' << denom << ' ';
			} else {
				os << "X=" << "(-" << nom << ')' << '/' << denom << ' ';
			}
			sign = 1;
			nom = -c*r1 + a*r2;
			denom = a*d - b*c;
			if (nom < 0) {
				nom = -nom;
				sign *= -1;
			}
			if (denom < 0) {
				denom = -denom;
				sign *= -1;
			}
			t = gcd(nom, denom);
			nom /= t;
			denom /= t;
			if (sign == 1 || nom==0) {
				os << "Y=" << nom << '/' << denom;
			} else {
				os << "Y=" << "(-" << nom << ')' << '/' << denom;
			}
			return os.str();
		} else {
			if (a==0 && b==0 && r1!=0) return "NO SOLUTIONS";
			if (c==0 && d==0 && r2!=0) return "NO SOLUTIONS";
			if (a==0 && b==0 && r1==0) return "MULTIPLE SOLUTIONS";
			if (c==0 && d==0 && r2==0) return "MULTIPLE SOLUTIONS";
			/*if (a*r2 - c*r1 == 0) return "MULTIPLE SOLUTIONS";
			if (r1*d - r2*b == 0) return "MULTIPLE SOLUTIONS";*/
			Frac k1(b!=0 ? -a : 10000, b!=0 ? b : 1);
			Frac k2(d!=0 ? -c : 10000, d!=0 ? d : 1);
			Frac c1(r1, b!=0 ? b : a);
			Frac c2(r2, d!=0 ? d : c);
			k1.norm(); k2.norm();
			assert(k1.n==k2.n && k1.d==k2.d);
			c1.norm(); c2.norm();
			if (c1.n==c2.n && c1.d==c2.d) return "MULTIPLE SOLUTIONS";
			else return "NO SOLUTIONS";
		}
		return "T_T";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1*X + 2*Y = 6"; string Arg1 = "1*X + (-4)*Y = (-3)"; string Arg2 = "X=3/1 Y=3/2"; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "(-3)*X + 0*Y = 7"; string Arg1 = "0*X + 8*Y = 6"; string Arg2 = "X=(-7)/3 Y=3/4"; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1*X + 0*Y = 1"; string Arg1 = "1*X + 0*Y = 1"; string Arg2 = "MULTIPLE SOLUTIONS"; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "1*X + 3*Y = 1"; string Arg1 = "2*X + 6*Y = (-1)"; string Arg2 = "NO SOLUTIONS"; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "0*X + 0*Y = 0"; string Arg1 = "(-3)*X + (-3)*Y = 0"; string Arg2 = "MULTIPLE SOLUTIONS"; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TwoEquations ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

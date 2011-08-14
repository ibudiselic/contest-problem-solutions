#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string tostr(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
struct Polinomial {
	vector<int> coeff;
	Polinomial() {}
	Polinomial(const string &s) {
		istringstream is(s);
		string w;
		while (is >> w) {
			int c;
			int exp_pos;
			int exp;
			if (w[0] == 'x') {
				c = 1;
				exp_pos = 2;
			} else {
				c = w[0]-'0';
				exp_pos = 4;
			}
			if (w.size() == 1)
				if (w[0] == 'x')
					exp = 1;
				else
					exp = 0;
			else
				exp = (exp_pos<(int)w.size() ? w[exp_pos]-'0' : 1);

			if ((int)coeff.size() <= exp)
				coeff.resize(exp+1);
			coeff[exp] += c;
			is >> w;
		}
	}
	string str() const {
		string ret;
		bool flag = false;
		for (int i=(int)coeff.size()-1; i>=0; --i)
			if (coeff[i] != 0) {
				if (flag)
					ret += " + ";
				flag = 1;

				if (coeff[i]!=1 || i==0) {
					ret += tostr(coeff[i]);
					if (i != 0)
						ret += "*x" + (i!=1 ? "^"+tostr(i) : "");
				} else if (i != 0) {
					ret += "x" + (i!=1 ? "^"+tostr(i) : "");
				}
			}

		return ret;
	}
};

Polinomial operator*(const Polinomial &a, const Polinomial &b) {
	Polinomial ret;
	ret.coeff.resize(a.coeff.size()+b.coeff.size());

	for (int i=0; i<(int)a.coeff.size(); ++i)
		for (int j=0; j<(int)b.coeff.size(); ++j)
			ret.coeff[i+j] += a.coeff[i]*b.coeff[j];

	return ret;
}

class PolynomialMultiplier {
	public:
	string product(string f1, string f2) {
		Polinomial P1(f1);
		Polinomial P2(f2);

		return (P1*P2).str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1 + x"; string Arg1 = "1 + x"; string Arg2 = "x^2 + 2*x + 1"; verify_case(0, Arg2, product(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "4*x^4 + 1"; string Arg1 = "3*x^5 + 7*x"; string Arg2 = "12*x^9 + 31*x^5 + 7*x"; verify_case(1, Arg2, product(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1 + x + 1 + x"; string Arg1 = "5 + 5"; string Arg2 = "20*x + 20"; verify_case(2, Arg2, product(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "8*x^5"; string Arg1 = "9*x^7"; string Arg2 = "72*x^12"; verify_case(3, Arg2, product(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "5*x^3 + x^4 + 8 + 2*x^6"; string Arg1 = "3*x^5 + 4*x + 7*x^9"; string Arg2 = "14*x^15 + 7*x^13 + 35*x^12 + 6*x^11 + 59*x^9 + 15*x^8 + 8*x^7 + 28*x^5 + 20*x^4 + 32*x"; verify_case(4, Arg2, product(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PolynomialMultiplier ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

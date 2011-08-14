#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
vector<string> tokenize_to_string(const string &s, const char delim=' ') {
	vector<string> ret;

	string t;
	for (string::size_type i=0; i<s.size(); ++i) {
		if (s[i]==delim) {
			ret.push_back(t);
			t.clear();
		} else {
			t += s[i];
		}
	}
	ret.push_back(t);

	return ret;
}

void parse(const string &s, vector<int> &a) {
	vector<string> t = tokenize_to_string(s, '+');
	for (int i=0; i<(int)t.size(); ++i)
		if (t[i].size()==1)
			a[0] += t[i][0]-'0';
		else
			a[t[i][3]-'0'] += t[i][0]-'0';
}
long long calc(int x, const vector<int> &a) {
	long long ret = a[0];
	for (int i=1; i<10; ++i)
		if (a[i] > 0) {
			long long xx = 1;
			for (int j=0; j<i; ++j)
				xx *= x;
			ret += a[i]*xx;
		}
	return ret;
}
bool constant(const vector<int> &a) {
	for (int i=1; i<10; ++i)
		if (a[i] > 0)
			return false;
	return true;
}
class Polynomials {
	public:
	long long integralPoints(int ymax, int xmax, string equation) {
		vector<int> a(10, 0), b(10, 0);

		vector<string> t = tokenize_to_string(equation, '=');

		parse(t[0], a);
		parse(t[1], b);

		long long mul = 1;
		if (constant(a)) { mul *= ymax+1; ymax = 0; }
		if (constant(b)) { mul *= xmax+1; xmax = 0; }

		int x = 0;
		int y = 0;
		long long sol = 0;
		while (x<=xmax && y<=ymax) {
			long long xx = calc(x, b);
			long long yy = calc(y, a);
			if (xx==yy) {
				++sol; ++x; ++y;
			} else if (xx>yy)
				++y;
			else ++x;
		}
		return sol*mul;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; string Arg2 = "1y^1=1x^1"; long long Arg3 = 6LL; verify_case(0, Arg3, integralPoints(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 65; int Arg1 = 34; string Arg2 = "1y^2=1x^3"; long long Arg3 = 5LL; verify_case(1, Arg3, integralPoints(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 1000000; string Arg2 = "1=1x^2"; long long Arg3 = 1000001LL; verify_case(2, Arg3, integralPoints(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 55000; int Arg1 = 15982; string Arg2 = "1y^4+1y^2=5+9+6"; long long Arg3 = 15983LL; verify_case(3, Arg3, integralPoints(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Polynomials ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

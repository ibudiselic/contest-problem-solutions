#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long nextOdd(vector<int> &v, int b) {
	++v[0];
	int i=0;
	while (v[i] == b) {
		v[i] = 0;
		if (i == (int)v.size()-1)
			v.push_back(0);
		++v[++i];
	}

	long long ret = 0;
	long long f = b;
	b *= b;

	for (int i=0; i<(int)v.size(); ++i, f*=b)
		ret += v[i]*f;

	return ret;
}
long long nextEven(vector<int> &v, int b) {
	++v[0];
	int i=0;
	while (v[i] == b) {
		v[i] = 0;
		if (i == (int)v.size()-1)
			v.push_back(0);
		++v[++i];
	}

	long long ret = 0;
	long long f = 1;
	b *= b;

	for (int i=0; i<(int)v.size(); ++i, f*=b)
		ret += v[i]*f;

	return ret;
}
class ReverseUnnaturalBaseConversion {
	public:
	string convertToBase(int x, int b) {
		if (x == 0)
			return "0";

		if (b > 0) {
			int sign = (x<0 ? -1 : 1);

			x *= sign;


			string sol;
			while (x > 0) {
				sol += (x%b + '0');
				x /= b;
			}
			if (sign == -1)
				sol += '-';

			reverse(sol.begin(), sol.end());

			return sol;
		} else {
			//cerr << x << ' ' << b << '\n';
			b = -b;
			vector<int> odd(1, 0);
			vector<int> even(1, 0);
			long long A = 0;
			long long B = 0;
			while (A-B != x) {

				if (A-B > x)
					B = nextOdd(odd, b);
				else
					A = nextEven(even, b);

				/*cerr << "even: " << A << '\n';
				for (int i=0; i<(int)even.size(); ++i)
					cerr << even[i];
				cerr << "\nodd: " << B << '\n';
				for (int i=0; i<(int)odd.size(); ++i)
					cerr << odd[i];
				cerr << '\n';*/

			}

			int k = max(odd.size(), even.size());
			odd.resize(k);
			even.resize(k);
			string sol;
			for (int i=0; i<k; ++i) {
				sol += even[i]+'0';
				sol += odd[i]+'0';
			}

			if (sol[sol.size()-1] == '0')
				sol = sol.substr(0, sol.size()-1);
			reverse(sol.begin(), sol.end());

			return sol;
		}
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12345; int Arg1 = 10; string Arg2 = "12345"; verify_case(0, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8265; int Arg1 = -10; string Arg2 = "12345"; verify_case(1, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1001; int Arg1 = -2; string Arg2 = "10000111001"; verify_case(2, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -52; int Arg1 = -2; string Arg2 = "11011100"; verify_case(3, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = -38; int Arg1 = 4; string Arg2 = "-212"; verify_case(4, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = -123456789; int Arg1 = -7; string Arg2 = "3031330536"; verify_case(5, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 0; int Arg1 = 2; string Arg2 = "0"; verify_case(6, Arg2, convertToBase(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ReverseUnnaturalBaseConversion ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

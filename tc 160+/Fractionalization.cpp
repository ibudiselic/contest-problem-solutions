#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

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

struct Item {
	string name;
	vector<int> sub;
	Item(const string &s): name(s) {}
};

int gcd(int a, int b) {
	int t;
	if (a==0 && b==0) return 1;
	if (a < b) { t=a; a=b; b=t; }
	while (b != 0) {
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}
struct Frac {
	int n, d;
	Frac(int nn, int dd): n(nn), d(dd) {}
	Frac& operator-=(const Frac &other) {
		n = other.d*n - other.n*d;
		d *= other.d;
		return *this;
	}
	Frac& operator+=(const Frac &other) {
		n = other.d*n + other.n*d;
		d *= other.d;
		return *this;
	}
	Frac& operator*=(int x) {
		n *= x;
		return *this;
	}
	Frac& norm() {
		int t = gcd(n, d);
		n /= t;
		d /= t;
		return *this;
	}
};
bool operator<(const Frac &lhs, const Frac &rhs) {
	return lhs.n*rhs.d < lhs.d*rhs.n;
}
bool operator>(const Frac &lhs, const Frac &rhs) {
	return lhs.n*rhs.d > lhs.d*rhs.n;
}
bool operator<=(const Frac &lhs, const Frac &rhs) {
	return lhs.n*rhs.d <= lhs.d*rhs.n;
}
bool operator>=(const Frac &lhs, const Frac &rhs) {
	return lhs.n*rhs.d >= lhs.d*rhs.n;
}
bool operator==(const Frac &lhs, const Frac &rhs) {
	return lhs.n*rhs.d == lhs.d*rhs.n;
}
bool operator!=(const Frac &lhs, const Frac &rhs) {
	return lhs.n*rhs.d != lhs.d*rhs.n;
}

const Frac operator+(const Frac &lhs, const Frac &rhs) {
	Frac t = lhs;
	t += rhs;
	return t;
}
const Frac operator-(const Frac &lhs, const Frac &rhs) {
	Frac t = lhs;
	t -= rhs;
	return t;
}
const Frac operator*(const Frac &lhs, int x) {
	Frac t = lhs;
	t *= x;
	return t;
}
const Frac operator*(int x, const Frac &rhs) {
	Frac t = rhs;
	t *= x;
	return t;
}

map<string, int> ind;
vector<Item> d;

class Fractionalization {
	public:
	vector <string> partial(vector <string> definitions, int m, int n, string danceCall) {
		d.clear();
		ind.clear();

		for (int i=0; i<(int)definitions.size(); ++i) {
			vector<string> t = tokenize<string>(definitions[i]);

			d.push_back(Item(t[0].substr(0, t[0].size()-1)));
			ind[t[0].substr(0, t[0].size()-1)] = d.size()-1;

			int x = d.size()-1;

			for (int j=1; j<(int)t.size(); ++j) {
				if (ind.count(t[j]) == 0) {
					d.push_back(Item(t[j]));
					ind[t[j]] = d.size()-1;
				}
				d[x].sub.push_back(ind[t[j]]);
			}
		}

		vector<string> sol;
		Frac t(m, n);
		t.norm();
		for (;;) {
			if (ind.count(danceCall)==0)
				return vector<string>(1, "ILLEGAL");
			int x = ind[danceCall];
			if (d[x].sub.size() == 0)
				return vector<string>(1, "ILLEGAL");

			Frac unit(1, d[x].sub.size());
			int k = 1;
			while (k*unit <= t) {
				sol.push_back(d[d[x].sub[k-1]].name);
				++k;
			}
			t -= (k-1)*unit;
			t *= unit.d;
			t.norm();
			if (t.n == 0)
				break;
			danceCall = d[d[x].sub[k-1]].name;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "FiveParts: One Two Three Four Five" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; string Arg3 = "FiveParts"; string Arr4[] = {"One", "Two" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, partial(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = { "Trade: Hinge Hinge",
  "TradeThreeTimes: Trade Trade Trade" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; string Arg3 = "TradeThreeTimes"; string Arr4[] = {"Trade", "Trade", "Hinge" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, partial(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = { "Trade: Hinge Hinge",
  "CenterTwoTrade: CenterTwoHinge CenterTwoHinge",
  "SpinTheTop: Trade FanTheTop",
  "HotFootSpin: FanTheTop CenterTwoTrade SpinTheTop" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; string Arg3 = "HotFootSpin"; string Arr4[] = {"FanTheTop", "CenterTwoHinge" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, partial(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = { "Trade: Hinge Hinge",
  "CenterTwoTrade: CenterTwoHinge CenterTwoHinge",
  "SpinTheTop: Trade FanTheTop",
  "HotFootSpin: FanTheTop CenterTwoTrade SpinTheTop" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; string Arg3 = "HotFootSpin"; string Arr4[] = {"FanTheTop", "CenterTwoTrade", "Hinge" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, partial(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = { "A: One Two",
  "B: One Two Three",
  "C: One Two Three Four" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; string Arg3 = "C"; string Arr4[] = {"One", "Two", "Three" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, partial(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = { "A: X Y Z",
  "B: A A A" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 23; string Arg3 = "B"; string Arr4[] = {"ILLEGAL" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, partial(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { string Arr0[] = { "A: B C",
  "D: E F" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; string Arg3 = "G"; string Arr4[] = {"ILLEGAL" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(6, Arg4, partial(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Fractionalization ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

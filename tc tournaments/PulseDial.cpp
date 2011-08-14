#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

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

int dig(const string &s) {
	if (s.size() == 10)
		return 0;
	else
		return s.size();
}

class PulseDial {
	public:
	string toDigits(string raw) {
		vector<string> v = tokenize<string>(raw, "*");

		if (v.size() == 7) {
			ostringstream os;
			for (int i=0; i<3; ++i)
				os << dig(v[i]);
			os << '-';
			for (int i=3; i<5; ++i)
				os << dig(v[i]);
			os << '-';
			for (int i=5; i<7; ++i)
				os << dig(v[i]);

			return os.str();
		} else {
			ostringstream os;
			os << '+';
			for (int i=0; i<11; ++i)
				os << dig(v[i]);
			return os.str();
		}

		return ":cry";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "---***-*--*-*--*-******--***"; string Arg1 = "312-12-12"; verify_case(0, Arg1, toDigits(Arg0)); }
	void test_case_1() { string Arg0 = "-*--*-----*------*---*----*-"; string Arg1 = "125-63-41"; verify_case(1, Arg1, toDigits(Arg0)); }
	void test_case_2() { string Arg0 = "--**--**--**--**--**--**--**--**--**--**--******"; string Arg1 = "+22222222222"; verify_case(2, Arg1, toDigits(Arg0)); }
	void test_case_3() { string Arg0 = "*-*****-**-*--***--*****--***-***--**-**---**----*"; string Arg1 = "+11122212134"; verify_case(3, Arg1, toDigits(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PulseDial ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

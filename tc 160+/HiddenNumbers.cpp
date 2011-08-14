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

struct num {
	long long val;
	string repr;
	num(const string &s): repr(s) {
		istringstream is(repr);
		is >> val;
	}
};
bool operator<(const num &a, const num &b) {
	if (a.val != b.val)
		return a.val < b.val;
	else
		return a.repr.size() < b.repr.size();
}
class HiddenNumbers {
	public:
	vector <string> findAll(vector <string> text) {
		bool inNumber = false;
		int start = -1;

		string s;
		for (int i=0; i<(int)text.size(); ++i)
			s += text[i];

		vector<num> v;
		s += '+';
		for (int i=0; i<(int)s.size(); ++i)
			if (inNumber) {
				if (!isdigit(s[i])) {
					v.push_back(num(s.substr(start, i-start)));
					inNumber = false;
				}
			} else {
				if (isdigit(s[i])) {
					start = i;
					inNumber = true;
				}
			}

		sort(v.begin(), v.end());
		vector<string> sol;
		for (int i=(int)v.size()/2; i<(int)v.size(); ++i)
			sol.push_back(v[i].repr);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"098m03r9f80239802389f0m9KDKLKLJDKLJm0983m890DMOm03",
 "dlkfj3hljf4h3klhl  4j4 444 44  rjhkrrkr34534539893",
 " 390804980498409480 dkldjkl djkl djkl d00000002998"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "9",  "44",  "098",  "444",  "890",  "0983",  "00000002998",  "34534539893",  "80239802389",  "390804980498409480" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"39 000220 30 skldjdije939939slkk 3090 2912kjdk3949",
 "dlkjd dkljsl098 dkd3 23kdkdkl 0000002222kdjdie9000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0000002222",  "2912",  "3090",  "3949",  "9000",  "939939" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findAll(Arg0)); }
	void test_case_2() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"0022 22k00022a022"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0022",  "00022" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findAll(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HiddenNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

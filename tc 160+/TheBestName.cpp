#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct S_ {
	int w;
	string s;
	S_(int w_, const string &s_): w(w_), s(s_) {}
};
bool operator<(const S_ &a, const S_ &b) {
	if (a.s == "JOHN") {
		return true;
	}
	if (b.s == "JOHN") {
		return false;
	}
	if (a.w != b.w) {
		return a.w > b.w;
	}
	return a.s < b.s;
}
int gw(const string &s) {
	int ret = 0;
	for (int i=0; i<(int)s.size(); ++i) {
		ret += s[i]-'A'+1;
	}
	
	return ret;
}
class TheBestName {
	public:
	vector <string> sort(vector <string> names) {
		vector<S_> v;
		for (int i=0; i<(int)names.size(); ++i) {
			v.push_back(S_(gw(names[i]), names[i]));
		}
		::sort(v.begin(), v.end());

		for (int i=0; i<(int)names.size(); ++i) {
			names[i] = v[i].s;
		}

		return names;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"JOHN", "PETR", "ACRUSH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"JOHN", "ACRUSH", "PETR" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sort(Arg0)); }
	void test_case_1() { string Arr0[] = {"GLUK", "MARGARITKA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"MARGARITKA", "GLUK" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sort(Arg0)); }
	void test_case_2() { string Arr0[] = {"JOHN", "A", "AA", "AAA", "JOHN", "B", "BB", "BBB", "JOHN", "C", "CC", "CCC", "JOHN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"JOHN", "JOHN", "JOHN", "JOHN", "CCC", "BBB", "CC", "BB", "AAA", "C", "AA", "B", "A" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sort(Arg0)); }
	void test_case_3() { string Arr0[] = {"BATMAN", "SUPERMAN", "SPIDERMAN", "TERMINATOR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"TERMINATOR", "SUPERMAN", "SPIDERMAN", "BATMAN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sort(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBestName ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

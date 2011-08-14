#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class EqualSubstrings {
	public:
	vector <string> getSubstrings(string str) {
		for (int i=(int)str.size(); i>0; --i) {
			const string &a = str.substr(0, i);
			const string &b = (i<(int)str.size() ? str.substr(i) : "");
			if (count(a.begin(), a.end(), 'a') == count(b.begin(), b.end(), 'b')) {
				vector<string> sol;
				sol.push_back(a);
				sol.push_back(b);
				return sol;
			}
		}

		vector<string> sol;
		sol.push_back("");
		sol.push_back(str);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "aaabbb"; string Arr1[] = { "aaa",  "bbb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSubstrings(Arg0)); }
	void test_case_1() { string Arg0 = "bbbaaa"; string Arr1[] = { "bbb",  "aaa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSubstrings(Arg0)); }
	void test_case_2() { string Arg0 = "bbbbbb"; string Arr1[] = { "bbbbbb",  "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSubstrings(Arg0)); }
	void test_case_3() { string Arg0 = "aaaaaa"; string Arr1[] = { "",  "aaaaaa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSubstrings(Arg0)); }
	void test_case_4() { string Arg0 = "abjlkbjalkbjaljsbljbalb"; string Arr1[] = { "abjlkbjalkbjaljs",  "bljbalb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSubstrings(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EqualSubstrings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

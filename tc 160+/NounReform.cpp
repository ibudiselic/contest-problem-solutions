#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class NounReform {
	public:
	vector <string> makePlural(vector <string> nouns) {
		vector<string> sol;
		for (int i=0; i<(int)nouns.size(); ++i) {
			const string &s = nouns[i];
			if (string("szx").find(s[s.size()-1])!=string::npos || s.size()>1 && s[s.size()-1]=='h' && string("cs").find(s[s.size()-2])!=string::npos)
				sol.push_back(s + "es");
			else if (s.size()>1 && s[s.size()-1]=='y' && string("aeiou").find(s[s.size()-2])!=string::npos)
				sol.push_back(s + "s");
			else if (s[s.size()-1]=='y')
				sol.push_back(s.substr(0, s.size()-1) + "ies");
			else
				sol.push_back(s + "s");
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"box", "church", "elephant", "stereo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"boxes", "churches", "elephants", "stereos" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makePlural(Arg0)); }
	void test_case_1() { string Arr0[] = {"tray", "key", "enemy", "baby"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"trays", "keys", "enemies", "babies" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makePlural(Arg0)); }
	void test_case_2() { string Arr0[] = {"a", "s", "oy", "y", "yy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"as", "ses", "oys", "ies", "yies" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makePlural(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NounReform ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

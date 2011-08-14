#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class UserName {
	public:
	string str(int x) {
		if (x == 0)
			return "";

		ostringstream os;
		os << x;
		return os.str();
	}
	string newMember(vector <string> ex, string s) {
		int x = 0;

		while (1)
			if (find(ex.begin(), ex.end(), s+str(x)) == ex.end())
				return s+str(x);
			else
				++x;

		return ":cry";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"MasterOfDisaster", "DingBat", "Orpheus", "WolfMan", "MrKnowItAll"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TygerTyger"; string Arg2 = "TygerTyger"; verify_case(0, Arg2, newMember(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus",
 "TygerTyger", "WolfMan", "MrKnowItAll"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TygerTyger"; string Arg2 = "TygerTyger2"; verify_case(1, Arg2, newMember(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"TygerTyger2000", "TygerTyger1", "MasterDisaster", "DingBat",
 "Orpheus", "WolfMan", "MrKnowItAll"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TygerTyger"; string Arg2 = "TygerTyger"; verify_case(2, Arg2, newMember(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"grokster2", "BrownEyedBoy", "Yoop", "BlueEyedGirl",
 "grokster", "Elemental", "NightShade", "Grokster1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "grokster"; string Arg2 = "grokster1"; verify_case(3, Arg2, newMember(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"Bart4", "Bart5", "Bart6", "Bart7", "Bart8", "Bart9", "Bart10",
 "Lisa", "Marge", "Homer", "Bart", "Bart1", "Bart2", "Bart3",
 "Bart11", "Bart12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bart"; string Arg2 = "Bart13"; verify_case(4, Arg2, newMember(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UserName ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool sw(const string &s, const string &t) {
	if (s.size() < t.size())
		return false;
	for (int i=0; i<(int)t.size(); ++i)
		if (s[i] != t[i])
			return false;
	return true;
}
class AzimuthMonitoring {
	public:
	int getAzimuth(vector <string> instructions) {
		int sol = 0;
		for (int i=0; i<(int)instructions.size(); ++i)
			if (instructions[i] == "HALT")
				break;
			else if (instructions[i] == "RIGHT")
				sol += 90;
			else if (instructions[i] == "LEFT")
				sol -= 90;
			else if (instructions[i] == "TURN AROUND")
				sol += 180;
			else if (sw(instructions[i], "LEFT")) {
				int x;
				sscanf(instructions[i].c_str(), "LEFT %d", &x);
				sol -= x;
			} else {
				int x;
				sscanf(instructions[i].c_str(), "RIGHT %d", &x);
				sol += x;
			}

		return (sol + 36000) % 360;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RIGHT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 90; verify_case(0, Arg1, getAzimuth(Arg0)); }
	void test_case_1() { string Arr0[] = {"LEFT", "LEFT", "TURN AROUND"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getAzimuth(Arg0)); }
	void test_case_2() { string Arr0[] = {"LEFT 5", "RIGHT 10", "LEFT 15", "RIGHT 20", "LEFT 25", "RIGHT 30", "LEFT 35", "RIGHT 40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, getAzimuth(Arg0)); }
	void test_case_3() { string Arr0[] = {"RIGHT 59", "RIGHT", "RIGHT", "HALT", "LEFT", "LEFT", "LEFT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 239; verify_case(3, Arg1, getAzimuth(Arg0)); }
	void test_case_4() { string Arr0[] = {"TURN AROUND", "HALT", "LEFT 5", "HALT", "LEFT 5", "HALT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 180; verify_case(4, Arg1, getAzimuth(Arg0)); }
	void test_case_5() { string Arr0[] = {"LEFT", "LEFT", "LEFT", "LEFT", "LEFT", "HALT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 270; verify_case(5, Arg1, getAzimuth(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AzimuthMonitoring ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Team {
	string name;
	int w, p;
	Team(const string &name_, int w_, int p_): name(name_), w(w_), p(p_) {}
};
bool operator<(const Team &a, const Team &b) {
	if (a.w*b.p != a.p*b.w)
		return a.w*b.p > a.p*b.w;
	return a.name < b.name;
}
class ScheduleStrength {
	public:
	vector <string> calculate(vector <string> teams, vector <string> results) {
		vector<Team> v;
		for (int i=0; i<(int)teams.size(); ++i) {
			int w = 0;
			int p = 0;
			for (int j=0; j<(int)teams.size(); ++j)
				if (results[i][j] != '-')
					for (int k=0; k<(int)teams.size(); ++k)
						if (k != i) {
							if (results[j][k] != '-')
								++p;
							if (results[j][k] == 'W')
								++w;
						}

			v.push_back(Team(teams[i], w, p));
		}

		sort(v.begin(), v.end());

		vector<string> sol;
		for (int i=0; i<(int)v.size(); ++i)
			sol.push_back(v[i].name);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"BEARS",
 "GIANTS",
 "COWBOYS",
 "BRONCOS",
 "DOLPHINS",
 "LIONS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-WLWW-",
 "L-WL-W",
 "WL---W",
 "LW--L-",
 "L--W--",
 "-LL---"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"BEARS", "DOLPHINS", "BRONCOS", "COWBOYS", "GIANTS", "LIONS" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, calculate(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BEARS",
 "COWBOYS",
 "GIANTS",
 "PACKERS"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-LLW",
 "W-WW",
 "WL--",
 "LL--"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"GIANTS", "BEARS", "COWBOYS", "PACKERS" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, calculate(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AZTECS",
 "COUGARS",
 "COWBOYS",
 "FALCONS",
 "HORNEDFROGS",
 "LOBOS",
 "RAMS",
 "REBELS",
 "UTES"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"---L-L--W",
 "--LL-LWL-",
 "-W--WWLLW",
 "WW---L--W",
 "--L--W-L-",
 "WWLWL-LW-",
 "-LW--W-L-",
 "-WW-WLW--",
 "L-LL-----"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"HORNEDFROGS", "COUGARS", "RAMS", "LOBOS", "REBELS", "UTES", "COWBOYS", "AZTECS", "FALCONS" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, calculate(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"E", "D", "C", "B", "Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {
"--LLL",
"---LL",
"W---L",
"WW---",
"WWW--"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"D", "E", "C", "Z", "B" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, calculate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ScheduleStrength ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

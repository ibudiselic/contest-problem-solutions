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
int getDiff(const Team &a, const Team &b) {
	if (a.p == b.p)
		return 2*(b.w - a.w);
	else if (a.p > b.p)
		return 2*b.w + (a.p-b.p) - 2*a.w;
	else
		return 2*b.w - (b.p-a.p) - 2*a.w;
}
bool operator<(const Team &a, const Team &b) {
	int diff = getDiff(a, b);

	if (diff != 0)
		return diff < 0;
	else
		return a.name < b.name;
}

class BasketballStandings {
	public:
	vector <string> constructTable(vector <string> teams) {
		vector<Team> v;

		for (int i=0; i<(int)teams.size(); ++i) {
			string s;
			int w, l;
			istringstream is(teams[i]);

			is >> s >> w >> l;
			v.push_back(Team(s, w, w+l));
		}

		sort(v.begin(), v.end());

		vector<string> sol;
		for (int i=0; i<(int)v.size(); ++i) {
			ostringstream os;

			os << v[i].name << ' ';

			int twoDiff = getDiff(v[i], v[0]);

			os << (twoDiff/2) << '.' << (twoDiff%2 == 0 ? 0 : 5);

			sol.push_back(os.str());
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"A 1 1", "A 8 8","D 0 0", "B 7 7", "C 99 99", "BAA 13 13"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A 0.0", "A 0.0", "B 0.0", "BAA 0.0", "C 0.0", "D 0.0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, constructTable(Arg0)); }
	void test_case_1() { string Arr0[] = {"B 11 10", "A 10 10", "C 10 11", "D 20 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"D 0.0", "B 7.0", "A 7.5", "C 8.0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, constructTable(Arg0)); }
	void test_case_2() { string Arr0[] = {"MAVS 54 11", "SUNS 50 16", "SPURS 46 20", "JAZZ 43 23"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"MAVS 0.0", "SUNS 4.5", "SPURS 8.5", "JAZZ 11.5" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, constructTable(Arg0)); }
	void test_case_3() { string Arr0[] = {"TEAMA 17 15", "TEAMB 14 11", "TEAMC 3 0",
 "TEAMD 99 94", "LOSER 10 85", "WINNER 76 34"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WINNER 0.0", "TEAMD 18.5", "TEAMB 19.5", "TEAMC 19.5", "TEAMA 20.0", "LOSER 58.5" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, constructTable(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BasketballStandings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

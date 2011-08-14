#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
typedef unsigned long long ull;

struct Rule {
	string name;
	ull comb;
};
bool operator<(const Rule &a, const Rule &b) {
	if (a.comb != b.comb)
		return a.comb < b.comb;
	else return a.name < b.name;
}

class Lottery {
	public:
	vector <string> sortByOdds(vector <string> rules) {
		vector<Rule> a(rules.size());

		for (int i=0; i<(int)rules.size(); ++i) {
			string t;
			int j;
			for (j=0; j<(int)rules[i].size() && rules[i][j] != ':'; ++j)
				a[i].name += rules[i][j];
			int choice = 0;
			int blank = 0;
			for (j+=2; j<(int)rules[i].size() && isdigit(rules[i][j]); ++j)
				choice = choice*10 + rules[i][j]-'0';
			for (++j; j<(int)rules[i].size() && isdigit(rules[i][j]); ++j)
				blank = blank*10 + rules[i][j]-'0';
			bool sorted, unique;
			sorted = (rules[i][j+1]=='T');
			unique = (rules[i][j+3]=='T');
			a[i].comb = 0;
			if (sorted) {
				if (unique) {
					ull x = 1;
					ull y = 1;
					for (int t=0; t<blank; ++t) {
						x *= choice-t;
						y *= t+1;
					}
					a[i].comb = x/y;
				} else {
					choice += blank-1;
					ull x = 1;
					ull y = 1;
					for (int t=0; t<blank; ++t) {
						x *= choice-t;
						y *= t+1;
					}
					a[i].comb = x/y;
				}
			} else {
				if (unique) {
					a[i].comb = 1;
					for (int t=0; t<blank; ++t)
						a[i].comb *= choice-t;
				} else {
					a[i].comb = 1;
					for (int t=0; t<blank; ++t)
						a[i].comb *= choice;
				}
			}
		}
		sort(a.begin(), a.end());
		vector<string> sol;
		for (int i=0; i<(int)a.size(); ++i)
			sol.push_back(a[i].name);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortByOdds(Arg0)); }
	void test_case_1() { string Arr0[] = {"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortByOdds(Arg0)); }
	void test_case_2() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortByOdds(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Lottery ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

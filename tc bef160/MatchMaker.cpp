#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct member {
	string name;
	int sf;
	bool gend, want;
	member() {
		sf = 0;
	}
};
bool operator<(const member &a, const member &b) {
	return a.sf < b.sf;
}

class MatchMaker {
	public:
	vector <string> getBestMatches(vector <string> memb, string who, int sf) {
		vector<member> match;
		int a[50][10];
		int x;
		int n;

		for (int i=0; i<(int)memb.size(); ++i) {
			istringstream is(memb[i]);
			string t;
			is >> match[i].name;
			if (match[i].name == who)
				x = i;
			is >> t;
			match[i].gend = t[0]=='M';
			is >> t;
			match[i].want = t[0]=='M';
			for (n=0; is >> t; ++n)
				a[i][n] = t[0];
		}
		vector<member> sol;
		for (int i=0; i<(int)memb.size(); ++i)
			if (i!=x) {
				int cnt = 0;
				for (int j=0; j<n; ++j)
					if (a[i][j]==a[x][j])
						++cnt;
				if (cnt >= sf) {
					match[i].sf = cnt;
					sol.push_back(match[i]);
				}
			}
		stable_sort(sol.begin(), sol.end());
		vector<string> ret;
		for (int i=0; i<(int)sol.size(); ++i)
			ret.push_back(sol[i].name);
		return ret;
	}








   // *** WARNING *** No test cases defined for this problem
};

// BEGIN CUT HERE
int main()
    {
    MatchMaker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

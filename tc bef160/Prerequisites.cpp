#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

struct predmet {
	string dep;
	int num;
	predmet() {
		num = 0;
	}
};
bool operator<(const predmet &a, const predmet &b) {
	if (a.num != b.num)
		return a.num < b.num;
	else return a.dep < b.dep;
}
bool preq[20][20];
predmet a[21];
map<predmet, int> m;
int n;

class Prerequisites {
	public:
	vector <string> orderClasses(vector <string> vs) {
		n = (int)vs.size();
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				preq[i][j] = false;

		m.clear();
		for (int i=0; i<n; ++i) {
			int j;
			for (j=0; j<(int)vs[i].size() && isalpha(vs[i][j]); ++j)
				a[i].dep += vs[i][j];
			for (; j<(int)vs[i].size() && isdigit(vs[i][j]); ++j)
				a[i].num = a[i].num*10 + vs[i][j]-'0';
			m[a[i]] = i;
		}
		for (int i=0; i<n; ++i) {
			string t;
			istringstream is(vs[i]);
			is >> t;
			while (is >> t) {
				predmet x;
				int j;
				for (j=0; j<(int)t.size() && isalpha(t[j]); ++j)
					x.dep += t[j];
				for (; j<(int)t.size(); ++j)
					x.num = x.num*10 + t[j]-'0';
				if (m.count(x) == 0) return vector<string>();
				preq[i][m[x]] = true;
			}
		}
		int cnt = 0;
		vector<string> sol;
		vector<bool> used(n, false);
		a[20].num = 1000000;
		a[20].dep = "dummy";
		for (;;) {
			int next = 20;
			for (int i=0; i<n; ++i) {
				if (used[i]) continue;
				bool can_do = true;
				for (int j=0; j<n; ++j)
					if (!used[j] && preq[i][j]) {
						can_do = false;
						break;
					}
				if (can_do && a[i]<a[next])
					next = i;
			}
			if (next == 20)
				break;
			used[next] = true;
			sol.push_back(vs[next].substr(0, vs[next].find(':')));
			++cnt;
		}
		if (cnt < n)
			return vector<string>();
		else return sol;
	}







   // *** WARNING *** No test cases defined for this problem
};

// BEGIN CUT HERE
int main()
    {
    Prerequisites ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

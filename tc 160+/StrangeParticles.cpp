#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<bool> > a;
int n;
int cur;
int color[50];
bool is_root[50];
void dfs(int x) {
	color[x] = cur;
	for (int i=0; i<n; ++i)
		if (color[i]==0 && a[x][i] && a[i][x])
			dfs(i);
}
class StrangeParticles {
	public:
	int remain(vector <string> interacts) {
		n = interacts.size();
		a.assign(n, vector<bool>(n, false));
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				a[i][j] = (interacts[i][j]=='-');
		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
				for (int j=0; j<n; ++j)
					a[i][j] = a[i][j] || a[i][k]&&a[k][j];
		memset(color, 0, sizeof color);
		cur = 0;
		for (int i=0; i<n; ++i)
			if (color[i] == 0) {
				++cur;
				dfs(i);
			}

		memset(is_root, 1, sizeof is_root);
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (interacts[i][j]=='+' && color[i]!=color[j])
					is_root[color[i]-1] = 0;

		int sol = 0;
		for (int i=0; i<cur; ++i)
			sol += is_root[i];
		return sol;
	}







// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0+-","-0+","+-0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, remain(Arg0)); }
	void test_case_1() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, remain(Arg0)); }
	void test_case_2() { string Arr0[] = {"0++++++++++++++",
 "-0+++++++++++++",
 "--0++++++++++++",
 "---0+++++++++++",
 "----0++++++++++",
 "-----0+++++++++",
 "------0++++++++",
 "-------0+++++++",
 "--------0++++++",
 "---------0+++++",
 "----------0++++",
 "-----------0+++",
 "------------0++",
 "-------------0+",
 "--------------0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, remain(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StrangeParticles ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

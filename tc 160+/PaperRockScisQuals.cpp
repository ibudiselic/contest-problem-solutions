#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

typedef pair<int, int> player;

class PaperRockScisQuals {
	public:
	int whoPassed(vector <string> players) {
		vector<player> a;
		const int n = players.size();
		for (int i=0; i<n; ++i)
			a.push_back(player(0, i));
		for (int i=0; i<n-1; ++i)
			for (int j=i+1; j<n; ++j) {
				int x=0, y=0;
				for (int k=0; k<5; ++k)
					if (players[i][k] == 'R') {
						if (players[j][k] == 'S')
							x += 2;
						else if (players[j][k] == 'P')
							y += 2;
						else {
							++x;
							++y;
						}
					} else if (players[i][k] == 'S') {
						if (players[j][k] == 'P')
							x += 2;
						else if (players[j][k] == 'R')
							y += 2;
						else {
							++x;
							++y;
						}
					} else {
						if (players[j][k] == 'R')
							x += 2;
						else if (players[j][k] == 'S')
							y += 2;
						else {
							++x;
							++y;
						}
					}
				if (x > y)
					a[i].first -= 2;
				else if (x < y)
					a[j].first -= 2;
				else {
					--a[i].first;
					--a[j].first;
				}
			}
		sort(a.begin(), a.end());
		return a[0].second;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"PPRRS","PPRRP","PPRSP","PPSSP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, whoPassed(Arg0)); }
	void test_case_1() { string Arr0[] = {"RRRRR","PPPPP","RRRRR","PPPPP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, whoPassed(Arg0)); }
	void test_case_2() { string Arr0[] = {"RRRRR","PPPPP","SSSSS","PPPPP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, whoPassed(Arg0)); }
	void test_case_3() { string Arr0[] = {"RRRRR","PPPPP","SSSSS","SSSSS","RRRRR","RRRRR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, whoPassed(Arg0)); }
	void test_case_4() { string Arr0[] = {"PPRPS","RRRPR","SSPRS","SSPRR","PPRSP","SPRPS","SPRSP","PRSPR","PRSPR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, whoPassed(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PaperRockScisQuals ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

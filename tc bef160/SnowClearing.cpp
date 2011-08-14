#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*** real code starts here ***/

int n, m;
int dr[] = { 0, 1, 0, -1 };
int dc[] = { -1, 0, 1, 0 };
queue<pair<int, int> > q;

class SnowClearing {
	public:
	bool inbounds(int i, int j) {
		return (i>=0 && i<n && j>=0 && j<m);
	}
	int deg(vector<string> &m, int r, int c) {
		int cnt = 0;
		
		for (int i=0; i<4; ++i)
			if (inbounds(r+dr[i], c+dc[i]) && (m[r+dr[i]][c+dc[i]]=='-' || m[r+dr[i]][c+dc[i]]=='|'))
				++cnt;
		return cnt;
	}
	int unreachable(vector <string> map, int r, int c) {
		int sol = 0;
		
		n = (int)map.size();
		m = (int)map[0].size();
		vector<vector<int> > cnt(n, vector<int>(m, 0));
		r = (r-1)*2;
		c = (c-1)*2;
		
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j) {
				if (i==r && j==c)
					cnt[i][j] = 0;
				else if (map[i][j]=='+')
					cnt[i][j] = deg(map, i, j);
				if (cnt[i][j]==1) {
					q.push(make_pair(i, j));
					++sol;
				}
			}
		while (!q.empty()) {
			int k, x, y;
			int row, col;
			
			row = q.front().first;
			col = q.front().second;
			q.pop();
			k = x = y = 0;
			for (int i=0; i<4; ++i)
				if (inbounds(row+dr[i], col+dc[i]) && (map[row+dr[i]][col+dc[i]]=='-' || map[row+dr[i]][col+dc[i]]=='|') && cnt[row+2*dr[i]][col+2*dc[i]]>1) {
					++k;
					x = row+2*dr[i], y = col+2*dc[i];
				}
			if (k==1) {
				if (--cnt[x][y] == 1) {
					q.push(make_pair(x, y));
					++sol;
				}
			}
		}
		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"+-+-+-+-+-+-+"
,"| | | | | | |"
,"+-+ +-+ +-+ +"
,"|   |   |    "
,"+-+-+-+-+-+-+"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 7; int Arg3 = 2; verify_case(0, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"+-+"
,"| |"
,"+ +"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"+-+-+"
,"| | |"
,"+-+ +"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; int Arg3 = 1; verify_case(2, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"+-+-+"
,"|   |"
,"+-+-+"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; verify_case(3, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"+ +-+ +-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+-+ +-+-+-+ +"
,"| |   | |     |   |   |         |     | |     | |"
,"+ +-+-+-+ +-+-+-+ +-+ +-+-+-+-+ +-+-+-+ +-+ +-+-+"
,"| | |       |   | |   |   |   |   |     | |   |  "
,"+ +-+-+ +-+-+ +-+-+-+-+-+-+-+ +-+ +-+ +-+ +-+ +-+"
,"|     | | | | |   |             |     |   | |   |"
,"+-+-+ +-+-+-+ +-+ +-+ + +-+-+-+-+-+ +-+-+ +-+-+-+"
,"|       | |     |     |   |         |   | |     |"
,"+-+-+-+ +-+-+-+-+-+-+-+-+-+-+ +-+ +-+ +-+-+-+-+-+"
,"      |   | |     |   | |     | | |   | |       |"
,"+ +-+-+-+-+ + +-+ +-+ +-+ +-+-+ +-+-+-+-+-+ +-+-+"
,"| |   | |     |   |         |   | | |     |   | |"
,"+-+-+-+-+-+ +-+-+ +-+-+-+ +-+-+ +-+-+ +-+-+ +-+-+"
,"          |   |   |   |   | |                    "
,"+-+-+-+-+-+-+ +-+-+-+ + +-+-+ +-+ +-+-+-+ +-+-+ +"
,"|                     | |     |   |   | |   | | |"
,"+ +-+-+-+-+-+-+ + +-+-+-+-+-+-+-+-+ +-+-+-+ + +-+"
,"| |     |   | | |   | | | |       | |   | | | | |"
,"+-+-+-+ +-+-+-+-+ +-+ + +-+ +-+-+-+ +-+-+ +-+ +-+"
,"    | |   | | |   |               |   |          "
,"+-+ +-+-+-+-+-+ +-+ + +-+-+-+-+-+-+ + + +-+-+ +-+"
,"  | | |         | | | |   |   | | | | | | | | |  "
,"+-+-+ + +-+ +-+ +-+-+-+-+ + + + +-+-+ +-+-+-+-+-+"
,"    | | | | | | |         | | |       |     | |  "
,"+ +-+ + + +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+"
,"| |   | |     | |   |   |   |   |   | |         |"
,"+-+-+ +-+-+-+-+ +-+ + +-+-+-+-+ +-+ +-+-+-+-+-+-+"
,"      | |   | | | |     |       | |         | |  "
,"+-+ + +-+-+-+-+ + +-+-+-+ +-+-+-+-+ +-+ +-+-+-+-+"
,"  | | | |   |   |     | |   |   | |   | | |   |  "
,"+-+-+-+-+-+-+ +-+-+-+-+-+-+ +-+ +-+ +-+ +-+-+ +-+"
,"|     | | |   |     |     |   | | |   |   | | | |"
,"+-+-+-+-+-+-+ + +-+-+-+-+-+ +-+-+-+-+ +-+ + +-+-+"
,"| | | | |   | | |   | |         |     | | | |   |"
,"+ +-+ +-+-+ + + +-+-+ + + +-+-+-+-+ +-+ +-+-+-+-+"
,"  | | |   |     | |     |         |   | |   | | |"
,"+ +-+ +-+-+-+ +-+-+-+-+ +-+-+-+ +-+-+-+ +-+-+ + +"
,"|     | |     |   |           |   | | |   | | |  "
,"+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+ +-+-+ +-+-+ +-+"
,"|         |     |       | |   |       | | | | |  "
,"+-+-+-+ +-+-+-+-+-+-+-+-+ +-+ +-+ +-+-+ +-+-+-+-+"
,"        |   |   | | | | | | | | | | | | | |     |"
,"+-+-+-+-+-+-+-+ +-+-+ +-+-+ +-+-+-+ +-+ + +-+-+ +"
,"      | | | |       | |     | |   |       |   | |"
,"+ +-+-+-+-+-+ +-+ +-+ +-+-+-+ +-+-+-+-+-+ + +-+-+"
,"| | |       | | | |       |     | | | |       | |"
,"+-+-+-+-+-+-+-+ + +-+-+-+ + +-+-+-+-+-+-+-+ +-+ +"
,"      |   |   | |   | |         |     | | | | | |"
,"+-+-+-+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+ + + +-+-+ +"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 12; int Arg3 = 160; verify_case(4, Arg3, unreachable(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SnowClearing ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

bool done[50][50];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

bool valid(int i, int j, int m, int n) {
	if (i<0 || j<0 || i>=m || j>=n)
		return false;
	return true;
}
class WalkingHome {
	public:
	int fewestCrossings(vector <string> map) {
		memset(done, 0, sizeof done);
		int m = map.size();
		int n = map[0].size();

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (map[i][j] == 'S') {
					deque<pair<int, int> > Q;
					deque<int> dist;
					Q.push_back(make_pair(i, j));
					dist.push_back(0);
					done[i][j] = 1;
					int cross = 1234567890;
					while (!Q.empty()) {
						i = Q.front().first;
						j = Q.front().second;
						Q.pop_front();
						int cost = dist.front();
						dist.pop_front();
						if (cost >= cross)
							return cross;
						done[i][j] = 1;

						for (int d=0; d<4; ++d) {
							const int r = i + di[d];
							const int c = j + dj[d];

							if (valid(r, c, m, n)) {
								if (map[r][c] == 'H')
									return cost;
								if (map[r][c] == 'F')
									continue;
								if (map[r][c] == '.') {
									if (!done[r][c]) {
										Q.push_front(make_pair(r, c));
										dist.push_front(cost);
										done[r][c] = 1;
									}
								} else {
									int cnt = 1;
									while (valid(i+cnt*di[d], j+cnt*dj[d], m, n) && map[i+cnt*di[d]][j+cnt*dj[d]]==(d%2==1 ? '|':'-'))
										++cnt;
									if (valid(i+cnt*di[d], j+cnt*dj[d], m, n) && map[i+cnt*di[d]][j+cnt*dj[d]]=='H') {
										cross = min(cross, cost+1);
									} else if (valid(i+cnt*di[d], j+cnt*dj[d], m, n) && map[i+cnt*di[d]][j+cnt*dj[d]]=='.' && !done[i+cnt*di[d]][j+cnt*dj[d]]) {
										Q.push_back(make_pair(i+cnt*di[d], j+cnt*dj[d]));
										dist.push_back(cost+1);
									}
								}
							}
						}
					}
					return cross<1234567890 ? cross:-1;
				}
		return -123;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"S.|..",
 "..|.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, fewestCrossings(Arg0)); }
	void test_case_1() { string Arr0[] = {"S.|..",
 "..|.H",
 "..|..",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, fewestCrossings(Arg0)); }
	void test_case_2() { string Arr0[] = {"S.||...",
 "..||...",
 "..||...",
 "..||..H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, fewestCrossings(Arg0)); }
	void test_case_3() { string Arr0[] = {"S.....",
 "---*--",
 "...|..",
 "...|.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, fewestCrossings(Arg0)); }
	void test_case_4() { string Arr0[] = {"S.F..",
 "..F..",
 "--*--",
 "..|..",
 "..|.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, fewestCrossings(Arg0)); }
	void test_case_5() { string Arr0[] = {"H|.|.|.|.|.|.|.|.|.|.|.|.|.",
 "F|F|F|F|F|F|F|F|F|F|F|F|F|-",
 "S|.|.|.|.|.|.|.|.|.|.|.|.|."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(5, Arg1, fewestCrossings(Arg0)); }
	void test_case_6() { string Arr0[] = {"S-H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, fewestCrossings(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WalkingHome ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

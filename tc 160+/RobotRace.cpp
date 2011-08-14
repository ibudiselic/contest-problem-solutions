#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <queue>

using namespace std;

vector<string> B;
int M, N;
int dist[26][26]; // robot to token
int match[26]; // robot to token
int rmatch[26]; // token to robot
string pref[26];
int prefInd[26]; // next token to try

const int INF = 1234567890;
vector<int> robots;
vector<int> tokens;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
bool done[50][50][4];
bool valid(int i, int j) {
	if (i<0 || j<0 || i>=M || j>=N)
		return false;
	return true;
}
string toStr(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
struct State {
	int i, j, d;
	State(int i_, int j_, int d_): i(i_), j(j_), d(d_) {}
};
void bfs(int robotInd, int i, int j) { // discontinue movement once you are on a token!
	memset(done, 0, sizeof done);
	queue<State> Q;

	for (int d=0; d<4; ++d) {
		done[i][j][d] = 1;
		Q.push(State(i, j, d));
	}
	int t = 0;
	int len = -1;
	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++len;
		}
		--t;
		i = Q.front().i;
		j = Q.front().j;
		int d = Q.front().d;
		Q.pop();

		if (isupper(B[i][j])) {
			dist[robotInd][B[i][j]-'A'] = min(dist[robotInd][B[i][j]-'A'], len);
			continue;
		}

		int r = i + di[d];
		int c = j + dj[d];
		if (valid(r, c) && B[r][c]!='*' && !done[r][c][d]) {
			done[r][c][d] = 1;
			Q.push(State(r, c, d));
		}

		d = (d+1)%4;
		if (valid(i, j) && !done[i][j][d]) {
			done[i][j][d] = 1;
			Q.push(State(i, j, d));
		}

		d = (d+2)%4;
		if (valid(i, j) && !done[i][j][d]) {
			done[i][j][d] = 1;
			Q.push(State(i, j, d));
		}
	}
}

class RobotRace {
	public:
	vector <string> getPrizes(vector <string> board, vector <string> tokenValues) {
		B = board;
		M = B.size();
		N = B[0].size();

		// determine distances for all robots to all tokens (bfs)
		// INF if not reachable
		robots.clear();
		tokens.clear();
		for (int i=0; i<26; ++i)
			for (int j=0; j<26; ++j)
				dist[i][j] = INF;

		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				if (islower(B[i][j])) {
					robots.push_back(B[i][j]-'a');
					bfs(B[i][j]-'a', i, j);
				} else if (isupper(B[i][j])) {
					tokens.push_back(B[i][j]-'A');
				}

		// stable match robots and reachable and valuable tokens
		memset(match, 0xff, sizeof match);
		memset(rmatch, 0xff, sizeof rmatch);
		for (int i=0; i<26; ++i)
			pref[i].clear();

		for (int i=0; i<(int)tokenValues.size(); ++i)
			pref[tokenValues[i][0]-'a'] = tokenValues[i].substr(2);
		memset(prefInd, 0, sizeof prefInd);

		sort(robots.begin(), robots.end());
		queue<int> R;
		for (int i=0; i<(int)robots.size(); ++i)
			R.push(robots[i]);

		while (!R.empty()) {
			int x = R.front();
			R.pop();
			assert(match[x] == -1);

			while (prefInd[x] < (int)pref[x].size()) {
				int y = pref[x][prefInd[x]++]-'A';
				if (dist[x][y] == INF)
					continue;

				if (rmatch[y] == -1) {
					match[x] = y;
					rmatch[y] = x;
					break;
				} else if (dist[x][y]<dist[rmatch[y]][y] || (dist[x][y]==dist[rmatch[y]][y] && x<rmatch[y])) {
					match[x] = y;
					match[rmatch[y]] = -1;
					R.push(rmatch[y]);
					rmatch[y] = x;
					break;
				}
			}
		}

		vector<string> sol;
		for (int i=0; i<(int)robots.size(); ++i)
			sol.push_back(char(robots[i]+'a') + string(" ") + toStr(match[robots[i]]==-1 ? 20 : 100-prefInd[robots[i]]+1));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"b C"
,"a D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:CD", "b:DC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 100", "b 100" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"b Cx"
,"a D "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:CD", "b:DC", "x:C"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 99", "b 20", "x 100" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"b C x"
,"a D  "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:CD", "b:DC", "x:C"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 99", "b 99", "x 20" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"w     x"
,"  A*B  "
," H   C "
," * Q * "
," G   D "
,"  F*E  "
,"y     z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"z:Q", "y:Q", "x:Q", "w:Q"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"w 20", "x 20", "y 20", "z 20" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"a*  "
," X b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:X","b:X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 20", "b 100" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getPrizes(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"  bY a"
,"X c  Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a:XYZ"
,"b:XYZ"
,"c:YXZ"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a 98", "b 99", "c 99" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, getPrizes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RobotRace ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

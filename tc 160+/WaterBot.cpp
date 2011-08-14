#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <set>
#include <queue>
#include <cctype>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
bool done[50][50];
int dp[21][6][6][6][6][6];

bool valid(int i, int j, int m, int n) {
	return i>=0 && i<m && j>=0 && j<n;
}
int bfs(int si, int sj, int ti, int tj, const vector<string> &garden) { // points must be distinct, i.e. the distance is always positive! (>0)
	queue< pair<int, int> > Q;
	memset(done, 0, sizeof done);

	done[si][sj] = 1;
	Q.push(make_pair(si, sj));

	int dist = -1;
	int sz = 0;

	while (!Q.empty()) {
		if (sz == 0) {
			++dist;
			sz = Q.size();
		}

		const int i = Q.front().first;
		const int j = Q.front().second;
		Q.pop();

		--sz;

		for (int d=0; d<4; ++d) {
			const int r = i + di[d];
			const int c = j + dj[d];

			if (valid(r, c, garden.size(), garden[0].size()) && garden[r][c]=='.' && !done[r][c]) {
				if (r==ti && c==tj)
					return dist+1;
				done[r][c] = 1;
				Q.push(make_pair(r, c));
			}
		}
	}

	return 0;
}

void dpSet(const vector<int> &state, int x) {
	dp[state[2]][state[3]][state[4]][state[5]][state[6]][state[7]] = x;
}
int &dpGet(const vector<int> &state) {
	return dp[state[2]][state[3]][state[4]][state[5]][state[6]][state[7]];
}

class WaterBot {
	public:
	int minTime(vector <string> garden, int carryLimit) {
		set< pair<int, int> > keyPoints_;
		vector<int> state(4, 0); // sum, -cost, keyPoint index, carry, plant1, plant2, plant3, plant4
		int m, n;
		m = garden.size();
		n = garden[0].size();

		int Ri=0, Rj=0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j) {
				if (garden[i][j] == 'R') {
					keyPoints_.insert(make_pair(i, j));
					Ri = i; Rj = j;
					garden[i][j] = '.';
				} else if (garden[i][j] != '.') {
					for (int d=0; d<4; ++d) {
						const int r = i + di[d];
						const int c = j + dj[d];
						if (valid(r, c, m, n) && garden[r][c]!='W' && garden[r][c]>10 && !isdigit(garden[r][c]))
							keyPoints_.insert(make_pair(r, c));
					}
				}

				if (isdigit(garden[i][j])) {
					state.push_back(garden[i][j]-'0');
					state[0] += state.back();
					garden[i][j] = state.size()-1;
				}
			}

		while (state.size() < 8)
			state.push_back(0);

		vector< pair<int, int> > keyPoints(keyPoints_.begin(), keyPoints_.end());
		for (int i=0; i<(int)keyPoints.size(); ++i)
			if (Ri==keyPoints[i].first && Rj==keyPoints[i].second) {
				state[2] = i;
				break;
			}

		vector< vector<int> > dist(keyPoints.size(), vector<int> (keyPoints.size(), 0)); // 0 means unreachable

		for (int i=0; i<(int)keyPoints.size(); ++i)
			for (int j=i+1; j<(int)keyPoints.size(); ++j)
				dist[i][j] = dist[j][i] = bfs(keyPoints[i].first, keyPoints[i].second, keyPoints[j].first, keyPoints[j].second, garden);

		/*for (int i=0; i<(int)keyPoints.size(); ++i)
			cerr << keyPoints[i].first << ' ' << keyPoints[i].second << '\n';

		for (int i=0; i<(int)keyPoints.size(); ++i) {
			for (int j=0; j<(int)keyPoints.size(); ++j)
				cerr << dist[i][j] << ' ';
			cerr << '\n';
		}*/

		vector< vector<int> > adjPlants(keyPoints.size(), vector<int>());
		vector<bool> adjWell(keyPoints.size(), 0);

		for (int i=0; i<(int)keyPoints.size(); ++i)
			for (int d=0; d<4; ++d) {
				const int r = keyPoints[i].first + di[d];
				const int c = keyPoints[i].second + dj[d];

				if (valid(r, c, m, n)) {
					if (garden[r][c] == 'W')
						adjWell[i] = 1;
					if (garden[r][c] < 10)
						adjPlants[i].push_back(garden[r][c]);
				}
			}

		/*for (int i=0; i<(int)adjPlants.size(); ++i) {
			for (int j=0; j<(int)adjPlants[i].size(); ++j)
				cerr << adjPlants[i][j] << ' ';
			cerr << adjWell[i] << '\n';
		}*/

		for (int a=0; a<21; ++a)
			for (int b=0; b<6; ++b)
				for (int c=0; c<6; ++c)
					for (int d=0; d<6; ++d)
						for (int e=0; e<6; ++e)
							for (int f=0; f<6; ++f)
								dp[a][b][c][d][e][f] = 1234567890;

		if (state[0] == 0) // no water needed
			return 0;

		dpSet(state, 0);
		priority_queue< vector<int> > Q;
		Q.push(state);

		while (!Q.empty()) {
			state = Q.top();
			int cost = -state[1];
			int pos = state[2];
			int carry = state[3];
			Q.pop();

			if (dpGet(state) < cost)
				continue;

			// move somewhere
			for (int npos=0; npos<(int)keyPoints.size(); ++npos)
				if (dist[pos][npos] > 0) {
					vector<int> t = state;
					t[1] -= dist[pos][npos];
					t[2] = npos;
					if (cost+dist[pos][npos] < dpGet(t)) {
						dpSet(t, cost+dist[pos][npos]);
						Q.push(t);
					}
				}

			// if you are at the well you can fill up if you can carry more water
			if (adjWell[pos] && carry<carryLimit) {
				vector<int> t = state;
				--t[1];
				++t[3];
				if (cost+1 < dpGet(t)) {
					dpSet(t, cost+1);
					Q.push(t);
				}
			}

			// water some adjacent plant if you have water and it needs watering
			if (carry > 0) {
				vector<int> t = state;
				--t[0];
				--t[1];
				--t[3];
				for (int i=0; i<(int)adjPlants[pos].size(); ++i) {
					const int x = adjPlants[pos][i];
					if (t[x] > 0) { // needs water
						--t[x];
						if (t[0] == 0)
							return cost+1;
						if (cost+1 < dpGet(t)) {
							dpSet(t, cost+1);
							Q.push(t);
						}
						++t[x];
					}
				}
			}
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"5....",
 ".....",
 ".....",
 ".....",
 "...RW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 16; verify_case(0, Arg2, minTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"3.2..",
 ".....",
 ".....",
 "....R",
 "....W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 16; verify_case(1, Arg2, minTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".5555",
 ".....",
 ".....",
 "....R",
 "....W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 85; verify_case(2, Arg2, minTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"R.....55",
 "......55",
 "........",
 "........",
 "........",
 ".......W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = -1; verify_case(3, Arg2, minTime(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"R.......",
 "........",
 "....5...",
 "...5W5..",
 "....5...",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = -1; verify_case(4, Arg2, minTime(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".1",
 ".2",
 ".3",
 ".4",
 "R.",
 "W."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 28; verify_case(5, Arg2, minTime(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"R....",
 ".....",
 ".....",
 ".....",
 "....W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 0; verify_case(6, Arg2, minTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WaterBot ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int G[50][50];
int minDist[50][54];
int N;

struct State {
	State(int d_, int i_, int p_): dist(d_), interval(i_), pos(p_) {}
	int dist, interval, pos;
};
bool operator<(const State &a, const State &b) {
	if (a.dist != b.dist)
		return a.dist > b.dist;
	else if (a.interval != b.interval)
		return a.interval < b.interval;
	else
		return a.pos < b.pos;
}

int bfs(int pos, int intSz) {
	for (int i=0; i<N; ++i)
		for (int j=0; j<54; ++j)
			minDist[i][j] = 1234567890;

	priority_queue<State> PQ;
	PQ.push(State(0, intSz, pos));
	minDist[pos][intSz] = 0;

	while (!PQ.empty()) {
		int d = PQ.top().dist;
		intSz = PQ.top().interval;
		pos = PQ.top().pos;

		PQ.pop();

		if (pos == 1)
			return d;

		if (d > minDist[pos][intSz])
			continue;

		for (int i=0; i<N; ++i)
			if (G[pos][i]>0 && G[pos][i]<=intSz) {
				if (d+G[pos][i] < minDist[i][G[pos][i]]) {
					minDist[i][G[pos][i]] = d+G[pos][i];
					PQ.push(State(d+G[pos][i], G[pos][i], i));
				}
			}
	}

	return -1;
}
class FamilyTravel {
	public:
	int shortest(vector <string> edges) {
		N = edges.size();

		for (int i=0; i<N; ++i) {
			G[i][i] = 0;
			for (int j=i+1; j<N; ++j)
				if (edges[i][j] == '0')
					G[i][j] = G[j][i] = 0;
				else if (edges[i][j] >= 'a')
					G[i][j] = G[j][i] = edges[i][j]-'a'+1;
				else
					G[i][j] = G[j][i] = edges[i][j]-'A'+27;
		}

		return bfs(0, 53);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0ze","z0c","ec0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, shortest(Arg0)); }
	void test_case_1() { string Arr0[] = {"0zc","z0e","ce0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(1, Arg1, shortest(Arg0)); }
	void test_case_2() { string Arr0[] = {"0Zej0","Z0fkh","ef00d","jk00i","0hdi0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(2, Arg1, shortest(Arg0)); }
	void test_case_3() { string Arr0[] = {"00z00","0000a","z00bb","00b0b","0abb0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 29; verify_case(3, Arg1, shortest(Arg0)); }
	void test_case_4() { string Arr0[] = {"000a", "00a0", "0a0a", "a0a0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, shortest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FamilyTravel ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

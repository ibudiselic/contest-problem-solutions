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
#include <cmath>

using namespace std;

bool done[50][50][99];
int Ti, Tj, S, D;
bool valid(int i, int j) {
	return i>=0 && j>=0 && i<50 && j<50 && (i!=Ti || j!=Tj);
}
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

int sqr(int x) { return x*x; }
double dist(int x1, int y1, int x2, int y2) {
	return sqrt(sqr(x1-x2) + sqr(y1-y2));
}
bool visible(int i, int j, int t) {
	if (dist(i, j, Ti, Tj) > D+1e-9)
		return false;
	double a = (t%S) * 360.0 / S;
	double b = a + 360.0 / S;
	double c = atan2(i-Ti, j-Tj) * 180/M_PI;

	return (a-1e-9 <= c && c <= b+1e-9) || (a-1e-9 <= c+360 && c+360 <= b+1e-9);
}
int bfs(int i, int j, int ti, int tj) {
	queue< pair<int, int> > Q;
	Q.push(make_pair(i, j));
	done[i][j][0] = 1;
	int time = -1;
	int t = 0;
	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++time;
		}
		--t;

		i = Q.front().first;
		j = Q.front().second;
		Q.pop();

		if (visible(i, j, time))
			continue;

		if (i==ti && j==tj)
			return time;

		for (int d=0; d<4; ++d) {
			int r = i + di[d];
			int c = j + dj[d];
			if (valid(r, c) && !done[r][c][(time+1)%S]) {
				done[r][c][(time+1)%S] = 1;
				Q.push(make_pair(r, c));
			}
		}
	}

	return -1;
}

class WatchtowerSpotlight {
	public:
	int quickestEscape(string start, string end, string watchtower) {
		int i, j, ti, tj;
		sscanf(start.c_str(), "%d %d", &j, &i);
		sscanf(end.c_str(), "%d %d", &tj, &ti);
		sscanf(watchtower.c_str(), "%d %d %d %d", &Tj, &Ti, &S, &D);
		memset(done, 0, sizeof done);

		return bfs(i, j, ti, tj);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0 0"; string Arg1 = "10 10"; string Arg2 = "7 3 10 5"; int Arg3 = 20; verify_case(0, Arg3, quickestEscape(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "0 0"; string Arg1 = "10 10"; string Arg2 = "3 7 9 4"; int Arg3 = 20; verify_case(1, Arg3, quickestEscape(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "0 0"; string Arg1 = "10 10"; string Arg2 = "9 9 3 5"; int Arg3 = 32; verify_case(2, Arg3, quickestEscape(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "0 0"; string Arg1 = "49 49"; string Arg2 = "24 24 5 40"; int Arg3 = -1; verify_case(3, Arg3, quickestEscape(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "0 0"; string Arg1 = "26 26"; string Arg2 = "24 24 20 30"; int Arg3 = 52; verify_case(4, Arg3, quickestEscape(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "10 13"; string Arg1 = "10 11"; string Arg2 = "5 10 70 6"; int Arg3 = 4; verify_case(5, Arg3, quickestEscape(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "20 20"; string Arg1 = "21 20" ; string Arg2 = "0 0 4 50"; int Arg3 = -1; verify_case(6, Arg3, quickestEscape(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arg0 = "0 0"; string Arg1 = "0 1"; string Arg2 = "0 1 99 10"; int Arg3 = -1; verify_case(7, Arg3, quickestEscape(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WatchtowerSpotlight ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

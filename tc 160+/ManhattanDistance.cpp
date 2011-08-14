#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

inline double sqr(double x) {
	return x*x;
}

struct State {
	int i, j, m;
	double d;
	State(int i_, int j_, int m_, double d_): i(i_), j(j_), m(m_), d(d_) {}
};
bool operator<(const State &a, const State &b) {
	if (a.d != b.d)
		return a.d > b.d;
	else if (a.i != b.i)
		return a.i < b.i;
	else if (a.j != b.j)
		return a.j < b.j;
	else
		return a.m < b.m;
}

double dp[26][50][5];
bool done[26][50][5];
priority_queue<State> PQ;
double D, W;

inline void visit(int i, int j, int m, double d) {
	if (!done[i][j][m] && d<dp[i][j][m]) {
		dp[i][j][m] = d;
		PQ.push(State(i, j, m, d));
	}
}
inline bool valid(int i, int j) {
	return (i>=0 && i<26 && j>=0 && j<50);
}
struct Point {
	double x, y;
	Point(int i=0, int j=0, int m=0) {
		x = i*D;
		y = j*D;
		switch (m) {
			case 1: x += W; y += W; break;
			case 2: x -= W; y += W; break;
			case 3: x += W; y -= W; break;
			case 4: x -= W; y -= W; break;
		}
	}
};
Point P[26][50][5];

inline double dist(const Point &a, const Point &b) {
	return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}
inline double dist(int i, int j, int m1, int r, int c, int m2) {
	return dist(P[i][j][m1], P[r][c][m2]);
}
class ManhattanDistance {
	public:
	double minDistance(int distance, int width, string start, string target) {
		D = distance;
		W = width/2.0;

		for (int i=0; i<26; ++i)
			for (int j=0; j<50; ++j)
				for (int k=0; k<5; ++k) {
					dp[i][j][k] = 1e32;
					P[i][j][k] = Point(i, j, k);
				}

		int si = start[0]-'A';
		int sj = atoi(start.substr(1).c_str()) - 1;
		int ei = target[0]-'A';
		int ej = atoi(target.substr(1).c_str()) - 1;

		PQ = priority_queue<State>();
		visit(si, sj, 0, 0);

		while (!PQ.empty()) {
			int i = PQ.top().i;
			int j = PQ.top().j;
			int m = PQ.top().m;
			double d = PQ.top().d;
			PQ.pop();

			if (i==ei && j==ej && m==0)
				return d;

			if (done[i][j][m])
				continue;
			done[i][j][m] = true;

			for (int dir=0; dir<4; ++dir) {
				int r = i + di[dir];
				int c = j + dj[dir];
				while (valid(r, c)) {
					for (int mode=0; mode<5; ++mode)
						visit(r, c, mode, d + dist(i, j, m, r, c, mode));
					r += di[dir];
					c += dj[dir];
				}
			}
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 10; string Arg2 = "B1"; string Arg3 = "B4"; double Arg4 = 300.0; verify_case(0, Arg4, minDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 20; string Arg2 = "F3"; string Arg3 = "G2"; double Arg4 = 181.10770276274835; verify_case(1, Arg4, minDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 1; string Arg2 = "E18"; string Arg3 = "P9"; double Arg4 = 19982.008508256098; verify_case(2, Arg4, minDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 4; string Arg2 = "B10"; string Arg3 = "E13"; double Arg4 = 35.27652763864304; verify_case(3, Arg4, minDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 120; int Arg1 = 30; string Arg2 = "C2"; string Arg3 = "D48"; double Arg4 = 5584.950296406279; verify_case(4, Arg4, minDistance(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ManhattanDistance ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

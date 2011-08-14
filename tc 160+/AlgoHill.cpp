#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int dx[] = { -1,  0,  1,  0 };
const int dy[] = {  0,  1,  0, -1 };

struct Entry {
	int x, y;
	int dist, pred;
	Entry(int x_, int y_, int dist_, int pred_): x(x_), y(y_), dist(dist_), pred(pred_) {}
};
bool operator<(const Entry &a, const Entry &b) {
	return a.dist+a.pred > b.dist+b.pred;
}
int pred(int x1, int y1, int x2, int y2) {
	return abs(x1-x2)+abs(y1-y2);
}
int dist(int x) {
	if (x == 0)
		return 2;
	else if (x > 0)
		return 1;
	else return 3;
}
bool valid(int x, int y, int X, int Y) {
	return x>=0 && x<X && y>=0 && y<Y;
}
class AlgoHill {
	public:
	int astar(vector <string> hill, int sx, int sy, int gx, int gy) {
		int Y = hill.size();
		int X = hill[0].size();
		int lim = 1000000000;

		vector<vector<bool> > used(Y, vector<bool>(X, false));
		priority_queue<Entry> q;
		q.push(Entry(sx, sy, 0, pred(sx, sy, gx, gy)));

		int sol = 0;
		while (!q.empty()) {
			Entry t = q.top(); q.pop();

			if (used[t.y][t.x]) continue;
			used[t.y][t.x] = true;
			if (t.y==gy && t.x==gx)
				lim = t.dist+t.pred;
			if (t.dist+t.pred > lim)
				break;
			++sol;
			for (int dir=0; dir<4; ++dir) {
				const int xx = t.x+dx[dir];
				const int yy = t.y+dy[dir];
				if (valid(xx, yy, X, Y) && !used[yy][xx])
					q.push(Entry(xx, yy, t.dist+dist(hill[t.y][t.x]-hill[yy][xx]), pred(xx, yy, gx, gy)));
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"34567",
 "23456",
 "12345",
 "23456",
 "34567"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 5; verify_case(0, Arg5, astar(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"55555",
 "54555",
 "55355",
 "55525",
 "55551"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 4; int Arg4 = 4; int Arg5 = 25; verify_case(1, Arg5, astar(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"55555",
 "54445",
 "54345",
 "54445",
 "55555"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arg3 = 4; int Arg4 = 3; int Arg5 = 21; verify_case(2, Arg5, astar(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"99999",
 "89992",
 "76543",
 "99992",
 "99991"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 4; int Arg4 = 0; int Arg5 = 13; verify_case(3, Arg5, astar(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"68233335836531",
 "57244363483169",
 "92744511826738",
 "76864574378195",
 "39927887799237",
 "89447973623642",
 "19758793475135",
 "33857155647757",
 "82987352116383",
 "18813823791825",
 "91772225881964",
 "46692256258431",
 "41961397519198",
 "48265328441524",
 "31422961925492",
 "17844758382392",
 "47549368526297",
 "27955796939522",
 "59699922792416",
 "56366572279148",
 "26884644728715",
 "98234493558879",
 "38984599399327",
 "66812381124583",
 "73833939626911",
 "13681831986111",
 "69237772565286",
 "34347792857462"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 2; int Arg3 = 8; int Arg4 = 2; int Arg5 = 1; verify_case(4, Arg5, astar(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {"44435",
 "44425",
 "44445",
 "32445",
 "55555"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 2; int Arg5 = 13; verify_case(5, Arg5, astar(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AlgoHill ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

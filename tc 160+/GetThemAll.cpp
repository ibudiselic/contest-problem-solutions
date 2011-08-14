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

vector<int> Px, Py;
int N;
int di[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dj[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

bool got[10];
int dist[200][200];
int fastDist(int x, int y) {
	int ret = 0;
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	if (x < y)
		swap(x, y);
	while (x>=100 || y>=100) {
		int cnt = x/4;
		x -= cnt*2;
		y -= cnt;
		ret += cnt;
		if (x < 0)
			x = -x;
		if (y < 0)
			y = -y;
		if (x < y)
			swap(x, y);
	}

	return ret + dist[x+100][y+100];
}
int go(int cnt, int x, int y) {
	if (cnt == N)
		return 0;
	int ret = 123456789;
	for (int i=0; i<N; ++i)
		if (!got[i]) {
			got[i] = 1;
			ret = min(ret, fastDist(abs(Px[i]-x), abs(Py[i]-y)) + go(cnt+1, Px[i], Py[i]));
			got[i] = 0;
		}

	return ret;
}
class GetThemAll {
	public:
	int quickKnight(vector <string> pieces) {
		N = pieces.size();
		Px.assign(N, 0);
		Py.assign(N, 0);

		for (int i=0; i<(int)pieces.size(); ++i)
			sscanf(pieces[i].c_str(), "%d %d", &Px[i], &Py[i]);

		memset(dist, 0xff, sizeof dist);
		queue<int> qi, qj;
		qi.push(100);
		qj.push(100);
		int t = 0;
		int d = -1;
		dist[100][100] = 0;
		while (!qi.empty()) {
			if (t == 0) {
				t = qi.size();
				++d;
			}
			--t;
			int i = qi.front(); qi.pop();
			int j = qj.front(); qj.pop();

			for (int dir=0; dir<8; ++dir) {
				const int r = i + di[dir];
				const int c = j + dj[dir];
				if (r<0 || r>=200 || c<0 || c>=200 || dist[r][c]!=-1)
					continue;
				dist[r][c] = d+1;
				qi.push(r);
				qj.push(c);
			}
		}

		memset(got, 0, sizeof got);
		return go(0, 0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, quickKnight(Arg0)); }
	void test_case_1() { string Arr0[] = {"2 -1", "2 1", "-2 1", "-2 -1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, quickKnight(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, quickKnight(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 7", "7 7", "7 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(3, Arg1, quickKnight(Arg0)); }
	void test_case_4() { string Arr0[] = {"-1000000 -1000000", "1000000 1000000", "1000000 -1000000", "-1000000 1000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3666668; verify_case(4, Arg1, quickKnight(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GetThemAll ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

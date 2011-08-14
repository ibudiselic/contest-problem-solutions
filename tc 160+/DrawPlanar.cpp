#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
bool G[7][7];
vector<int> order;
int board[16][16];
int X[7], Y[7];
char online_[16][16][16][16][16][16];
char ccw0_[16][16][16][16][16][16];
string repr;

inline int sgn0(int x) {
	return (x>0 ? 1 : (x==0 ? 0 : -1));
}
inline int cross(int x1, int y1, int x2, int y2) {
	return x1*y2 - y1*x2;
}
inline int ccw0(int a, int b, int c) {
	char &ret = ccw0_[X[a]][Y[a]][X[b]][Y[b]][X[c]][Y[c]];
	if (ret != -1)
		return ret;

	return (ret = sgn0(cross(X[b]-X[a], Y[b]-Y[a], X[c]-X[b], Y[c]-Y[b])));
}
bool online(int c, int a, int b) {
	char &ret = online_[X[a]][Y[a]][X[b]][Y[b]][X[c]][Y[c]];
	if (ret != -1)
		return ret;

	const int x1 = min(X[a], X[b]);
	const int x2 = max(X[a], X[b]);
	const int y1 = min(Y[a], Y[b]);
	const int y2 = max(Y[a], Y[b]);

	return (ret = (c!=a && c!=b && x1<=X[c] && X[c]<=x2 && y1<=Y[c] && Y[c]<=y2 && ccw0(a, b, c)==0));
}
inline bool intersects(int a, int b, int c, int d) {
	if (online(a, c, d) || online(b, c, d))
		return true;
	int x = ccw0(a, b, c);
	int y = ccw0(a, b, d);
	if (x==0 || y==0 || x==y)
		return false;

	x = ccw0(c, d, a);
	y = ccw0(c, d, b);
	return x!=0 && y!=0 && x!=y;
}
bool inside(int a, int b, int c, int d) {
	const int x1 = min(X[a], X[b]);
	const int x2 = max(X[a], X[b]);
	const int y1 = min(Y[a], Y[b]);
	const int y2 = max(Y[a], Y[b]);

	return (y1<Y[c] && Y[c]<y2 || y1<Y[d] && Y[d]<y2 || x1<X[c] && X[c]<x2 || x1<X[d] && X[d]<x2);
}
inline bool overlap(int a, int b, int c, int d) {
	return ((inside(a, b, c, d) || inside(c, d, a, b)) && ccw0(a, b, c)==0 && ccw0(a, b, d)==0);
}
bool intersects(int a, int b) {
	for (int i=0; i<b; ++i)
		for (int j=i+1; j<b; ++j)
			if (G[i][j] && (intersects(i, j, a, b) || overlap(i, j, a, b)))
				return true;

	return false;
}
bool ok(int n) {
	for (int i=0; i<n; ++i)
		if (G[i][n] && intersects(i, n))
			return false;

	return true;
}

bool check(int n, int x, int y) {
	if (n == N)
		return true;

	for (int i=0; i<=x; ++i) {
		X[n] = i;
		for (int j=0; j<=y; ++j)
			if (!board[i][j]) {
				Y[n] = j;
				board[i][j] = order[n]+1;
				if (ok(n)) {
					board[i][j] = order[n]+1;
					if (check(n+1, x, y))
						return true;
					board[i][j] = 0;
				}
				board[i][j] = 0;
			}
	}

	return false;
}

bool check0(int x, int y) {
	for (int i=0; i<=x/2; ++i) {
		X[0] = i;
		for (int j=0; j<=y/2; ++j) {
			Y[0] = j;
			board[i][j] = order[0]+1;
			if (check(1, x, y))
				return true;
			board[i][j] = 0;
		}
	}

	return false;
}
bool checkArea(int A) {
	for (int x=1; x*x<=A; ++x)
		if (A%x==0 && check0(x, A/x))
			return true;
	return false;
}
class DrawPlanar {
	public:
	int minArea(vector <string> graph) {
		N = graph.size();

		vector<int> deg(N, 0);
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				deg[i] += (graph[i][j] == 'T');

		order.assign(N, 0);
		for (int i=0; i<N; ++i)
			order[i] = i;

		for (int i=0; i<N; ++i)
			for (int j=i+1; j<N; ++j)
				if (deg[order[i]] < deg[order[j]])
					swap(order[i], order[j]);

		memset(G, 0, sizeof G);
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				G[i][j] = (graph[order[i]][order[j]]=='T');

        memset(online_, 0xff, sizeof online_);
        memset(ccw0_, 0xff, sizeof ccw0_);
		if (check0(0, N-1))
			return 0;

		int lo = 1, hi = 15;

		while (lo < hi) {
			int mid = lo + (hi-lo)/2;

			memset(board, 0, sizeof board);
			if (checkArea(mid))
				hi = mid;
			else
				lo = mid+1;
		}

		return lo;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minArea(Arg0)); }
	void test_case_1() { string Arr0[] = {"FTF",
 "TFF",
 "FFF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minArea(Arg0)); }
	void test_case_2() { string Arr0[] = {"FTT",
 "TFT",
 "TTF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minArea(Arg0)); }
	void test_case_3() { string Arr0[] = {"FTTT",
 "TFTT",
 "TTFT",
 "TTTF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minArea(Arg0)); }
	void test_case_4() { string Arr0[] = {"FTTTTTT",
 "TFTTTFT",
 "TTFFFFT",
 "TTFFTFF",
 "TTFTFTT",
 "TFFFTFT",
 "TTTFTTF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(4, Arg1, minArea(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DrawPlanar ___test;
    ___test.run_test(4);
    }
// END CUT HERE

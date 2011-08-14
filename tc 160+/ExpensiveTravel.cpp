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

int A[50][50];
int gcd(int m, int n) {
	return n==0 ? m : gcd(n, m%n);
}
int lcm(int m, int n) {
	return m/gcd(m, n)*n;
}
int num; // num is lcm of numbers from 1 to 9 inclusive
int m, n;

struct state {
	int i, j, time, val;
	state(int i_, int j_, int t, int v): i(i_), j(j_), time(t), val(v) {}
};
bool operator>(const state &a, const state &b) {
	if (a.time != b.time)
		return a.time > b.time;
	else if (a.val != b.val)
		return a.val > b.val;
	else if (a.i != b.i)
		return a.i > b.i;
	else
		return a.j > b.j;
};
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

bool done[50][50];
bool valid(int i, int j) {
	if (i<0 || j<0 || i>=m || j>=n)
		return false;
	return true;
}
int bfs(int si, int sj, int ei, int ej) {
	memset(done, 0, sizeof done);
	priority_queue<state, vector<state>, greater<state> > pq;

	pq.push(state(si, sj, 1, A[si][sj]));

	while (!pq.empty()) {
		const int i = pq.top().i;
		const int j = pq.top().j;
		const int t = pq.top().time;
		const int v = pq.top().val;
		pq.pop();

		if (done[i][j])
			continue;

		done[i][j] = 1;
		if (i==ei && j==ej)
			return t;

		for (int d=0; d<4; ++d) {
			const int r = i + di[d];
			const int c = j + dj[d];

			if (valid(r, c) && !done[r][c]) {
				int nv = v + A[r][c];
				if (nv > num) {
					if (A[i][j] + A[r][c] <= num)
						pq.push(state(r, c, t+1, A[i][j]+A[r][c]));
				} else {
					pq.push(state(r, c, t, nv));
				}
			}
		}
	}
	return -1;
}
class ExpensiveTravel {
	public:
	int minTime(vector <string> A_, int startRow, int startCol, int endRow, int endCol) {
		num = 1;
		for (int i=1; i<10; ++i)
			num = lcm(num, i);

		m = A_.size();
		n = A_[0].size();

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				A[i][j] = num/(A_[i][j]-'0');

		return bfs(startRow-1, startCol-1, endRow-1, endCol-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"22334"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 5; int Arg5 = 3; verify_case(0, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"55",
 "52",
 "55"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; int Arg4 = 2; int Arg5 = 1; verify_case(1, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"251",
 "212",
 "122"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; int Arg4 = 3; int Arg5 = -1; verify_case(2, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"452232",
 "287979",
 "219872",
 "928234",
 "767676"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; int Arg3 = 3; int Arg4 = 1; int Arg5 = 3; verify_case(3, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = -1; verify_case(4, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {"123456789987654321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; int Arg4 = 16; int Arg5 = 5; verify_case(5, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ExpensiveTravel ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

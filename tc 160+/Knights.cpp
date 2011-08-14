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

int B[26*26][26*26];
int C[26*26+2][26*26+2];
int F[26*26+2][26*26+2];
int P[26*26+2];
const int S = 0;
const int T = 1;
int n;
const int di[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dj[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
bool bfs(int x) {
	P[x] = -2;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front(); q.pop();
		if (x == T)
			return true;
		for (int i=0; i<n; ++i)
			if (P[i]==-1 && C[x][i]-F[x][i]>0) {
				P[i] = x;
				q.push(i);
			}
	}
	return false;
}

class Knights {
	public:
	int makeFriendly(int N, vector <string> pos) {
		memset(C, 0, sizeof C);
		memset(F, 0, sizeof F);
		memset(B, 0, sizeof B);
		n = 2;

		for (int i=0; i<(int)pos.size(); ++i) {
			istringstream is(pos[i]);
			string s;
			while (is >> s) {
				istringstream x(s);
				char r;
				int c;
				x >> r >> c;
				r -= 'A';
				--c;
				if (r%2 == c%2)
					C[S][n] = 1;
				else
					C[n][T] = 1;
				B[r][c] = n++;
			}
		}
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				if (B[i][j])
				for (int d=0; d<8; ++d) {
					const int ii = i + di[d];
					const int jj = j + dj[d];
					if (ii>=0 && ii<N && jj>=0 && jj<N)
						if (B[ii][jj])
							if (i%2 == j%2)
								C[ B[i][j] ][ B[ii][jj] ] = 1;
							else
								C[ B[ii][jj] ][ B[i][j] ] = 1;
				}
		int sol = 0;
		memset(P, 0xff, sizeof P);
		while (bfs(S)) {
			++sol;
			int x = T;
			while (x != -2) {
				++F[ P[x] ][x];
				--F[ x ][ P[x] ];
				x = P[x];
			}
			memset(P, 0xff, sizeof P);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"A2 A4", "B1 B5", "D1 D5 E2 E4 C3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"A1 A2 B1 B2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arr1[] = {"A1 A5 B3 C1 C5 D2 D4 E6 F5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; string Arr1[] = {"A2 A4 A5 A6 B2 B5 B6 B7 B8",
 "C3 C8 D1 D2 D3 D4 D5 D6 D8",
 "E1 E3 E8 F1 F2 F8 G3 G5 H4 H7 H8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9; string Arr1[] = {"A3 A4 A5 A7 A8 B6 B8 C3 C6",
 "C7 C9 D4 D5 D8 D9 E1 E3 E7",
 "F2 G2 G6 G7 H2 H9 I2 I4 I5",
 "I6 I7 I8 I9"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(4, Arg2, makeFriendly(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Knights ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

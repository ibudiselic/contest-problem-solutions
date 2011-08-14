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

using namespace std;

bool done[10][10][10];
int D[10][10][10][10][10];
vector<string> B;
int M, N;
queue< pair<int, int> > Q;

int Si, Sj;
const int di[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
const int dj[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

void expand(int i, int j, int t) {
	if (t == 0) {
		return;
	}
	for (int d=0; d<8; ++d) {
		const int r = i + di[d];
		const int c = j + dj[d];
		if (r<0 || c<0 || r>=M || c>=N) {
			continue;
		}
		if (!done[t][r][c]) {
			done[t][r][c] = 1;
			Q.push(make_pair(r, c));
			expand(r, c, t-1);
		}
	}
}

int dist(int t, int si, int sj, int ti, int tj) {
	if (si==ti && sj==tj) {
		return 0;
	}
	if (D[t][si][sj][ti][tj] != -1) {
		return D[t][si][sj][ti][tj];
	}

	Q = queue< pair<int, int> >();
	memset(done, 0, sizeof done);
	done[t][si][sj] = 1;
	int ret = -1;
	int sz = 0;
	Si = si;
	Sj = sj;
	Q.push(make_pair(si, sj));

	while (!Q.empty()) {
		if (sz == 0) {
			sz = Q.size();
			++ret;
		}
		--sz;
		int i = Q.front().first;
		int j = Q.front().second;
		Q.pop();
		if (D[t][si][sj][i][j]==-1 || ret<D[t][si][sj][i][j]) {
			D[t][si][sj][i][j] = ret;
		} 

		if (i==ti && j==tj) {
			return ret;
		}

		expand(i, j, t);
	}

	return -1;
}

class CollectingRiders {
	public:
	int minimalMoves(vector <string> board) {
		B = board;
		M = B.size();
		N = B[0].size();

		int sol = 123456789;
		memset(D, 0xff, sizeof D);
		for (int i=0; i<M; ++i) {
			for (int j=0; j<N; ++j) {
				int cur = 0;
				for (int r=0; r<M; ++r) {
					for (int c=0; c<N; ++c) {
						if (B[r][c] != '.') {
							int t = dist(B[r][c]-'0', r, c, i, j); 
							if (t == -1) {
								goto NEXT;
							}
							cur += t;
						}
					}
				}
				sol = min(sol, cur);
				NEXT: ;
			}
		}

		return sol==123456789 ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...1",
 "....",
 "2..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"........",
 ".1......",
 "........",
 "....3...",
 "........",
 "........",
 ".7......",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimalMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"..",
 "2.",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minimalMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {".1....1."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minimalMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"9133632343",
 "5286698232",
 "8329333369",
 "5425579782",
 "4465864375",
 "8192124686",
 "3191624314",
 "5198496853",
 "1638163997",
 "6457337215"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 121; verify_case(4, Arg1, minimalMoves(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CollectingRiders ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

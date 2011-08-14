#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };

double cur[50][50][5][2], best[50][50][5][2], init[50][50][5][2]; // i, j, forbidden dir, waited on light?

vector<string> A;
int T;
double S, R;
int M, N;
inline bool valid(int i, int j) {
	if (i<0 || j<0 || i>=M || j>=N)
		return false;
	return true;
}

class LateForConcert {
	public:
	double bestRoute(vector <string> A_, int T_, double S_, double R_) {
		A = A_;
		M = A.size();
		N = A[0].size();
		T = T_;
		S = S_;
		R = 0.7*R_;

		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				for (int k=0; k<5; ++k)
					for (int l=0; l<2; ++l)
						init[i][j][k][l] = 1e32;

		int Ti=0, Tj=0;
		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				if (A[i][j] == 'C') {
					Ti = i;
					Tj = j;
					goto NEXT_STEP;
				}
		NEXT_STEP: ;

		memcpy(cur, init, sizeof cur);
		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				if (A[i][j] == 'Y') {
					A[i][j] = '.';
					cur[i][j][4][0] = 0.0;
					goto START_WORK;
				}
		START_WORK: ;

		double sol = 1e32;
		int t = 0;
		memcpy(best, init, sizeof best);
		while (t<=T) {
			for (int i=0; i<M; ++i)
				for (int j=0; j<N; ++j)
					for (int fd=0; fd<5; ++fd)
						for (int waited=0; waited<2; ++waited) {
							if (A[i][j] == 'C') {
								if (t == T)
									sol = min(sol, cur[i][j][fd][waited]);
								continue;
							}
						if (abs(i-Ti)+abs(j-Tj)>T-t)
							continue;

						if (A[i][j]=='T' && !waited)
							best[i][j][fd][1] = min(best[i][j][fd][1], cur[i][j][fd][0]);

						for (int d=0; d<4; ++d)
							if (d != fd) {
								const int ii = i + di[d];
								const int jj = j + dj[d];
								if (!valid(ii, jj) || A[ii][jj]=='X')
									continue;

								double nc = cur[i][j][fd][waited];
								if (A[i][j] == 'S')
									nc += S;
								else if (A[i][j]=='T' && !waited)
									nc += R;
								int nfd = (d+2)%4;

								best[ii][jj][nfd][0] = min(best[ii][jj][nfd][0], nc);
							}
					}
			++t;
			memcpy(cur, best, sizeof cur);
			memcpy(best, init, sizeof best);
		}

		return sol>1e30 ? -1.0 : sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"XXXXXXXX",
 "XY...S.X",
 "XXXXXX.X",
 "C..S.TT."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; double Arg2 = 60; double Arg3 = 93; double Arg4 = 185.1; verify_case(0, Arg4, bestRoute(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"XX..XX",
 "Y....C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; double Arg2 = 52; double Arg3 = 874; double Arg4 = 0.0; verify_case(1, Arg4, bestRoute(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"YTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 67; double Arg2 = 123.4; double Arg3 = 42.192; double Arg4 = 886.032; verify_case(2, Arg4, bestRoute(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"C.......",
 "SXXSXXX.",
 "TSSTY..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; double Arg2 = 1.23456789; double Arg3 = 123.456789; double Arg4 = 0.0; verify_case(3, Arg4, bestRoute(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"Y..",
 "...",
 "..C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 1.0; double Arg3 = 1.0; double Arg4 = -1.0; verify_case(4, Arg4, bestRoute(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LateForConcert ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
double A[256][256];
double b[256];
double x[256];
void swapRows(int a, int b) {
	static double tmp[256];
	memcpy(tmp, A[a], sizeof tmp);
	memcpy(A[a], A[b], sizeof A[a]);
	memcpy(A[b], tmp, sizeof A[b]);
}
void gaussianElimination(int eqCnt) {
	for (int i=0; i<eqCnt; ++i)
		x[i] = 0;

	for (int j=0; j<eqCnt; ++j) {
		int best = j;
		for (int i=j+1; i<eqCnt; ++i)
			if (fabs(A[i][j]) > fabs(A[best][j]))
				best = i;
		if (best != j) {
			swapRows(best, j);
			swap(b[best], b[j]);
		}
		if (fabs(A[j][j]) < 1e-9)
			continue;

		b[j] /= A[j][j];
		for (int k=j+1; k<eqCnt; ++k)
			A[j][k] /= A[j][j];
		A[j][j] = 1.0;

		for (int i=j+1; i<eqCnt; ++i) {
			b[i] -= A[i][j]*b[j];
			for (int k=j+1; k<eqCnt; ++k)
				A[i][k] -= A[i][j]*A[j][k];
			A[i][j] = 0.0;
		}
	}

	x[eqCnt-1] = b[eqCnt-1];
	for (int i=eqCnt-2; i>=0; --i)
		if (fabs(A[i][i]) > 1e-9) {
			x[i] = b[i];
			for (int j=i+1; j<eqCnt; ++j)
				x[i] -= A[i][j]*x[j];
		}
}

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
vector<string> jail;
bool done[20][20];
bool exitable(int i, int j) {
	if (jail[i][j] == '$')
		return true;
	done[i][j] = 1;
	for (int d=0; d<4; ++d) {
		int r = i+di[d];
		int c = j+dj[d];
		if (r>=0 && r<(int)jail.size() && c>=0 && c<(int)jail[0].size())
			if (!done[r][c] && jail[r][c]!='#')
				if (exitable(r, c))
					return true;
	}
	return false;
}
class EscapeTheJail {
	public:
	double findExit(vector <string> jail_) {
		jail = jail_;
		int starti=-1, startj=-1;
		int m = jail.size();
		int n = jail[0].size();
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (jail[i][j] == '@') {
					starti = i;
					startj = j;
					jail[i][j] = '.';
					goto FOUND_START;
				}
		FOUND_START:;

		memset(done, 0, sizeof done);
		if (!exitable(starti, startj))
			return -1.0;

		for (int i=0; i<256; ++i) {
			b[i] = 0;
			x[i] = 0;
			for (int j=0; j<256; ++j)
				A[i][j] = 0;
		}

		int eqCnt = 0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (jail[i][j] == '.') {
					vector<int> neighbors;
					for (int d=0; d<4; ++d) {
						int r = i + di[d];
						int c = j + dj[d];
						if (r>=0 && r<m && c>=0 && c<n && jail[r][c]!='#')
							neighbors.push_back(r*n + c);
					}
					if (neighbors.size() > 0) {
						A[eqCnt][eqCnt] = neighbors.size();
						for (int k=0; k<(int)neighbors.size(); ++k)
							A[eqCnt][neighbors[k]] = -1;
						b[eqCnt] = neighbors.size();
						++eqCnt;
					} else {
						A[eqCnt][eqCnt] = 1;
						b[eqCnt] = 0;
						++eqCnt;
					}
				} else {
					A[eqCnt][eqCnt] = 1;
					b[eqCnt] = 0;
					++eqCnt;
				}

		gaussianElimination(eqCnt);

		return x[starti*n + startj];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"@$"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, findExit(Arg0)); }
	void test_case_1() { string Arr0[] = {"$.",
 ".@"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(1, Arg1, findExit(Arg0)); }
	void test_case_2() { string Arr0[] = {"@..$"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.0; verify_case(2, Arg1, findExit(Arg0)); }
	void test_case_3() { string Arr0[] = {"@#",
 "#$"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -1.0; verify_case(3, Arg1, findExit(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EscapeTheJail ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

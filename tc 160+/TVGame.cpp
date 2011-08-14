#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int mod = 121547;
int A[50][50];
int N;

struct egcds {
	int t, s, d;
};
egcds egcd(int m, int n) {
	if (m == 0) {
		return (egcds){0, 1, n};
	}
	egcds next = egcd(n%m, m);
	int temp = next.t;
	next.t = next.s - temp*(n/m);
	next.s = temp;

	assert(next.t*m + next.s*n == next.d);
	return next;
}

int msub(int a, int b) {
	assert(a >= 0);
	assert(b >= 0);
	return (a-b + mod) % mod;
}
int mmul(int a, int b) {
	assert(a >= 0);
	assert(b >= 0);
	return int((long long)a*b % mod);
}
int mdiv(int a, int b) {
	assert(a >= 0);
	assert(b >= 0);
	egcds t = egcd(b, mod);
	assert(t.d == 1); // relatively prime
	if (t.t < 0) {
		t.t = (t.t + (-t.t + mod - 1)/mod * mod) % mod;
	}
	return mmul(a, t.t);
}

void print_mat() {
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			cerr << A[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
}
int det() {
	int ret = 1;
	for (int r=0; r<N; ++r) {
		int nr = r;
		while (nr<N && A[nr][r]==0) {
			++nr;
		}
		if (nr == N) {
			return 0;
		}
		if (nr != r) {
			ret = msub(0, ret);
			for (int c=r; c<N; ++c) {
				swap(A[r][c], A[nr][c]);
			}
		}

		ret = mmul(ret, A[r][r]);
		for (int c=0; c<r; ++c) {
			assert(A[r][c] == 0);
		}
		int d = A[r][r];
		assert(d > 0);
		for (int r2=r+1; r2<N; ++r2) {
			int f = A[r2][r];
			for (int c=r; c<N; ++c) {
				A[r2][c] = msub(A[r2][c], mmul(mdiv(A[r][c], d), f));
			}
			assert(A[r2][r] == 0);
		}
	}

	return ret;
}

class TVGame {
	public:
	int expectedProfit(vector <string> board) {
		N = board.size();
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				A[i][j] = (isdigit(board[i][j]) ? board[i][j]-'0' : msub(0, (board[i][j]-'A'+1)));
			}
		}

		int sol = det();

		if (N%2 == 0) {
			sol = msub(0, sol);
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"35",
 "44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, expectedProfit(Arg0)); }
	void test_case_1() { string Arr0[] = {"00200",
 "0B000",
 "00020",
 "10000",
 "00001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 121539; verify_case(1, Arg1, expectedProfit(Arg0)); }
	void test_case_2() { string Arr0[] = {"12A",
 "A12",
 "2A1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(2, Arg1, expectedProfit(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAAA",
 "BBBB",
 "CCCC",
 "DDDD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, expectedProfit(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TVGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

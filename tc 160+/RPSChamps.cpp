#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[501];
double p[501][501];

class RPSChamps {
	public:
	double numberOfMoves(int N) {
		p[0][0] = 1.0;
		for (int n=1; n<=N; ++n)
			for (int a=0; a<=n; ++a) {
				const int b = n-a;
				p[a][b] = (a>0 ? p[a-1][b] : 0.0)/3 + (b>0 ? p[a][b-1] : 0.0)/3;
			}

		dp[0] = 0.0;
		dp[1] = 0.0;
		for (int n=2; n<=N; ++n) {
			double pnorep = 0.0;
			dp[n] = 0.0;
			for (int a=1; a<n; ++a) {
				dp[n] += 3*p[a][n-a]*(1+dp[a]+dp[n-a]);
				pnorep += p[a][n-a];
			}
			pnorep *= 3;
			dp[n] = (dp[n] + (1-pnorep))/pnorep;
		}
		return dp[N];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; double Arg1 = 0.0; verify_case(0, Arg1, numberOfMoves(Arg0)); }
	void test_case_1() { int Arg0 = 2; double Arg1 = 1.5; verify_case(1, Arg1, numberOfMoves(Arg0)); }
	void test_case_2() { int Arg0 = 3; double Arg1 = 3.0; verify_case(2, Arg1, numberOfMoves(Arg0)); }
	void test_case_3() { int Arg0 = 10; double Arg1 = 35.59012622220019; verify_case(3, Arg1, numberOfMoves(Arg0)); }
	void test_case_4() { int Arg0 = 200; double Arg1 = 5.509733035960696E34; verify_case(4, Arg1, numberOfMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RPSChamps ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int A[451][451], B[451][451];
int (*dp)[451], (*temp)[451];
const int mod = 999983;
class CharmingTicketsEasy {
	public:
	int count(int K, string good) {
		dp = &A[0];
		temp = &B[0];
		memset(dp, 0, sizeof A);

		dp[0][0] = 1;
		for (int i=0; i<K; ++i) {
			for (int o1=450; o1>=0; --o1) {
				for (int o2=450; o2>=0; --o2) {
					temp[o1][o2] = 0;
					for (int j=0; j<(int)good.size(); ++j) {
						int n1 = o1 + (good[j]-'0');
						int n2 = o2 + (i%2==0)*(good[j]-'0');
						if (n1<451 && n2<451) {
							temp[n1][n2] = (temp[n1][n2] + dp[o1][o2]) % mod;
						}
					}
				}
			}

			swap(temp, dp);
		}

		int sol = 0;
		for (int sum=0; sum<451; ++sum) {
			for (int x=0; x<=sum; ++x) {
				sol = (sol + (long long)dp[sum][x]*dp[sum][x]) % mod;
				for (int y=0; y<x; ++y) {
					sol = (sol + (long long)dp[sum][x]*dp[sum][y]*2) % mod;
				}
			}
		}


		for (int x=0; x<451; ++x) {
			for (int z=0; z<451; ++z) {
				if (x!=z && (x+z)%2==0) {
					for (int y=0; y<=x; ++y) {
						int w = (x+z)/2 - y;
						int ww = (K%2==0 ? w : z-w);
						if (0<=ww && ww<=z) {
							sol = (sol + (long long)dp[x][y]*dp[z][ww]) % mod;
						}
					}
				}
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "0123456789"; int Arg2 = 10; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "21"; int Arg2 = 8; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arg1 = "0123456789"; int Arg2 = 1240; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; string Arg1 = "731"; int Arg2 = 207444; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; string Arg1 = "0123456789"; int Arg2 = 367584; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CharmingTicketsEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

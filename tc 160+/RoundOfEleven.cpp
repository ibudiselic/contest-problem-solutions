#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[10][501][11];
vector<int> d;
long long go(int p, int m, int r) {
	if (m < 0) {
		return 0;
	}
	if (p == (int)d.size()) {
		return (r==0 ? m : 0);
	}
	
	long long &ret = dp[p][m][r];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int x=0; x<10; ++x) {
		ret += go(p+1, m-abs(d[p]-x), (10*r + x)%11);
	}

	return ret;
}

class RoundOfEleven {
	public:
	long long maxIncome(int n, int money) {
		memset(dp, 0xff, sizeof dp);
		d.clear();
		while (n > 0) {
			d.push_back(n%10);
			n /= 10;
		}
		reverse(d.begin(), d.end());

		return go(0, money, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 31; int Arg1 = 4; long long Arg2 = 6LL; verify_case(0, Arg2, maxIncome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 31; int Arg1 = 5; long long Arg2 = 11LL; verify_case(1, Arg2, maxIncome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 110; int Arg1 = 3; long long Arg2 = 7LL; verify_case(2, Arg2, maxIncome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 19759; int Arg1 = 435; long long Arg2 = 3788217LL; verify_case(3, Arg2, maxIncome(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RoundOfEleven ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

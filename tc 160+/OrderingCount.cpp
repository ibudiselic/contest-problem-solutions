#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
vector<unsigned> M;

int n;
long long dp[1<<20];
long long go(unsigned mask) {
	if (dp[mask] != -1)
		return dp[mask];
	if (mask == 0)
		return dp[mask] = 1;

	long long ret = 0;
	for (int i=0; i<n; ++i)
		if ((mask & (1u<<i))!=0 && (mask&M[i])==0)
			ret += go(mask^(1u<<i));

	return dp[mask] = ret;
}

class OrderingCount {
	public:
	long long countOrderings(vector <string> req) {
		memset(dp, 0xff, sizeof dp);
		n = req.size();
		M.assign(n, 0);
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (req[i][j] == 'Y')
					if (i == j) return 0;
					else M[j] |= (1u<<i);

		return go((1u<<n)-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNNN",
 "YNNY",
 "NNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, countOrderings(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYN",
 "NNY",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, countOrderings(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 120LL; verify_case(2, Arg1, countOrderings(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNNN",
 "NNYNNN",
 "NNNYNN",
 "NNNNYN",
 "NNNNNY",
 "NNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(3, Arg1, countOrderings(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNYNNN",
 "YNYNNN",
 "NNNNNN",
 "NNNNNN",
 "NNYYNN",
 "NNYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 42LL; verify_case(4, Arg1, countOrderings(Arg0)); }
	void test_case_5() { string Arr0[] = {"NNN",
 "NYN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(5, Arg1, countOrderings(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OrderingCount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

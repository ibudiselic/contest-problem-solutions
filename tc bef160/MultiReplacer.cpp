#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef long long lint;

class MultiReplacer {
	public:
	long long length(string arep, string brep, string crep, int iter, int m) {
		lint a[31][3][3] = {0};
		lint sol[3], b[3];

		for (int i=0; i<(int)arep.size(); ++i) ++a[0][arep[i]-'a'][0];
		for (int i=0; i<(int)brep.size(); ++i) ++a[0][brep[i]-'a'][1];
		for (int i=0; i<(int)crep.size(); ++i) ++a[0][crep[i]-'a'][2];

		for (int t=1; t<31; ++t)
			for (int i=0; i<3; ++i)
				for (int j=0; j<3; ++j) {
					lint x = 0;
					for (int k=0; k<3; ++k)
						x = (x + a[t-1][i][k]*a[t-1][k][j])%m;
					a[t][i][j] = x;
				}

		sol[0] = 1;
		sol[1] = sol[2] = 0;
		for (int t=0; t<31; ++t)
			if (iter & (1<<t)) {
				for (int i=0; i<3; ++i) {
					b[i] = 0;
					for (int k=0; k<3; ++k)
						b[i] = (b[i] + a[t][i][k]*sol[k])%m;
				}
				memcpy(sol, b, sizeof sol);
		}

		return ((sol[0]+sol[1])%m + sol[2])%m;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abc"; string Arg1 = "c"; string Arg2 = "ba"; int Arg3 = 3; int Arg4 = 7; long long Arg5 = 5LL; verify_case(0, Arg5, length(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arg0 = "b"; string Arg1 = "c"; string Arg2 = "a"; int Arg3 = 2000000000; int Arg4 = 100; long long Arg5 = 1LL; verify_case(1, Arg5, length(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arg0 = "b"; string Arg1 = "c"; string Arg2 = "aa"; int Arg3 = 30; int Arg4 = 10000; long long Arg5 = 1024LL; verify_case(2, Arg5, length(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arg0 = "acabbcabbabac"; string Arg1 = "cababcababcabcabacbacbabcacb"; string Arg2 = "acbacbabcababcabababbabcbcab"; int Arg3 = 2000000000; int Arg4 = 2000000000; long long Arg5 = 1876480521LL; verify_case(3, Arg5, length(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MultiReplacer ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<long long> > matMul(const vector< vector<long long> > &A, const vector< vector< long long> > &B, long long mod) {
	vector< vector<long long> > C(3, vector<long long> (3, 0));

	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			for (int k=0; k<3; ++k)
				C[i][j] = (C[i][j] + A[i][k]*B[k][j]%mod)%mod;

	return C;
}
vector< vector<long long> > fastMatExp(vector< vector<long long> > A, int n, long long mod) {
	vector< vector<long long> > ret(3, vector<long long> (3, 0));
	for (int i=0; i<3; ++i)
		ret[i][i] = 1;

	while (n > 0) {
		if (n & 1)
			ret = matMul(ret, A, mod);

		A = matMul(A, A, mod);
		n /= 2;
	}

	return ret;
}
int cnt(const string &s, char c) {
	return count(s.begin(), s.end(), c);
}
class MultiReplacer {
	public:
	long long length(string arep, string brep, string crep, int iter, int m) {
		vector< vector<long long> > A(3, vector<long long> (3, 0));
		A[0][0] = 1;

		vector< vector<long long> > B(3, vector<long long> (3, 0));
		B[0][0] = cnt(arep, 'a');
		B[0][1] = cnt(arep, 'b');
		B[0][2] = cnt(arep, 'c');
		B[1][0] = cnt(brep, 'a');
		B[1][1] = cnt(brep, 'b');
		B[1][2] = cnt(brep, 'c');
		B[2][0] = cnt(crep, 'a');
		B[2][1] = cnt(crep, 'b');
		B[2][2] = cnt(crep, 'c');

		B = fastMatExp(B, iter, m);
		A = matMul(A, B, m);

		return ((A[0][0] + A[0][1])%m + A[0][2])%m;
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

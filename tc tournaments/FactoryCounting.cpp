#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

unsigned mask[30];
long long C[31][31];
int N;
int n, m;
long long choose(int n, int k) {
	if (n < k)
		return 0;
	if (k==0 || k==n)
		return 1;
	if (C[n][k] != -1)
		return C[n][k];
	return C[n][k] = choose(n-1, k-1) + choose(n-1, k);
}
int bc(int x) {
	return (x==0 ? 0 : 1 + bc(x & (x-1)));
}
long long go(int x, int cnt_n, unsigned allow) {
	if (cnt_n == n)
		return choose(bc(allow), m);
	if (x == N)
		return 0;

	return go(x+1, cnt_n, allow) + go(x+1, cnt_n+1, allow & mask[x]);
}
class FactoryCounting {
	public:
	long long count(int n_, int m_, vector <string> county) {
		n = n_;
		m = m_;
		if (n > m)
			swap(n, m);
		N = county.size();
		if (n+m > N)
			return 0;
		memset(mask, 0, sizeof mask);
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				mask[i] |= (county[i][j]=='Y')*(1u<<j);

		memset(C, 0xff, sizeof C);
		return go(0, 0, (1u<<N)-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arr2[] = {
 "NYY",
 "YNY",
 "YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {
 "NYYYYN",
 "YNYYNY",
 "YYNYYY",
 "YYYNYN",
 "YNYYNY",
 "NYYNYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 32LL; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {
 "NNNNYN",
 "NNNYNN",
 "NNNNYN",
 "NYNNYN",
 "YNYYNN",
 "NNNNNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 8LL; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {
 "NYYYNYYNYY",
 "YNYYYYYYYN",
 "YYNYYYNYYN",
 "YYYNYYNYNY",
 "NYYYNYYYYY",
 "YYYYYNYYNY",
 "YYNNYYNYYN",
 "NYYYYYYNNY",
 "YYYNYNYNNY",
 "YNNYYYNYYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 308LL; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 8; string Arr2[] = {
 "NYYYYYNYYYYYNYYYYYYYYYYNYYYYYY",
 "YNYYYYYYYYYYYYYYYNYYYYYYYYYYYY",
 "YYNYYYYYYYYYYYYNYNYYYNNYYYNYYY",
 "YYYNYYYYYYYYNYYYYYNYYYYYYNYYYY",
 "YYYYNYYYYYYYYYNYYYYYYYYYYYNYYY",
 "YYYYYNYYNYYYYNYYYYYNYYYYYYYNNY",
 "NYYYYYNYYYYYYYYYNYYYYNYYYYYYYY",
 "YYYYYYYNYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYNYYNYYYYNNYYYYYYYYNYYNNYY",
 "YYYYYYYYYNYYNYYNYNYYNYYYYYYYYY",
 "YYYYYYYYYYNYYNYYYYYYYNYYYYYYYY",
 "YYYYYYYYYYYNYYYYNYYYYYYYYYYYYY",
 "NYYNYYYYYNYYNYYYNYNYYYYYNYYYYY",
 "YYYYYNYYNYNYYNYYYYYYYYYYYNYYNY",
 "YYYYNYYYNYYYYYNNNYYYYYYYYYYYYY",
 "YYNYYYYYYNYYYYNNYNYYYYYNNYYYNY",
 "YYYYYYNYYYYNNYNYNNYYNYYYYYNYNY",
 "YNNYYYYYYNYYYYYNNNYYNYYYYYYYYY",
 "YYYNYYYYYYYYNYYYYYNNYYNYYYYYYY",
 "YYYYYNYYYYYYYYYYYYNNYYYYYYYYYY",
 "YYYYYYYYYNYYYYYYNNYYNYYYYYNYYY",
 "YYNYYYNYYYNYYYYYYYYYYNYYYYYYYY",
 "YYNYYYYYYYYYYYYYYYNYYYNYYYYYYY",
 "NYYYYYYYNYYYYYYNYYYYYYYNYYYYYY",
 "YYYYYYYYYYYYNYYNYYYYYYYYNYYYYY",
 "YYYNYYYYYYYYYNYYYYYYYYYYYNYYYY",
 "YYNYNYYYNYYYYYYYNYYYNYYYYYNYYY",
 "YYYYYNYYNYYYYYYYYYYYYYYYYYYNYY",
 "YYYYYNYYYYYYYNYNNYYYYYYYYYYYNN",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 522891760LL; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 8; int Arg1 = 8; string Arr2[] = {
 "NYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YNYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYNYYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYNYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYNYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYNYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYNYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYNYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYNYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYNYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYNYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYNYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYNYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYNYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYNYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYNYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYNYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYNYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYNYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYNYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYNYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYNYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYNYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYNYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYNYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYNYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYNYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYNYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYNY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1871589827250LL; verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FactoryCounting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

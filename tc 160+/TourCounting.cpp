#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long a[100][100];
long long b[100][100];
long long c[10000];
int n;
int M;
inline int calc(int i, int j) {
	return i*100 + j;
}
void mul(long long *x, long long *y) {
	for (int i=0; i<2*n; ++i)
		for (int j=0; j<2*n; ++j) {
			c[calc(i, j)] = 0;
			for (int k=0; k<2*n; ++k)
				c[calc(i, j)] = (c[calc(i, j)] + x[calc(i, k)]*y[calc(k, j)])%M;
		}
	memcpy(x, c, sizeof c);
}

class TourCounting {
	public:
	int countTours(vector <string> g, int k, int m) {
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		n = g.size();
		M = m;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				a[i][j] = (g[i][j]=='Y');

		for (int i=0; i<n; ++i) {
			a[i][i+n] = 1;
			a[i+n][i+n] = 1;
			b[i][i] = b[i+n][i+n] = 1;
		}

		for (int i=0; (1<<i)<=k; ++i) {
			if ((1<<i) & k)
				mul(&b[0][0], &a[0][0]);
			mul(&a[0][0], &a[0][0]);
		}

		long long sol = 0;
		for (int i=0; i<n; ++i)
			sol = (sol + b[i][i+n]-1)%m;

		return (int)sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNY",
 "NNYN",
 "YNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 100; int Arg3 = 12; verify_case(0, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"NYNNNNN",
 "NNYNNNN",
 "NNNYNNN",
 "NNNNYNN",
 "NNNNNYN",
 "NNNNNNY",
 "YNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; int Arg2 = 13; int Arg3 = 9; verify_case(1, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"NYNY",
 "NNNN",
 "YYNY",
 "NYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; int Arg2 = 1000000000; int Arg3 = 0; verify_case(2, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1500; int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"NYYNYYN",
 "YNYNYNY",
 "NYNYNYN",
 "YYYNYNY",
 "NNYYNNY",
 "NYYYNNY",
 "YYYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 100; int Arg3 = 72; verify_case(4, Arg3, countTours(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"NYYY",
 "YNYY",
 "YYNY",
 "YNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 10000; int Arg3 = 3564; verify_case(5, Arg3, countTours(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TourCounting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

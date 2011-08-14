#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int best[50][51][1200];
vector<int> a;
int n;

inline int mymin(int a, int b) {
	return a<b ? a:b;
}
inline int myabs(int x) {
	return x<0 ? -x:x;
}
int go(int x, int k, int low) {
	if (k <= 0) return 0;
	if (x == n) return 1000000000;
	if (low > 1197) return 1000000000;

	if (best[x][k][low] != -1) return best[x][k][low];
	best[x][k][low] = 1000000000;
	best[x][k][low] = mymin(best[x][k][low], go(x  , k  , low+1));
	best[x][k][low] = mymin(best[x][k][low], go(x+1, k  , low  ) + myabs(low-a[x]));
	best[x][k][low] = mymin(best[x][k][low], go(x+1, k-1, low+1) + myabs(low-a[x]));

	return best[x][k][low];
}
class Distincter {
	public:
	int disperse(vector <int> vec, int K) {
		a = vec;
		sort(a.begin(), a.end());
		for (int i=0; i<(int)a.size(); ++i) a[i] += 49;
		n = a.size();
		memset(best, 0xff, sizeof best);
		return go(0, K, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(0, Arg2, disperse(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(1, Arg2, disperse(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 1, 1, 1, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 6; verify_case(2, Arg2, disperse(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {8, 9, 7, 8, 7, 9, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 7; verify_case(3, Arg2, disperse(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4, 4, 5, 7, 7, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 4; verify_case(4, Arg2, disperse(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {576, 571, 571, 572, 575, 572, 571, 568, 573, 572, 569, 572}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; int Arg2 = 12; verify_case(5, Arg2, disperse(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Distincter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

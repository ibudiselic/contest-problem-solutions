#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

bool a[1001][1001];
int deg[1001];
bool used[1001];
bool ima[1001];
int n;
void dfs(int x) {
	used[x] = 1;
	for (int i=0; i<1001; ++i)
		if (a[x][i] && !used[i])
			dfs(i);
}
class OrderDoesMatter {
	public:
	int getOrder(vector <int> N, vector <int> M) {
		memset(a, 0, sizeof a);
		memset(deg, 0, sizeof deg);
		memset(ima, 0, sizeof ima);
		int najveci = -1;
		for (int i=0; i<(int)N.size(); ++i) {
			ima[N[i]] = ima[M[i]] = 1;
			a[N[i]][M[i]] = 1;
			++deg[N[i]];
			--deg[M[i]];
			najveci = max(najveci, N[i]);
		}
		int x = -10;
		int y = -10;
		int xx = 0;
		int yy = 0;
		for (int i=0; i<1001; ++i) {
			if (deg[i] != 0)
				if (x == -10) {
					x = deg[i];
					xx = i;
				} else if (y == -10) {
					y = deg[i];
					yy = i;
				} else {
					x = 0;
				}
		}
		if (x==0 || x!=-10&&y==-10)
			return -1;
		if (x!=-10 && (x+y!=0 || x!=1 && y!=1))
			return -1;
		memset(used, 0, sizeof used);

		if (x == 1)
			dfs(xx);
		else if (y == 1)
			dfs(yy);
		else
			dfs(N[0]);

		for (int i=0; i<1001; ++i)
			if (ima[i] && !used[i])
				return -1;


		if (x != -10)
			return xx*yy;
		else
			return najveci*najveci;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,7,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 49; verify_case(0, Arg2, getOrder(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,1,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, getOrder(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, getOrder(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, getOrder(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, getOrder(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OrderDoesMatter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

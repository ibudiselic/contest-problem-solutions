#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int G[50][50];
vector<int> B;
int N;
int C[50];
void dfs(int x, int comp) {
	C[x] = comp;
	for (int i=0; i<N; ++i)
		if (G[x][i] && C[i]==-1)
			dfs(i, comp);
}
int compSz(int comp) {
	int ret = 0;
	for (int i=0; i<N; ++i)
		ret += (C[i]==comp);

	return ret;
}
int edge(int x) {
	int ret = 0;
	for (int i=0; i<N; ++i)
		ret += G[x][i];

	return ret;
}
int compEdge(int comp) {
	int ret = 0;
	for (int i=0; i<N; ++i)
		if (C[i] == comp)
			ret += edge(i);

	return ret;
}
class SwapSorter {
	public:
	int maximizeSwaps(vector <int> A) {
		B = A;
		sort(B.begin(), B.end());
		set<int> S(B.begin(), B.end());
		N = S.size();
		map<int, int> M;
		int t = 0;
		for (set<int>::const_iterator it=S.begin(); it!=S.end(); ++it, ++t)
			M[*it] = t;

		for (int i=0; i<(int)A.size(); ++i) {
			A[i] = M[A[i]];
			B[i] = M[B[i]];
		}

		memset(G, 0, sizeof G);
		for (int i=0; i<(int)A.size(); ++i)
			if (A[i] != B[i])
				++G[A[i]][B[i]];

		int sol = 0;
		memset(C, 0xff, sizeof C);
		int c = 0;
		for (int x=0; x<N; ++x)
			if (C[x] == -1) {
				dfs(x, c);
				int cnt = compSz(c);
				int eCnt = compEdge(c);

				if (cnt == 2)
					sol += eCnt/2;
				else if (cnt > 2)
					sol += eCnt-1;
				++c;
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 1, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maximizeSwaps(Arg0)); }
	void test_case_1() { int Arr0[] = {7, 5, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, maximizeSwaps(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 1, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maximizeSwaps(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 7, 8, 12, 17, 19, 21, 23, 24, 25, 26, 27, 35}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, maximizeSwaps(Arg0)); }
	void test_case_4() { int Arr0[] = {2, 3, 3, 1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, maximizeSwaps(Arg0)); }
	void test_case_5() { int Arr0[] = {2, 3, 4, 1, 7, 7, 5, 5, 8, 7, 10, 10, 10, 9, 9, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(5, Arg1, maximizeSwaps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SwapSorter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
int C[50];
int deg[50];
int oddCnt[50];
bool G[50][50];
int N;
map<char, int> M;

void dfs(int x, int comp) {
	C[x] = comp;
	for (int i=0; i<N; ++i)
		if (G[x][i] && C[i]==-1)
			dfs(i, comp);
}
class MaxTrip {
	public:
	int minBuy(string portA, string portB) {
		memset(G, 0, sizeof G);
		M.clear();
		N = 0;
		for (int i=0; i<(int)portA.size(); ++i) {
			if (M.count(portA[i]) == 0)
				M[portA[i]] = N++;
			if (M.count(portB[i]) == 0)
				M[portB[i]] = N++;
		}
		memset(deg, 0, sizeof deg);

		for (int i=0; i<(int)portA.size(); ++i) {
			portA[i] = M[portA[i]];
			portB[i] = M[portB[i]];
			++deg[portA[i]];
			++deg[portB[i]];
		}

		memset(C, 0xff, sizeof C);
		memset(oddCnt, 0, sizeof oddCnt);
		memset(G, 0, sizeof G);
		for (int i=0; i<(int)portA.size(); ++i) {
			G[portA[i]][portB[i]] = 1;
			G[portB[i]][portA[i]] = 1;
		}

		int compCnt = 0;
		for (int i=0; i<N; ++i)
			if (C[i] == -1)
				dfs(i, compCnt++);

		for (int c=0; c<compCnt; ++c)
			for (int i=0; i<N; ++i)
				if (C[i]==c && (deg[i]&1))
					++oddCnt[c];

		int sol = compCnt-1;
		for (int c=0; c<compCnt; ++c)
			sol += max(0, oddCnt[c]-2)/2;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAX"; string Arg1 = "CBY"; int Arg2 = 1; verify_case(0, Arg2, minBuy(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAAAA"; string Arg1 = "CBXYQ"; int Arg2 = 2; verify_case(1, Arg2, minBuy(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AB"; string Arg1 = "AB"; int Arg2 = 1; verify_case(2, Arg2, minBuy(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MaxTrip ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool dead[50];
bool adj[50][50];
int C[50];
bool used[50];
int n;

int indeg(int u) {
	int ret = 0;
	for (int i=0; i<n; ++i)
		ret += adj[i][u];
	return ret;
}
int paths() {
	int ret = 0;
	for (int i=0; i<n; ++i)
		if (!dead[i] && !used[C[i]]) {
			used[C[i]] = 1;
			const int c = C[i];
			int sz = 0;
			bool is_cycle = 1;
			for (int j=0; j<n; ++j)
				if (!dead[j] && C[j]==c) {
					++sz;
					if (indeg(j) == 0)
						is_cycle = 0;
				}
			if (!is_cycle)
				ret += sz-1;
		}
	return ret;
}
int gcd(int m, int n) { return (n==0 ? m : gcd(n, m%n)); }
int cycles() {
	int ret = 0;
	for (int i=0; i<n; ++i)
		if (!dead[i]) {
			const int c = C[i];
			int sz = 0;
			bool is_cycle = 1;
			for (int j=0; j<n; ++j)
				if (!dead[j] && C[j]==c) {
					++sz;
					if (indeg(j) == 0) {
						is_cycle = 0;
						break;
					}
				}
			if (is_cycle)
				ret = gcd(sz, ret);
		}
	return ret;
}
void dfs(int x, int c) {
	C[x] = c;
	for (int i=0; i<n; ++i)
		if (!dead[i] && C[i]==-1 && (adj[x][i]||adj[i][x]))
			dfs(i, c);
}
void components() {
	int c = 0;
	for (int i=0; i<n; ++i)
		if (!dead[i] && C[i]==-1)
			dfs(i, c++);
}
void merge(int u, int v) {
	for (int i=0; i<n; ++i) {
		adj[u][i] |= adj[v][i];
		adj[i][u] |= adj[i][v];
	}
	dead[v] = 1;
}
void do_mandatory() {
	bool repeat = 1;
	while (repeat) {
	repeat = 0;
	for (int i=0; i<n; ++i)
		if (!dead[i])
		for (int j=i+1; j<n; ++j)
			if (!dead[j])
			for (int k=0; k<n; ++k)
				if (!dead[k] && (adj[i][k]&&adj[j][k] || adj[k][i]&&adj[k][j])) {
					merge(i, j);
					repeat = 1;
					goto ponovno;
				}
	ponovno: ;
	}
}

class MergingGraph {
	public:
	int distanceToCycle(vector <string> Adj) {
		n = Adj.size();
		memset(dead, 0, sizeof dead);
		memset(adj, 0, sizeof adj);
		memset(C, 0xff, sizeof C);
		memset(used, 0, sizeof used);

		bool any = 0;
		for (int i=0; i<n; ++i) {
			istringstream is(Adj[i]);
			int x;
			while (is >> x) {
				any = 1;
				adj[i][x] = 1;
			}
		}
		if (!any)
			return n;
		do_mandatory();
		components();
		const int cyc = cycles();
		const int p = paths();

		/*for (int i=0; i<n; ++i)
			if (!dead[i]) {
			for (int j=0; j<n; ++j)
				if (!dead[j])
					cerr << adj[i][j];
			cerr << ' ' << C[i] << '\n';
			}

		cerr << cyc << ' ' << p << '\n';*/
		if (cyc)
			return n-cyc;
		else
			return n-p;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 1", "2", "0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, distanceToCycle(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 1 1", "2", "0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, distanceToCycle(Arg0)); }
	void test_case_2() { string Arr0[] = {"1", "", "3", ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, distanceToCycle(Arg0)); }
	void test_case_3() { string Arr0[] = {"2", "5 4", "", "0", "0", "0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, distanceToCycle(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MergingGraph ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

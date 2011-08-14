#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -1, -1, 0, 0 };
const int dj[] = { -1, 0, 0, -1 };
const int dmi[] = { -1, 0, 1, 0 };
const int dmj[] = { 0, 1, 0, -1 };

vector<string> P;
bool A[52][52];
int m, n;
bool valid(int i, int j) {
	return i>=0 && i<=m+1 && j>=0 && j<=n+1;
}
bool has_air(int i, int j) {
	for (int d=0; d<4; ++d)
		if (valid(i+di[d], j+dj[d]) && P[i+di[d]][j+dj[d]]==' ')
			return true;

	return false;
}
bool is_edge(int i, int j, int d) {
	const int r1 = i + di[d];
	const int c1 = j + dj[d];
	const int r2 = i + di[(d+1)%4];
	const int c2 = j + dj[(d+1)%4];
	if (!valid(r1, c1) || !valid(r2, c2))
		return false;

	return P[r1][c1]!=' ' && P[r2][c2]!=' ' && P[r1][c1]!=P[r2][c2];
}
void dfs(int i, int j) {
	A[i][j] = 1;
	for (int d=0; d<4; ++d)
		if (is_edge(i, j, d) && !A[i+dmi[d]][j+dmj[d]])
			dfs(i+dmi[d], j+dmj[d]);
}
int get_deg(int i, int j) {
	int ret = 0;
	for (int d=0; d<4; ++d)
		ret += is_edge(i, j, d);

	return ret;
}
class CuttingPaper {
	public:
	int minCuts(vector <string> paper) {
		m = paper.size();
		n = 0;
		for (int i=0; i<m; ++i)
			n = max(n, (int)paper[i].size());
		P.assign(1, string(n+2, ' '));
		for (int i=0; i<m; ++i)
			P.push_back(" " + paper[i] + string(n-paper[i].size(), ' ') + " ");
		P.push_back(string(n+2, ' '));

		memset(A, 0, sizeof A);
		for (int i=0; i<=m+1; ++i)
			for (int j=0; j<=n+1; ++j)
				if (!A[i][j] && has_air(i, j))
					dfs(i, j);

		int sol = 0;
		for (int i=0; i<=m+1; ++i)
			for (int j=0; j<=n+1; ++j) {
				const int deg = get_deg(i, j);
				if (deg>0 && !A[i][j])
					return -1;

				sol += deg<2 || has_air(i, j) ? deg : deg-2;
			}

		return sol/2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AABB",
 "AABB",
 "BBDD",
 "BBDD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minCuts(Arg0)); }
	void test_case_1() { string Arr0[] = {"  X",
 " XXX A Y",
 "XX XX YYY",
 " XXX B Y",
 "  X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minCuts(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAA",
 "ABA",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minCuts(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABBBB",
 "AABBB",
 "AAABB",
 "AAAAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, minCuts(Arg0)); }
	void test_case_4() { string Arr0[] = {"AABB",
 "A BB",
 "CCDD",
 "CCDD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, minCuts(Arg0)); }
	void test_case_5() { string Arr0[] = {"BAA",
 "ABA",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, minCuts(Arg0)); }
	void test_case_6() { string Arr0[] = {"BBB CCCC",
 "BAB CD C",
 "BB  CCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, minCuts(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CuttingPaper ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

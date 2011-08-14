#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n, m;
int dp[50][50][51][3];
/* dp[i][j][k][l] is minimum possible number of wrong colors for the
first j chars of row i using k strokes with the last stroke being of color l */
int row[50][51];
int used[3001][51];
int best[3001];
class MiniPaint {
	public:
	int leastBad(vector <string> picture, int maxStrokes) {
		m = picture.size();
		n = picture[0].size();
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				picture[i][j] = (picture[i][j]=='B'); /* white = 0, black = 1, blank = 2 */

		memset(dp, 0, sizeof dp);
		for (int i=0; i<m; ++i) {
			for (int j=0; j<3; ++j) {
				dp[i][0][0][j] = 1;
				dp[i][0][1][j] = (picture[i][0]!=j);
			}
			for (int j=1; j<n; ++j)
				for (int k=0; k<=j+1; ++k) {
					for (int x=0; x<2; ++x)
						dp[i][j][k][x] = dp[i][j-1][k][x] + (k==0 || picture[i][j]!=x);
					dp[i][j][k][2] = *min_element(dp[i][j-1][k], dp[i][j-1][k]+3) + 1;
					if (k > 0) {
						const int t = *min_element(dp[i][j-1][k-1], dp[i][j-1][k-1]+3);
						for (int x=0; x<2; ++x)
							dp[i][j][k][x] = min(dp[i][j][k][x], t + (k==0 || picture[i][j]!=x));
					}
				}
		}
		for (int i=0; i<m; ++i)
			for (int k=0; k<=n; ++k)
				row[i][k] = *min_element(dp[i][n-1][k], dp[i][n-1][k]+3);
		memset(used[0], 0, sizeof used[0]);
		memset(best, 0, sizeof best);

		best[0] = n*m;
		for (int i=1; i<=maxStrokes; ++i) {
			best[i] = best[i-1];
			memmove(used[i], used[i-1], sizeof used[i]);
			for (int j=0; j<i; ++j) {
				const int diff = i-j;
				for (int k=0; k<m; ++k)
					if (used[j][k]+diff <= n  &&  best[j] - (row[k][used[j][k]]-row[k][used[j][k]+diff]) < best[i]) {
						best[i] = best[j] - (row[k][used[j][k]]-row[k][used[j][k]+diff]);
						memmove(used[i], used[j], sizeof used[i]);
						used[i][k] += diff;
					}
			}
		}

		return best[maxStrokes];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 0; verify_case(0, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(1, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 60; verify_case(2, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 40; verify_case(3, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(4, Arg2, leastBad(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MiniPaint ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

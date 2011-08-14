#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long sum[51][51];
class DividingRectangle {
	public:
	long long maxProduct(vector <string> rectangle) {
		memset(sum, 0, sizeof sum);
		int m = rectangle.size();
		int n = rectangle[0].size();

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + rectangle[i][j]-'0';

		long long best = 0;
		for (int i1=1; i1<=m; ++i1)
			for (int j1=1; j1<=n; ++j1) {
				const long long rect1 = sum[i1][j1];
				if (i1 == m) {
					for (int j2=j1+1; j2<n; ++j2) {
						const long long rect2 = sum[m][j2] - rect1;
						const long long rect3 = sum[m][n] - rect2 - rect1;
						best = max(best, rect1*rect2*rect3);
					}
					for (int i2=1; i2<m; ++i2) {
						const long long rect2 = sum[i2][n] - sum[i2][j1];
						const long long rect3 = sum[m][n] - rect1 - rect2;
						best = max(best, rect1*rect2*rect3);
					}
				} else if (j1 == n) {
					for (int i2=i1+1; i2<m; ++i2) {
						const long long rect2 = sum[i2][n] - rect1;
						const long long rect3 = sum[m][n] - rect1 - rect2;
						best = max(best, rect1*rect2*rect3);
					}
					for (int j2=1; j2<n; ++j2) {
						const long long rect2 = sum[m][j2] - sum[i1][j2];
						const long long rect3 = sum[m][n] - rect1 - rect2;
						best = max(best, rect1*rect2*rect3);
					}
				} else if (i1 < m) {
					// rect2 is below rect1
					long long rect2 = sum[m][j1] - rect1;
					long long rect3 = sum[m][n] - rect2 - rect1;
					best = max(best, rect1*rect2*rect3);

					rect2 = sum[m][n] - sum[i1][n];
					rect3 = sum[m][n] - rect2 - rect1;
					best = max(best, rect1*rect2*rect3);
				} else if (j1 < n) {
					// rect2 is to the right of rect1
					long long rect2 = sum[i1][n] - rect1;
					long long rect3 = sum[m][n] - rect2 - rect1;
					best = max(best, rect1*rect2*rect3);

					rect2 = sum[m][n] - sum[m][j1];
					rect3 = sum[m][n] - rect2 - rect1;
					best = max(best, rect1*rect2*rect3);
				}
			}

		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11911103"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 108LL; verify_case(0, Arg1, maxProduct(Arg0)); }
	void test_case_1() { string Arr0[] = {"123","456","789"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3264LL; verify_case(1, Arg1, maxProduct(Arg0)); }
	void test_case_2() { string Arr0[] = {"7","9","3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 189LL; verify_case(2, Arg1, maxProduct(Arg0)); }
	void test_case_3() { string Arr0[] = {"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999",
"99999999999999999999999999999999999999999999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 421749281250LL; verify_case(3, Arg1, maxProduct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DividingRectangle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

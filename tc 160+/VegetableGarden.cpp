#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct State {
	int i, j, mask, cost;
	State(int i_, int j_, int mask_): i(i_), j(j_), mask(mask_) {}
};

int len[51][51][1<<10];
int under[51][51];
int bc[1<<10];
class VegetableGarden {
	public:
	vector <int> getMinDistances(vector <string> garden) {
		int m = garden.size();
		int n = garden[0].size();
		int cnt = 0;

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (garden[i][j] == 'I')
					garden[i][j] = cnt++;

		int xi = cnt;

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (garden[i][j] == 'X')
					garden[i][j] = xi++;

		bc[0] = 0;
		for (int i=1; i<(1<<cnt); ++i)
			bc[i] = bc[i>>1] + (i&1);

		memset(under[m], 0, sizeof under[m]);
		for (int i=m-1; i>=0; --i)
			for (int j=0; j<n; ++j)
				under[i][j] = under[i+1][j] | (garden[i][j] < 10 ? (1<<garden[i][j]) : 0);

		const int di[] = { -1, 0, 1, 0 };
		const int dj[] = { 0, 1, 0, -1 };

		for (int i=0; i<=m; ++i)
			for (int j=0; j<=n; ++j)
				for (int mask=0; mask<(1<<xi); ++mask)
					len[i][j][mask] = 1234567890;

		queue<State> Q;
		Q.push(State(0, 0, 0));
		len[0][0][0] = 0;

		while (!Q.empty()) {
			int i = Q.front().i;
			int j = Q.front().j;
			int mask = Q.front().mask;
			Q.pop();

			for (int d=0; d<4; ++d) {
				const int r = i + di[d];
				const int c = j + dj[d];
				if (r>=0 && r<=m && c>=0 && c<=n) {
					int nmask = mask;
					if (d == 1)
						nmask ^= under[i][j];
					else if (d == 3)
						nmask ^= under[r][c];

					if (len[r][c][nmask] > len[i][j][mask]+1) {
						len[r][c][nmask] = len[i][j][mask]+1;
						Q.push(State(r, c, nmask));
					}
				}
			}
		}

		vector<int> ret(cnt, 1234567890);
		for (int i=1; i<(1<<cnt); ++i)
			ret[bc[i]-1] = min(ret[bc[i]-1], len[0][0][i]);

		return ret;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"I"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMinDistances(Arg0)); }
	void test_case_1() { string Arr0[] = {"XX",
 "XI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMinDistances(Arg0)); }
	void test_case_2() { string Arr0[] = {"III",
 "IXI",
 "III"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 6, 8, 10, 12, 14, 16, 18 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMinDistances(Arg0)); }
	void test_case_3() { string Arr0[] = {"X.I",
 ".I.",
 "I.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 10, 14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMinDistances(Arg0)); }
	void test_case_4() { string Arr0[] = {"IIXIIXIXII"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 6, 12, 14, 20, 26, 28 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getMinDistances(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VegetableGarden ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

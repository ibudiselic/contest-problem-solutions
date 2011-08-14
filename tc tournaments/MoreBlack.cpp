#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool done[50][50];
vector<string> B;
int m, n;
int Color[2];

bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

void go(int i, int j, int col) {
	++Color[col];
	done[i][j] = 1;

	for (int d=0; d<4; ++d) {
		const int r = i + di[d];
		const int c = j + dj[d];

		if (valid(r, c) && B[r][c]=='#' && !done[r][c])
			go(r, c, 1-col);
	}
}

void doColoring(int i, int j, int col) {
	B[i][j] = (col ? 'w' : 'b');

	for (int d=0; d<4; ++d) {
		const int r = i + di[d];
		const int c = j + dj[d];

		if (valid(r, c) && B[r][c]=='#')
			doColoring(r, c, 1-col);
	}
}
class MoreBlack {
	public:
	vector <string> color(vector <string> board) {
		B = board;
		m = B.size();
		n = B[0].size();
		memset(done, 0, sizeof done);
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (B[i][j] == '#') {
					Color[0] = Color[1] = 0;
					go(i, j, 0);

					if (Color[0] >= Color[1])
						doColoring(i, j, 0);
					else
						doColoring(i, j, 1);
				}

		return B;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {".#.", "###", ".#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".b.", "bwb", ".b." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, color(Arg0)); }
	void test_case_1() { string Arr0[] = {"#.#.#.", ".#.#.#", "#.#.#.", ".#.#.#", "#.#.#.", ".#.#.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"b.b.b.", ".b.b.b", "b.b.b.", ".b.b.b", "b.b.b.", ".b.b.b" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, color(Arg0)); }
	void test_case_2() { string Arr0[] = {"######"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bwbwbw" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, color(Arg0)); }
	void test_case_3() { string Arr0[] = {".#.", ".#.", "###", ".#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".w.", ".b.", "bwb", ".b." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, color(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MoreBlack ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

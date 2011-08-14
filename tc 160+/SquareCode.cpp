#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

class SquareCode {
	public:
	vector <string> completeIt(vector <string> grille) {
		const int n = grille.size();
		vector<pii> p[4];

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				p[0].push_back(pii(i, j));

		for (int j=0; j<n; ++j)
			for (int i=n-1; i>=0; --i)
				p[1].push_back(pii(i, j));

		for (int i=n-1; i>=0; --i)
			for (int j=n-1; j>=0; --j)
				p[2].push_back(pii(i, j));

		for (int j=n-1; j>=0; --j)
			for (int i=0; i<n; ++i)
				p[3].push_back(pii(i, j));

		for (int i=0; i<(int)p[0].size(); ++i) {
			int cnt = 0;
			for (int j=0; j<4; ++j)
				cnt += (grille[p[j][i].first][p[j][i].second]=='.');
			if (cnt > 1)
				return vector<string>();
			else if (cnt == 0) {
				int r=0, c=0;
				for (int j=0; j<4; ++j)
					if (p[j][i].first<n/2 && p[j][i].second<n/2) {
						r = p[j][i].first;
						c = p[j][i].second;
						break;
					}
				grille[r][c] = '.';
			}
		}
		return grille;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"XX..",
 "XX.X",
 ".XXX",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "XX..",  "XX.X",  ".XXX",  "XXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, completeIt(Arg0)); }
	void test_case_1() { string Arr0[] = {"XXX.",
 "XX.X",
 ".XXX",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "XXX.",  ".X.X",  ".XXX",  "XXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, completeIt(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXX.",
 "XX.X",
 ".X.X",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, completeIt(Arg0)); }
	void test_case_3() { string Arr0[] = {"XXXXXX",
 "XXXXX.",
 "XXXX..",
 "XXX.XX",
 "X.XXXX",
 "XX.XX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "XXXXXX",  ".XXXX.",  "X.XX..",  "XXX.XX",  "X.XXXX",  "XX.XX." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, completeIt(Arg0)); }
	void test_case_4() { string Arr0[] = {"XXX.XX",
 ".XXXX.",
 "X.XXX.",
 "XXX.XX",
 "X.XXXX",
 "XX.XX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, completeIt(Arg0)); }
	void test_case_5() { string Arr0[] = {"XXXXX.XX",
 "XXXX.XXX",
 "XXX..X.X",
 ".XXXXXXX",
 "XXXXXXXX",
 "XXXXXXXX",
 "X.XXXXXX",
 "XXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "....X.XX",  ".XX..XXX",  "X....X.X",  ".XX.XXXX",  "XXXXXXXX",  "XXXXXXXX",  "X.XXXXXX",  "XXXXXXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, completeIt(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SquareCode ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

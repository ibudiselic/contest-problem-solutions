#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { 0, 1, 1 };
const int dj[] = { 1, 1, 0 };
string toStr(int i, int j) {
	ostringstream os;
	os << i << ' ' << j;
	return os.str();
}
class WordFind {
	public:
	vector <string> findWords(vector <string> grid, vector <string> wordList) {
		vector<string> sol;

		int m = grid.size();
		int n = grid[0].size();

		for (int k=0; k<(int)wordList.size(); ++k) {
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j)
					if (grid[i][j] == wordList[k][0])
						for (int d=0; d<3; ++d) {
							if (i+(int)wordList[k].size()*di[d]<=m && j+(int)wordList[k].size()*dj[d]<=n) {
								for (int x=0; x<(int)wordList[k].size(); ++x)
									if (grid[i+x*di[d]][j+x*dj[d]] != wordList[k][x])
										goto NEXT_D;

								sol.push_back(toStr(i, j));
								goto DONE_K;
								NEXT_D:;
							}
						}
			sol.push_back("");
			DONE_K: ;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"TEST",
 "GOAT",
 "BOAT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"GOAT", "BOAT", "TEST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "1 0",
  "2 0",
  "0 0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findWords(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"SXXX",
 "XQXM",
 "XXLA",
 "XXXR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SQL", "RAM"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "0 0",
  "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findWords(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"EASYTOFINDEAGSRVHOTCJYG",
 "FLVENKDHCESOXXXXFAGJKEO",
 "YHEDYNAIRQGIZECGXQLKDBI",
 "DEIJFKABAQSIHSNDLOMYJIN",
 "CKXINIMMNGRNSNRGIWQLWOG",
 "VOFQDROQGCWDKOUYRAFUCDO",
 "PFLXWTYKOITSURQJGEGSPGG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "0 0",
  "1 6",
  "0 22",
  "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findWords(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordFind ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

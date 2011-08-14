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

vector< pair<int, int> > A;
unsigned r[4], c[4], q[4];
inline int get_q(int i, int j) {
	return (i<2 ? 0 : 2) + (j<2 ? 0 : 1);
}
inline bool test(int i, int j, int t) {
	return ((r[i] & (1u<<t))==0) && ((c[j] & (1u<<t))==0) && ((q[get_q(i, j)] & (1u<<t))==0);
}
inline void mark(int i, int j, int t) {
	r[i] |= (1u<<t);
	c[j] |= (1u<<t);
	q[get_q(i, j)] |= (1u<<t);
}
inline void unmark(int i, int j, int t) {
	r[i] ^= (1u<<t);
	c[j] ^= (1u<<t);
	q[get_q(i, j)] ^= (1u<<t);
}
int go(int x) {
	if (x == (int)A.size())
		return 1;

	const int i = A[x].first;
	const int j = A[x].second;

	int ret = 0;
	for (int t=0; t<4; ++t)
		if (test(i, j, t)) {
			mark(i, j, t);
			ret += go(x+1);
			unmark(i, j, t);
		}
	return ret;
}
class SillySudoku {
	public:
	int countWays(vector <string> board) {
		A.clear();
		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);
		memset(q, 0, sizeof q);
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				if (board[i][j] == '-') {
					A.push_back(make_pair(i, j));
				} else {
					if (!test(i, j, (board[i][j]-'0'-1)))
						return 0;
					mark(i, j, board[i][j]-'0'-1);
				}
		return go(0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"--21",
 "--34",
 "2143",
 "3412"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {"--1-",
 "--1-",
 "----",
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"1---",
 "-42-",
 "-3--",
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"1---",
 "--1-",
 "-1--",
 "---1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {"1---",
 "----",
 "----",
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; verify_case(4, Arg1, countWays(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SillySudoku ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

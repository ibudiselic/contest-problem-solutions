#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
template<class T> vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}
class CrossWordPuzzle {
	public:
	int countWords(vector <string> board, int size) {
		int sol = 0;
		for (int i=0; i<(int)board.size(); ++i) {
			vector<string> t = tokenize<string>(board[i], "X");

			for (int j=0; j<(int)t.size(); ++j)
				sol += ((int)t[j].size() == size);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X....X",
 "X.XX.X",
 "...X..",
 "X.XX.X",
 "..X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, countWords(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"...X...",
 ".X...X.",
 "..X.X..",
 "X..X..X",
 "..X.X..",
 ".X...X.",
 "...X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(1, Arg2, countWords(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".....X....X....",
 ".....X....X....",
 "..........X....",
 "....X....X.....",
 "...X....X....XX",
 "XXX...X....X...",
 ".....X....X....",
 ".......X.......",
 "....X....X.....",
 "...X....X...XXX",
 "XX....X....X...",
 ".....X....X....",
 "....X..........",
 "....X....X.....",
 "....X....X....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 8; verify_case(2, Arg2, countWords(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; int Arg2 = 0; verify_case(3, Arg2, countWords(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"....",
 "....",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(4, Arg2, countWords(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CrossWordPuzzle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

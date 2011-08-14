#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int R[50];
class TheSquareDivTwo {
	public:
	vector <string> solve(vector <string> board) {
        for (int i=0; i<(int)board.size(); ++i) {
            R[i] = count(board[i].begin(), board[i].end(), 'C');
        }
        for (int i=0; i<(int)board.size(); ++i) {
            for (int j=0; j<(int)board.size()-R[i]; ++j) {
                board[j][i] = '.';
            }
            for (int j=(int)board.size()-R[i]; j<(int)board.size(); ++j) {
                board[j][i] = 'C';
            }
        }
        
        return board;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"..",
 "C."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..", ".C" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"CC",
 ".C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"C.", "CC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {".C..",
 "CC.C",
 "..C.",
 "CCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"...C", ".C.C", ".C.C", "CCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"...CCC",
 "...CCC",
 "...CCC",
 "CCC...",
 "CCC...",
 "CCC..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"......", "......", "......", "CCCCCC", "CCCCCC", "CCCCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arr0[] = {".....C",
 "....CC",
 "...CCC",
 "..CCCC",
 ".CCCCC",
 "CCCCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".....C", "....CC", "...CCC", "..CCCC", ".CCCCC", "CCCCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { string Arr0[] = {"C.C..C.C..C..C.",
 "CCC...C..CCC.C.",
 "......CC...CCCC",
 ".C..CC.C.C.C.C.",
 "C....C.C......C",
 ".....C..CCCCC.C",
 "CCC.......CCCCC",
 "..C.C..C.C...C.",
 "CCC....CCC.CC..",
 "CC.CCCC.CCCC...",
 ".C..C.CC.C.CC.C",
 "C.CCCC..CC..C.C",
 ".CCCC.CCCCCC...",
 "..C...C.CCC.CC.",
 "CCCC..CCC.C...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"...............", "...............", "...............", "...............", "...............", ".........C..C..", ".........C.CC..", ".C....C.CCCCC.C", ".C.C.CC.CCCCCCC", "CCCC.CC.CCCCCCC", "CCCC.CCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, solve(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheSquareDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

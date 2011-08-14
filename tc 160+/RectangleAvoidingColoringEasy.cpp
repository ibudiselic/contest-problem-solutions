#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> B;
int m, n;

bool test(int i, int j) {
    for (int ii=0; ii<i; ++ii) {
        for (int jj=0; jj<j; ++jj) {
            if (B[ii][jj]==B[i][j] && B[ii][j]==B[i][j] && B[i][jj]==B[i][j]) {
                return false;
            }
        }
    }
    return true;
}
int go(int i, int j) {
    if (i == m) {
        return 1;
    } else if (j == n) {
        return go(i+1, 0);
    } else if (B[i][j] == '?') {
        int ret = 0;
        B[i][j] = 'B';
        if (test(i, j)) {
            ret += go(i, j+1);
        }
        B[i][j] = 'W';
        if (test(i, j)) {
            ret += go(i, j+1);
        }
        B[i][j] = '?';
        return ret;
    } else {
        return test(i, j) ? go(i, j+1) : 0;
    }
}
class RectangleAvoidingColoringEasy {
	public:
	int count(vector <string> board) {
	    B = board;
        m = B.size();
        n = B[0].size();
        return go(0, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"??",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"B?",
 "?B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"WW",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"??B??",
 "W???W",
 "??B??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RectangleAvoidingColoringEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

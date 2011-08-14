#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> T;
int sol;

void upd() {
    int win_score = 0;
    for (int i=0; i<(int)T.size(); ++i) {
        int i_win = count(T[i].begin(), T[i].end(), 'W');
        for (int j=0; j<(int)T.size(); ++j) {
            i_win += (T[j][i] == 'L');
        }
        win_score = max(win_score, i_win);
    }
    sol = min(sol, win_score);
}
    
void go(int i, int j) {
    if (i == (int)T.size()) {
        upd();
        return;
    }
    if (j == (int)T.size()) {
        go(i+1, 0);
        return;
    }
    if (T[i][j] != '?') {
        go(i, j+1);
        return;
    }
    T[i][j] = 'W';
    go(i, j+1);
    T[i][j] = 'L';
    go(i, j+1);
    T[i][j] = '?';
}
class TheBasketballDivTwo {
	public:
	int find(vector <string> table) {
	    T = table;
        sol = 123456789;
        go(0, 1);
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X?", "?X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"XW", "LX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"XWL", "?XW", "WLX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"XW?", "LX?", "??X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBasketballDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

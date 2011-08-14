#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string to_str(int x) {
    ostringstream os;
    os << x;
    return os.str();
}

int board[50][50];
const int di[] = { 0, -1, 0, 1 };
const int dj[] = { 1, 0, -1, 0 };
class PrettyPrintASpiral {
	public:
	vector <string> getWindow(int row1, int col1, int row2, int col2) {
		int i = 0;
        int j = 0;
        int rem = (row2-row1+1) * (col2-col1+1);
        int val = 1;
        int moves = 1;
        int moves_left = 1;
        int dir = 0;
        bool extend = false;

        while (rem) {
            if (row1<=i && i<=row2 && col1<=j && j<=col2) {
                board[i-row1][j-col1] = val;
                --rem;
            }
            ++val;
            
            i += di[dir];
            j += dj[dir];
            if (--moves_left == 0) {
                if (extend) {
                    ++moves;
                }
                extend = !extend;
                moves_left = moves;
                dir = (dir+1) % 4;
            }
        }

        int sz = 0;
        for (int i=0; i<row2-row1+1; ++i) {
            for (int j=0; j<col2-col1+1; ++j) {
                sz = max(sz, (int)to_str(board[i][j]).size());
            }
        }

        vector<string> sol;
        for (int i=0; i<row2-row1+1; ++i) {
            string str;
            for (int j=0; j<col2-col1+1; ++j) {
                string t = to_str(board[i][j]);
                str += ' ' + string(sz-t.size(), ' ') + t;
            }
            sol.push_back(str.substr(1));
        }

        return sol; 
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; string Arr4[] = {"1" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getWindow(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = -1; int Arg1 = -2; int Arg2 = -1; int Arg3 = 1; string Arr4[] = {"18  5  4  3" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getWindow(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = -2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 3; string Arr4[] = {"13 30", "12 29", "11 28" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getWindow(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = -3; int Arg1 = -3; int Arg2 = 2; int Arg3 = 0; string Arr4[] = {"37 36 35 34", "38 17 16 15", "39 18  5  4", "40 19  6  1", "41 20  7  8", "42 21 22 23" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getWindow(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PrettyPrintASpiral ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int color[3][3] = { { 0, 1, 0 }, { 1, 2, 1 }, { 0, 1, 0 } };
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
class CubeWalking {
	public:
	string finalPosition(string movement) {
		int i = 1;
        int j = 1;
        int d = 0;
        for (int t=0; t<(int)movement.size(); ++t) {
            if (movement[t] == 'R') {
                ++d;
                if (d == 4) {
                    d = 0;
                }
            } else if (movement[t] == 'L') {
                --d;
                if (d < 0) {
                    d = 3;
                }
            } else {
                i += di[d];
                j += dj[d];
                if (i < 0) {
                    i = 2;
                } else if (i > 2) {
                    i = 0;
                }
                if (j < 0) {
                    j = 2;
                } else if (j > 2) {
                    j = 0;
                }
            }
        }
        
        return color[i][j]==0 ? "RED" : color[i][j]==1 ? "BLUE" : "GREEN";
	}








   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLRR"; string Arg1 = "GREEN"; verify_case(0, Arg1, finalPosition(Arg0)); }
	void test_case_1() { string Arg0 = "WWWWWWWWWWWW"; string Arg1 = "GREEN"; verify_case(1, Arg1, finalPosition(Arg0)); }
	void test_case_2() { string Arg0 = "WLWRW"; string Arg1 = "RED"; verify_case(2, Arg1, finalPosition(Arg0)); }
	void test_case_3() { string Arg0 = "WWLLWRWLWLLRWW"; string Arg1 = "BLUE"; verify_case(3, Arg1, finalPosition(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CubeWalking ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

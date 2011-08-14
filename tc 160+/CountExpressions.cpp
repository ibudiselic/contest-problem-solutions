#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

set<string> sol;
long long V;
long long X, Y;
string strX, strY;
string to_str(long long x) {
    ostringstream os;
    os << x;
    return os.str();
}

void go(int cx, int cy, int v, const string &s) {
    if (cx==0 && cy==0) {
        if (v == V) {
            sol.insert(s);
        }
        return;
    }

    if (cx > 0) {
        go(cx-1, cy, v+X, s + '+' + strX);
        go(cx-1, cy, v-X, s + '-' + strX);
        go(cx-1, cy, v*X, s + '*' + strX);
    }

    if (cy > 0) {
        go(cx, cy-1, v+Y, s + '+' + strY);
        go(cx, cy-1, v-Y, s + '-' + strY);
        go(cx, cy-1, v*Y, s + '*' + strY);
    }
}

class CountExpressions {
	public:
	int calcExpressions(int x, int y, int val) {
		sol.clear();
        X = x;
        Y = y;
        V = val;

        strX = to_str(x);
        strY = to_str(y);

        go(1, 2, x, strX);
        go(2, 1, y, strY);

        return sol.size();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 8; int Arg2 = 16; int Arg3 = 9; verify_case(0, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 7; int Arg3 = 5; verify_case(1, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 100; int Arg2 = 98010000; int Arg3 = 6; verify_case(2, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = -99; int Arg1 = 42; int Arg2 = -1764; int Arg3 = 2; verify_case(3, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = -100; int Arg2 = -100000000; int Arg3 = 0; verify_case(4, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 5; int Arg3 = 17; verify_case(5, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CountExpressions ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

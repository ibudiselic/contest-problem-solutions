#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Pathfinding {
	public:
	int getDirections(int x, int y) {
		if (x == 0) {
			if (y == 0)
				return 0;
			if (y > 0)
				return y;

			return -y + 2 + ((-y)%2 == 0)*2;
		} else if (x > 0) {
			if (x%2==0 && y>=0 || x%2==1 && y<=0)
				return x+abs(y);
			return (x-1) + abs(y) + 1 + (abs(y)%2==1)*2;
		} else {
			x = -x;
			if (y == 0) {
				return 2 + x + (x%2==0)*2;
			} else if (y > 0) {
				if (y%2 == 1)
					return x+y;
				else
					return (y-1) + x + 1 + (x%2==1)*2;
			} else {
				y = -y;
				if (x%2==1 || y%2==1)
					return 2+x+y;
				else
					return 4+x+y;
			}
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = -4; int Arg2 = 8; verify_case(0, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = -4; int Arg2 = 9; verify_case(1, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 9; verify_case(2, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -1; int Arg1 = -4; int Arg2 = 7; verify_case(3, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; verify_case(4, Arg2, getDirections(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Pathfinding ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

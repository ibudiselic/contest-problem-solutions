#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int MAX_DIM = 1000000;

const int di[] = { 1, -1, -1, 1 };
const int dj[] = { 1, 1, -1, -1 };

class BallBouncing {
	public:
	int bounces(int rows, int columns, int startrow, int startcol, vector <string> holes) {
		vector<bool> slash(2*MAX_DIM, false); // 0, 2
		vector<bool> backslash(2*MAX_DIM, false); // 1, 3

		const int R = rows-1;
		const int C = columns-1;

		for (int i=0; i<(int)holes.size(); ++i) {
			istringstream is(holes[i]);
			int rr, cc;
			is >> rr >> cc;
			if (rr-startrow>0 && cc-startcol>0 && rr-startrow==cc-startcol)
				return 0;
			slash[rr-cc + MAX_DIM] = backslash[rr+cc] = true;
		}
		int dir = 0;
		int r = startrow;
		int c = startcol;
		int sol = 0;

		while (sol < 8000000) {
			if (0==dir || 2==dir) {
				if (slash[r-c + MAX_DIM] && sol)
					return sol;
			} else {
				if (backslash[r+c] && sol)
					return sol;
			}

			int rlen = (1==di[dir]) ? R-r : r;
			int clen = (1==dj[dir]) ? C-c : c;

			r += di[dir]*min(rlen, clen);
			c += dj[dir]*min(rlen, clen);

			int dr = -di[dir];
			int dc = -dj[dir];
			if (rlen > clen) {
				dr = -dr;
				c += dj[dir];
			} else if (clen > rlen) {
				dc = -dc;
				r += di[dir];
			}

			for (dir=0; dir<4; ++dir)
				if (di[dir]==dr && dj[dir]==dc)
					break;
			++sol;
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 11; int Arg2 = 2; int Arg3 = 1; string Arr4[] = { "1 5", "5 3", "4 4" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(0, Arg5, bounces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 5; int Arg2 = 5; int Arg3 = 3; string Arr4[] = { "1 3" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 7; verify_case(1, Arg5, bounces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 7; int Arg2 = 4; int Arg3 = 4; string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(2, Arg5, bounces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; string Arr4[] = { "2 2" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 0; verify_case(3, Arg5, bounces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 6; int Arg2 = 0; int Arg3 = 5; string Arr4[] = { "4 1", "3 2", "4 3", "2 1", "3 0", "5 2" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(4, Arg5, bounces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 1000000; int Arg1 = 999999; int Arg2 = 66246; int Arg3 = 84332; string Arr4[] = { "854350 4982" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1662562; verify_case(5, Arg5, bounces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 3; int Arg3 = 4; string Arr4[] = { "0 6", "2 3" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; verify_case(6, Arg5, bounces(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 0; int Arg3 = 1; string Arr4[] = { "0 3" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(7, Arg5, bounces(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BallBouncing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

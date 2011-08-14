#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { 0, 1, 0, -1 };
const int dj[] = { 1, 0, -1, 0 };
class Spirals {
	public:
	vector <string> draw(int width, int height, int startx, int starty) {
		vector<string> sol(height, string(width, '.'));

		int r = starty;
		int c = startx;
		int d = 0;
		int num = 2;
		sol[r][c] = '0';
		r += di[d];
		c += dj[d];
		if (r<0 || c<0 || r>=height || c>=width || sol[r][c]!='.')
			return sol;
		sol[r][c] = '1';
		while (1) {
			const int d_new = (d+1)%4;
			const int i = r + di[d_new];
			const int j = c + dj[d_new];
			if (i<0 || j<0 || i>=height || j>=width)
				break;
			if (sol[i][j]=='.') {
				r = i;
				c = j;
				d = d_new;
			} else {
				r += di[d];
				c += dj[d];
				if (r<0 || c<0 || r>=height || c>=width || sol[r][c]!='.')
					break;
			}
			sol[r][c] = char(num + '0');
			num = (num + 1)%10;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 2; string Arr4[] = {"01234", "96789", "85010", "74321", "65432" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, draw(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 1; int Arg3 = 1; string Arr4[] = {"6789.", "5010.", "4321.", "5432.", ".....", "....." }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, draw(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 0; int Arg3 = 0; string Arr4[] = {"01........", "32........", "..........", "..........", "..........", "..........", "..........", "..........", "..........", ".........." }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, draw(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 9; int Arg3 = 9; string Arr4[] = {"..........", "..........", "..........", "..........", "..........", "..........", "..........", "..........", "..........", ".........0" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, draw(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 0; int Arg3 = 5; string Arr4[] = {".", ".", ".", ".", ".", "0", ".", ".", ".", "." }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, draw(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 11; int Arg1 = 7; int Arg2 = 8; int Arg3 = 3; string Arr4[] = {"...........", "......01234", "......96789", "......85010", "......74321", "......65432", "..........." }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, draw(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Spirals ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

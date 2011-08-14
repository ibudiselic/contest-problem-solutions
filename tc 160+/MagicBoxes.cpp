#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
NE RADI
*/

bool canMake[31][31][1<<15];
bool done[31][31][1<<15];

bool go(int x, int y, int mask) {
	assert(x>=0 && y>=0);
	if (mask == 0)
		return true;
	if (x > y)
		swap(x, y);
	if (done[x][y][mask])
		return canMake[x][y][mask];

	done[x][y][mask] = true;
	for (int i=15; i>0; --i)
		if (mask & (1<<(i-1))) {
			if (i > x)
				return (canMake[x][y][mask] = false);

			int left = (mask ^ (1<<(i-1)));
			if (left == 0)
				return canMake[x][y][mask] = true;

			for (int m1=0; m1<left; m1=(((~left | m1)+1)&left)) {
				int m2 = left^m1;
				assert((m1|m2) == left);
				assert((m1&m2) == 0);
				if (go(x-i, y, m1) && go(i, y-i, m2)
					||
					go(x-i, i, m1) && go(x, y-i, m2))
				return (canMake[x][y][mask] = true);
			}
			if (go(x-i, y, left) || go(x-i, i, left))
				return (canMake[x][y][mask] = true);

			break;
		}
	for (int i=1; i<16; ++i)
		if (mask & (1<<(i-1))) {
			int left = (mask ^ (1<<(i-1)));
			if (left == 0)
				return canMake[x][y][mask] = true;

			for (int m1=0; m1<left; m1=(((~left | m1)+1)&left)) {
				int m2 = left^m1;
				assert((m1|m2) == left);
				assert((m1&m2) == 0);
				if (go(x-i, y, m1) && go(i, y-i, m2)
					||
					go(x-i, i, m1) && go(x, y-i, m2))
				return (canMake[x][y][mask] = true);
			}
			if (go(x-i, y, left) || go(x-i, i, left))
				return (canMake[x][y][mask] = true);

			break;
		}

	return (canMake[x][y][mask] = false);
}
class MagicBoxes {
	public:
	int biggest(int x, int y) {
		memset(done, 0, sizeof done);

		for (int i=15; i>1; --i)
			if (go(x, y, (1<<i)-1))
				return i;

		return 1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, biggest(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; verify_case(1, Arg2, biggest(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; verify_case(2, Arg2, biggest(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 26; int Arg1 = 26; int Arg2 = 11; verify_case(3, Arg2, biggest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MagicBoxes ___test;
    ___test.run_test(3);
    }
// END CUT HERE

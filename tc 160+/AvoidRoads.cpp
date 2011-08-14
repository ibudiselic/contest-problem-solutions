#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
struct Point {
	int x, y;
	Point(int xx, int yy): x(xx), y(yy) {}
};
bool operator<(const Point &a, const Point &b) {
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}


bool l[101][101];
bool d[101][101];
long long sol[101][101];
class AvoidRoads {
	public:
	long long numWays(int width, int height, vector <string> bad) {
		memset(l, 0, sizeof l);
		memset(d, 0, sizeof d);

		const int n = bad.size();
		for (int i=0; i<n; ++i)  {
			istringstream is(bad[i]);
			int x1, x2, y1, y2;
			is >> x1 >> y1 >> x2 >> y2;
			Point a(x1, y1);
			Point b(x2, y2);
			if (b < a) {
				const Point t = a;
				a = b;
				b = t;
			}
			if (a.x != b.x)
				l[b.x][b.y] = true;
			else
				d[b.x][b.y] = true;
		}

		for (int i=0; i<101; ++i)
			for (int j=0; j<101; ++j)
				sol[i][j] = 0;
		sol[0][0] = 1;
		for (int sum=1; sum<=width+height; ++sum)
			for (int x=0; x<=sum && x<=width; ++x) {
				const int y = sum - x;
				if (y>=0 && y<=height) {
					if (x && !l[x][y])
						sol[x][y] += sol[x-1][y];
					if (y && !d[x][y])
						sol[x][y] += sol[x][y-1];
				}
			}

		return sol[width][height];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 6; string Arr2[] = {"0 0 0 1","6 6 5 6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 252LL; verify_case(0, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(1, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 35; int Arg1 = 31; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 6406484391866534976LL; verify_case(2, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(3, Arg3, numWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AvoidRoads ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

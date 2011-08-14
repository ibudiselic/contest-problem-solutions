#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct point {
	int x, y;
	point(int x_, int y_): x(x_), y(y_) {}
	point(const string &s) {
		istringstream is(s);
		is >> x >> y;
	}
};
bool operator!=(const point &a, const point &b) {
	return a.x!=b.x || a.y!=b.y;
}
vector<point> P;
signed char dp[1<<16][16][16];
bool ok(const point &a, const point &b, const point &c) {
	long long x1 = b.x - a.x;
	long long y1 = b.y - a.y;
	long long x2 = c.x - a.x;
	long long y2 = c.y - a.y;

	long long cross = x1*y2 - x2*y1;
	long long dot = x1*x2 + y1*y2;
	if (cross != 0) {
		return cross > 0;
	}
	return dot <= 0;
}
bool ok(int m, const point &a, const point &b) {
	for (int i=0; i<(int)P.size(); ++i) {
		if ((m & (1<<i)) == 0) {
			if (P[i]!=a && !ok(a, b, P[i])) {
				return false;
			}
		}
	}
	return true;
}
bool ok(int m, const point &b, const point &a, const point &c) {
	long long x1 = b.x - a.x;
	long long y1 = b.y - a.y;
	long long x2 = c.x - a.x;
	long long y2 = c.y - a.y;

	long long cross = x1*y2 - x2*y1;
	long long dot = x1*x2 + y1*y2;
	if (cross != 0) {
		return cross>0 && ok(m, b, c);
	}
	return dot>=0 && ok(m, b, c);
}
bool ok(int m, int b, int a, int c) {
	return ok(m, P[b], P[a], P[c]);
}
int go(int m, int a, int b) {
	if (m == 0) {
		return 0;
	}

	signed char &ret = dp[m][a][b];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	if (b == 16) {
		for (int i=0; i<(int)P.size(); ++i) {
			ret = max((int)ret, 1 + go(m ^ (1<<i), 16, i));
		}
	} else if (a == 0) {
		for (int i=0; i<(int)P.size(); ++i) {
			if (m & (1<<i)) {
				ret = max((int)ret, 1 + go(m ^ (1<<i), i, b));
			}
		}
	} else {
		for (int i=0; i<(int)P.size(); ++i) {
			if ((m & (1<<i)) == 0) {
				continue;
			}
			if (ok(m, a, b, i)) {
				ret = max((int)ret, 1 + go(m ^ (1<<i), i, a));
			}
		}
	}

	return ret;
}
class SpiralConstruction {
	public:
	int longestSpiral(vector <string> points) {
		P.clear();
		P.push_back(point(0, 0));
		for (int i=0; i<(int)points.size(); ++i) {
			P.push_back(point(points[i]));
		}

		memset(dp, 0xff, sizeof dp);
		return go((1<<P.size())-2, 0, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 1", "1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, longestSpiral(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 1", "2 2", "-1 -1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, longestSpiral(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 1", "1 1", "0 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, longestSpiral(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 1", "-1 0", "0 -1", "1 2", "2 -2", "-2 1", "1 0", "-1 -1", "1 3", "-3 -2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, longestSpiral(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SpiralConstruction ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

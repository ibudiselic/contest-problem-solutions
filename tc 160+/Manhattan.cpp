#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct par {
	int x, y;
	par(int x_, int y_): x(x_), y(y_) {}
};
int dist(const par &a, const par &b) {
	return abs(a.x-b.x) + abs(a.y-b.y);
}
class Manhattan {
	public:
	vector <int> furthestPair(int n, int a, int b, int m) {
		vector<par> V;

		long long x = 0;
		long long y = b%m;
		for (int i=0; i<n; ++i) {
			V.push_back(par(x, y));
			x = (a*y + b)%m;
			y = (a*x + b)%m;
		}

		int o, p, q, r, oi, pi, qi, ri;
		o = q = -2*m;
		p = r = 2*m;
		oi = pi = qi = ri = -1;

		for (int i=0; i<n; ++i) {
			if (V[i].x+V[i].y > o) { o = V[i].x+V[i].y; oi = i; }
			if (V[i].x+V[i].y < p) { p = V[i].x+V[i].y; pi = i; }
			if (V[i].x-V[i].y > q) { q = V[i].x-V[i].y; qi = i; }
			if (V[i].x-V[i].y < r) { r = V[i].x-V[i].y; ri = i; }
		}

		if (dist(V[oi], V[pi]) > dist(V[qi], V[ri])) {
			a = min(oi, pi);
			b = max(oi, pi);
		} else if (dist(V[oi], V[pi])==dist(V[qi], V[ri]) && (min(oi, pi)<min(qi, ri) || min(oi, pi)==min(qi, ri) && max(oi, pi)<max(qi, ri))) {
			a = min(oi, pi);
			b = max(oi, pi);
		} else {
			a = min(qi, ri);
			b = max(qi, ri);
		}

		if (b == 0)
			++b;
		vector<int> sol(2);
		sol[0] = a; sol[1] = b;
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 13; int Arg3 = 23; int Arr4[] = {2, 6 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, furthestPair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 17; int Arg2 = 17; int Arg3 = 17; int Arr4[] = {0, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, furthestPair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 912; int Arg2 = 1023; int Arg3 = 103871; int Arr4[] = {0, 54 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, furthestPair(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Manhattan ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

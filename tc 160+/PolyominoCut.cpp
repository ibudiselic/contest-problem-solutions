#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> coord;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

set< set<coord> > done;
int HIGH, WIDT;

int calc(const set<coord> &poly) {
	int maxi=0, maxj=0;
	for (set<coord>::const_iterator it=poly.begin(); it!=poly.end(); ++it) {
		maxi = max(maxi, it->first);
		maxj = max(maxj, it->second);
	}

	for (int i=0; i<=maxi; ++i)
		for (int j=0; j<=maxj; ++j)
			if (!poly.count(coord(i, j)) &&
				poly.count(coord(i  , j-1)) &&
				poly.count(coord(i-1, j  )) &&
				poly.count(coord(i  , j+1)) &&
				poly.count(coord(i+1, j  )))
				return 0;

	bool N = 0, S = 0, W = 0, E = 0;

	int state = 0;
	for (int j=0; j<=maxj; ++j) {
		if (state==2 && poly.count(coord(0, j))) ++state;
		if (state==1 && !poly.count(coord(0, j))) ++state;
		if (state==0 && poly.count(coord(0, j))) ++state;
	}
	if (state == 3)
		N = 1;

	state = 0;
	for (int j=0; j<=maxj; ++j) {
		if (state==2 && poly.count(coord(maxi, j))) ++state;
		if (state==1 && !poly.count(coord(maxi, j))) ++state;
		if (state==0 && poly.count(coord(maxi, j))) ++state;
	}
	if (state == 3)
		S = 1;

	state = 0;
	for (int i=0; i<=maxi; ++i) {
		if (state==2 && poly.count(coord(i, 0))) ++state;
		if (state==1 && !poly.count(coord(i, 0))) ++state;
		if (state==0 && poly.count(coord(i, 0))) ++state;
	}
	if (state == 3)
		W = 1;

	state = 0;
	for (int i=0; i<=maxi; ++i) {
		if (state==2 && poly.count(coord(i, maxj))) ++state;
		if (state==1 && !poly.count(coord(i, maxj))) ++state;
		if (state==0 && poly.count(coord(i, maxj))) ++state;
	}
	if (state == 3)
		E = 1;

	bool NW = !poly.count(coord(0, 0));
	bool NE = !poly.count(coord(0, maxj));
	bool SE = !poly.count(coord(maxi, maxj));
	bool SW = !poly.count(coord(maxi, 0));

	return (HIGH-maxi-N-S)*(WIDT-maxj-W-E) - (NW&&!N&&!W) - (NE&&!N&&!E) - (SE&&!S&&!E) - (SW&&!S&&!W);
}
int go(int k, set<coord> poly) {
	int mini=0, minj=0;
	for (set<coord>::const_iterator it=poly.begin(); it!=poly.end(); ++it) {
		mini = min(mini, it->first);
		minj = min(minj, it->second);
	}

	set<coord> norm;
	for (set<coord>::const_iterator it=poly.begin(); it!=poly.end(); ++it)
		norm.insert(coord(it->first - mini, it->second - minj));

	if (done.count(norm))
		return 0;
	done.insert(norm);

	poly = norm;
	if (k == 0)
		return calc(poly);

	int ret = 0;
	for (set<coord>::const_iterator it=poly.begin(); it!=poly.end(); ++it)
		for (int d=0; d<4; ++d) {
			const int r = it->first + di[d];
			const int c = it->second + dj[d];
			if (!norm.count(coord(r, c))) {
				norm.insert(coord(r, c));
				ret += go(k-1, norm);
				norm.erase(coord(r, c));
			}
		}
	return ret;
}
class PolyominoCut {
	public:
	int count(int k, int width, int height) {
		done.clear();
		HIGH = height;
		WIDT = width;

		set<coord> poly;
		poly.insert(coord(0, 0));

		return go(k-1, poly);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 20; int Arg3 = 200; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 10; int Arg3 = 480; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 800; int Arg2 = 800; int Arg3 = 1704053350; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PolyominoCut ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

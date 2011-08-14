#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool hasPt[51*51];
int x[51], y[51];
int cross(int x1, int y1, int x2, int y2) {
	return x1*y2 - x2*y1;
}
int sgn(int x) {
	return (x>0 ? 1 : (x<0 ? -1 : 0));
}
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	return sgn(cross(x2-x1, y2-y1, x3-x2, y3-y2));
}
bool trueIntersect(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
	return ccw(ax, ay, bx, by, cx, cy)*ccw(ax, ay, bx, by, dx, dy)==-1 && ccw(cx, cy, dx, dy, ax, ay)*ccw(cx, cy, dx, dy, bx, by)==-1;
}
bool noIntersect(vector<int> &v) {
	int n = v.size()/2;
	v.push_back(v[0]);
	v.push_back(v[1]);
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (trueIntersect(v[2*i], v[2*i+1], v[2*(i+1)], v[2*(i+1)+1], v[2*j], v[2*j+1], v[2*(j+1)], v[2*(j+1)+1])) {
				v.pop_back();
				v.pop_back();
				return false;
			}
	v.pop_back();
	v.pop_back();
	return true;
}
bool ok(vector<int> &v) {
	assert(v.size()%2 == 0);
	assert(v.size()>=6 && v.size()<=50);
	for (int i=1; i<51; ++i)
		if (x[i] > 2 || y[i] > 2)
			return false;

	int n = v.size()/2;
	int ccwTarget = ccw(v[0], v[1], v[2], v[3], v[4], v[5]);
	if (ccwTarget == 0)
		return false;
	for (int i=3; i<n; ++i)
		if (ccw(v[2*(i-2)], v[2*(i-2)+1], v[2*(i-1)], v[2*(i-1)+1], v[2*i], v[2*i+1]) != ccwTarget)
			return false;
	if (ccw(v[2*(n-2)], v[2*(n-2)+1], v[2*(n-1)], v[2*(n-1)+1], v[0], v[1]) != ccwTarget)
		return false;
	if (ccw(v[2*(n-1)], v[2*(n-1)+1], v[0], v[1], v[2], v[3]) != ccwTarget)
		return false;

	return noIntersect(v);
}
bool addY(vector<int> &v) {
	int myX = v.back();
	v.push_back(0);
	for (v.back()=1; v.back()<=50; ++v.back()) {
		++y[v.back()];
		if (!hasPt[myX*51 + v.back()] && y[v.back()]<3 && ok(v))
			return true;
		--y[v.back()];
	}
	v.pop_back();
	return false;
}
bool addPoint(vector<int> &v) {
	v.push_back(0);
	for (v.back()=1; v.back()<=50; ++v.back()) {
		++x[v.back()];
		if (x[v.back()]<3 && addY(v))
			return true;
		--x[v.back()];
	}
	return false;
}
class ConvexArray {
	public:
	vector <int> getEnding(vector <int> beg) {
		int origSz = beg.size();
		vector<int> sol;
		if (origSz == 0) {
			sol.push_back(1);
			sol.push_back(1);
			sol.push_back(1);
			sol.push_back(2);
			sol.push_back(2);
			sol.push_back(1);
			return sol;
		} else if (origSz == 1) {
			sol.push_back(1);
			sol.push_back(1);
			if (beg[0] != 1) {
				sol.push_back(1);
				sol.push_back(1);
				sol.push_back(2);
			} else {
				sol.push_back(2);
				sol.push_back(2);
				sol.push_back(1);
			}
			return sol;
		} else {
			memset(x, 0, sizeof x);
			memset(y, 0, sizeof y);
			memset(hasPt, 0, sizeof hasPt);
			for (int i=0; i<origSz; i+=2)
				++x[beg[i]];
			for (int i=1; i<origSz; i+=2) {
				hasPt[beg[i-1]*51 + beg[i]] = 1;
				++y[beg[i]];
			}

			if (origSz == 2) {
				beg.push_back(1);
				++x[1];
				if (beg[0]==1 && beg[1]==1) {
					beg.push_back(2);
					++y[2];
					hasPt[1*51 + 2] = 1;
				} else {
					beg.push_back(1);
					++y[1];
					hasPt[1*51 + 1] = 1;
				}
				addPoint(beg);
				return vector<int>(beg.begin()+origSz, beg.end());
			} else if (origSz == 3) {
				int myX = beg.back();
				if (beg[0] != beg[2]) {
					beg.push_back(1);
					++y[1];
					hasPt[myX*51 + 1] = 1;
				} else {
					if (beg[1] != 1) {
						beg.push_back(1);
						++y[1];
						hasPt[myX*51 + 1] = 1;
					} else {
						beg.push_back(2);
						++y[2];
						hasPt[myX*51 + 2] = 1;
					}
				}
				addPoint(beg);
				return vector<int>(beg.begin()+origSz, beg.end());
			}
			// origSz >= 4
			if (origSz & 1) {
				// odd
				if (addY(beg))
					return vector<int>(beg.begin()+origSz, beg.end());
			} else {
				// even
				if (origSz < 6) {
					if (addPoint(beg))
						return vector<int>(beg.begin()+origSz, beg.end());
				} else if (ok(beg)) {
					return vector<int>();
				} else {
					return vector<int>(1, -1);
				}
			}
		}
		return vector<int>(1, -1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getEnding(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 6, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getEnding(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getEnding(Arg0)); }
	void test_case_3() { int Arr0[] = {2, 5, 5, 5, 4, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getEnding(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 1, 2, 3, 3, 1, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getEnding(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ConvexArray ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

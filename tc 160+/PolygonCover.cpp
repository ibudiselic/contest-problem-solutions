#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int, int> point;
vector<int> x, y;
int n;

bool done[1<<15];
double area[1<<15];
double best[1<<15];
int bc[1<<15];

point operator-(const point &a, const point &b) {
	return point(a.first-b.first, a.second-b.second);
}
int cross(const point &a, const point &b) {
	return (a.first*b.second - a.second*b.first);
}
void calc(int mask) {
	vector<point> v;
	for (int i=0; i<n; ++i) {
		if ((mask>>i) & 1) {
			v.push_back(point(x[i]+1000, y[i]+1000));
		}
	}

	sort(v.begin(), v.end());
	vector<int> ch;
	ch.push_back(0);
	int p = 0;
	do {
		int next = -1;
		for (int cand=0; cand<(int)v.size(); ++cand) {
			if (cand != p) {
				if (next==-1 || cross(v[next]-v[p], v[cand]-v[next])<0) {
					next = cand;
				}
			}
		}
		p = next;
		ch.push_back(p);
	} while (p != 0);

	double ret = 0.0;
	for (int i=1; i<(int)ch.size(); ++i) {
		ret += cross(v[ch[i-1]], v[ch[i]]);
	}

	area[mask] = ret/2.0;
}
	
class PolygonCover {
	public:
	double getArea(vector <int> x_, vector <int> y_) {
		bc[0] = 0;
		best[0] = 1e32;
		for (int i=1; i<(1<<15); ++i) {
			bc[i] = bc[i>>1] + (i&1);
			best[i] = 1e32;
			area[i] = 1e32;
		}
		x = x_;
		y = y_;
		n = x.size();

		for (int m=7; m<(1<<x.size()); ++m) {
			if (bc[m] >= 3) {
				calc(m);
			}
		}

		int all = (1<<x.size()) - 1;
		best[0] = 0.0;
		for (int m1=1; m1<=all; ++m1) {
			best[m1] = area[m1];
			for (int m2=(m1-1)&m1; m2>0; m2=(m2-1)&m1) {
				if (bc[m2] != 3) {
					continue;
				}
				assert((m1&m2) == m2);
				best[m1] = min(best[m1], best[m1-m2] + area[m2]);
				int diff = m1 - m2;
				assert((m2|diff) == m1);
				for (int m3=(m2-1)&m2; m3>0; m3=(m3-1)&m2) {
					assert((m2&m3) == m3);
					assert(((diff+m3) & m1) == (diff+m3));
					best[m1] = min(best[m1], best[diff+m3] + area[m2]);
				}
			}
		}

		return best[all];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,10,0,-10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10,0,10,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 200.0; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,2,-2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,0,2,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,0,-2,-1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,0,-2,-2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.0; verify_case(2, Arg2, getArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,0,-4,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,0,-4,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(3, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PolygonCover ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

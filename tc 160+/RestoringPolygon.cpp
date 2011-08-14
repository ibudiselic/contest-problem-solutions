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

class RestoringPolygon {
	public:
	int restore(vector <int> x1, vector <int> x2, vector <int> y) {
		int n = x1.size();
		int sol = 0;
		for (unsigned mask=1; mask<(1u<<n); ++mask) {
			vector<point> v;
			for (int i=0; i<n; ++i)
				if (mask & (1u<<i)) {
					v.push_back(point(x1[i], y[i]));
					v.push_back(point(x2[i], y[i]));
				}
			sort(v.begin(), v.end());

			int m = v.size();
			for (int i=0; i<m/2; ++i)
				if (v[2*i].first != v[2*i+1].first)
					goto fail;
			{
			vector<int> next(m);
			for (int i=0; i<n; ++i)
				if (mask & (1u<<i)) {
					point p(x1[i], y[i]), q(x2[i], y[i]);
					int a=0, b=0;
					for (int j=0; j<m; ++j)
						if (v[j] == p) {
							a = j;
							break;
						}
					for (int j=0; j<m; ++j)
						if (v[j] == q) {
							b = j;
							break;
						}
					next[b] = a;
					next[a] = b;
				}

			int cur = 0;
			for (int i=0; i<m/2; ++i) {
				cur = next[cur];
				cur ^= 1;
				if (i<m/2-1 && cur==0)
					goto fail;
			}
			}
			for (int i=0; i<n; ++i)
				if (mask & (1u<<i)) {
					int xl = min(x1[i], x2[i]);
					int xr = max(x1[i], x2[i]);
					int yh = y[i];

					for (int j=0; j<m/2; ++j) {
						int xv = v[2*j].first;
						int yd = v[2*j].second;
						int yu = v[2*j+1].second;

						if (xl<xv && xv<xr && yd<yh && yh<yu)
							goto fail;
					}
				}

			sol = max(sol, m);
			fail: ;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,2,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, restore(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,2,1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, restore(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, restore(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,1000,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(3, Arg3, restore(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RestoringPolygon ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

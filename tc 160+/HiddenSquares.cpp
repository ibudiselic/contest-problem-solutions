#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

int h[100][100], v[100][100];
class HiddenSquares {
	public:
	int count(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2) {
		set<int> X, Y;

		X.insert(x1.begin(), x1.end());
		X.insert(x2.begin(), x2.end());
		Y.insert(y1.begin(), y1.end());
		Y.insert(y2.begin(), y2.end());

		vector<int> x(X.begin(), X.end());
		vector<int> y(Y.begin(), Y.end());

		memset(h, 0, sizeof h);
		memset(v, 0, sizeof v);

		for (int i=0; i<(int)x.size(); ++i)
			for (int j=1; j<(int)y.size(); ++j)
				for (int k=0; k<(int)x1.size(); ++k)
					if ((x1[k]==x[i] || x2[k]==x[i]) && (y1[k]<=y[j] && y[j]<=y2[k])) {
						v[i][j] = max(v[i][j], y[j]-y1[k]);
						for (int l=0; l<j; ++l)
							if (y1[k]<=y[l] && y[l]<=y2[k]) {
								v[i][j] = max(v[i][j], y[j]-y[l] + v[i][l]);
								break;
							}
					}
		for (int j=0; j<(int)y.size(); ++j)
			for (int i=1; i<(int)x.size(); ++i)
				for (int k=0; k<(int)y1.size(); ++k)
					if ((y1[k]==y[j] || y2[k]==y[j]) && (x1[k]<=x[i] && x[i]<=x2[k])) {
						h[i][j] = max(h[i][j], x[i]-x1[k]);
						for (int l=0; l<i; ++l)
							if (x1[k]<=x[l] && x[l]<=x2[k]) {
								h[i][j] = max(h[i][j], x[i]-x[l] + h[l][j]);
								break;
							}
					}

		int sol = 0;
		for (int i=0; i<(int)x.size(); ++i)
			for (int j=0; j<(int)y.size(); ++j)
				for (int k=i+1; k<(int)x.size(); ++k)
					for (int l=j+1; l<(int)y.size(); ++l) {
						int side = x[k]-x[i];
						if (y[l]-y[j] != side) continue;
						if (v[k][l] < side) continue;
						if (v[i][l] < side) continue;
						if (h[k][l] < side) continue;
						if (h[k][j] < side) continue;
						++sol;
					}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 14; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,0,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,4,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {453453463,453453500,453453495,453453512,453453478,453453489,
 453453466,453453500,453453498,453453510,453453472,453453512,
 453453519,453453514,453453521,453453518,453453523,453453517,
 453453466,453453525,453453496,453453495,453453463,453453461,
 453453460,453453522,453453471,453453468,453453479,453453517,
 453453485,453453518,453453499,453453464,453453494}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {364646438,364646402,364646449,364646438,364646415,364646401,
 364646446,364646416,364646456,364646414,364646463,364646407,
 364646436,364646450,364646421,364646411,364646414,364646419,
 364646445,364646427,364646405,364646442,364646418,364646464,
 364646457,364646463,364646432,364646426,364646444,364646431,
 364646450,364646418,364646434,364646458,364646402}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {453453488,453453510,453453525,453453523,453453493,453453500,
 453453470,453453511,453453499,453453521,453453518,453453524,
 453453523,453453523,453453524,453453523,453453525,453453519,
 453453473,453453526,453453511,453453517,453453470,453453464,
 453453511,453453524,453453516,453453516,453453492,453453524,
453453513,453453522,453453520,453453505,453453512}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {364646460,364646454,364646462,364646466,364646464,364646455,
 364646457,364646461,364646457,364646450,364646466,364646453,
 364646441,364646451,364646460,364646461,364646446,364646464,
 364646447,364646460,364646454,364646450,364646444,364646466,
 364646458,364646466,364646455,364646442,364646462,364646435,
 364646464,364646444,364646455,364646459,364646430}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 124; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HiddenSquares ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

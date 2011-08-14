#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class QuadraticRoots {
	public:
	bool test(int x, int a, int b, int c) {
		return a*x*x + b*x + c == 0;
	}
	vector <int> findRoots(vector <int> a, vector <int> b, vector <int> c) {
		vector<int> temp;

		for (int i=0; i<(int)a.size(); ++i)
			for (int j=0; j<(int)b.size(); ++j)
				for (int k=0; k<(int)c.size(); ++k) {
					if (b[j]*b[j] < 4*a[i]*c[k]) continue;
					double d = sqrt((double)b[j]*b[j] - 4*a[i]*c[k]);
					int x = (int)((-b[j]-d)/(2*a[i]));
					if (test(x, a[i], b[j], c[k]))
						temp.push_back(x);
					else if (test(x+1, a[i], b[j], c[k]))
						temp.push_back(x+1);
					else if (test(x-1, a[i], b[j], c[k]))
						temp.push_back(x-1);
					x = (int)((-b[j]+d)/(2*a[i]));
					if (test(x, a[i], b[j], c[k]))
						temp.push_back(x);
					else if (test(x+1, a[i], b[j], c[k]))
						temp.push_back(x+1);
					else if (test(x-1, a[i], b[j], c[k]))
						temp.push_back(x-1);
				}

		sort(temp.begin(), temp.end());
		vector<int> sol;
		unique_copy(temp.begin(), temp.end(), back_inserter(sol));
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { -2,  -1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, findRoots(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, findRoots(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { -4,  -3,  -2,  -1,  1,  2,  3,  4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, findRoots(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,1,2,2,3,3,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,2,2,3,3,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,2,2,3,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { -3,  -2,  -1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, findRoots(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,10000,-10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,10000,-10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,10000,-10000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { -10000,  -100,  -1,  0,  1,  100,  10000 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, findRoots(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    QuadraticRoots ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

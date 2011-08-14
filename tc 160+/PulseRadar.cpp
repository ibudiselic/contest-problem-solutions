#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int sqr(int x) {
	return x*x;
}
class PulseRadar {
	public:
	vector <int> deduceSpeeds(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2, vector <int> x3, vector <int> y3) {
		const int n = x1.size();
		vector<int> sol(n, -1);
		vector<bool> used2(n, 0), used3(n, 0);

		int cnt = 0;
		while (cnt < n) {
			int old = cnt;
			for (int i=0; i<n; ++i)
				if (sol[i] == -1) {
					vector<int> opt3;
					vector<int> opt2;
					for (int j=0; j<n; ++j)
						if (!used3[j]) {
							if ((x1[i]+x3[j])%2 != 0 || (y1[i]+y3[j])%2 != 0) continue;
							const int x = (x1[i]+x3[j])/2;
							const int y = (y1[i]+y3[j])/2;
							for (int k=0; k<n; ++k)
								if (!used2[k] && x==x2[k] && y==y2[k]) {
									opt3.push_back(j);
									opt2.push_back(k);
									break;
								}
						}
					if (opt3.size() == 0) return vector<int>();
					if (opt3.size() == 1) {
						used3[opt3[0]] = 1;
						used2[opt2[0]] = 1;
						sol[i] = (int)(sqrt(sqr(x1[i]-x3[opt3[0]]) + sqr(y1[i]-y3[opt3[0]]))/2.0 + 0.5 + 1e-9);
						++cnt;
					}
				}
			if (old == cnt)
				return vector<int>();
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {-8, -7, 9, -5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, -1, -2, -6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-2, -3, 8, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-3, 1, 4, -2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4, 1, 7, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {-8, 3, 10, 2}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = { 8,  4,  6,  7 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, deduceSpeeds(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arr0[] = {-7, -2, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, -2, -2, -6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-5, -1, 3, -1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9, 1, -4, -8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-3, 1, 5, -2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {10, 5, -6, -10}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = { }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, deduceSpeeds(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arr0[] = {-4, -4, -4, -4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 3, -1, -7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1, -1, -1, -1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6, -2, 4, -4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 2, 2, 2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {3, -7, 9, -1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = { }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, deduceSpeeds(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arr0[] = {5, -4, 2, -1, 8, -4, -8, 3, -3, -4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 9, -2, -8, 3, -8, -4, 2, -4, -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-2, 2, 1, 2, 1, -1, -3, 1, -4, -1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-1, -5, 6, -2, 2, 2, 0, -1, -2, -5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {8, 5, -1, -3, 6, -5, 2, 0, -6, -8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {4, -2, 2, 3, -5, 2, -8, 0, -5, 2}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = { 5,  9,  5,  4,  8,  8,  4,  4,  3,  4 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, deduceSpeeds(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arr0[] = {-300, 466}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-600, 866}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {466, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {866, -450}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {500, 466}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {-300, 866}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = { 427,  0 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(4, Arg6, deduceSpeeds(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PulseRadar ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

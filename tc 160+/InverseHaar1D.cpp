#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class InverseHaar1D {
	public:
	vector <int> transform(vector <int> v, int L) {
		int n = (v.size() >> L);

		while (L--) {
			vector<int> t = v;
			for (int i=0; i<n; ++i) {
				t[2*i] = (v[i] + v[n+i])/2;
				t[2*i+1] = v[i] - t[2*i];
			}
			n *= 2;
			v.swap(t);
		}

		return v;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {101, -53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {24, 77 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3, 8, -1, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {1, 2, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {11, -5, -1, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {1, 2, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {369, 477, 451, 262, 47, 135,
 -125, -2, 18, -23, 30, 101,
 -5, -18, 54, -20, 11, 45, -5,
 70, -24, 2, -50, 15, 55, -62,
 -23, -17, 44, -8, -44, -52}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {62, 51, 70, 25, 32, 37, 81, 11, 72, 96, 70, 68, 43, 93, 25, 10, 67, 12, 11, 73, 56, 79, 68, 85, 68, 24, 15, 23, 6, 50, 12, 64 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InverseHaar1D ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

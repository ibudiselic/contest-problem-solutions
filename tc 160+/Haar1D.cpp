#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Haar1D {
	public:
	vector <int> transform(vector <int> data, int L) {
		int n = data.size();

		while (L--) {
			vector<int> x(n, 0);
			for (int i=0; 2*i<n; ++i) {
				x[i] = data[2*i]+data[2*i+1];
				x[n/2+i] = data[2*i]-data[2*i+1];
			}
			copy(x.begin(), x.end(), data.begin());
			n /= 2;
		}

		return data;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {3, 8, -1, -2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {11, -5, -1, -2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 4, 3, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {20, 0, -4, 4, -1, -1, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {94, 47, 46, 28, 39, 89, 75, 4, 28, 62, 69, 89, 34, 55, 81, 24}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {215, 207, 248, 194, 67, 49, -68, -16, 47, 18, -50, 71, -34, -20, -21, 57 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Haar1D ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

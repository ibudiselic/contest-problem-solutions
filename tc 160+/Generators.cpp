#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

bool used[1000];
bool isGen(int x, int p) {
	memset(used, 0, sizeof used);

	used[1] = 1;
	int y = x;
	for (int i=1; i<p-1; ++i) {
		used[x] = 1;
		x = (x*y)%p;
	}

	return accumulate(used+1, used+p, 0) == p-1;
}
class Generators {
	public:
	vector <int> find(int p) {
		vector<int> sol;
		for (int i=1; i<p; ++i)
			if (isGen(i, p))
				sol.push_back(i);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 13; int Arr1[] = {2, 6, 7, 11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 19; int Arr1[] = {2, 3, 10, 13, 14, 15 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { int Arg0 = 337; int Arr1[] = {10, 15, 19, 20, 22, 23, 29, 31, 33, 34, 44, 45, 46, 51, 53, 60, 61, 67, 68, 70, 71, 73, 80, 83, 87, 89, 90, 93, 99, 101, 106, 109, 114, 116, 118, 120, 124, 130, 132, 134, 139, 143, 151, 152, 154, 160, 161, 166, 171, 176, 177, 183, 185, 186, 194, 198, 203, 205, 207, 213, 217, 219, 221, 223, 228, 231, 236, 238, 244, 247, 248, 250, 254, 257, 264, 266, 267, 269, 270, 276, 277, 284, 286, 291, 292, 293, 303, 304, 306, 308, 314, 315, 317, 318, 322, 327 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Generators ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

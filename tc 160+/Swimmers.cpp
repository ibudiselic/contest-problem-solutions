#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Swimmers {
	public:
	vector <int> getSwimTimes(vector <int> distances, vector <int> speeds, int current) {
		vector<int> sol;

		for (int i=0; i<(int)speeds.size(); ++i) {
			if (distances[i]==0)
				sol.push_back(0);
			else {
				double t = (double)distances[i]/(speeds[i]+current);
				if (speeds[i] > current)
					sol.push_back(t + (double)distances[i]/(speeds[i]-current));
				else
					sol.push_back(-1);
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { 300, 300, 300 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = { -1,  -1,  360 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getSwimTimes(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 500, 500 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = { 333,  238 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getSwimTimes(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 0, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arr3[] = { 0,  0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getSwimTimes(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 0, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arr3[] = { 0,  -1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getSwimTimes(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = { 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583,
  7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691,
  7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823,
  7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
  73, 79, 83, 89, 97, 99, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,
  32, 34, 36, 38, 40, 42, 44, 46, 48, 51 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arr3[] = { -1,  -1,  -1,  8108,  1950,  1474,  1014,  882,  705,  544,  507,  420,  377,  359,  328,  290,  260,  252,  229,  216,  210,  195,  185,  173,  159,  155,  -1,  -1,  4409,  2413,  1717,  1354,  1127,  969,  852,  764,  692,  635,  585,  543,  507,  476,  449,  424,  402,  383,  365,  349,  334,  314 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, getSwimTimes(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Swimmers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

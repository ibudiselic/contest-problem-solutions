#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class LeaguePicks {
	public:
	vector <int> returnPicks(int position, int friends, int picks) {
		vector<int> sol;
		int x = position;

		while (x<=picks) {
			sol.push_back(x);
			x += 2*(friends-position)+1;
			if (x<=picks)
				sol.push_back(x);
			x += 2*(position-1)+1;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 6; int Arg2 = 15; int Arr3[] = { 3,  10,  15 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, returnPicks(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arr3[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, returnPicks(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 39; int Arr3[] = { 1,  4,  5,  8,  9,  12,  13,  16,  17,  20,  21,  24,  25,  28,  29,  32,  33,  36,  37 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, returnPicks(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 11; int Arg2 = 100; int Arr3[] = { 5,  18,  27,  40,  49,  62,  71,  84,  93 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, returnPicks(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LeaguePicks ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

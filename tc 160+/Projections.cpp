#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Projections {
	public:
	vector <int> count(string front, string right) {
		int x=0, y=0;
		for (int i=0; i<(int)front.size(); ++i) x += (front[i]=='x');
		for (int i=0; i<(int)right.size(); ++i) y += (right[i]=='x');
		vector<int> sol(2);
		sol[0] = max(x, y);
		sol[1] = x*y;
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "x"; string Arg1 = "x"; int Arr2[] = {1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "x."; string Arg1 = ".x"; int Arr2[] = {1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "xxxx"; string Arg1 = "x..x"; int Arr2[] = {4, 8 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "x.x.x.x"; string Arg1 = "x.x.x.x"; int Arr2[] = {4, 16 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "x...xx..x.xxx..x.xx."; string Arg1 = ".xx..xxx.xx."; int Arr2[] = {10, 70 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Projections ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

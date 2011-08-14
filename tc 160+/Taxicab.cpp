#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Taxicab {
	public:
	string calculateFare(vector <int> blocks) {
		int u = 0;
		int cost = 0;

		for (int i=0; i<(int)blocks.size(); ++i)
			if (blocks[i] < 2)
				u += 4;
			else
				u += blocks[i];

		cost = 250;
		u-=4;
		if (u > 0)
			cost += u*10;

		char buff[10];
		sprintf(buff, "%3.2f", cost/100.0);

		return string(buff);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "2.50"; verify_case(0, Arg1, calculateFare(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "2.90"; verify_case(1, Arg1, calculateFare(Arg0)); }
	void test_case_2() { int Arr0[] = {10, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "3.30"; verify_case(2, Arg1, calculateFare(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "6.10"; verify_case(3, Arg1, calculateFare(Arg0)); }
	void test_case_4() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "2.50"; verify_case(4, Arg1, calculateFare(Arg0)); }
	void test_case_5() { int Arr0[] = {0,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "3.10"; verify_case(5, Arg1, calculateFare(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Taxicab ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

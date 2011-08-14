#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
0 consists of 6 dashes, 1 consists of 2 dashes, 2 consists of 5 dashes, 3 consists of 5 dashes, 4 consists of 4 dashes, 5 consists of 5 dashes, 6 consists of 6 dashes, 7 consists of 3 dashes, 8 consists of 7 dashes, 9 consists of 6 dashes.
*/
const int cnt[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
class CheckFunction {
	public:
	int newFunction(string code) {
		int sol = 0;
		for (int i=0; i<(int)code.size(); ++i)
			sol += cnt[code[i]-'0'];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "13579"; int Arg1 = 21; verify_case(0, Arg1, newFunction(Arg0)); }
	void test_case_1() { string Arg0 = "02468"; int Arg1 = 28; verify_case(1, Arg1, newFunction(Arg0)); }
	void test_case_2() { string Arg0 = "73254370932875002027963295052175"; int Arg1 = 157; verify_case(2, Arg1, newFunction(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CheckFunction ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

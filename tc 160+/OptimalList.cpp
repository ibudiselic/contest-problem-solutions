#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
string dir = "NESW";
int getDir(char c) {
	return dir.find(c);
}
class OptimalList {
	public:
	string optimize(string inst) {
		int i = 0;
		int j = 0;

		for (int k=0; k<(int)inst.size(); ++k) {
			int d = getDir(inst[k]);
			i += di[d];
			j += dj[d];
		}

		int d1;
		if (i >= 0)
			d1 = 2;
		else
			d1 = 0;

		int d2;
		if (j >= 0)
			d2 = 1;
		else
			d2 = 3;

		if (dir[d1] > dir[d2])
			return string(abs(j), dir[d2]) + string(abs(i), dir[d1]);
		else
			return string(abs(i), dir[d1]) + string(abs(j), dir[d2]);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "NENENNWWWWWS"; string Arg1 = "NNNWWW"; verify_case(0, Arg1, optimize(Arg0)); }
	void test_case_1() { string Arg0 = "NNEESSWW"; string Arg1 = ""; verify_case(1, Arg1, optimize(Arg0)); }
	void test_case_2() { string Arg0 = "NEWSNWESWESSEWSENSEWSEWESEWWEWEEWESSSWWWWWW"; string Arg1 = "SSSSSSSSWWW"; verify_case(2, Arg1, optimize(Arg0)); }
	void test_case_3() { string Arg0 = "NENENE"; string Arg1 = "EEENNN"; verify_case(3, Arg1, optimize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OptimalList ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

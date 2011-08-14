#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool valid(const string &a, const string &b) {
	for (int i=0; i<(int)a.size(); ++i)
		if (a[i]=='C' && b[i]=='^')
			return false;

	return true;
}
class Trekking {
	public:
	int findCamps(string trail, vector <string> plans) {
		int sol = 1234567890;
		for (int i=0; i<(int)plans.size(); ++i)
			if (valid(plans[i], trail))
				sol = min(sol, count(plans[i].begin(), plans[i].end(), 'C'));

		return sol==1234567890 ? -1 : sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "^^....^^^..."; string Arr1[] = {"CwwCwwCwwCww",
 "wwwCwCwwwCww",
 "wwwwCwwwwCww"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, findCamps(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "^^^^"; string Arr1[] = {"wwww",
 "wwwC"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, findCamps(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "^^.^^^^"; string Arr1[] = {"wwCwwwC",
 "wwwCwww",
 "wCwwwCw"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, findCamps(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "^^^^....^.^.^."; string Arr1[] = {"wwwwCwwwwCwCwC",
 "wwwwCwwCwCwwwC",
 "wwwCwwwCwwwCww",
 "wwwwwCwwwCwwwC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, findCamps(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = ".............."; string Arr1[] = {"CwCwCwCwCwCwCw",
 "CwwCwwCwwCwwCw"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(4, Arg2, findCamps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Trekking ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

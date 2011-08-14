#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SquareCypher {
	public:
	string decrypt(string C) {
		int cnt = 0;
		while (cnt*cnt < (int)C.size())
			++cnt;

		string sol = C.substr(cnt);
		for (int i=0; i<cnt; ++i)
			sol.insert(sol.begin()+(i*i), C[i]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "thinissacotest"; string Arg1 = "thisisacontest"; verify_case(0, Arg1, decrypt(Arg0)); }
	void test_case_1() { string Arg0 = "thisisacontest"; string Arg1 = "thisiaconstest"; verify_case(1, Arg1, decrypt(Arg0)); }
	void test_case_2() { string Arg0 = "heoll"; string Arg1 = "hello"; verify_case(2, Arg1, decrypt(Arg0)); }
	void test_case_3() { string Arg0 = "test"; string Arg1 = "test"; verify_case(3, Arg1, decrypt(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SquareCypher ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

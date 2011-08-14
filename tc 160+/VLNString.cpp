#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

class VLNString {
	public:
	string makeAcronym(string longName) {
		istringstream is(longName);

		string sol;
		string w;
		while (is >> w)
			if (w!="of" && w!="the" && w!="and")
				sol += toupper(w[0]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "dance dance revolution"; string Arg1 = "DDR"; verify_case(0, Arg1, makeAcronym(Arg0)); }
	void test_case_1() { string Arg0 = "  return  of  the king   "; string Arg1 = "RK"; verify_case(1, Arg1, makeAcronym(Arg0)); }
	void test_case_2() { string Arg0 = "the united states of america"; string Arg1 = "USA"; verify_case(2, Arg1, makeAcronym(Arg0)); }
	void test_case_3() { string Arg0 = " of  the   and    "; string Arg1 = ""; verify_case(3, Arg1, makeAcronym(Arg0)); }
	void test_case_4() { string Arg0 = " "; string Arg1 = ""; verify_case(4, Arg1, makeAcronym(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VLNString ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

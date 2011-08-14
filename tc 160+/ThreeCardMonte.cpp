#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ThreeCardMonte {
	public:
	string position(string swaps) {
		vector<int> a(3, 0);
		for (int i=0; i<3; ++i)
			a[i] = i;
		for (int i=0; i<(int)swaps.size(); ++i)
			if (swaps[i] == 'L')
				swap(a[0], a[1]);
			else if (swaps[i] == 'R')
				swap(a[1], a[2]);
			else if (swaps[i] == 'E')
				swap(a[0], a[2]);
		if (a[0] == 1)
			return "L";
		else if (a[1] == 1)
			return "M";
		else
			return "R";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "L"; string Arg1 = "L"; verify_case(0, Arg1, position(Arg0)); }
	void test_case_1() { string Arg0 = "REL"; string Arg1 = "M"; verify_case(1, Arg1, position(Arg0)); }
	void test_case_2() { string Arg0 = "RFRFR"; string Arg1 = "R"; verify_case(2, Arg1, position(Arg0)); }
	void test_case_3() { string Arg0 = ""; string Arg1 = "M"; verify_case(3, Arg1, position(Arg0)); }
	void test_case_4() { string Arg0 = "FLRELFLRELLFRLFEELFLRFLELRFLRFREFRFLLRFERLFLREFRFL"; string Arg1 = "L"; verify_case(4, Arg1, position(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ThreeCardMonte ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

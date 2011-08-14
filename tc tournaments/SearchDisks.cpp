#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SearchDisks {
	public:
	int numberToTakeOut(string diskNames, string searchingDisk) {
		vector<string> w;

		istringstream is(diskNames);
		string s;
		while (is >> s)
			w.push_back(s);

		return w.size()-1-(find(w.begin(), w.end(), searchingDisk)-w.begin());
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "beatles queen abba"; string Arg1 = "abba"; int Arg2 = 0; verify_case(0, Arg2, numberToTakeOut(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "beatles queen abba"; string Arg1 = "beatles"; int Arg2 = 2; verify_case(1, Arg2, numberToTakeOut(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "a b c"; string Arg1 = "b"; int Arg2 = 1; verify_case(2, Arg2, numberToTakeOut(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "t k o h z s v r i c e d n f a m u w p g j q x y l"; string Arg1 = "f"; int Arg2 = 11; verify_case(3, Arg2, numberToTakeOut(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SearchDisks ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

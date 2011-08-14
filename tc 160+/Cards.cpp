#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Cards {
	public:
	vector <string> deal(int numPlayers, string deck) {
		vector<string> sol(numPlayers, "");
		for (int i=0; i<(int)deck.size()/numPlayers*numPlayers; ++i)
			sol[i%numPlayers] += deck[i];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; string Arg1 = "012345012345012345"; string Arr2[] = {"000", "111", "222", "333", "444", "555" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, deal(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; string Arg1 = "111122223333"; string Arr2[] = {"123", "123", "123", "123" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, deal(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; string Arg1 = "012345012345012345"; string Arr2[] = {"012345012345012345" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, deal(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; string Arg1 = "01234"; string Arr2[] = {"", "", "", "", "", "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, deal(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; string Arg1 = ""; string Arr2[] = {"", "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, deal(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Cards ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

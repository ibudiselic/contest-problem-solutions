#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DiamondHunt {
	public:
	int countDiamonds(string mine) {
		int sol = 0;
		while (1) {
			for (int i=0; i<(int)mine.size()-1; ++i)
				if (mine[i] == '<' && mine[i+1] == '>') {
					++sol;
					mine.erase(mine.begin()+i, mine.begin()+i+2);
					goto NEXT;
				}
			break;
			NEXT:;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "><<><>>><"; int Arg1 = 3; verify_case(0, Arg1, countDiamonds(Arg0)); }
	void test_case_1() { string Arg0 = ">>>><<"; int Arg1 = 0; verify_case(1, Arg1, countDiamonds(Arg0)); }
	void test_case_2() { string Arg0 = "<<<<<<<<<>>>>>>>>>"; int Arg1 = 9; verify_case(2, Arg1, countDiamonds(Arg0)); }
	void test_case_3() { string Arg0 = "><<><><<>>>><<>><<><<>><<<>>>>>><<<"; int Arg1 = 14; verify_case(3, Arg1, countDiamonds(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DiamondHunt ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Item {
	char c;
	Item(char data='D'): c(data) {}
};
bool operator==(Item a, Item b) {
	return a.c==b.c;
}
Item operator/(Item a, Item b) {
	assert(!(a==b));
	Item ret;
	if (a.c=='R')
		ret = (b.c=='S')?'P':'S';
	else if (a.c=='P')
		ret = (b.c=='R')?'S':'R';
	else
		ret = (b.c=='P')?'R':'P';

	return ret;
}

class Rochambo {
	public:
	int wins(string opponent) {
		int sol = 0;
		sol += (opponent[0]=='S') + (opponent[1]=='S');

		Item prev1 = opponent[1];
		Item prev2 = opponent[0];
		Item myguess;

		for (int i=2; i<(int)opponent.size(); ++i) {
			if (prev1 == prev2)
				myguess = prev1;
			else
				myguess = prev1/prev2;

			prev2 = prev1;
			prev1 = opponent[i];
			sol += myguess==prev1;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "PS"; int Arg1 = 1; verify_case(0, Arg1, wins(Arg0)); }
	void test_case_1() { string Arg0 = "PSRRPS"; int Arg1 = 3; verify_case(1, Arg1, wins(Arg0)); }
	void test_case_2() { string Arg0 = "PSRPSRPRSR"; int Arg1 = 7; verify_case(2, Arg1, wins(Arg0)); }
	void test_case_3() { string Arg0 = "SRPSRPSPRSPRPSRPSRP"; int Arg1 = 16; verify_case(3, Arg1, wins(Arg0)); }
	void test_case_4() { string Arg0 = "RPPPRRPSSSRRRSRSPPSSPRRPSRRRRSPPPPSSPSSSSSRSSSRPRR"; int Arg1 = 18; verify_case(4, Arg1, wins(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Rochambo ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

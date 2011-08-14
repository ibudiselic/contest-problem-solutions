#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CantorSet {
	public:
	int removed(string value) {
		string cur = value.substr(1, value.size()-1);
		reverse(cur.begin(), cur.end());

		int t = 1000000;
		while (t--) {
			int carry = 0;
			for (int i=0; i<(int)cur.size(); ++i) {
				int x = (cur[i]-'0')*3 + carry;
				cur[i] =  x%10 + '0';
				carry = x/10;
			}
			if (carry == 1) return 1000000-t;
		}

		return 0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".200"; int Arg1 = 2; verify_case(0, Arg1, removed(Arg0)); }
	void test_case_1() { string Arg0 = ".74928"; int Arg1 = 14; verify_case(1, Arg1, removed(Arg0)); }
	void test_case_2() { string Arg0 = ".975"; int Arg1 = 0; verify_case(2, Arg1, removed(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CantorSet ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

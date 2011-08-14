#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool ok(const string &s, int start, int l, int k) {
	int cnt = 0;
	for (int i=0; i<l; ++i)
		cnt += (s[start+i] != s[start+l+i]);

	return cnt <= k;
}
class TandemRepeats {
	public:
	int maxLength(string dna, int k) {
		for (int l=(int)dna.size()/2; l>0; --l)
			for (int i=0; i+2*l<=(int)dna.size(); ++i)
				if (ok(dna, i, l, k))
					return l;

		return 0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "GATCATCA"; int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "GATCATGA"; int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "GATCATGA"; int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AGAGAAAGAA"; int Arg1 = 3; int Arg2 = 5; verify_case(3, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ATTAGCATTGCACACCTTGAGGACTTAGACAAACCTAGTACACAGGTGTA"; int Arg1 = 5; int Arg2 = 11; verify_case(4, Arg2, maxLength(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TandemRepeats ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

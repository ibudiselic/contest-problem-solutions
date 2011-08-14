#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class WordParts {
	public:
	bool ok(const string &a, const string &b) {
		if (a.size() > b.size()) return false;

		bool ret = true;
		for (string::size_type i=0; i<a.size(); ++i)
			if (a[i] != b[i]) {
				ret = false;
				break;
			}
		if (ret) return true;
		ret = true;
		for (string::size_type i=0; i<a.size(); ++i)
			if (a[i] != b[b.size()-a.size()+i]) {
				ret = false;
				break;
			}
		return ret;
	}
	int partCount(string original, string compound) {
		int a[51];

		for (int i=1; i<51; ++i)
			a[i] = 2000000000;

		a[0] = 0;
		for (string::size_type i=1; i<=compound.size(); ++i)
			for (string::size_type j=0; j<i; ++j)
				if (ok(compound.substr(j, i-j), original) && a[j]+1 < a[i])
					a[i] = a[j]+1;
		return (a[compound.size()]!=2000000000)? a[compound.size()] : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ANTIDISESTABLISHMENTARIANISM"; string Arg1 = "ANTIDISIANISMISM"; int Arg2 = 3; verify_case(0, Arg2, partCount(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ANTIDISESTABLISHMENTARIANISM"; string Arg1 = "ESTABLISHMENT"; int Arg2 = -1; verify_case(1, Arg2, partCount(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "TOPCODERDOTCOM"; string Arg1 = "TOMTMODERDOTCOM"; int Arg2 = 5; verify_case(2, Arg2, partCount(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "HELLO"; string Arg1 = "HELLOHEHELLOLOHELLO"; int Arg2 = 5; verify_case(3, Arg2, partCount(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "DONTFORGETTHEEMPTYCASE"; string Arg1 = ""; int Arg2 = 0; verify_case(4, Arg2, partCount(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "BAAABA"; string Arg1 = "BAAABAAA"; int Arg2 = 2; verify_case(5, Arg2, partCount(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB"; string Arg1 = "BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA"; int Arg2 = 17; verify_case(6, Arg2, partCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordParts ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

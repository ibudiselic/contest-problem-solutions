#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class AntiPalindrome {
	public:
	string rearrange(string s) {
		sort(s.begin(), s.end());

		for (int i=((int)s.size()+1)/2; i<(int)s.size(); ++i)
			if (s[i] == s[(int)s.size()-1-i]) {
				int pos = -1;
				for (int j=i+1; j<(int)s.size(); ++j)
					if (s[i] != s[j])
						if (pos==-1 || s[pos]>s[j])
							pos = j;
				if (pos == -1)
					return "";
				else
					swap(s[i], s[pos]);
			}


		return s;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "test"; string Arg1 = "estt"; verify_case(0, Arg1, rearrange(Arg0)); }
	void test_case_1() { string Arg0 = "aabbcc"; string Arg1 = "aabcbc"; verify_case(1, Arg1, rearrange(Arg0)); }
	void test_case_2() { string Arg0 = "reflectionnoitcelfer"; string Arg1 = "cceeeeffiillnnoorrtt"; verify_case(2, Arg1, rearrange(Arg0)); }
	void test_case_3() { string Arg0 = "hello"; string Arg1 = "ehllo"; verify_case(3, Arg1, rearrange(Arg0)); }
	void test_case_4() { string Arg0 = "www"; string Arg1 = ""; verify_case(4, Arg1, rearrange(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AntiPalindrome ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

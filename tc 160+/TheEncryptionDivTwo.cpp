#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char seen[26];
class TheEncryptionDivTwo {
	public:
	string encrypt(string message) {
		memset(seen, 0, sizeof seen);
        string C;
        char c = 'a';
        for (int i=0; i<(int)message.size(); ++i) {
            if (!seen[message[i]-'a']) {
                seen[message[i]-'a'] = c;
                C += c;
                ++c;
            } else {
                C += seen[message[i]-'a'];
            }
        }
        return C;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hello"; string Arg1 = "abccd"; verify_case(0, Arg1, encrypt(Arg0)); }
	void test_case_1() { string Arg0 = "abcd"; string Arg1 = "abcd"; verify_case(1, Arg1, encrypt(Arg0)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arg1 = "abcdbefg"; verify_case(2, Arg1, encrypt(Arg0)); }
	void test_case_3() { string Arg0 = "encryption"; string Arg1 = "abcdefghib"; verify_case(3, Arg1, encrypt(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheEncryptionDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class SentenceCapitalizerInator {
	public:
	string fixCaps(string paragraph) {
		bool up = true;
        for (int i=0; i<(int)paragraph.size(); ++i) {
            if (up && isalpha(paragraph[i])) {
                paragraph[i] = toupper(paragraph[i]);
                up = false;
            } else if (paragraph[i] == '.') {
                up = true;
            }
        }
        return paragraph;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hello programmer. welcome to topcoder."; string Arg1 = "Hello programmer. Welcome to topcoder."; verify_case(0, Arg1, fixCaps(Arg0)); }
	void test_case_1() { string Arg0 = "one."; string Arg1 = "One."; verify_case(1, Arg1, fixCaps(Arg0)); }
	void test_case_2() { string Arg0 = "not really. english. qwertyuio. a. xyz."; string Arg1 = "Not really. English. Qwertyuio. A. Xyz."; verify_case(2, Arg1, fixCaps(Arg0)); }
	void test_case_3() { string Arg0 = "example four. the long fourth example. a. b. c. d."; string Arg1 = "Example four. The long fourth example. A. B. C. D."; verify_case(3, Arg1, fixCaps(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SentenceCapitalizerInator ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

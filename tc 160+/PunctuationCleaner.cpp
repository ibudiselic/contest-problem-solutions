#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class PunctuationCleaner {
	public:
	string clearExcess(string document) {
		string sol;
		bool in_seq = false;
		bool has_q = false;
		for (int i=0; i<(int)document.size(); ++i) {
			if (document[i]=='?' || document[i]=='!') {
				in_seq = true;
				has_q |= (document[i]=='?');
			} else {
				if (in_seq) {
					sol += (has_q ? '?' : '!');
					in_seq = false;
					has_q = false;
				}
				sol += document[i];
			}
		}

		if (in_seq) {
			sol += (has_q ? '?' : '!');
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "This cheese is really great!!!!!"; string Arg1 = "This cheese is really great!"; verify_case(0, Arg1, clearExcess(Arg0)); }
	void test_case_1() { string Arg0 = "You really like THIS cheese!?!?!?!!!?"; string Arg1 = "You really like THIS cheese?"; verify_case(1, Arg1, clearExcess(Arg0)); }
	void test_case_2() { string Arg0 = " !!?X! ?? This is delicious!!! ??!a!?!"; string Arg1 = " ?X! ? This is delicious! ?a?"; verify_case(2, Arg1, clearExcess(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PunctuationCleaner ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

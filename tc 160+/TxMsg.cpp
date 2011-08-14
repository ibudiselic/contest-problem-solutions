#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const string V = "aeiou";
bool is_vowel(char c) {
    return V.find(c) != string::npos;
}
string process(const string &s) {
    string ret;
    int cnt_vowels = 0;
    for (int i=0; i<(int)s.size(); ++i) {
        if (is_vowel(s[i])) {
            ++cnt_vowels;
        } else if (i==0 || is_vowel(s[i-1])) {
            ret += s[i];
        }
    }
    return cnt_vowels==(int)s.size() ? s : ret;
}
class TxMsg {
	public:
	string getMessage(string original) {
		istringstream is(original);
        string sol;
        string w;
        while (is >> w) {
            sol = sol + ' ' + process(w);
        }
        return sol.substr(1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "text message"; string Arg1 = "tx msg"; verify_case(0, Arg1, getMessage(Arg0)); }
	void test_case_1() { string Arg0 = "ps i love u"; string Arg1 = "p i lv u"; verify_case(1, Arg1, getMessage(Arg0)); }
	void test_case_2() { string Arg0 = "please please me"; string Arg1 = "ps ps m"; verify_case(2, Arg1, getMessage(Arg0)); }
	void test_case_3() { string Arg0 = "back to the ussr"; string Arg1 = "bc t t s"; verify_case(3, Arg1, getMessage(Arg0)); }
	void test_case_4() { string Arg0 = "aeiou bcdfghjklmnpqrstvwxyz"; string Arg1 = "aeiou b"; verify_case(4, Arg1, getMessage(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TxMsg ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

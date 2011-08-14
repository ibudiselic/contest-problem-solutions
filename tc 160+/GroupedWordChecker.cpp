#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is(const string &s) {
    bool seen[26] = {0};
    for (int i=0; i<(int)s.size(); ++i) {
        if (seen[s[i]-'a'] && i>0 && s[i]!=s[i-1]) {
            return false;
        }
        seen[s[i]-'a'] = 1;
    }
    return true;
}
class GroupedWordChecker {
	public:
	int howMany(vector <string> words) {
		int sol = 0;
        for (int i=0; i<(int)words.size(); ++i) {
            sol += is(words[i]);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ccazzzzbb", "code", "aabbbccb", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"ab", "aa", "aca", "ba", "bb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"happy", "new", "year"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"yzyzy", "zyzyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GroupedWordChecker ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

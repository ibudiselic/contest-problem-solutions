#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string merge(const string &s, const string &t, int &start) {
    while (start < (int)s.size()) {
        bool ok = true;
        for (int i=start; i<(int)s.size() && i-start<(int)t.size(); ++i) {
            if (s[i] != t[i-start]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return (start+(int)t.size()<(int)s.size() ? s : s.substr(0, start) + t);
        }
        ++start;
    }
    return s + t;
}
class OrderedSuperString {
	public:
	int getLength(vector <string> words) {
		string s = words[0];

        int start = 0;
        for (int i=1; i<(int)words.size(); ++i) {
            s = merge(s, words[i], start);
        }

        return (int)s.size();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"abc","ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","a","b","a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"abcdef", "ab","bc", "de","ef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"ab","bc", "de","ef","abcdef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, getLength(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    OrderedSuperString ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

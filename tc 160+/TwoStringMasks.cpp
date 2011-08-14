#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool intersects(int a, int b, int c, int d) {
    return (a<=c && c<=b || c<=a && a<=d);
}
class TwoStringMasks {
	public:
	string shortestCommon(string s1, string s2) {
        int p = s1.find('*');
        string a = s1.substr(0, p);
        string b = (p+1<(int)s1.size() ? s1.substr(p+1) : string());

        p = s2.find('*');
        string x = s2.substr(0, p);
        string y = (p+1<(int)s2.size() ? s2.substr(p+1) : string());

        string sol = string(220, 'Z');
        for (int l1=0; l1<=55; ++l1) {
            for (int l2=0; l2<=55; ++l2) {
                if (a.size()+b.size()+l1 != x.size()+y.size()+l2) {
                    continue;
                }

                if (l1!=0 && l2!=0 && intersects(a.size()+1, a.size()+l1, x.size()+1, x.size()+l2)) {
                    continue;
                }

                string s = a + string(l1, '*') + b;
                string t = x + string(l2, '*') + y;
                bool ok = true;
                for (int i=0; i<(int)s.size(); ++i) {
                    assert(s[i]!='*' || t[i]!='*');
                    if (s[i] == '*') {
                        s[i] = t[i];
                    } else if (t[i]!='*' && s[i]!=t[i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    if (s.size() < sol.size()) {
                        sol = s;
                    } else if (s.size() == sol.size()) {
                        sol = min(sol, s);
                    }
                }
            }
        }

        return sol.size() < 220u ? sol : string("impossible");
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "TOPC*DER"; string Arg1 = "T*PCODER"; string Arg2 = "TOPCODER"; verify_case(0, Arg2, shortestCommon(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "HELLO*"; string Arg1 = "HI*"; string Arg2 = "impossible"; verify_case(1, Arg2, shortestCommon(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "GOOD*LUCK"; string Arg1 = "*"; string Arg2 = "GOODLUCK"; verify_case(2, Arg2, shortestCommon(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "*SAMPLETEST"; string Arg1 = "THIRDSAMPLE*"; string Arg2 = "THIRDSAMPLETEST"; verify_case(3, Arg2, shortestCommon(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "*TOP"; string Arg1 = "*CODER"; string Arg2 = "impossible"; verify_case(4, Arg2, shortestCommon(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "*"; string Arg1 = "A*"; string Arg2 = "A"; verify_case(5, Arg2, shortestCommon(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "*A"; string Arg1 = "B*"; string Arg2 = "BA"; verify_case(6, Arg2, shortestCommon(Arg0, Arg1)); }
	void test_case_7() { string Arg0 = "LASTCASE*"; string Arg1 = "*LASTCASE"; string Arg2 = "LASTCASE"; verify_case(7, Arg2, shortestCommon(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TwoStringMasks ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

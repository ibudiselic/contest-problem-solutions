#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string sol;
char buff[30];
void upd(const string &s) {
    int h, m, off;
    sscanf(s.c_str(), "%d:%d GMT%d", &h, &m, &off);
    if (!(h>=0 && h<=23) || !(m>=0 && m<=59) || !(off>=-9 && off<=9)) {
        return;
    }
    h = (h - off + 24) % 24;
    sprintf(buff, "%02d:%02d", h, m);
    sol = min(sol, string(buff));
}
void go(string &s, int p) {
    if (p == (int)s.size()) {
        upd(s);
    } else if (s[p] == '?') {
        if (p != 9) {
            int lim = 10;
            int start = 0;
            switch (p) {
                case 0: lim = 3; break;
                case 1: lim = (s[0]=='2' ? 4 : 10); break;
                case 3: lim = 6; break;
                case 10: start = (s[9]=='-'); break;
            }
            for (int i=start; i<lim; ++i) {
                s[p] = '0' + i;
                go(s, p+1);
            }
        } else {
            char c = '-';
            for (int t=0; t<2; ++t) {
                s[9] = c;
                go(s, p+1);
                c = '+';
            }
        }
        s[p] = '?';
    } else {
        go(s, p+1);
    }
}
class TheTriangleBothDivs {
	public:
	string fix(string tajm) {
		sol = "23:59";
        go(tajm, 0);
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "17:45 GMT-4"; string Arg1 = "21:45"; verify_case(0, Arg1, fix(Arg0)); }
	void test_case_1() { string Arg0 = "16:?? GMT??"; string Arg1 = "00:00"; verify_case(1, Arg1, fix(Arg0)); }
	void test_case_2() { string Arg0 = "?1:34 GMT-9"; string Arg1 = "06:34"; verify_case(2, Arg1, fix(Arg0)); }
	void test_case_3() { string Arg0 = "??:?? GMT??"; string Arg1 = "00:00"; verify_case(3, Arg1, fix(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheTriangleBothDivs ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

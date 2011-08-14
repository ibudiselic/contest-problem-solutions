#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <set>

using namespace std;

typedef pair<int, string> P;
set<P> S;
string sol;

void go(string &s, int k) {
    if (!S.insert(P(k, s)).second) {
        return;
    }
    if (k == 0) {
        if (sol.size()==0 || sol<s) {
            sol = s;
        }
        return;
    }
    for (int i=0; i<(int)s.size(); ++i) {
        for (int j=0; j<i; ++j) {
            if (j>0 || s[i]!='0') {
                swap(s[i], s[j]);
                go(s, k-1);
                swap(s[i], s[j]);
            }
        }
    }
}
class TheSwap {
	public:
	int findMax(int n, int k) {
		ostringstream os;
        os << n;
        string s = os.str();
        S.clear();
        sol.clear();
        go(s, k);
        
        if (sol.size() == 0) {
            return -1;
        } else {
            istringstream is(sol);
            is >> n;
            return n;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 16375; int Arg1 = 1; int Arg2 = 76315; verify_case(0, Arg2, findMax(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 432; int Arg1 = 1; int Arg2 = 423; verify_case(1, Arg2, findMax(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 90; int Arg1 = 4; int Arg2 = -1; verify_case(2, Arg2, findMax(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 2; int Arg2 = -1; verify_case(3, Arg2, findMax(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 436659; int Arg1 = 2; int Arg2 = 966354; verify_case(4, Arg2, findMax(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheSwap ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

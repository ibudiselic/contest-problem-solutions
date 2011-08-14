#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<int> > v;
vector<int> cur;

void gen(int m, int n) {
    if (m == 0) {
        v.push_back(cur);
    } else {
        for (int i=n; i>0; --i) {
            cur.push_back(i);
            gen(m-1, i-1);
            cur.pop_back();
        }
    }
}

int inter_sz(int i, int j) {
    const vector<int> &a = v[i];
    const vector<int> &b = v[j];

    int ret = 0;
    i = 0;
    j = 0;
    while (i<(int)a.size() && j<(int)b.size()) {
        if (a[i] == b[j]) {
            ++ret;
            ++i;
            ++j;
        } else if (a[i] > b[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    return ret;
}

class TwoLotteryGames {
	public:
	double getHigherChanceGame(int n, int m, int k) {
	    v.clear();
        gen(m, n);

        double unit = 1.0/v.size()/v.size();

        double sol = 0.0;
        for (int i=0; i<(int)v.size(); ++i) {
            for (int j=0; j<(int)v.size(); ++j) {
                if (inter_sz(i, j) >= k) {
                    sol += unit;
                }
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; double Arg3 = 1.0; verify_case(0, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; double Arg3 = 0.3333333333333333; verify_case(1, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 2; int Arg2 = 1; double Arg3 = 0.4642857142857143; verify_case(2, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 4; int Arg2 = 2; double Arg3 = 0.7571428571428571; verify_case(3, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TwoLotteryGames ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string F;
int bc[1<<17];

void upd(int newpos, int &next, int &multi) {
    if (next & (1<<newpos)) {
        multi |= (1<<newpos);
    } else {
        next |= (1<<newpos);
    }
}
int go(int n, int mask) {
    vector<int> from(n, -1);
    while (n > 2) {
        int next = 0;
        int multi = 0;
        vector<int> nfrom(n-1, -1);
        for (int i=0; i<n; ++i) {
            if (mask & (1<<i)) {
                if (i == 0) {
                    upd(1, next, multi);
                    nfrom[1] = 0;
                } else if (i==n-1 || i==n-2) {
                    upd(i-1, next, multi);
                    nfrom[i-1] = i;
                } else if (F[i] == 'W') {
                    upd(i-1, next, multi);
                    nfrom[i-1] = i;
                } else if (F[i] == 'B') {
                    upd(i+1, next, multi);
                    nfrom[i+1] = i;
                } else if (n == (int)F.size()) {
                    upd(i-1, next, multi);
                    nfrom[i-1] = i;
                } else {
                    assert(from[i] != -1);
                    upd(from[i], next, multi);
                    nfrom[from[i]] = i;
                }
            }
        }
        from.swap(nfrom);
        mask = next^multi;
        --n;
    }
    return bc[mask];
}
class RabbitStepping {
	public:
	double getExpected(string field, int r) {
	    F = field;
        int n = F.size();
        double sol = 0.0;
        double cnt = 0.0;
        for (int i=1; i<(1<<n); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        for (int i=0; i<(1<<n); ++i) {
            if (bc[i] == r) {
                sol += go(n, i);
                cnt += 1.0;
            }
        }
        
        return sol/cnt;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "WRBRW"; int Arg1 = 4; double Arg2 = 0.8; verify_case(0, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "WWB"; int Arg1 = 2; double Arg2 = 1.3333333333333333; verify_case(1, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "WW"; int Arg1 = 1; double Arg2 = 1.0; verify_case(2, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BBBBBBBBBB"; int Arg1 = 4; double Arg2 = 0.9523809523809523; verify_case(3, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "RRBRRWRRBRRW"; int Arg1 = 8; double Arg2 = 0.9696969696969697; verify_case(4, Arg2, getExpected(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RabbitStepping ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

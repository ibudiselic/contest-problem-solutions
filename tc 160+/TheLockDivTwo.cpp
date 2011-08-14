#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool used[1<<10];
int n;
int next(int x) {
    used[x] = true;
    
    int sol = 1<<12;
    for (int m=0; m<(1<<n); ++m) {
        if ((x&m) == 0) {
            int y = x | m;
            if (!used[y] && y<sol) {
                sol = y;
            }
        } else if ((x&m) == m) {
            int y = x ^ m;
            if (!used[y] && y<sol) {
                sol = y;
            }
        }
    }
    return sol;
}
string to_sol(int x) {
    string s(n, '0');
    int i = n-1;
    while (x > 0) {
        if (x & 1) {
            s[i] = '1';
        }
        --i;
        x >>= 1;
    }
    
    return s;
}
class TheLockDivTwo {
	public:
	string password(int n, int k) {
		memset(used, 0, sizeof used);
        ::n = n;
        
        int x = 0;
        while (--k) {
            x = next(x);
        }
        
        return to_sol(x);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; string Arg2 = "10"; verify_case(0, Arg2, password(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 6; string Arg2 = "0100"; verify_case(1, Arg2, password(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "0000000000"; verify_case(2, Arg2, password(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 100; string Arg2 = "1100001"; verify_case(3, Arg2, password(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLockDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

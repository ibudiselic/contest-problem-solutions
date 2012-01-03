#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int cnt[4748];
int get_cnt(int a, int b) {
    return cnt[b] - cnt[a-1];
}
bool f(int x) {
    while (x > 0) {
        int d = x%10;
        if (d!=4 && d!=7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int brus(int a, int b, int bLen) {
    int ret = b-a+1;
    for (int i=a; i+bLen-1<=b; ++i) {
        ret = min(ret, get_cnt(i, i+bLen-1));
    }
    return ret;
}
class TheLuckyGameDivTwo {
	public:
	int find(int a, int b, int jLen, int bLen) {
        for (int i=a; i<=b; ++i) {
            cnt[i] = cnt[i-1] + f(i);
        }
        
        int sol = 0;
        for (int i=a; i+jLen<=b+1; ++i) {
            sol = max(sol, brus(i, i+jLen-1, bLen));
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 2; int Arg3 = 1; int Arg4 = 0; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 100; int Arg3 = 100; int Arg4 = 6; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 8; int Arg2 = 3; int Arg3 = 2; int Arg4 = 1; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 75; int Arg3 = 50; int Arg4 = 2; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLuckyGameDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

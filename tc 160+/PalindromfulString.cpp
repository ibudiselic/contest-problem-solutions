#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long sol;
int N, M, K;
vector<int> pattern;
int tokens;
bool is_palin(int start) {
    assert(start + M <= N);
    for (int i=0; i<M/2; ++i) {
        if (pattern[start+i] != pattern[start+M-1-i]) {
            return false;
        }
    }
    return true;
}
int cnt_palin() {
    int ret = 0;
    for (int i=0; i+M<=N; ++i) {
        ret += is_palin(i);
    }
    return ret;
}
long long ways() {
    long long ret = 1;
    for (int i=0; i<tokens; ++i) {
        ret *= 26-i;
    }
    return ret;
}
void go(int pos) {
    if (pos == N) {
        if (cnt_palin() >= K) {
            sol += ways();
        }
    } else {
        for (int i=0; i<tokens; ++i) {
            pattern.push_back(i);
            go(pos + 1);
            pattern.pop_back();
        }
        pattern.push_back(tokens++);
        go(pos + 1);
        pattern.pop_back();
        --tokens;
    }
}
class PalindromfulString {
	public:
	long long count(int N, int M, int K) {
        sol = 0;
        ::N = N;
        ::M = M;
        ::K = K;
        tokens = 0;
        go(0);
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 26LL; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; long long Arg3 = 676LL; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 1326LL; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; long long Arg3 = 676LL; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 3; int Arg2 = 3; long long Arg3 = 4310176LL; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PalindromfulString ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const int mod = 1000000007;
map< pair<int, int>, int> f_mem, g_mem;

int f(int H, int N);
int g(int H, int N) {
    if (g_mem.count(make_pair(H, N))) {
        return g_mem[make_pair(H, N)];
    }
    return g_mem[make_pair(H, N)] = (N==1 ? 1 : f(H, H/N));
}

int f(int H, int N) {
    if (f_mem.count(make_pair(H, N))) {
        return f_mem[make_pair(H, N)];
    }
    int &ret = f_mem[make_pair(H, N)];
    for (int d=1; d<=N/d; ++d) {
        if (N%d == 0) {
            if (d > 1) {
                ret += g(H/d, N/d);
            }
            if (ret >= mod) {
                ret -= mod;
            }
            if (d*d != N) {
                ret += g(H/(N/d), d);
            }
            if (ret >= mod) {
                ret -= mod;
            }
        }
    }
    return ret;
}

class StrangeElevator {
	public:
	int theCount(int H, int N) {
		if (H%N != 0) {
            return 0;
        }
        f_mem.clear();
        g_mem.clear();
        return (g(H, N) + f(H, N)) % mod;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 58; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 2; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 120; int Arg1 = 12; int Arg2 = 30; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 58585858; int Arg1 = 495; int Arg2 = 0; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StrangeElevator ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

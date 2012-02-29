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

int T;
int ok[100001];
int go(int n) {
    int &ret = ok[n];
    if (ret != -1) {
        return ret;
    }
    if (n == T) {
        return ret = 1;
    }
    if (n < T) {
        return ret = 0;
    }
    bool composite = false;
    bool can = true;
    for (int d=2; d*d<=n; ++d) {
        if (n%d == 0) {
            composite = true;
            if (!go(d) && !go(n/d)) {
                can = false;
                break;
            }
        }
    }
    return ret = (composite && can);
}
class CompositeSmash {
	public:
	string thePossible(int N, int target) {
        T = target;
		memset(ok, 0xff, sizeof ok);
        return go(N) ? "Yes" : "No";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 517; int Arg1 = 47; string Arg2 = "Yes"; verify_case(0, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 4; string Arg2 = "Yes"; verify_case(1, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 6; string Arg2 = "No"; verify_case(2, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "No"; verify_case(3, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; string Arg2 = "Yes"; verify_case(4, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 5858; int Arg1 = 2; string Arg2 = "Yes"; verify_case(5, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 81461; int Arg1 = 2809; string Arg2 = "No"; verify_case(6, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 65536; int Arg1 = 256; string Arg2 = "No"; verify_case(7, Arg2, thePossible(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CompositeSmash ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string exact(int n, long long k) {
    if (n == 0) {
        return string();
    }
    if (k == 0) {
        return string(n, '0');
    }
    if (n == 1) {
        return string(1, '1');
    }
    
    assert(k < (1LL<<n));
    long long t = 1LL << (n-1);
    if (k == t) {
        return string(1, '1') + exact(n-1, k-1);
    } else if (k < t) {
        return string(1, '0') + exact(n-1, k);
    } else {
        return string(1, '1') + exact(n-1, k-1-t);
    }
}
string calc(int n, long long k) {
    if (n == 0) {
        return string();
    }
    if (k == 0) {
        return string(n, '0');
    }
    if (n == 1) {
        return string(1, '1');
    }
    assert(k < (1LL<<n));
    long long t = 1LL << (n-1);
    if (k == t) {
        return string(1, '1') + exact(n-1, k-1);
    } else if (k < t) {
        return string(1, '0') + calc(n-1, k);
    } else {
        string tt = string(1, '1') + exact(n-1, t-1);
        return max(tt, string(1, '1') + calc(n-1, k-1-t));
    }
}
class TheLockDivOne {
	public:
	string password(int n, long long k) {
        return calc(n, k-1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; string Arg2 = "11"; verify_case(0, Arg2, password(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 8LL; string Arg2 = "111"; verify_case(1, Arg2, password(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 6LL; string Arg2 = "0110"; verify_case(2, Arg2, password(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; long long Arg1 = 1LL; string Arg2 = "0000000000"; verify_case(3, Arg2, password(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; long long Arg1 = 100LL; string Arg2 = "1111110"; verify_case(4, Arg2, password(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLockDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

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

class TheLuckyBasesDivTwo {
	public:
	long long find(long long n) {
		if (n==4 || n==7) {
            return -1;
        }
        
        int sol = 0;
        int base = 2;
        while (1) {
            if (n/base < base) {
                break;
            }
            bool ok = true;
            long long x = n;
            while (x >= base) {
                int d = x % base;
                if (d!=4 && d!=7) {
                    ok = false;
                    break;
                }
                x /= base;
            }
            if (ok && (x==4 || x==7)) {
                ++sol;
            }
            ++base;
        }
        
        for (int a=4; a<8; a+=3) {
            for (int b=4; b<8; b+=3) {
                if (n-b>=0 && (n-b)%a==0) {
                    long long x = (n-b)/a;
                    sol += (a<x) && (b<x);
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
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 255LL; long long Arg1 = 1LL; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { long long Arg0 = 4LL; long long Arg1 = -1LL; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 0LL; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { long long Arg0 = 60LL; long long Arg1 = 2LL; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLuckyBasesDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long LIMIT = 1<<20;
int S_memo[LIMIT];
int S(long long x) {
    int ret = 0;
    while (x >= LIMIT) {
        ret += x%10;
        x /= 10;
    }
    if (S_memo[x] == 0) {
        long long t = x;
        int tmp = 0;
        while (t > 0) {
            tmp += t%10;
            t /= 10;
        }
        S_memo[x] = tmp;
    }
    return ret + S_memo[x];
}
class RabbitNumber {
	public:
	int theCount(long long low, long long high) {
        int sol = 0;
        int digcnt = 0;
        long long p10 = 1;
        while (low >= p10) {
            ++digcnt;
            p10 *= 10;
        }
        
        for (long long i=low; i<=high; ++i) {
            if (i >= p10) {
                ++digcnt;
                p10 *= 10;
            }
            int s = S(i);
            if (s*s > (2*digcnt-1)*9) {
                int moveby = 1;
                while (s*s > (2*digcnt-1)*9) {
                    moveby *= 10;
                    long long tmp = (i/moveby+1)*moveby;
                    if (tmp >= p10) {
                        break;
                    }
                    s = S(tmp);
                }
                i = (i/moveby+1) * moveby - 1;
            } else {
                const long long ii = i*i;
                const int ss = S(ii);
                sol += (s*s == ss);
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 22; int Arg1 = 22; int Arg2 = 1; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 484; int Arg1 = 484; int Arg2 = 0; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 12; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 58; int Arg1 = 484; int Arg2 = 24; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RabbitNumber ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

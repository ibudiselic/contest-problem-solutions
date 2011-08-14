#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
long long A;
long long B;
const long long INF = 1000000000000LL;
vector<long long> lucky;
void test_push(long long x) {
    if (x <= B) {
        lucky.push_back(x);
    }
}
long long sol;
long long gcd(long long m, long long n) {
    return (m==0 ? n : gcd(n%m, m));
}
long long lcm(long long m, long long n) {
    const long long d = gcd(m, n);
    m /= d;
    return (m<=INF/n ? m*n : INF);
}

void go(bool add, int p, long long cur) {
    if (p == -1) {
        return;
    }
    go(add, p-1, cur);
    add = !add;
    cur = lcm(cur, lucky[p]);
    if (cur <= B) {
        sol += (add ? +1 : -1)*(B/cur - A/cur);
        go(add, p-1, cur);
    }
}
class TheAlmostLuckyNumbers {
	public:
	long long count(long long a, long long b) {
        A = a - 1;
        B = b;
		lucky.clear();
        lucky.push_back(4);
        lucky.push_back(7);
        for (int i=0; i<(int)lucky.size(); ++i) {
            test_push(lucky[i]*10 + 4);
            test_push(lucky[i]*10 + 7);
        }
        sort(lucky.begin(), lucky.end());
        int cnt_muls = 0;
        for (int i=1; i<(int)lucky.size(); ++i) {
            if (lucky[i] != INF) {
                for (int j=0; j<i; ++j) {
                    if (lucky[j]!=INF && lucky[i]%lucky[j]==0) {
                        lucky[i] = INF;
                        ++cnt_muls;
                        break;
                    }
                }
            }
        }
        sort(lucky.begin(), lucky.end());
        lucky.resize((int)lucky.size()-cnt_muls);
        
        sol = 0;
        go(0, (int)lucky.size()-1, 1);
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 10LL; long long Arg2 = 3LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 14LL; long long Arg1 = 14LL; long long Arg2 = 1LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 39LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1234LL; long long Arg1 = 4321LL; long long Arg2 = 1178LL; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheAlmostLuckyNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

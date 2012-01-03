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

vector<long long> v;
long long A, B;
int cnt_nums(long long a, long long b, long long aa, long long bb) {
    if (a<aa || b>bb) {
        return 123456789;
    }
    int r = lower_bound(v.begin(), v.end(), b) - v.begin();
    int l = lower_bound(v.begin(), v.end(), a) - v.begin();
    return r-l+(v[r]==b);
}
int brus(long long a, long long b, long long len) {
    if (a<A || b>B) {
        return 0;
    }
    int sol = min(cnt_nums(a, a+len-1, a, b), cnt_nums(b-len+1, b, a, b));
    for (int i=0; i<(int)v.size(); ++i) {
        sol = min(sol, cnt_nums(v[i]+1, v[i]+len, a, b));
        sol = min(sol, cnt_nums(v[i]-len, v[i]-1, a, b));
    }
    return sol;
}
class TheLuckyGameDivOne {
	public:
	int find(long long a, long long b, long long jLen, long long bLen) {
        A = a;
        B = b;
        v.clear();
        v.push_back(4);
        v.push_back(7);
        int i = 0;
        while (1) {
            v.push_back(v[i]*10 + 4);
            if (v.back() > b) {
                break;
            }
            v.push_back(v[i]*10 + 7);
            if (v.back() > b) {
                break;
            }
            ++i;
        }
        int sol = max(brus(a, a+jLen-1, bLen), brus(b-jLen+1, b, bLen));
        for (int i=0; i<(int)v.size(); ++i) {
            sol = max(sol, brus(v[i], v[i]+jLen-1, bLen));
            sol = max(sol, brus(v[i]+1, v[i]+jLen, bLen));
            sol = max(sol, brus(v[i]-jLen+1, v[i], bLen));
            sol = max(sol, brus(v[i]-jLen, v[i]-1, bLen));
            sol = max(sol, brus(v[i]-bLen, v[i]-bLen+jLen-1, bLen));
            sol = max(sol, brus(v[i]-bLen+1, v[i]-bLen+jLen, bLen));
            sol = max(sol, brus(v[i]+bLen-jLen+1, v[i]+bLen, bLen));
            sol = max(sol, brus(v[i]+bLen-jLen, v[i]+bLen-1, bLen));
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 10LL; long long Arg2 = 2LL; long long Arg3 = 1LL; int Arg4 = 0; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 100LL; long long Arg3 = 100LL; int Arg4 = 6; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 4LL; long long Arg1 = 8LL; long long Arg2 = 3LL; long long Arg3 = 2LL; int Arg4 = 1; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 75LL; long long Arg3 = 50LL; int Arg4 = 2; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLuckyGameDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

struct S {
    int rounds, cnt, largest;
};

int INF = 123456789;
S dp[1000001][2];
class ChangeOMatic {
	public:
	long long howManyRounds(vector <int> V, long long x) {
        for (int i=0; i<1000001; ++i) {
            for (int j=0; j<2; ++j) {
                dp[i][j].largest = 51;
                dp[i][j].rounds = INF;
                dp[i][j].cnt = INF;
            }
        }
        
        for (int i=0; i<2; ++i) {
            dp[0][i].rounds = 0;
            dp[0][i].cnt = 0;
            dp[0][i].largest = 51;
            dp[1][i].rounds = 0;
            dp[1][i].cnt = 1;
            dp[1][i].largest = 1;
        }
        
        for (int i=0; i<(int)V.size(); ++i) {
            for (int u=V[i]; u<1000001; ++u) {
                for (int whole=1; whole>=0; --whole) {
                    S &ret = dp[u][whole];
                    S t = dp[u-V[i]][0];
                    if (whole && t.cnt==0) {
                        continue;
                    }
                    ++t.cnt;
                    t.largest = i;
                    if (t.cnt <= ret.cnt) {
                        ret = t;
                        assert(u!=V[i] || !whole);
                        ret.rounds += dp[V[i]][1].rounds + whole;
                    }
                }
            }
        }
        
        if (x <= 1000000) {
            return dp[x][1].rounds;
        } else {
            long long cnt = (x - 999000)/V.back();
            return cnt*dp[V.back()][1].rounds + dp[999000 + (x-999000)%V.back()][0].rounds + 1;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,5,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 21LL; long long Arg2 = 7LL; verify_case(0, Arg2, howManyRounds(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,33,90,91,92,93,94,95,96,97,98}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 99LL; long long Arg2 = 12LL; verify_case(1, Arg2, howManyRounds(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,30,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 50LL; long long Arg2 = 2LL; verify_case(2, Arg2, howManyRounds(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,30,60,90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 60LL; long long Arg2 = 3LL; verify_case(3, Arg2, howManyRounds(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,8,9,11,12,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 120LL; long long Arg2 = 37LL; verify_case(4, Arg2, howManyRounds(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ChangeOMatic ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

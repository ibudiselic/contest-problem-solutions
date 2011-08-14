#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long mod = 1234567891LL;
long long dp[16][1<<16];
vector<string> C;

bool can(int i, int j) {
    return C[i][0]==C[j][0] || C[i][1]==C[j][1];
}
long long ALL;
long long go(int last, int mask) {
    long long &ret = dp[last][mask];
    if (ret != -1) {
        return ret;
    }
    if (mask == ALL) {
        return (ret = 1);
    }
    
    ret = 0;
    for (int i=0; i<(int)C.size(); ++i) {
        if (((mask>>i) & 1)==0 && can(last, i)) {
            ret += go(i, mask | (1<<i));
            if (ret >= mod) {
                ret -= mod;
            }
        }
    }
    
    return ret;
}
class TheCardLineDivTwo {
	public:
	int count(vector <string> cards) {
		C = cards;
        ALL = (1<<C.size()) - 1;
        for (int i=0; i<(int)C.size(); ++i) {
            if (C[i][1] == 'D') {
                C[i][1] = 'H';
            } else if (C[i][1] == 'C') {
                C[i][1] = 'S';
            }
        }
        
        long long sol = 0;
        memset(dp, 0xff, sizeof dp);
        for (int i=0; i<(int)C.size(); ++i) {
            sol += go(i, 1<<i);
            if (sol >= mod) {
                sol -= mod;
            }
        }
        return int(sol);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"KH", "QD", "KC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"JS", "JC", "JD", "JH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"2S", "3C", "4C", "5S", "6C", "7S", "8S", "9H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"KD", "KC", "AD", "7C", "AH", "9C", "4H", "4S", "AS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2416; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheCardLineDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

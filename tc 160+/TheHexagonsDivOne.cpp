#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[151][1<<7];
const int END_MASK = (1<<7) - 1;
vector< vector<int> > adj;
bool noadj(int i, int j) {
    for (int k=0; k<(int)adj[i].size(); ++k) {
        if (adj[i][k] == j) {
            return false;
        }
    }
    return true;
}
long long go(int n, int mask) {
    long long &ret = dp[n][mask];
    if (ret != -1) {
        return ret;
    }
    if (mask == END_MASK) {
        return (ret = 1);
    }
    if (n == 0) {
        return (ret = 0);
    }
    
    ret = go(n-1, mask);
    for (int i=0; i<7; ++i) {
        if (!((mask>>i) & 1)) {
            ret += 2*go(n-1, mask | (1<<i)); // n or 2n
            for (int j=i+1; j<7; ++j) {
                if (!((mask>>j) & 1) && noadj(i, j)) {
                    ret += 2*go(n-1, mask | (1<<i) | (1<<j));
                }
            }
        }
    }
    
    return ret;
}

class TheHexagonsDivOne {
	public:
	long long count(int n) {
        if (adj.size() == 0) {
           adj.assign(7, vector<int>());
           adj[0].push_back(1);
           adj[0].push_back(2);
           adj[0].push_back(3);
       
           adj[1].push_back(0);
           adj[1].push_back(3);
           adj[1].push_back(4);

           adj[2].push_back(0);
           adj[2].push_back(3);
           adj[2].push_back(5);

           adj[3].push_back(0);
           adj[3].push_back(1);
           adj[3].push_back(2);
           adj[3].push_back(4);
           adj[3].push_back(5);
           adj[3].push_back(6);

           adj[4].push_back(1);
           adj[4].push_back(3);
           adj[4].push_back(6);

           adj[5].push_back(2);
           adj[5].push_back(3);
           adj[5].push_back(6);
           
           adj[6].push_back(4);
           adj[6].push_back(3);
           adj[6].push_back(5);
        }
        
        memset(dp, 0xff, sizeof dp);
        return go(n, 0)/6;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 0LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 256LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 8; long long Arg1 = 3458560LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 20; long long Arg1 = 11193888000LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheHexagonsDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

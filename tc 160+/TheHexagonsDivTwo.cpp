#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int p10[10];
int cur[7];
vector< vector<int> > adj;
int N, K;
long long F[10];
long long sol;
long long cnt() {
    long long ret = 1;
    for (int i=0; i<K; ++i) {
        int t = 0;
        for (int j=0; j<7; ++j) {
            t += (cur[j] == i);
        }
        int u = max(0, (N+i)/K);
        if (t > u) {
            return 0;
        }
        long long f = 1;
        for (int j=0; j<t; ++j) {
            f *= u - j;
        }
        ret *= f;
    }
    return ret;
}
void go(int p) {
    if (p == 7) {
        sol += cnt();
    } else {
        for (int i=0; i<K; ++i) {
            bool ok = true;
            for (int j=0; j<(int)adj[p].size(); ++j) {
                if (adj[p][j]<p && cur[adj[p][j]]==i) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cur[p] = i;
                go(p+1);
            }
        }
    }
}
class TheHexagonsDivTwo {
	public:
	long long count(int n, int k) {
        N = n;
        K = k;
        F[0] = 1;
        for (int i=1; i<10; ++i) {
            F[i] = F[i-1] * i;
        }
		p10[0] = 1;
        for (int i=1; i<10; ++i) {
            p10[i] = p10[i-1] * 10;
        }

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

        sol = 0;
        go(0);
        return sol/6;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 3; long long Arg2 = 0LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 3; long long Arg2 = 24LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 4; long long Arg2 = 256LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 5; long long Arg2 = 4692480LL; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheHexagonsDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

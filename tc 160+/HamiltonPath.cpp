#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int n;
int C[50];
int sz[50];
vector<string> A;
int go(int x, int c, int p, int cnt1) {
    C[x] = c;
    int ret = 1;
    int deg = 0;
    for (int i=0; i<n; ++i) {
        if (A[x][i] == 'Y') {
            ++deg;
        }
    }
    if (deg>2 || deg==1 && cnt1==2) {
        return -1;
    }
    if (deg == 1) {
        ++cnt1;
    }
    
    for (int i=0; i<n; ++i) {
        if (i!=p && A[x][i]=='Y') {
            if (C[i] == -1) {
                int t = go(i, c, x, cnt1);
                if (t == -1) {
                    return -1;
                }
                ret += t;
            } else {
                return -1;
            }
        }
    }
    return ret;
}
class HamiltonPath {
	public:
	int countPaths(vector <string> roads) {
		n = roads.size();
        A = roads;
        memset(C, 0xff, sizeof C);
        
        int cnt = 0;
        for (int i=0; i<n; ++i) {
            if (C[i] == -1) {
                sz[cnt] = go(i, cnt, -1, 0);
                if (sz[cnt] == -1) {
                    return 0;
                }
                ++cnt;
            }
        }
        
        long long sol = 1;
        for (int i=0; i<cnt; ++i) {
            sol = (sol * (sz[i]>1 ? 2 : 1) * (i+1)) % 1000000007;
        }
        return int(sol);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, countPaths(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countPaths(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYY",
 "YNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countPaths(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(3, Arg1, countPaths(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HamiltonPath ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

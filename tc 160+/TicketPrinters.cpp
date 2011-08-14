#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> S, W;
int n;
int D[16][16];
int INF;
int dp[2][16][2][1<<16];
int my_abs(int x) {
    return x<0 ? -x : x;
}
int go(int len, int l, bool at_left, int need) {
    int &ret = dp[len][l][at_left][need];
    if (ret != -1) {
        return ret;
    }
    
    int r = l + len;
    ret = 0;
    if (need != 0) {
        int my_pos = at_left ? l : r;
        ret = INF;
        for (int i=0; i<n; ++i) {
            if (need & (1<<i)) {
                if (l > 0) {
                    ret = min(ret, D[my_pos][l-1] + max(my_abs(S[l-1]-W[i])+1, go(len+1, l-1, 1, need ^ (1<<i))));
                }
                if (r < n-1) {
                    ret = min(ret, D[my_pos][r+1] + max(my_abs(S[r+1]-W[i])+1, go(len+1, l, 0, need ^ (1<<i))));
                }
            }
        }
    }
    
    return ret;
}
int bc[1<<16];
int lg[1<<16];
class TicketPrinters {
	public:
	int minTime(int currentPrinter, vector <int> printerDistance, vector <int> startingValues, vector <int> wantedValues) {
		S = startingValues;
        W = wantedValues;
        n = S.size();
        for (int i=0; i<n-1; ++i) {
            D[i][i+1] = printerDistance[i];
        }
        for (int len=2; len<n; ++len) {
            for (int i=0; i+len<n; ++i) {
                D[i][i+len] = D[i][i+len-1] + D[i+len-1][i+len];
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                D[j][i] = D[i][j];
            }
        }
        
        bc[0] = 0;
        for (int i=1; i<(1<<n); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        
        vector< vector<int> > bc_mask(17, vector<int>());
        for (int i=0; i<(1<<n); ++i) {
            bc_mask[bc[i]].push_back(i);
        }
        
        for (int i=0; i<n; ++i) {
            lg[1<<i] = i;
        }
        
        memset(&INF, 0x3f, sizeof INF);
        memset(dp, 0x3f, sizeof dp);
        dp[(n-1)&1][0][0][0] = 0;
        dp[(n-1)&1][0][1][0] = 0;
        for (int len=n-2; len>=0; --len) {
            for (int l=0; l+len<n; ++l) {
                int r = l + len;
                for (int at_left=0; at_left<2; ++at_left) {
                    for (int ind=0; ind<(int)bc_mask[n-len-1].size(); ++ind) {
                        int need = bc_mask[n-len-1][ind];
                        int &ret = dp[len&1][l][at_left][need];
                        int my_pos = at_left ? l : r;
                        ret = INF;
                        int tmp = need;
                        while (tmp > 0) {
                            int last = tmp & (-tmp);
                            int i = lg[last];
                            tmp -= last;
                            if (l > 0) {
                                ret = min(ret, D[my_pos][l-1] + max(my_abs(S[l-1]-W[i])+1, dp[(len+1)&1][l-1][1][need ^ (1<<i)]));
                            }
                            if (r < n-1) {
                                ret = min(ret, D[my_pos][r+1] + max(my_abs(S[r+1]-W[i])+1, dp[(len+1)&1][l][0][need ^ (1<<i)]));
                            }
                        }
                    }
                }
            }
        }
        int sol = INF;
        for (int i=0; i<n; ++i) {
            sol = min(sol, max(my_abs(S[currentPrinter]-W[i])+1, dp[0][currentPrinter][0][((1<<n)-1)^(1<<i)]));
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arr1[] = {100, 20, 50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {66, 78, 99, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {99, 5, 78, 66}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 171; verify_case(0, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {50, 50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100, 200, 300}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {101, 201, 302}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 152; verify_case(1, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {13, 26, 39, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {123, 12, 32, 67, 1015}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3, 4, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1063; verify_case(2, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TicketPrinters ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

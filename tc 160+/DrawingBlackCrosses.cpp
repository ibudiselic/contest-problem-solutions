#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int bc[1<<20];
long long F[21];
const long long mod = 1000000007;
int R[8], C[8];
int cnt;
int M, N;
int RHB[20];
int has_black_row[8];
int need_cols[20];
long long calc(int r, int c, int b_mask) {
    int b_rows[20] = {0};
    int c_need[20];
    memcpy(c_need, need_cols, sizeof c_need);
    int rr = r;
    int cc = c;
    for (int i=0; i<cnt; ++i) {
        if (b_mask & (1<<i)) {
            if (b_rows[R[i]]) {
                return 0;
            }
            b_rows[R[i]] = 1;
            --rr;
            if (c_need[C[i]] == -1) {
                return 0;
            }
            c_need[C[i]] = -1;
            --cc;
        }
    }
    int ccc = count(c_need, c_need+20, 1);
    if (cc<ccc || rr<ccc) {
        return 0;
    }
    long long ret = 1;
    for (int i=0; i<ccc; ++i) {
        ret = ret * (rr - i) % mod;
    }
    for (int i=0; i<rr-ccc; ++i) {
        ret = ret * (cc-ccc-i) % mod;
    }
    return ret*F[r]%mod;
}
class DrawingBlackCrosses {
	public:
	int count(vector <string> field) {
		bc[0] = 0;
        for (int i=1; i<(1<<20); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        F[0] = 1;
        for (int i=1; i<21; ++i) {
            F[i] = F[i-1] * i % mod;
        }
        
        M = field.size();
        N = field[0].size();
        if (M > N) {
            vector<string> t(N, string(M, ' '));
            for (int i=0; i<M; ++i) {
                for (int j=0; j<N; ++j) {
                    t[j][i] = field[i][j];
                }
            }
            swap(M, N);
            field.swap(t);
        }
        
        cnt = 0;
        memset(RHB, 0, sizeof RHB);
        int has_black = 0;
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (field[i][j] == 'B') {
                    R[cnt] = i;
                    C[cnt++] = j;
                    if (!RHB[i]) {
                        RHB[i] = 1;
                        has_black_row[has_black++] = i;
                    }
                }
            }
        }

        long long sol = 0;
        for (int miss_row=0; miss_row<(1<<has_black); ++miss_row) {
            memset(need_cols, 0, sizeof need_cols);
            int dead_black = 0;
            for (int i=0; i<has_black; ++i) {
                if (miss_row & (1<<i)) {
                    const int r = has_black_row[i];
                    for (int j=0; j<N; ++j) {
                        if (field[r][j] == '.') {
                            need_cols[j] = 1;
                        }
                    }
                    for (int j=0; j<cnt; ++j) {
                        if (R[j] == r) {
                            dead_black |= (1<<j);
                        }
                    }
                }
            }
            
            int alive_black = (1<<cnt)-1 - dead_black;
            long long add = calc(M-bc[miss_row], N, 0);
            for (int u=alive_black; u>0; u=(u-1)&alive_black) {
                add += ((bc[u]&1) ? -1 : 1) * calc(M-bc[miss_row], N, u);
                if (add < 0) {
                    add += mod;
                } else if (add >= mod) {
                    add -= mod;
                }
            }
            sol += add;
            if (sol >= mod) {
                sol -= mod;
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
	void test_case_0() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBB",
 "BBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", 
 "BB."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "....................", 
 "...................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 563200757; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"B..B",
 "B.B.",
 "...B",
 "BB.B",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 324; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DrawingBlackCrosses ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

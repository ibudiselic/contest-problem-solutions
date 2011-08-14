#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
long long B[50][50];
int L[50], R[50];
long long T[50], val[50];

class RowGame {
	public:
	long long score(vector <int> board, int k) {
		const int n = board.size();
        for (int i=0; i<n; ++i) {
            B[i][i] = board[i];
        }
        for (int l=1; l<n; ++l) {
            for (int i=0; i<n-l; ++i) {
                B[i][i+l] = B[i][i+l-1] + board[i+l];
            }
        }
        
        for (int i=0; i<n; ++i) {
            R[i] = max_element(B[i]+i, B[i]+n) - B[i];
            L[i] = i;
            for (int j=0; j<i; ++j) {
                if (B[j][i] > B[L[i]][i]) {
                    L[i] = j;
                }
            }
        }
        
        if (B[0][R[0]] < 0) {
            return 0;
        }
        memset(T, 0x3f, sizeof T);
        memset(val, 0x3f, sizeof val);
        T[0] = 0;
        val[0] = 0;
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                long long cycle_cost = 2*B[j][R[j]];
                if (T[j] < k-1) {
                    for (int midstep=i; midstep<n; ++midstep) {
                        long long nt = T[j];
                        long long nv = val[j];
                        long long step_cost = B[j][midstep];
                        if (B[i][midstep] < 0) {
                            long long total_step_cost = step_cost + B[i][midstep];
                            if (nv + total_step_cost < 0) {
                                if (cycle_cost <= 0) {
                                    continue;
                                }
                                long long cycle_cnt = (-nv-total_step_cost + cycle_cost - 1)/cycle_cost;
                                if (nt + cycle_cnt*2 + 2 > k) {
                                    continue;
                                }
                                nt += cycle_cnt*2;
                                nv += cycle_cnt*cycle_cost;
                            }
                        } else if (nv + step_cost < 0) {
                            if (cycle_cost <= 0) {
                                continue;
                            }
                            long long cycle_cnt = (-nv - step_cost + cycle_cost - 1) / cycle_cost;
                            if (nt + cycle_cnt*2 + 2 > k) {
                                continue;
                            }
                            nt += cycle_cnt*2;
                            nv += cycle_cnt*cycle_cost;
                        } 
                        nt += 2;
                        nv += step_cost + B[i][midstep];
                        if (nt<T[i] || nt==T[i] && nv>val[i]) {
                            T[i] = nt;
                            val[i] = nv;
                        }
                    }
                }
            }
        }
        
        long long sol = 0;
        for (int i=0; i<n; ++i) {
            if (T[i] <= k) {
                sol = max(sol, val[i]);
                if ((k-T[i]) & 1) {
                    sol = max(sol, val[i] + (k-T[i])*B[i][R[i]]);
                } else {
                    sol = max(sol, val[i] + (k-T[i]-1)*B[i][R[i]] + B[L[R[i]]][R[i]]);
                }
            }
        }
        
        return sol;		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,-2,4,3,-10} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 21LL; verify_case(0, Arg2, score(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-6,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; long long Arg2 = 0LL; verify_case(1, Arg2, score(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,-6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; long long Arg2 = 50LL; verify_case(2, Arg2, score(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,-100,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 30LL; verify_case(3, Arg2, score(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {10,-100,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 90LL; verify_case(4, Arg2, score(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-100,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 400000000; long long Arg2 = 41999999900LL; verify_case(5, Arg2, score(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RowGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
int A[25], B[25];
int dp[26][2];
const int INF = 987654321;
int largeJump;
void set_bounds(int i, int parity, int &lb, int &ub) {
    const int j = parity;
    if (i == 0) {
        lb = -(largeJump + 2 + (j==0));
        ub = A[0] - 1;
        if ((ub&1) != j) {
            --ub;
        }
    } else if (i == N) {
        lb = B[N-1] + 1;
        if ((lb&1) != j) {
            ++lb;
        }
        ub = 2000000008 + (j==1);
    } else {
        lb = B[i-1] + 1;
        if ((lb&1) != j) {
            ++lb;
        }
        ub = A[i] - 1;
        if ((ub&1) != j) {
            --ub;
        }
    }
}
bool can(int lb, int ub, int k, int j) {
    int lb2, ub2;
    set_bounds(k, 1-j, lb2, ub2);
    if (lb2 < lb) {
        swap(lb, lb2);
        swap(ub, ub2);
    }
    if (lb2>ub2 || lb+largeJump>ub2 || ub+largeJump<lb2) {
        return false;
    }
    int t = lb + largeJump;
    if (lb2<=t && t<=ub2) {
        return true;
    } 
    t = ub + largeJump;
    if (lb2<=t && t<=ub2) {
        return true;
    }
    t = lb2 - largeJump;
    if (lb<=t && t<=ub) {
        return true;
    }
    t = ub2 - largeJump;
    if (lb<=t && t<=ub) {
        return true;
    }
    
    return false;
}
class RabbitJumping {
	public:
	int getMinimum(vector <int> holes, int largeJump) {
		if (largeJump % 2 == 0) {
            return -1;
        }
        ::largeJump = largeJump;
        N = holes.size()/2;
        for (int i=0; i<N; ++i) {
            A[i] = holes[2*i];
            B[i] = holes[2*i + 1];
        }
        
        for (int i=0; i<26; ++i) {
            for (int j=0; j<2; ++j) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int iter=0; iter<N; ++iter) {
            for (int i=0; i<N; ++i) {
                for (int j=0; j<2; ++j) {
                    if (dp[i][j] < INF) {
                        int lb, ub, lb2, ub2;
                        set_bounds(i, j, lb, ub);
                        set_bounds(i, 1-j, lb2, ub2);
                        if (lb+largeJump<=ub2 || ub-largeJump>=lb2) {
                            dp[i][1-j] = min(dp[i][1-j], dp[i][j] + 1);
                        }
                    }
                }
                for (int j=0; j<2; ++j) {
                    if (dp[i][j] < INF) {
                        int lb, ub;
                        set_bounds(i, j, lb, ub);
                        if (lb > ub) {
                            continue;
                        }
                        for (int k=1; k<=N; ++k) {
                            if (i!=k && can(lb, ub, k, j)) {
                                dp[k][1-j] = min(dp[k][1-j], dp[i][j] + 1);
                            }
                        }
                    }
                }
            }
        }
        dp[N][1] = min(dp[N][1], dp[N][0] + 1);
        return dp[N][1]==INF ? -1 : dp[N][1];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = -1; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 2, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 2, 17, 21, 36, 40, 55, 59, 74 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arg2 = 5; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 187640193, 187640493, 187640738, 187640845, 564588641, 564588679, 
  564588696, 564588907, 605671187, 605671278, 605671288, 605671386, 
  755723729, 755723774, 755723880, 755723920, 795077469, 795077625, 
  795077851, 795078039, 945654724, 945654815, 945655107, 945655323 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 475; int Arg2 = 9; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RabbitJumping ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

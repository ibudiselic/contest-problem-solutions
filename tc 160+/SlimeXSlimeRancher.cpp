#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;

vector<long long> parse(const vector<string> &A) {
    vector<long long> ret;
    string s = accumulate(A.begin(), A.end(), string());
    istringstream is(s);
    copy(istream_iterator<long long>(is), istream_iterator<long long>(), back_inserter(ret));
    return ret;
}
vector<long long> uniq(vector<long long> A) {
    sort(A.begin(), A.end());
    A.resize(unique(A.begin(), A.end()) - A.begin());
    return A;
}
void recode(vector<long long> &A, const vector<long long> &AA) {
    for (int i=0; i<(int)A.size(); ++i) {
        A[i] = lower_bound(AA.begin(), AA.end(), A[i]) - AA.begin();
    }
}

const long long inf = 123456789123456LL;
int cnt_points[150][150][150];
long long dp[2][150][150];
long long BC_count[2][150][150], BC_sum[2][150][150];
long long AC_count[2][150][150], AC_sum[2][150][150];
long long AB_count[2][150][150], AB_sum[2][150][150];

inline void update(long long &a, long long b) {
    a = min(a, b);
}
void updateBC(long long X[2][150][150], int a, int b, int c, long long corner_val) {
    X[a&1][b][c] = corner_val;
    if (b && c) {
        X[a&1][b][c] += X[a&1][b-1][c] + X[a&1][b][c-1] - X[a&1][b-1][c-1];
    } else if (b) {
        X[a&1][b][c] += X[a&1][b-1][c];
    } else if (c) {
        X[a&1][b][c] += X[a&1][b][c-1];
    }
}
void updateAC(long long X[2][150][150], int a, int b, int c, long long corner_val) {
    X[a&1][b][c] = corner_val;
    if (a && c) {
        X[a&1][b][c] += X[(a-1)&1][b][c] + X[a&1][b][c-1] - X[(a-1)&1][b][c-1];
    } else if (a) {
        X[a&1][b][c] += X[(a-1)&1][b][c];
    } else if (c) {
        X[a&1][b][c] += X[a&1][b][c-1];
    }
}
void updateAB(long long X[2][150][150], int a, int b, int c, long long corner_val) {
    X[a&1][b][c] = corner_val;
    if (a && b) {
        X[a&1][b][c] += X[(a-1)&1][b][c] + X[a&1][b-1][c] - X[(a-1)&1][b-1][c];
    } else if (a) {
        X[a&1][b][c] += X[(a-1)&1][b][c];
    } else if (b) {
        X[a&1][b][c] += X[a&1][b-1][c];
    }
}
class SlimeXSlimeRancher {
	public:
	long long train(vector <string> first_slime, vector <string> second_slime, vector <string> third_slime) {
		vector<long long> A = parse(first_slime);
		vector<long long> B = parse(second_slime);
		vector<long long> C = parse(third_slime);
        vector<long long> AA = uniq(A);
        vector<long long> BB = uniq(B);
        vector<long long> CC = uniq(C);
        recode(A, AA);
        recode(B, BB);
        recode(C, CC);
        memset(cnt_points, 0, sizeof cnt_points);
        for (int i=0; i<(int)A.size(); ++i) {
            ++cnt_points[A[i]][B[i]][C[i]];
        }

        int na = AA.size();
        int nb = BB.size();
        int nc = CC.size();
        for (int a=0; a<na; ++a) {
            for (int b=0; b<nb; ++b) {
                for (int c=0; c<nc; ++c) {
                    if (a+b+c == 0) {
                        continue;
                    }
                    updateBC(BC_count, a, b, c, cnt_points[a][b][c]);
                    updateBC(BC_sum, a, b, c, cnt_points[a][b][c]*(BB[b]+CC[c]));
                    updateAC(AC_count, a, b, c, cnt_points[a][b][c]);
                    updateAC(AC_sum, a, b, c, cnt_points[a][b][c]*(AA[a]+CC[c]));
                    updateAB(AB_count, a, b, c, cnt_points[a][b][c]);
                    updateAB(AB_sum, a, b, c, cnt_points[a][b][c]*(AA[a]+BB[b]));
                    
                    dp[a&1][b][c] = inf;
                    if (a) {
                        update(dp[a&1][b][c], dp[(a-1)&1][b][c] + BC_count[a&1][b][c]*(BB[b]+CC[c]) - BC_sum[a&1][b][c]);
                    }
                    if (b) {
                        update(dp[a&1][b][c], dp[a&1][b-1][c] + AC_count[a&1][b][c]*(AA[a]+CC[c]) - AC_sum[a&1][b][c]);
                    }
                    if (c) {
                        update(dp[a&1][b][c], dp[a&1][b][c-1] + AB_count[a&1][b][c]*(AA[a]+BB[b]) - AB_sum[a&1][b][c]);
                    }
                }
            }
        }
        
        return dp[(na-1)&1][nb-1][nc-1];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 6 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 3 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"5 4 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(0, Arg3, train(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"3 2 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"6 5 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"9 8 7"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(1, Arg3, train(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 2", "3 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"12 3 ", "4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 ", "34"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 36LL; verify_case(2, Arg3, train(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1 1 1 1000000000 1000000000 1000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1000000000 1000000000 1000000000 1 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 1 1 2 2 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2999999997LL; verify_case(3, Arg3, train(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SlimeXSlimeRancher ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

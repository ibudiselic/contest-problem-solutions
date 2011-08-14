#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
const int dj[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int KD[8][8][8][8];
int ti[20], tj[20];
int tn;
vector<string> B1, B2;
int dp[1<<20];
int go(int i, int j, int mask) {
    if (i == 8) {
        return mask==0 ? 0 : 987654321;
    }
    if (j == 8) {
        return go(i+1, 0, mask);
    }
    if (B1[i][j] == '.') {
        return go(i, j+1, mask);
    }

    int &ret = dp[mask];
    if (ret != -1) {
        return ret;
    }
    if (B1[i][j] == 'N') {
        ret = 987654321;
        for (int k=0; k<tn; ++k) {
            if (mask & (1<<k)) {
                int r = ti[k];
                int c = tj[k];
                
                if (B2[r][c] == 'P') {
                    continue;
                }
                assert(B2[r][c] == 'N');
                ret = min(ret, KD[i][j][r][c] + go(i, j+1, mask^(1<<k)));
            }
        }
        return ret;
    } else {
        ret = 987654321;
        for (int k=0; k<tn; ++k) {
            if (mask & (1<<k)) {
                int r = ti[k];
                int c = tj[k];
                
                if (B2[r][c] == 'P') {
                    if (c==j && r<=i) {
                        ret = min(ret, i-r + go(i, j+1, mask^(1<<k)));
                    }
                } else {
                    assert(B2[r][c] == 'N');
                    ret = min(ret, i + KD[0][j][r][c] + go(i, j+1, mask^(1<<k)));
                }
            }
        }
        return ret;
    }
}
class SolitaireChess {
	public:
	int transform(vector <string> board1, vector <string> board2) {
        B1 = board1;
        B2 = board2;
		tn = 0;
        for (int i=0; i<8; ++i) {
            for (int j=0; j<8; ++j) {
                if (board2[i][j] != '.') {
                    ti[tn] = i;
                    tj[tn] = j;
                    ++tn;
                }
            }
        }
        
        memset(KD, 0x3f, sizeof KD);
        for (int i=0; i<8; ++i) {
            for (int j=0; j<8; ++j) {
                KD[i][j][i][j] = 0;
                for (int d=0; d<8; ++d) {
                    const int r = i + di[d];
                    const int c = j + dj[d];
                    if (r<0 || c<0 || r>=8 || c>=8) {
                        continue;
                    }
                    KD[i][j][r][c] = 1;
                }
            }
        }
        
        for (int ki=0; ki<8; ++ki) {
            for (int kj=0; kj<8; ++kj) {
                for (int ii=0; ii<8; ++ii) {
                    for (int ij=0; ij<8; ++ij) {
                        for (int ji=0; ji<8; ++ji) {
                            for (int jj=0; jj<8; ++jj) {
                                KD[ii][ij][ji][jj] = min(KD[ii][ij][ji][jj],
                                    KD[ii][ij][ki][kj] + KD[ki][kj][ji][jj]);
                            }
                        }
                    }
                }
            }
        }
        
        memset(dp, 0xff, sizeof dp);
        int t = go(0, 0, (1<<tn)-1);
        return t==987654321 ? -1 : t;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...N....",
 "........",
 "........",
 "........",
 "........",
 "........",
 "...P....",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"...N....",
 ".....N..",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"........",
 "........",
 "...P....",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "...P...."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 ".N...P.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 ".....P..",
 ".......N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"N.......",
 "........",
 "N.......",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"........",
 "..N.....",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, transform(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"..N.N...",
 "PPP....N",
 "..N..N..",
 "N...N...",
 "...NNNNN",
 "N.......",
 "...NN...",
 "..N...N."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..N....N",
 "P....N..",
 "..N..N..",
 "N..NNN.N",
 "N.....N.",
 "N.N.....",
 "...NNN..",
 ".....N.N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; verify_case(4, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SolitaireChess ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

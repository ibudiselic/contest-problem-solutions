#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> next(const vector<string> &v) {
    int n = v.size();
    vector<string> ret(3*n, string(3*n, '0'));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    ret[3*i+k][3*j+l] = v[i][j];
                }
            }
            for (int k=0; k<3; ++k) {
                ret[3*i+k][3*j+1] = '.';
                ret[3*i+1][3*j+k] = '.';
            }
        }
    }
    
    return ret;
}
int get_cnt(const vector<string> &A, const vector<string> &P, int i1, int j1, int i2, int j2) {
    const int n = A.size();
    const int a = P.size();
    const int b = P[0].size();
    int ret = 0;
    for (int i=i1; i<=i2-a; ++i) {
        for (int j=j1; j<=j2-b; ++j) {
            for (int k=0; k<a; ++k) {
                for (int l=0; l<b; ++l) {
                    if (A[i+k][j+l] != P[k][l]) {
                        goto FAIL;
                    }
                }
            }
            ++ret;
FAIL: ;
        }
    }
    
    return ret;
}
int get_cnt(const vector<string> &A, const vector<string> &P) {
    const int n = A.size();
    const int a = P.size();
    const int b = P[0].size();
    int ret = 0;
    for (int i=0; i<=n-a; ++i) {
        for (int j=0; j<=n-b; ++j) {
            for (int k=0; k<a; ++k) {
                for (int l=0; l<b; ++l) {
                    if (A[i+k][j+l] != P[k][l]) {
                        goto FAIL;
                    }
                }
            }
            ++ret;
FAIL: ;
        }
    }
    
    return ret;
}

int get_cross(int n, const vector<string> &P) {
    const int a = P.size();
    const int b = P[0].size();
    
    return (n-a+1)*(3*n-b+1) + 2*n*(n-b+1);
}
int get_small_big_cross_h(int n, const vector<string> &P) {
    const int a = P.size();
    const int b = P[0].size();
    
    return (n-a+1)*(b-1);
}
int get_small_big_cross_v(int n, const vector<string> &P) {
    const int a = P.size();
    const int b = P[0].size();
    
    return (n-b+1)*(a-1);
}

class CantorDust {
	public:
	int occurrencesNumber(vector <string> pattern, int time) {
		vector<string> P;
        P.push_back("X");
        const int x = max(pattern.size(), pattern[0].size());
        while (P.size()<3*x && time>0) {
            P = next(P);
            --time;
        }
        
        int unit = get_cnt(P, pattern);
        if (time == 0) {
            return unit;
        }

        bool not_empty = false;
        for (int i=0; i<(int)pattern.size(); ++i) {
            for (int j=0; j<(int)pattern[i].size(); ++j) {
                if (pattern[i][j] == 'X') {
                    not_empty = true;
                    goto DONE;
                }
            }
        }
DONE:;

        if (not_empty) {
            P = next(P);
            const int next_unit = get_cnt(P, pattern);
            const int N = P.size()/3;
            const int down = get_cnt(P, pattern, 0, 0, 2*N, N) - unit;
            const int up = get_cnt(P, pattern, N, 0, 3*N, N) - unit;
            const int left = get_cnt(P, pattern, 0, N, N, 3*N) - unit;
            const int right = get_cnt(P, pattern, 0, 0, N, 2*N) - unit;
            const int urdl = down + up + left + right;
            const int corners = next_unit - 4*unit - 2*urdl;
            
            assert(4*unit + 2*urdl + corners == next_unit);
            int umul = 4;
            int urdlmul = 2;
            int urdladd = 4;
            int cornermul = 1;
            int corneradd = 5;
            while (--time) {
                umul *= 4;
                urdlmul = urdlmul*4 + urdladd;
                urdladd *= 2;
                cornermul = cornermul*4 + corneradd;
                corneradd = corneradd*2 + 3;
            }
            
            return umul*unit + urdlmul*urdl + cornermul*corners; 
        } else {
            int N = P.size();
            int horiz = 0;
            int vert = 0;
            int nn = 1;
            while (nn < N) {
                horiz = 2*horiz + max(0, get_small_big_cross_h(nn, pattern));
                vert = 2*vert + max(0, get_small_big_cross_v(nn, pattern));
                nn *= 3;
            }
           
            int cross = get_cross(N, pattern);
            unit = 4*unit + cross + 4*(horiz + vert);
            horiz = 2*horiz + get_small_big_cross_h(N, pattern);
            vert = 2*vert + get_small_big_cross_v(N, pattern);
            while (--time) {
                N *= 3;
                unit = 4*unit + get_cross(N, pattern) + 4*(horiz + vert);
                horiz = 2*horiz + get_small_big_cross_h(N, pattern);
                vert = 2*vert + get_small_big_cross_v(N, pattern);
            }
            
            return unit;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".X",".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, occurrencesNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, occurrencesNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 65; verify_case(2, Arg2, occurrencesNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"X...X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(3, Arg2, occurrencesNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 262144; verify_case(4, Arg2, occurrencesNumber(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CantorDust ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

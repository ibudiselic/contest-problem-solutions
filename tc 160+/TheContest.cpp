#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
bool R[50][50], C[50][50];
int r_cnt[50];
int rounds;
int G[50][50];
bool col_unused[50];
int P[100];
bool augment(int r, int c, int u) {
    memset(P, 0xff, sizeof P);
    P[u] = -2;
    queue<int> Q;
    Q.push(u);
    int last = -1;
    while (!Q.empty() && last==-1) {
        int v = Q.front();
        Q.pop();
        if (v < 50) { // round
            for (int i=c+1; i<M; ++i) {
                if (G[v][i]==1 && P[i+50]==-1) {
                    P[i+50] = v;
                    Q.push(i+50);
                    if (col_unused[i]) {
                        last = i;
                        break;
                    }
                }
            }
        } else { // column
            for (int i=0; i<rounds; ++i) {
                if (G[i][v-50]==-1 && P[i]==-1) {
                    P[i] = v;
                    Q.push(i);
                }
            }
        }
    }
    if (last == -1) {
        return false;
    } else {
        int v = last + 50; // it's a column, but stored in the range 0-49
        while (P[v] != -2) {
            if (v < 50) {
                G[v][P[v]-50] *= -1;
            } else {
                G[P[v]][v-50] *= -1;
            }
            v = P[v];
        }
        col_unused[last] = false;
        return true;
    }
}
bool ok(int r, int c) {
    int crit = N - r;
    memset(G, 0, sizeof G);
    memset(col_unused, 0, sizeof col_unused);
    for (int i=c+1; i<M; ++i) {
        col_unused[i] = true;
    }
    
    for (int i=0; i<rounds; ++i) {
        if (!R[i][r]) {
            for (int j=c+1; j<M; ++j) {
                if (!C[i][j]) {
                    G[i][j] = +1;
                }
            }
        }
    }
    
    int matching = 0;
    for (int i=0; i<rounds; ++i) {
        if (!R[i][r]) {
            if (r_cnt[i] == crit) {
                if (!augment(r, c, i)) {
                    return false;
                } else {
                    ++matching;
                }
            }
        }
    }
    
    for (int i=0; i<rounds; ++i) {
        if (!R[i][r]) {
            if (r_cnt[i] < crit) {
                if (augment(r, c, i)) {
                    ++matching;
                }
            }
        }
    }
    
    return matching == M-c-1;
}

class TheContest {
	public:
	vector <string> getSchedule(int n, int m) {
		N = n;
        M = m;
        memset(R, 0, sizeof R);
        memset(C, 0, sizeof C);
        rounds = max(m, n);
        
        vector<string> sol(n, string(m, ' '));
        for (int i=0; i<rounds; ++i) {
            r_cnt[i] = min(m, n);
        }
        
        string lex = "123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmno";
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                for (int k=0; k<rounds; ++k) {
                    if (!R[k][i] && !C[k][j]) {
                        R[k][i] = C[k][j] = true;
                        --r_cnt[k];
                        sol[i][j] = lex[k];
                        if (ok(i, j)) {
                            break;
                        }
                        ++r_cnt[k];
                        R[k][i] = C[k][j] = false;
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"123", "231", "312" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getSchedule(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"1234", "2143", "3412", "4321" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getSchedule(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 6; string Arr2[] = {"123456", "214365", "345612", "436521" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getSchedule(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; string Arr2[] = {"123", "214", "345", "451", "532" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getSchedule(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 28; int Arg1 = 40; string Arr2[] = {"123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcde", "21436587A9CBEDGFIHKJMLONQPSRUTWVYXaZcbed", "34127856BC9AFGDEJKHINOLMRSPQVWTUZaXYdebc", "43218765CBA9GFEDKJIHONMLSRQPWVUTaZYXedcb", "56781234DEFG9ABCLMNOHIJKTUVWPQRSbcdeXYZa", "65872143EDGFA9CBMLONIHKJUTWVQPSRcbedYXaZ", "78563412FGDEBC9ANOLMJKHIVWTURSPQdebcZaXY", "87654321GFEDCBA9ONMLKJIHWVUTSRQPedcbaZYX", "9ABCDEFG12345678PQRSTUVWXYZabcdeHIJKLMNO", "A9CBEDGF21436587QPSRUTWVYXaZcbedIHKJMLON", "BC9AFGDE34127856RSPQVWTUZaXYdebcJKHINOLM", "CBA9GFED43218765SRQPWVUTaZYXedcbKJIHONML", "DEFG9ABC56781234TUVWPQRSbcdeXYZaLMNOHIJK", "EDGFA9CB65872143UTWVQPSRcbedYXaZMLONIHKJ", "FGDEBC9A78563412VWTURSPQdebcZaXYNOLMJKHI", "GFEDCBA987654321WVUTSRQPedcbaZYXONMLKJIH", "HIJKLMNOPQRSTUVWXYZabcde123456789ABCDEFG", "IHKJMLONQPSRUTWVYXaZcbed21436587A9CBEDGF", "JKHINOLMRSPQVWTUZaXYdebc34127856BC9AFGDE", "KJIHONMLSRQPWVUTaZYXedcb43218765CBA9GFED", "LMNOHIJKTUVWPQRSbcdeXYZa56781234DEFG9ABC", "MLONIHKJUTWVQPSRcbedYXaZ65872143EDGFA9CB", "NOLMJKHIVWTURSPQdebcZaXY78563412FGDEBC9A", "ONMLKJIHWVUTSRQPedcbaZYX87654321GFEDCBA9", "PQRSTUVWXYZabcde9ABCDEFGHIJKLMNO12345678", "QPSRUTWVYXaZcbedA9CBEDGFIHKJMLON21436587", "RSPQVWTUZaXYdebcBC9AFGDEJKHINOLM34127856", "SRQPWVUTaZYXedcbCBA9GFEDKJIHONML43218765" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getSchedule(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheContest ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

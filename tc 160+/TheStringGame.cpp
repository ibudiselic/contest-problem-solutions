#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int pow3[17];
int N, M;
enum {
    X, L, O
};

int encode(const string &s) {
    int ret = 0;
    for (int i=0; i<(int)s.size(); ++i) {
        ret += (s[i]=='X' ? 0 : (s[i]=='L' ? 1 : 2)) * pow3[i];
    }
    
    return ret;
}
inline int ith(int code, int i) {
    return code%pow3[i+1]/pow3[i];
}
string to_str(int x) {
    ostringstream os;
    os << x;
    return os.str();
}

inline bool is_winstate(int state) {
    int s = 0;
    int a = -1;
    int b = -1;
    int c = -1;
    for (int i=0; i<N-2; ++i) {
        c = ith(state, i+2);
        b = ith(state, i+1);
        a = ith(state, i);
        if (a==L && b==X && c==L || a==X && b==O && c==L || a==L && b==O && c==X) {
            return true;
        }
    }
    
    return false;
}

char dp[43046721];
int inf = 64;
vector<int> ind;
char go(int state) {
    char &ret = dp[state];
    if (ret != -1) {
        return ret;
    }
    if (is_winstate(state)) {
        return (ret = 1);
    }
    
    bool can_draw = false;
    int best_win = inf;
    int best_loss = -inf;
    bool can_move = false;
    for (int i=0; i<M; ++i) {
        if (ith(state, ind[i]) == X) {
            can_move = true;
            int ns = state;
            for (int rep=0; rep<2; ++rep) {
                ns += pow3[ind[i]];
                int t = go(ns);
                if (t == -2) {
                    can_draw = true;
                } else if (t & 1) {
                    best_loss = max(best_loss, t);
                } else {
                    best_win = min(best_win, t);
                }
            }
        }
    }
    
    if (!can_move) {
        return (ret = -2);
    }
    if (best_win < inf) {
        return (ret = best_win + 1);
    } else if (can_draw) {
        return (ret = -2);
    } else {
        return (ret = best_loss + 1);
    }
}

int precalc[] = { 13, 15, 15, 15, 15, 15, 13, 15, 13, 15, 13, 15, 13, 15, 13, 15, 13, 15, 13, 15, 13, 15, 13, 15, 13, 15, 15, 15, 15, 15, 13, 15 };
class TheStringGame {
	public:
	string winner(string s) {
		pow3[0] = 1;
        for (int i=1; i<17; ++i) {
            pow3[i] = pow3[i-1] * 3;
        }
        
        ind.clear();
        for (int i=0; i<(int)s.size(); ++i) {
            if (s[i] == 'X') {
                ind.push_back(i);
            }
        }
        M = ind.size();
        
        int sol = 0;
        if (M >= 15) {
            map<string, int> P;
            P[string(15, 'X')] = 15;
            P[string(16, 'X')] = 16;
            int T = 0;
            for (int i=0; i<16; ++i) {
                P[string(i, 'X') + string(1, 'L') + string(15-i, 'X')] = precalc[T++];
                P[string(i, 'X') + string(1, 'O') + string(15-i, 'X')] = precalc[T++];
            }
            sol = P[s];
        } else {
            N = s.size();
            memset(dp, 0xff, sizeof dp);
            
            sol = go(encode(s));
        }
        if (sol == -2) {
            return "Draw";
        } else {
            return (sol%2==0 ? "Brus " : "John ") + to_str(sol);
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "XXOXXXLXLX"; string Arg1 = "John 1"; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { string Arg0 = "LXXLXXL"; string Arg1 = "Brus 2"; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { string Arg0 = "LLOOLLOOLLOOLLOO"; string Arg1 = "Draw"; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { string Arg0 = "XXXXXXXXXXXXXXXX"; string Arg1 = "Brus 16"; verify_case(3, Arg1, winner(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheStringGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

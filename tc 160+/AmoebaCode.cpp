#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

/*char dp[50][823543];
int K;
string C;
int encode(const vector<int> &v) {
    int ret = 0;
    for (int i=0; i<K; ++i) {
        ret = 7*ret + min(v[i], 6);
    }
    return ret;
}
void inc(vector<int> &v) {
    for (int i=0; i<K; ++i) {
        ++v[i];
    }
}
void dec(vector<int> &v) {
    for (int i=0; i<K; ++i) {
        --v[i];
    }
}
char go(int p, vector<int> &state) {
    if (p == (int)C.size()) {
        return K;
    }

    char &ret = dp[p][encode(state)];
    if (ret != -1) {
        return ret;
    }
    
    inc(state);
    if (C[p] != '0') {
        int num = C[p] - '1';
        int old = state[num];
        state[num] = 0;
        ret = min(char(old-1), go(p+1, state));
        state[num] = old;
    } else {
        ret = 0;
        for (int d=0; d<K; ++d) {
            int old = state[d];
            state[d] = 0;
            ret = max(ret, min(char(old-1), go(p+1, state)));
            state[d] = old;
        }
    }
    dec(state);

    return ret;
}
int sol1(const string &code, int K_) {
    memset(dp, 0xff, sizeof dp);
    C = code;
    K = K_;

    vector<int> init(K, 6);
    return go(0, init) + 1;
}*/

bool can_do(const string &code, int K, int min_dist) {
    set<int> cur, next;
    cur.insert(0);
    int factor = 1;
    for (int i=0; i<min_dist-2; ++i) {
        factor *= K+1;
    }
    
    // kul nacin za dp... generiraju se stanja za sljedeci "red" (zato jer je stanje "nespretno" za bottom-up)
    for (int i=0; i<(int)code.size(); ++i) {
        for (set<int>::const_iterator it=cur.begin(); it!=cur.end(); ++it) {
            int state = *it;
            bool used[8] = {0};
            while (state > 0) {
                used[state%(K+1)] = true;
                state /= K+1;
            }
            if (code[i] != '0') {
                int num = code[i] - '0';
                if (!used[num]) {
                    next.insert(*it/(K+1) + factor*num);
                }
            } else {
                for (int d=1; d<=K; ++d) {
                    if (!used[d]) {
                        next.insert(*it/(K+1) + factor*d);
                    }
                }
            }
        }
        cur.swap(next);
        next.clear();
    }
    
    return !(cur.empty());
}
int sol2(const string &code, int K) {
    for (int sol=K; sol>1; --sol) {
        if (can_do(code, K, sol)) {
            return sol;
        }
    }
    return 1;
}
class AmoebaCode {
	public:
	int find(string code, int K_) {
		//return sol1(code, K_);
        return sol2(code, K_);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01"; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1001"; int Arg1 = 2; int Arg2 = 1; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1010"; int Arg1 = 2; int Arg2 = 2; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "01001"; int Arg1 = 3; int Arg2 = 3; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "10012031001"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AmoebaCode ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

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

const long long mod = 1234567891LL;
map< vector<int>, long long> M;
int cnt[3][3];
int to[52], from[52];
int id(char c) {
    if (c <= 'Z') {
        return 26 + c - 'A';
    } else {
        return c - 'a';
    }
}

long long go() {
    vector<int> t;
    t.reserve(9);
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            t.push_back(cnt[i][j]);
        }
    }
    if (M.count(t)) {
        return M[t];
    }
    long long &ret = M[t];
    int src_a = -1, src_b = -1;
    for (int i=0; i<2; ++i) {
        for (int j=0; j<3; ++j) {
            if (cnt[i][j] > 0) {
                src_a = i;
                src_b = j;
                break;
            }
        }
    }
    if (src_a == -1) {
        return (ret = 1);
    }
    
    --cnt[src_a][src_b];
    ++cnt[src_a+1][src_b];
    for (int i=0; i<3; ++i) {
        for (int j=0; j<2; ++j) {
            if (cnt[i][j] > 0) {
                long long choices = cnt[i][j];
                if (i==src_a+1 && j==src_b) {
                    if (--choices <= 0) {
                        continue;
                    }
                }
                if (j == 0) {
                    choices *= 2;
                }
                
                --cnt[i][j];
                ++cnt[i][j+1];
                ret = (ret + choices*go()) % mod;
                ++cnt[i][j];
                --cnt[i][j+1];
            }
        }
    }
    --cnt[src_a+1][src_b];
    ++cnt[src_a][src_b];
    return ret;
}
class TheEncryptionDivOne {
	public:
	int count(string msg, string encMsg) {
		M.clear();
        memset(cnt, 0, sizeof cnt);
        memset(to, 0xff, sizeof to);
        memset(from, 0xff, sizeof from);
        
        for (int i=0; i<(int)msg.size(); ++i) {
            int a = id(msg[i]);
            int b = id(encMsg[i]);
            if (a%26 == b%26) {
                return 0;
            }
            if (to[a]!=-1 && to[a]!=b) {
                return 0;
            }
            if (from[b]!=-1 && from[b]!=a) {
                return 0;
            }
            to[a] = b;
            from[b] = a;
        }
        
        for (int i=0; i<26; ++i) {
            const int x = (to[i]!=-1) + (to[i+26]!=-1);
            const int y = (from[i]!=-1) + (from[i+26]!=-1);
            ++cnt[x][y];
        }
        
        return int(go());
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX"; string Arg1 = "cdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX"; string Arg1 = "bcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY"; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arg1 = "TOPCODER"; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "thisisaveryhardproblem"; string Arg1 = "nobodywillsolveittoday"; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheEncryptionDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

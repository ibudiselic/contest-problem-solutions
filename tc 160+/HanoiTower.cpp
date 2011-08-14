#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

struct state {
    int a, b, c;
    state(int a_=0, int b_=0, int c_=0): a(a_), b(b_), c(c_) {}
    bool is_end() const;
};
state endstate;
bool operator<(const state &a, const state &b) {
    if (a.a != b.a) {
        return a.a < b.a;
    } else if (a.b != b.b) {
        return a.b < b.b;
    } else {
        return a.c < b.c;
    }
}
bool state::is_end() const {
    return !(*this<endstate) && !(endstate<*this);
}

class HanoiTower {
	public:
	int moves(string pegA, string pegB, string pegC) {
	    int a=0, b=0, c=0;
        int cnt[3] = {0};
        for (int i=0; i<(int)pegA.size(); ++i) {
            a = a*4 + (pegA[i]-'A'+1);
            ++cnt[pegA[i]-'A'];
        }
        for (int i=0; i<(int)pegB.size(); ++i) {
            b = b*4 + (pegB[i]-'A'+1);
            ++cnt[pegB[i]-'A'];
        }
        for (int i=0; i<(int)pegC.size(); ++i) {
            c = c*4 + (pegC[i]-'A'+1);
            ++cnt[pegC[i]-'A'];
        }
        
        endstate.a = 0;
        endstate.b = 0;
        endstate.c = 0;
        for (int i=0; i<cnt[0]; ++i) {
            endstate.a = endstate.a*4 + 1;
        }
        for (int i=0; i<cnt[1]; ++i) {
            endstate.b = endstate.b*4 + 2;
        }
        for (int i=0; i<cnt[2]; ++i) {
            endstate.c = endstate.c*4 + 3;
        }
        
        set<state> done;
        queue<state> Q;
        if (state(a, b, c).is_end()) {
            return 0;
        }
        Q.push(state(a, b, c));
        done.insert(state(a, b, c));
        int t = 0;
        int sol = 0;
        while (!Q.empty()) {
            if (t == 0) {
                t = Q.size();
                ++sol;
            }
            --t;
            
            state ns = Q.front();
            Q.pop();
            
            if (ns.a > 0) {
                int x = ns.a % 4;
                ns.a /= 4;
                
                ns.b = ns.b*4 + x;
                if (!done.count(ns)) {
                    if (ns.is_end()) {
                        return sol;
                    }
                    done.insert(ns);
                    Q.push(ns);
                }
                ns.b /= 4;
                
                ns.c = ns.c*4 + x;
                if (!done.count(ns)) {
                    if (ns.is_end()) {
                        return sol;
                    }
                    done.insert(ns);
                    Q.push(ns);
                }
                ns.c /= 4;
                
                ns.a = ns.a*4 + x;
            }
            if (ns.b > 0) {
                int x = ns.b % 4;
                ns.b /= 4;
                
                ns.a = ns.a*4 + x;
                if (!done.count(ns)) {
                    if (ns.is_end()) {
                        return sol;
                    }
                    done.insert(ns);
                    Q.push(ns);
                }
                ns.a /= 4;
                
                ns.c = ns.c*4 + x;
                if (!done.count(ns)) {
                    if (ns.is_end()) {
                        return sol;
                    }
                    done.insert(ns);
                    Q.push(ns);
                }
                ns.c /= 4;
                
                ns.b = ns.b*4 + x;
            }
            if (ns.c > 0) {
                int x = ns.c % 4;
                ns.c /= 4;
                
                ns.a = ns.a*4 + x;
                if (!done.count(ns)) {
                    if (ns.is_end()) {
                        return sol;
                    }
                    done.insert(ns);
                    Q.push(ns);
                }
                ns.a /= 4;
                
                ns.b = ns.b*4 + x;
                if (!done.count(ns)) {
                    if (ns.is_end()) {
                        return sol;
                    }
                    done.insert(ns);
                    Q.push(ns);
                }
            }
        }

        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; string Arg1 = "AA"; string Arg2 = "AA"; int Arg3 = 4; verify_case(0, Arg3, moves(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "B"; string Arg1 = "C"; string Arg2 = "A"; int Arg3 = 5; verify_case(1, Arg3, moves(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "CBA"; string Arg1 = ""; string Arg2 = ""; int Arg3 = 5; verify_case(2, Arg3, moves(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "BBBBBBBBBA"; string Arg1 = ""; string Arg2 = ""; int Arg3 = 11; verify_case(3, Arg3, moves(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "CBACBACBAA"; string Arg1 = ""; string Arg2 = ""; int Arg3 = 19; verify_case(4, Arg3, moves(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HanoiTower ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

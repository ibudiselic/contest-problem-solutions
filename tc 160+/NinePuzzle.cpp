#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int adj[][7] = {
 { 1, 2, -1, -1, -1, -1, -1 },
 { 0, 1, 3, 4, -1, -1, -1 },
 { 0, 1, 4, 5, -1, -1, -1 },
 { 1, 4, 6, 7, -1, -1, -1 },
 { 1, 2, 3, 5, 7, 8, -1 },
 { 2, 4, 8, 9, -1, -1, -1 },
 { 3, 7, -1, -1, -1, -1, -1 },
 { 3, 4, 6, 8, -1, -1, -1 },
 { 4, 5, 7, 9, -1, -1, -1 },
 { 5, 8, -1, -1, -1, -1, -1 } };
string G;
string C = "RGBY";
struct State {
    int p;
    string s;
    State(int p_, const string &s_): p(p_), s(s_) {}
};
bool can_do(const string &s) {
    if (s == G) {
        return true;
    }
    queue<State> Q;
    set<string> used;
    used.insert(s);
    Q.push(State(s.find('*'), s));
    
    while (!Q.empty()) {
        State state = Q.front();
        Q.pop();
        
        int i = 0;
        while (adj[state.p][i] != -1) {
            swap(state.s[state.p], state.s[adj[state.p][i]]);
            if (state.s == G) {
                return true;
            }
            if (!used.count(state.s)) {
                used.insert(state.s);
                Q.push(State(adj[state.p][i], state.s));
            }
            swap(state.s[state.p], state.s[adj[state.p][i]]);
            ++i;
        }
    }
    return false;
}
bool go(string &s, int pos, int changes, int r, int g, int b, int y) {
    if (changes<0 || r<0 || g<0 || b<0 || y<0) {
        return false;
    } else if (pos == 10) {
        return changes==0 ? can_do(s) : false;
    } else if (s[pos] == '*') {
        return go(s, pos+1, changes, r, g, b, y);
    } else {
        char orig = s[pos];
        for (int i=0; i<(int)C.size(); ++i) {
            s[pos] = C[i];
            if (go(s, pos+1, changes-(C[i]!=orig), r-(i==0), g-(i==1), b-(i==2), y-(i==3))) {
                return true;
            }
        }
        s[pos] = orig;
        return false;
    }
}
class NinePuzzle {
	public:
	int getMinimumCost(string init, string goal) {
        G = goal;
        int r = 0, g = 0, b = 0, y = 0;
        for (int i=0; i<10; ++i) {
            r += goal[i]=='R';
            g += goal[i]=='G';
            b += goal[i]=='B';
            y += goal[i]=='Y';
        }
		for (int changes=0; changes<9; ++changes) {
            if (go(init, 0, changes, r, g, b, y)) {
                return changes;
            }
        }

        return 9;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BG*YRGRRYR" ; string Arg1 = "BGGY*YRRRR" ; int Arg2 = 0; verify_case(0, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "GBBB*BGBBG" ; string Arg1 = "RYYY*YRYYR"; int Arg2 = 9; verify_case(1, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "RRBR*BRBBB" ; string Arg1 = "BBRB*RBRRR" ; int Arg2 = 1; verify_case(2, Arg2, getMinimumCost(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NinePuzzle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

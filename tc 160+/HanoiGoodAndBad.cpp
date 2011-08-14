#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<int> > D, E;
void print(const vector< vector<int> > &v, int moves) {
    cerr << moves;
    for (int i=0; i<3; ++i) {
        cerr << " (";
        for (int j=0; j<(int)v[i].size(); ++j) {
            if (j) {
                cerr << ' ';
            }
            cerr << v[i][j];
        }
        cerr << ')';
    }
    cerr << '\n';
}
void dave(int source, int target, int spare, int n, vector< vector<int> > &v, int &moves) {
    if (n > 0) {
        dave(source, spare, target, n-1, v, moves);
        ++moves;
        v[target].push_back(v[source].back());
        v[source].pop_back();
        print(v, moves);
        dave(spare, target, source, n-1, v, moves);
    }
}
void gen_dave(int source, int target, int spare, int n, vector< vector<int> > &v, int moves) {
    if (moves==0 || n==0) {
        return;
    } else {
        int k = (1<<(n-1)) - 1;
        if (k >= moves) {
            gen_dave(source, spare, target, n-1, v, moves);
        } else {
            moves -= k;
            for (int i=(int)v[source].size()-n+1; i<(int)v[source].size(); ++i) {
                v[spare].push_back(v[source][i]);
            }
            for (int i=1; i<n; ++i) {
                v[source].pop_back();
            }
            --moves;
            v[target].push_back(v[source].back());
            v[source].pop_back();
            gen_dave(spare, target, source, n-1, v, moves);
        }
    }
}
void earl(int source, int target, int spare, int n, vector< vector<int> > &v, int &moves) {
    if (n > 0) {
        earl(source, target, spare, n-1, v, moves);
        ++moves;
        v[spare].push_back(v[source].back());
        v[source].pop_back();
        earl(target, source, spare, n-1, v, moves);
        ++moves;
        v[target].push_back(v[spare].back());
        v[spare].pop_back();
        earl(source, target, spare, n-1, v, moves);
    }
}
int pow3(int n) {
    int ret = 1;
    while (n--) {
        ret *= 3;
    }
    return ret;
}
int move_earl(int source, int target, int spare, int n, vector< vector<int> > &v, const vector< vector<int> > &need) {
    if (v==need || n==0) {
        return 0;
    } else {
        int moves = 0;
        for (int i=0; i<(int)need[source].size(); ++i) {
            if (need[source][i] == n) {
                return move_earl(source, target, spare, n-1, v, need);
            }
        }
        const int p3 = pow3(n-1) - 1;
        moves += p3 + 1;
        for (int i=(int)v[source].size()-n+1; i<(int)v[source].size(); ++i) {
            v[target].push_back(v[source][i]);
        }
        for (int i=1; i<n; ++i) {
            v[source].pop_back();
        }
        v[spare].push_back(v[source].back());
        v[source].pop_back();
        if (v == need) {
            return moves;
        }
        
        for (int i=0; i<(int)need[spare].size(); ++i) {
            if (need[spare][i] == n) {
                return moves + move_earl(target, source, spare, n-1, v, need);
            }
        }
        moves += p3 + 1;
        for (int i=(int)v[target].size()-n+1; i<(int)v[target].size(); ++i) {
            v[source].push_back(v[target][i]);
        }
        for (int i=1; i<n; ++i) {
            v[target].pop_back();
        }
        v[target].push_back(v[spare].back());
        v[spare].pop_back();
        if (v == need) {
            return moves;
        }
        
        return moves + move_earl(source, target, spare, n-1, v, need);
    }
}
class HanoiGoodAndBad {
	public:
	int moves(int N, int Dave) {
        /*int n = 3;
        D.assign(n, vector<int>());
        E.assign(n, vector<int>());
        for (int i=0; i<n; ++i) {
            D[0].push_back(n-i);
            E[0].push_back(n-i);
        }
        cerr << "DAVE\n";
        int moves = 0;
		dave(0, 1, 2, n, D, moves);
        moves = 0;
        cerr << "EARL\n";
        earl(0, 1, 2, n, E, moves);
        return 0;*/
        D.assign(3, vector<int>());
        E.assign(3, vector<int>());
        for (int i=0; i<N; ++i) {
            D[0].push_back(N-i);
            E[0].push_back(N-i);
        }
        gen_dave(0, 1, 2, N, D, Dave);
        return move_earl(0, 1, 2, N, E, D);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, moves(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 15; int Arg2 = 80; verify_case(1, Arg2, moves(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 265; int Arg2 = 16418; verify_case(2, Arg2, moves(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HanoiGoodAndBad ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

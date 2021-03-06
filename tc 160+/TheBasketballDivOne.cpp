#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int sol;
int M, N;
int w[5], w2[5];
bool done[9*9*9*9];
void upd() {
    memcpy(w2, w, sizeof w2);
    sort(w2, w2+N);
    reverse(w2, w2+N);
    int code = 0;
    for (int i=1; i<N; ++i) {
        code = code*9 + w2[i];
    }
    if (w2[0]==M && !done[code]) {
        done[code] = 1;
        ++sol;
    }
}
void go(int a, int b) {
    if (a == N) {
        upd();
        return;
    }
    if (b == a) {
        go(a, b+1);
        return;
    }
    if (b == N) {
        go(a+1, 0);
        return;
    }
    ++w[a];
    go(a, b+1);
    --w[a];
    ++w[b];
    go(a, b+1);
    --w[b];
}
class TheBasketballDivOne {
	public:
	int find(int n, int m) {
		sol = 0;
        memset(w, 0, sizeof w);
        memset(done, 0, sizeof done);
        N = n;
        M = m;
        go(0, 1);
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 5; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBasketballDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

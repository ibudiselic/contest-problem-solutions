#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string S, cur;
bool done[20][1<<10][2];
int K;
int bc[1<<10];
bool go(int p, int dmask, bool any) {
    if (done[p][dmask][any]) {
        return false;
    }
    done[p][dmask][any] = true;
    if (bc[dmask] > K) {
        return false;
    }
    if (p == (int)S.size()) {
        return (bc[dmask] == K);
    }
    
    for (int i=(any ? 0 : S[p]-'0'); i<10; ++i) {
        cur[p] = char(i + '0');
        if (go(p+1, dmask | (1<<i), any || (i>S[p]-'0'))) {
            return true;
        }
    }
    
    return false;
}

class TheInteger {
	public:
	long long find(long long n, int k) {
        K = k;
		ostringstream os;
        os << n;
        S = os.str();
        
        if (k > (int)S.size()) {
            string sol = "10";
            for (int i=2; i<k; ++i) {
                sol += char('0' + i);
            }
            istringstream is(sol);
            is >> n;
            return n;
        }
        bc[0] = 0;
        for (int i=1; i<(1<<10); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        cur = S;
        memset(done, 0, sizeof done);
        
        if (!go(0, 0, 0)) {
            S = '0' + S;
            cur = S;
            cur[0] = '1';
            go(1, 2, 1);
        }
        istringstream is(cur);
        is >> n;
        return n;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 47LL; int Arg1 = 1; long long Arg2 = 55LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 7LL; int Arg1 = 3; long long Arg2 = 102LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 69LL; int Arg1 = 2; long long Arg2 = 69LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 12364LL; int Arg1 = 3; long long Arg2 = 12411LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheInteger ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int where[1000001];
class DivideAndShift {
	public:
	int getLeast(int N, int M) {
		memset(where, 0xff, sizeof where);
        where[N] = M-1;
        int sol = N;
        queue<int> Q;
        Q.push(N);
        int dist = -1;
        int sz = 0;
        vector<int> divs;
        int n = N;
        for (long long d=2; d*d<=n; ++d) {
            if (n%d == 0) {
                divs.push_back(d);
                do {
                    n /= d;
                } while (n%d == 0);
            }
        }
        if (n > 1) {
            divs.push_back(n);
        }
        while (!Q.empty()) {
            if (sz == 0) {
                sz = Q.size();
                ++dist;
            }
            --sz;
            int x = Q.front();
            Q.pop();
            sol = min(sol, dist + min(where[x], x-where[x]));
            for (int i=0; i<(int)divs.size(); ++i) {
                if (divs[i] > x) {
                    break;
                }
                if (x%divs[i] == 0) {
                    if (where[x/divs[i]] == -1) {
                        where[x/divs[i]] = where[x]%(x/divs[i]);
                        Q.push(x/divs[i]);
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 56; int Arg1 = 14; int Arg2 = 3; verify_case(0, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 49; int Arg1 = 5; int Arg2 = 2; verify_case(1, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 256; int Arg1 = 7; int Arg2 = 6; verify_case(2, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 77777; int Arg1 = 11111; int Arg2 = 2; verify_case(4, Arg2, getLeast(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DivideAndShift ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

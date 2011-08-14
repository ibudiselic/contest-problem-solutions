#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int sz[200001];
int f(int x) {
    int ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }

    return ret;
}
class RoundAboutCircle {
	public:
	int maxScore(int N) {
	    memset(sz, 0xff, sizeof sz);

        for (int i=1; i<=N; ++i) {
            if (sz[i] == -1) {
                int x = i;
                while (sz[x] == -1) {
                    sz[x] = -2;
                    x = ((x-1+f(x)) % N) + 1;
                }
                if (sz[x] == -2) {
                    int y = x;
                    int cyc = 0;
                    do {
                        assert(sz[y] == -2);
                        ++cyc;
                        y = ((y-1+f(y)) % N) + 1;
                    } while (y != x);

                    y = x;
                    do {
                        sz[y] = cyc;
                        y = ((y-1+f(y)) % N) + 1;
                    } while (y != x);
                }
                int tail = 0;
                int y = i;
                while (y != x) {
                    ++tail;
                    y = ((y-1+f(y)) % N) + 1;
                }
                y = i;
                while (y != x) {
                    sz[y] = sz[x] + tail;
                    --tail;
                    y = ((y-1+f(y)) % N) + 1;
                }
            }
        }

        return *max_element(sz+1, sz+N+1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; verify_case(0, Arg1, maxScore(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; verify_case(1, Arg1, maxScore(Arg0)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 11; verify_case(2, Arg1, maxScore(Arg0)); }
	void test_case_3() { int Arg0 = 566; int Arg1 = 176; verify_case(3, Arg1, maxScore(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RoundAboutCircle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

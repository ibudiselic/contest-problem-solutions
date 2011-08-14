#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <utility>

using namespace std;

int can[50001];
int calc(int a, int b) {
    return a*a*a + b*b;
}
class PlanarGraphShop {
	public:
	int bestCount(int N) {
        set<int> t;
        for (int i=1; i<37; ++i) {
            int j = 0;
            int lim = (i<3 ? i*(i-1)/2 : 3*i - 6);
            while (j <= lim) {
                const int x = calc(i, j);
                if (x > N) {
                    break;
                }
                t.insert(x);
                ++j;
            }
        }
        vector<int> v(t.begin(), t.end());
        memset(can, 0xff, sizeof can);
        can[0] = 0;
        for (int i=0; i<N; ++i) {
            if (can[i] != -1) {
                for (int j=0; j<(int)v.size(); ++j) {
                    int t = i + v[j];
                    if (t<=N && (can[t]==-1 || can[t]>=can[i]+1)) {
                        can[t] = can[i] + 1;
                    }
                }
            }
        }
        
        return can[N];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 36; int Arg1 = 1; verify_case(0, Arg1, bestCount(Arg0)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 7; verify_case(1, Arg1, bestCount(Arg0)); }
	void test_case_2() { int Arg0 = 72; int Arg1 = 2; verify_case(2, Arg1, bestCount(Arg0)); }
	void test_case_3() { int Arg0 = 46; int Arg1 = 3; verify_case(3, Arg1, bestCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PlanarGraphShop ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

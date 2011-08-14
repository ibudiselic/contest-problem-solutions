#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

double X[5001], Y[5001];
double tmp[2][10001];
void calc(int x, int M, int S, double *P) {
    P[0] = 1.0;
    memset(tmp, 0, sizeof tmp);
    tmp[0][x] = 1.0;
    for (int i=1; i<=S; ++i) {
        tmp[i&1][0] = 0.5 * tmp[(i+1)&1][1];
        tmp[i&1][M-1] = 0.5 * tmp[(i+1)&1][M-2];
        for (int j=1; j<M-1; ++j) {
            tmp[i&1][j] = 0.5 * (tmp[(i+1)&1][j-1] + tmp[(i+1)&1][j+1]);
        }
        P[i] = accumulate(tmp[i&1], tmp[i&1] + M, 0.0);
    }
}
class RectangularIsland {
	public:
	double theProbablity(int width, int height, int x, int y, int steps) {
		calc(x, width, steps, X);
        calc(y, height, steps, Y);
        
        memset(tmp, 0, sizeof tmp);
        tmp[0][0] = 1.0;
        for (int i=1; i<=steps; ++i) {
            tmp[i&1][0] = 0.5 * tmp[(i+1)&1][0];
            for (int j=1; j<=i; ++j) {
                tmp[i&1][j] = 0.5 * (tmp[(i+1)&1][j] + tmp[(i+1)&1][j-1]);
            }
        }
        
        double sol = 0.0;
        for (int dx=0; dx<=steps; ++dx) {
            sol += tmp[steps&1][dx] * X[dx] * Y[steps-dx];
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 4; int Arg3 = 3; int Arg4 = 1; double Arg5 = 0.75; verify_case(0, Arg5, theProbablity(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 4; int Arg3 = 7; int Arg4 = 1; double Arg5 = 0.5; verify_case(1, Arg5, theProbablity(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 1; int Arg4 = 5; double Arg5 = 0.03125; verify_case(2, Arg5, theProbablity(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 58; int Arg1 = 85; int Arg2 = 47; int Arg3 = 74; int Arg4 = 1000; double Arg5 = 0.13056659769966347; verify_case(3, Arg5, theProbablity(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 123; int Arg3 = 456; int Arg4 = 5000; double Arg5 = 0.9868611148475199; verify_case(4, Arg5, theProbablity(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RectangularIsland ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

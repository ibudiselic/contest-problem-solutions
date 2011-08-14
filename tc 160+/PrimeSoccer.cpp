#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long double P[2][2][20];
bool is_prime(int x) {
    for (int d=2; d*d<=x; ++d) {
        if (x%d == 0) {
            return false;
        }
    }
    
    return true;
}
class PrimeSoccer {
	public:
	double getProbability(int a, int b) {
        memset(P, 0, sizeof P);
        P[0][0][0] = P[0][1][0] = 1.0;
		int p = 1;
        for (int t=0; t<90; t+=5) {
            for (int g=0; g<20; ++g) {
                P[p][0][g] = P[!p][0][g]*(100-a)/100.0 + (g>0 ? P[!p][0][g-1]*a/100.0 : 0.0);
                P[p][1][g] = P[!p][1][g]*(100-b)/100.0 + (g>0 ? P[!p][1][g-1]*b/100.0 : 0.0);
            }
            p = !p;
        }
        
        double aa = 0.0;
        double bb = 0.0;
        for (int g=2; g<20; ++g) {
            if (is_prime(g)) {
                aa += P[!p][0][g];
                bb += P[!p][1][g];
            }
        }
        
        return aa + bb - aa*bb;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 50; int Arg1 = 50; double Arg2 = 0.5265618908306351; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; double Arg2 = 0.0; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 89; double Arg2 = 0.6772047168840167; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PrimeSoccer ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

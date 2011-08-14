#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ParkAmusement {
	public:
	double getProbability(vector <string> landings, int startLanding, int K) {
        int n = landings.size();
        int out[50] = {0};
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                out[i] += (landings[i][j] == '1');
            }
        }
        double p[50];
        double t[50];
        double sol[50] = {0};
        double total = 0.0;
        for (int i=0; i<n; ++i) {
            memset(p, 0, sizeof p);
            p[i] = 1.0;
            int k = K;
            while (k--) {
                memset(t, 0, sizeof t);
                for (int a=0; a<n; ++a) {
                    for (int b=0; b<n; ++b) {
                        if (landings[a][b] == '1') {
                            t[b] += p[a]/out[a];
                        }
                    }
                }
                memcpy(p, t, sizeof p);
            }
            
            for (int j=0; j<n; ++j) {
                if (landings[j][j] == 'E') {
                    sol[i] += p[j];
                }
            }
            total += sol[i];
        }
        
        return sol[startLanding] / total;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"E000",
 "1000",
 "1000",
 "1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; double Arg3 = 0.3333333333333333; verify_case(0, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"E000",
 "1000",
 "1001",
 "000P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; double Arg3 = 0.6666666666666666; verify_case(1, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"01000100",
 "00111000",
 "00001010",
 "000E0000",
 "0000E000",
 "00000P00",
 "000000P0",
 "01000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.14285714285714288; verify_case(2, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"0100",
 "0010",
 "0001",
 "000E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; double Arg3 = 0.0; verify_case(3, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"E00",
 "0E0",
 "010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; double Arg3 = 0.0; verify_case(4, Arg3, getProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ParkAmusement ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

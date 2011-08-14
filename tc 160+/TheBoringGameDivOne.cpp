#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TheBoringGameDivOne {
	public:
    vector <int> find(int SA, int KA, int SB, int KB, int SF, int KF) {
        if (KF-SA-SB != KA+KB-SF) {
            return vector<int>();
        }
        
        int lo = 1234567890;
        int hi = -lo;
        int K = KA + KB + KF;
        for (int a=0; a<=KF; ++a) {
            for (int b=0; b<=KF; ++b) {
                if ((K+a+b)%2 == 0) {
                    int numRounds = (K+a+b)/2;
                    int wonF = numRounds - KF;
                    int loF = -1234567890;
                    int hiF = -loF;
                    int h = max(0, SA-a);
                    int g = max(0, SB-b);
                    hiF = min(hiF, numRounds - h - a - g - b);
                    int e = h + a - SA;
                    int f = g + b - SB;
                    loF = max(loF, e + f);
                    hiF = min(hiF, KA-g);
                    hiF = min(hiF, KB-h);
                    if (loF<=wonF && wonF<=hiF) {
                        lo = min(lo, numRounds);
                        hi = max(hi, numRounds);
                    }
                }
            }
        }
        
        if (lo > hi) {
            return vector<int>();
        } else {
            vector<int> sol(1, lo);
            sol.push_back(hi);
            return sol;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 2; int Arr6[] = {2, 3 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arr6[] = {0, 0 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 7; int Arg2 = -2; int Arg3 = 5; int Arg4 = 1; int Arg5 = 9; int Arr6[] = { }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 5; int Arg2 = -1; int Arg3 = 4; int Arg4 = 3; int Arg5 = 6; int Arr6[] = {8, 9 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBoringGameDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

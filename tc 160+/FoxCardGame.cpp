#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FoxCardGame {
	public:
	double theMaxProportion(vector <double> pileA, vector <double> pileB, int k) {
		sort(pileA.begin(), pileA.end());
        sort(pileB.begin(), pileB.end());
        
        int sz = pileA.size();
        double sol = 0.0;
        for (int kk=0; kk<=k; ++kk) {
            double N = 0.0;
            double D = 0.0;
            for (int i=0; i<kk; ++i) {
                N += pileA[i]+pileB[kk-1-i];
                D += pileA[i]*pileB[kk-1-i];
            }
            
            int k2 = k - kk;
            for (int a=0; a<=k2; ++a) {
                for (int b=0; b<=k2; ++b) {
                    double NN = N;
                    double DD = D;
                    for (int i=0; i<k2; ++i) {
                        double x = (i<a ? pileA[kk+i] : pileA[sz-k2+i]);
                        double y = (i<b ? pileB[kk+i] : pileB[sz-k2+i]);
                        NN += x*y;
                        DD += x+y;
                    }
                    sol = max(sol, NN/DD);
                }
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arr0[] = {1, 2, 3}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {4, 5, 6}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 1.7692307692309948; verify_case(0, Arg3, theMaxProportion(Arg0, Arg1, Arg2)); }
	void test_case_1() { double Arr0[] = {1.234, 5.678, 9.012, 3.456, 7.89}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {2.345, 6.789, 9.876, 5.432, 1.012}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; double Arg3 = 4.159424420079586; verify_case(1, Arg3, theMaxProportion(Arg0, Arg1, Arg2)); }
	void test_case_2() { double Arr0[] = {1, 1.1, 1.2, 1.3, 1.4, 1.5}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {5, 10, 15, 20, 25, 30}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 1.3972602739726827; verify_case(2, Arg3, theMaxProportion(Arg0, Arg1, Arg2)); }
	void test_case_3() { double Arr0[] = {85.302, 92.798, 76.813, 37.994, 36.737, 98.659}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {13.352, 7.3094, 54.761, 8.2706, 63.223, 37.486}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; double Arg3 = 33.58603889836175; verify_case(3, Arg3, theMaxProportion(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxCardGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

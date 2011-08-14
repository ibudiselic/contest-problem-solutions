#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
    
vector<int> W;
int MC;
double calc(long long a, long long b) {
    bool have_one = false;
    long long am=a, bm=b;
    
    long long rem = MC;
    //cerr << double(a)/b << ":\n";
    for (int i=0; i<(int)W.size() && rem>=0; ++i) {
        if (W[i]*b <= a) {
            //cerr << W[i] << " ok\n";
            have_one |= (W[i]*b == a);
            if (am > W[i]*bm) {
                am = W[i];
                bm = 1;
            }
        } else if (W[i]*b > a) {
            long long num_pieces = (W[i]*b + a-1)/a;
            rem -= num_pieces - 1;
            //cerr << "cutting " << W[i] << " into " << num_pieces << " pieces of size " << double(W[i])/num_pieces << " with " << rem << " pieces remaining\n";
            if (num_pieces*a == W[i]*b) {
                have_one = true;
            } else if (am*num_pieces > W[i]*bm) {
                am = W[i];
                bm = num_pieces;
            }
        }
    }
    
    return rem>=0 && have_one ? double(a)/b - double(am)/bm : 1e32;
}

class CakesEqualization {
	public:
	double fairDivision(vector <int> weights, int maxCuts) {
        if (weights.size() == 1) {
            return 0;
        }
        W = weights;
        MC = maxCuts;
        sort(W.begin(), W.end());
        double sol = W.back() - W[0];
        reverse(W.begin(), W.end());
        
        for (int i=0; i<(int)W.size(); ++i) {
            for (int j=0; j<=maxCuts; ++j) {
                sol = min(sol, calc(W[i], j+1));
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.0; verify_case(0, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 0.0; verify_case(1, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 0.5; verify_case(2, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7, 11, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arg2 = 0.3999999999999999; verify_case(3, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {13, 69, 41, 37, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; double Arg2 = 1.4666666666666668; verify_case(4, Arg2, fairDivision(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CakesEqualization ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

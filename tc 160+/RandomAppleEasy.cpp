#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long ways[2][501][501];
class RandomAppleEasy {
	public:
	double theRed(vector <int> red, vector <int> green) {
        int n = red.size();
        memset(ways, 0, sizeof ways);
        ways[n&1][0][0] = 1;
        for (int i=n-1; i>=0; --i) {
            for (int r=0; r<red[i]; ++r) {
                for (int g=0; g<501; ++g) {
                    ways[i&1][r][g] = ways[(i+1)&1][r][g];
                }
            }
            for (int r=0; r<501; ++r) {
                for (int g=0; g<green[i]; ++g) {
                    ways[i&1][r][g] = ways[(i+1)&1][r][g];
                }
            }
            for (int r=red[i]; r<501; ++r) {
                for (int g=green[i]; g<501; ++g) {
                    ways[i&1][r][g] = ways[(i+1)&1][r][g] + ways[(i+1)&1][r-red[i]][g-green[i]];
                }
            }
        }
        double sol = 0.0;
        for (int r=1; r<501; ++r) {
            for (int g=1; g<501; ++g) {
                sol += ways[0][r][g] * double(r) / (r+g);
            }
        }
        double total = 1.0;
        for (int i=0; i<n; ++i) {
            total *= 2.0;
        }
        return sol / (total - 1.0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.38461538461538464; verify_case(0, Arg2, theRed(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5888888888888888; verify_case(1, Arg2, theRed(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2, 5, 6, 4, 9, 10, 6, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 5, 6, 4, 9, 10, 6, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.4999999999999999; verify_case(2, Arg2, theRed(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 5, 6, 4, 9, 10, 6, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 7, 4, 5, 3, 2, 9, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5429014970733334; verify_case(3, Arg2, theRed(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {5, 1, 2, 8, 4, 1, 1, 2, 3, 4, 5, 2, 10, 2, 6, 2, 8, 7, 9, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 7, 1, 1, 10, 3, 4, 1, 6, 2, 7, 6, 10, 5, 2, 9, 3, 8, 1, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.46460213827476854; verify_case(4, Arg2, theRed(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RandomAppleEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

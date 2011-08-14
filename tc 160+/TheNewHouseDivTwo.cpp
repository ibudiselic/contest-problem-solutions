#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> X[201], Y[201];
class TheNewHouseDivTwo {
	public:
	int count(vector <int> x, vector <int> y) {
        for (int i=0; i<201; ++i) {
            X[i].clear();
            Y[i].clear();
        }
        
        for (int i=0; i<(int)x.size(); ++i) {
            X[x[i] + 100].push_back(y[i] + 100);
            Y[y[i] + 100].push_back(x[i] + 100);
        }
        for (int i=0; i<201; ++i) {
            sort(X[i].begin(), X[i].end());
            X[i].resize(unique(X[i].begin(), X[i].end()) - X[i].begin());
            sort(Y[i].begin(), Y[i].end());
            Y[i].resize(unique(Y[i].begin(), Y[i].end()) - Y[i].begin());
        }
        
        int sol = 0;
        for (int i=0; i<201; ++i) {
            if (X[i].size() < 2) {
                continue;
            }
            int l = X[i][0];
            int r = X[i].back();
            for (int j=l+1; j<r; ++j) {
                if (Y[j].size() < 2) {
                    continue;
                }
                int ll = Y[j][0];
                int rr = Y[j].back();
                sol += (ll<i && i<rr);
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 1, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, -1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 5, 0, 8, -3, 5, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, -4, 2, 1, 1, 11, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 7, 3, 4, 9, 3, 7, 1, 1, 6, 1, 6, 1, 9, 7, 9, 4, 9, 1, 4, 7, 1, 2, 5, 3, 8, 7, 7, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2, 8, 9, 4, 3, 4, 1, 4, 1, 7, 8, 1, 1, 1, 4, 7, 1, 9, 4, 9, 1, 4, 1, 1, 1, 2, 4, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheNewHouseDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> len[2];
int n;

bool ok(int mask, const vector<int> &A, const vector<int> &B) {
    int ta = 0, tb = 0;
    for (int i=0; i<n; ++i) {
        if (mask & (1<<i)) {
            ta += A[i];
        }
    }
    for (int i=0; i<n; ++i) {
        if (mask & (1<<i)) {
            continue;
        }
        if (tb + B[i] > ta) {
            return false;
        }
        tb += B[i];
        ta += A[i];
    }
    
    return true;
}
bool ok(int mask) {
    return ok(mask, len[0], len[1]) && ok(~mask, len[1], len[0]);
}
class TheMoviesLevelThreeDivTwo {
	public:
	int find(vector <int> timeJ, vector <int> timeB) {
        len[0] = timeJ;
        len[1] = timeB;
		int sol = 0;
        n = len[0].size();
        
        for (int mask=0; mask<(1<<n); ++mask) {
            sol += ok(mask);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 6, 5, 4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 98; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheMoviesLevelThreeDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

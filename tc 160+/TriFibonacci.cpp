#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool test(const vector<int> &v) {
    for (int i=3; i<(int)v.size(); ++i) {
        if (v[i] != v[i-3] + v[i-1] + v[i-2]) {
            return false;
        }
    }
    return true;
}
class TriFibonacci {
	public:
	int complete(vector <int> A) {
		int i = 0;
        while (A[i] != -1) {
            ++i;
        }
        
        if (i >= 3) {
            A[i] = A[i-1] + A[i-2] + A[i-3];
        } else if (i == 0) {
            A[i] = A[3] - A[2] - A[1];
        } else if (i == 2) {
            A[i] = A[3] - A[1] - A[0];
        } else if (i == 1) {
            A[i] = A[3] - A[2] - A[0];
        }

        return A[i]>0 && test(A) ? A[i] : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, complete(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 20, 30, 60, -1 , 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 110; verify_case(1, Arg1, complete(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 5, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, complete(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 1, -1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, complete(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 7, 8, 1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999985; verify_case(4, Arg1, complete(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TriFibonacci ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

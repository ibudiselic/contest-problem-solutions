#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> sol;
void test(const vector<string> &A, vector<string> B) {
    for (int i=0; i<(int)A.size(); ++i) {
        for (int j=0; j<(int)A[0].size(); ++j) {
            if (A[i][j] == '?') {
                if (B[i][j] == '?') {
                    B[i][j] = '0';
                }
            } else {
                if (B[i][j] == '?') {
                    B[i][j] = A[i][j];
                } else if (B[i][j] != A[i][j]) {
                    goto FAIL;
                }
            }
        }
    }
    
    if (sol.size()==0 || B<sol) {
        sol.swap(B);
    }
    
    FAIL:;
}
void rot(vector<string> &v, int i, int j) {
    char t = v[i][j];
    v[i][j] = v[i-1][j];
    v[i-1][j] = v[i-1][j-1];
    v[i-1][j-1] = v[i][j-1];
    v[i][j-1] = t;
}
void rev_rot(vector<string> &v, int i, int j) {
    char t = v[i][j];
    v[i][j] = v[i][j-1];
    v[i][j-1] = v[i-1][j-1];
    v[i-1][j-1] = v[i-1][j];
    v[i-1][j] = t;
}
class TwistedMatrix {
	public:
	vector <string> solve(vector <string> A, vector <string> B) {
	    const int m = A.size();
        const int n = A[0].size();
        
        vector<string> T = A;
        sol.clear();
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                rot(T, i, j);
                test(T, B);
                rev_rot(T, i, j);
                rev_rot(T, i, j);
                test(T, B);
                rot(T, i, j);
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1000",
 "0000",
 "0000",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000",
 "?000",
 "0000",
 "0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0000", "1000", "0000", "0000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"11",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"??",
 "??"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"01", "11" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"000",
 "0?0",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"111",
 "1?1",
 "111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"?1111",
 "11111",
 "11011",
 "10111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"?1111",
 "11111",
 "1??11",
 "1??11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"01111", "11111", "10011", "11111" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"00111",
 "00111",
 "11111",
 "11111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"??1??",
 "??1??",
 "?????",
 "?????"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"00111", "00111", "11111", "11111" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TwistedMatrix ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

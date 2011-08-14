#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int T[50][50];
class CircularLine {
	public:
	int longestTravel(vector <int> t) {
	    int n = t.size();
        int circ = 0;
        for (int i=0; i<n; ++i) {
            circ += t[i];
        }
        vector<int> s = t;
        for (int i=1; i<n; ++i) {
            s[i] += s[i-1];
        }

        memset(T, 0xff, sizeof T);
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                T[i][j] = T[j][i] = min(s[j-1]-(i==0 ? 0 : s[i-1]), circ - (s[j-1]-(i==0 ? 0 : s[i-1])));
            }
        }

        int sol = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                sol = max(sol, T[i][j]);
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, longestTravel(Arg0)); }
	void test_case_1() { int Arr0[] = {1,4,4,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, longestTravel(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, longestTravel(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1000,1,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1001; verify_case(3, Arg1, longestTravel(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, longestTravel(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CircularLine ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

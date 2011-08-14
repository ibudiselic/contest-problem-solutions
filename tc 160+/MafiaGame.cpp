#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class MafiaGame {
	public:
	double probabilityToLose(int N, vector <int> decisions) {
		map<int, int> cnt;
        int maxval = 0;
        for (int i=0; i<(int)decisions.size(); ++i) {
            maxval = max(maxval, ++cnt[decisions[i]]);
        }
        
        if (maxval == 1) {
            return 0.0;
        }
        
        int left = 0;
        for (map<int, int>::const_iterator it=cnt.begin(); it!=cnt.end(); ++it) {
            left += (it->second == maxval);
        }
        int M = left;

        while (left > 1) {
            left = N%left;
        }
        if (left == 1) {
            return 1.0/M;
        } else {
            return 0.0;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 23; int Arr1[] = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.14285714285714285; verify_case(3, Arg2, probabilityToLose(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MafiaGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

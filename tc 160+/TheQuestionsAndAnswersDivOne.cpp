#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[10][1<<9][1<<9];
int N;
vector<string> A;
int go(int p, int yes, int on) {
    int &ret = dp[p][yes][on];
    if (ret != -1) {
        return ret;
    }
    
    if (p == (int)A.size()) {
        return (ret = (on==(1<<N)-1));
    }
    
    ret = 0;
    for (int i=0; i<N; ++i) {
        if (!((on>>i)&1)) {
            ret += go(p+1, yes | ((A[p][0]=='Y')<<i), on | (1<<i));
        } else if (A[p][0]==((yes&(1<<i)) ? 'Y' : 'N')) {
            ret += go(p+1, yes, on);
        }
    }
    return ret;
}
class TheQuestionsAndAnswersDivOne {
	public:
	int find(int questions, vector <string> answers) {
		A = answers;
        N = questions;
        memset(dp, 0xff, sizeof dp);
        
        return go(0, 0, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"No", "Yes"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"No", "No", "No"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"Yes", "No", "No", "Yes"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"Yes", "Yes", "Yes", "No"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheQuestionsAndAnswersDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

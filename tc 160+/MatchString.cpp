#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string T;
vector<string> W;
vector< vector<int> > pos;

int dp[50][1000];

int go(int p, int col) {
    if (p == (int)T.size()) {
        return 0;
    }

    int &ret = dp[p][col];
    if (ret != -1) {
        return ret;
    }

    ret = 123456789;
    for (int i=0; i<(int)pos[p].size(); ++i) {
        if (pos[p][i] <= col) {
            ret = min(ret, col-pos[p][i] + go(p+1, col));
        }
    }

    return ret;
}

class MatchString {
	public:
	int placeWords(string matchString, vector <string> matchWords) {
		T = matchString;
        W = matchWords;

        pos.assign(T.size(), vector<int>());
        for (int i=0; i<(int)T.size(); ++i) {
            for (int j=0; j<(int)W[i].size(); ++j) {
                if (T[i] == W[i][j]) {
                    pos[i].push_back(j);
                }
            }
            if (pos[i].size() == 0) {
                return -1;
            }
        }

        memset(dp, 0xff, sizeof dp);
        int sol = 123456789;
        for (int offset=0; offset<=50; ++offset) {
            for (int i=0; i<(int)pos[0].size(); ++i) {
                sol = min(sol, offset + go(1, pos[0][i]+offset));
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
	void test_case_0() { string Arg0 = "TOP"; string Arr1[] = {"TIK", 
 "PPPO", 
 "OP"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, placeWords(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "EEA"; string Arr1[] = {"GEGA", 
 "TOPCODER", 
 "TEST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, placeWords(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AB"; string Arr1[] = {"ABA", 
 "ABAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, placeWords(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "FIND"; string Arr1[] = {"VERYFAST", 
 "OPINION", 
 "SPENDING", 
 "ODD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, placeWords(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "TOP"; string Arr1[] = {"OUTTHERE", 
 "FROM", 
 "NOPQRSTU"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, placeWords(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MatchString ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

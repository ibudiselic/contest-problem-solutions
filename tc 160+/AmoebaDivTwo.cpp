#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt(const vector<string> &A, int K) {
    int m = A.size();
    int n = A[0].size();
    int ret = 0;
    for (int i=0; i<m; ++i) {
        int succ = 0;
        for (int j=0; j<n; ++j) {
            if (A[i][j] == 'M') {
                succ = 0;
            } else {
                ++succ;
            }
            ret += (succ >= K);
        }
    }
    return ret;
}
vector<string> transpose(const vector<string> &A) {
    int m = A.size();
    int n = A[0].size();
    vector<string> ret(n, string(m, ' '));
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            ret[j][i] = A[i][j];
        }
    }
    return ret;
}
class AmoebaDivTwo {
	public:
	int count(vector <string> table, int K) {
		return cnt(table, K) + (K>1)*cnt(transpose(table), K);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"MA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AAA",
 "AMA",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AA",
 "AA",
 "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 7; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"MMM",
 "MMM",
 "MMM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"AAM",
 "MAM",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"AAA",
 "AAM",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 9; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AmoebaDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

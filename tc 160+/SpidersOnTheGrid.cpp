#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const string S = "NESW";
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

bool V[52][52];
class SpidersOnTheGrid {
	public:
	int find(vector <string> A) {
	    memset(V, 0, sizeof V);
        for (int i=0; i<(int)A.size(); ++i) {
            for (int j=0; j<(int)A[i].size(); ++j) {
                const int d = S.find(A[i][j]);
                V[i+1+di[d]][j+1+dj[d]] = 1;
            }
        }
        
        int sol = 0;
        for (int i=0; i<(int)A.size(); ++i) {
            for (int j=0; j<(int)A[i].size(); ++j) {
                sol += !V[i+1][j+1];
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
	void test_case_0() { string Arr0[] = {"EW","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"EW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"ESW","ENW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SpidersOnTheGrid ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

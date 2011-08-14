#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class ColorfulRabbits {
	public:
	int getMinimum(vector <int> replies) {
		sort(replies.begin(), replies.end());
        int cnt = 1;
        replies.push_back(-1);
        int sol = 0;
        for (int i=1; i<(int)replies.size(); ++i) {
            if (replies[i] != replies[i-1]) {
                sol += (cnt+replies[i-1])/(replies[i-1]+1) * (replies[i-1]+1);
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = { 0 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = { 2, 2, 44, 2, 2, 2, 444, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 499; verify_case(2, Arg1, getMinimum(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulRabbits ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

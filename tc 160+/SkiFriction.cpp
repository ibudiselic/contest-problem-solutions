#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SkiFriction {
	public:
	int bestPosition(string skiFriction, string pathFriction) {
        int sol = 0;
        for (int i=skiFriction.size(); i<(int)pathFriction.size(); ++i) {
            vector<int> t;
            for (int j=0; j<(int)skiFriction.size(); ++j) {
                t.push_back(skiFriction[skiFriction.size()-1-j]-'0' + pathFriction[i-1-j]-'0');
            }
            sol += *max_element(t.begin(), t.end());
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "45"; string Arg1 = "15196"; int Arg2 = 33; verify_case(0, Arg2, bestPosition(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "6"; string Arg1 = "65"; int Arg2 = 12; verify_case(1, Arg2, bestPosition(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "6723"; string Arg1 = "562516639"; int Arg2 = 61; verify_case(2, Arg2, bestPosition(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "623883347715596655"; string Arg1 = "724951246328811474"; int Arg2 = 0; verify_case(3, Arg2, bestPosition(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SkiFriction ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char c[4] = { 'R', 'G', 'B', 'Y' };
class ColorfulTilesEasy {
	public:
	int theMin(string room) {
		int n = 2*room.size();
        int sol = 123456;
        for (int mask=0; mask<(1<<n); ++mask) {
            int t = mask;
            int cur = 0;
            int last = 4;
            for (int i=0; 2*i<n; ++i) {
                if ((t&3) == last) {
                    cur = 123456;
                    break;
                }
                last = (t&3);
                cur += (c[(t & 3)]!=room[i]);
                t >>= 2;
            }
            sol = min(sol, cur);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRRRRR"; int Arg1 = 3; verify_case(0, Arg1, theMin(Arg0)); }
	void test_case_1() { string Arg0 = "GGGGGGG"; int Arg1 = 3; verify_case(1, Arg1, theMin(Arg0)); }
	void test_case_2() { string Arg0 = "BBBYYYYYY"; int Arg1 = 4; verify_case(2, Arg1, theMin(Arg0)); }
	void test_case_3() { string Arg0 = "BRYGYBGRYR"; int Arg1 = 0; verify_case(3, Arg1, theMin(Arg0)); }
	void test_case_4() { string Arg0 = "RGGBBBRYYB"; int Arg1 = 3; verify_case(4, Arg1, theMin(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulTilesEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

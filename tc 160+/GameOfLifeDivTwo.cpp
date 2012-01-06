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

class GameOfLifeDivTwo {
	public:
	string theSimulation(string init, int T) {
		string cur[2];
        cur[0] = cur[1] = init;
        int n = init.size();
        for (int t=0; t<T; ++t) {
            for (int i=0; i<n; ++i) {
                int cnt = (cur[t&1][(i+n-1)%n]=='1') + (cur[t&1][i]=='1') + (cur[t&1][(i+1)%n]=='1');
                cur[(t+1)&1][i] = (cnt>=2 ? '1' : '0');
            }
        }
        return cur[T&1];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01010"; int Arg1 = 2; string Arg2 = "00000"; verify_case(0, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "010101"; int Arg1 = 5; string Arg2 = "101010"; verify_case(1, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "111010"; int Arg1 = 58; string Arg2 = "111111"; verify_case(2, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "111111111"; int Arg1 = 511; string Arg2 = "111111111"; verify_case(3, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "110010000010111110010100001001"; int Arg1 = 1000; string Arg2 = "110000000001111110000000000001"; verify_case(4, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "00101110011"; int Arg1 = 0; string Arg2 = "00101110011"; verify_case(5, Arg2, theSimulation(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GameOfLifeDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

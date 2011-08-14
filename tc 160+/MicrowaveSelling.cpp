#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MicrowaveSelling {
	public:
	int mostAttractivePrice(int minPrice, int maxPrice) {
        int res = 0;
		for (int m=1000000; res<minPrice; res=maxPrice+((-maxPrice-1)%m)) {
            m /= 10;
        }
        return res;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 460; int Arg1 = 680; int Arg2 = 599; verify_case(0, Arg2, mostAttractivePrice(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1000; int Arg2 = 999; verify_case(1, Arg2, mostAttractivePrice(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1255; int Arg1 = 2999; int Arg2 = 2999; verify_case(2, Arg2, mostAttractivePrice(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 25; int Arg2 = 25; verify_case(3, Arg2, mostAttractivePrice(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MicrowaveSelling ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

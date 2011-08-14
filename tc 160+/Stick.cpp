#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class Stick {
	public:
	int pieces(int x) {
		vector<int> v;
        v.push_back(64);
        while (1) {
            int t = accumulate(v.begin(), v.end(), 0);
            if (t == x) {
                return (int)v.size();
            }
            v[0] = v[0]/2;
            if (t - v[0] < x) {
                v.insert(v.begin(), v[0]);
            }
        }

        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 32; int Arg1 = 1; verify_case(0, Arg1, pieces(Arg0)); }
	void test_case_1() { int Arg0 = 48; int Arg1 = 2; verify_case(1, Arg1, pieces(Arg0)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 4; verify_case(2, Arg1, pieces(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Stick ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

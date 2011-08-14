#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int G[100001];
class SmoothNumbers {
	public:
	int countSmoothNumbers(int N, int k) {
		int sol = (N>=1 && k>=1);

		G[0] = 0;
		G[1] = 1;
		for (int x=2; x<=N; ++x) {
			for (int d=2; d*d<=x; ++d) {
				if (x%d == 0) {
					G[x] = max(d, G[x/d]);
					break;
				}
			}
			if (G[x] == 0) {
				G[x] = x;
			}
			sol += (G[x] <= k);
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 7; verify_case(0, Arg2, countSmoothNumbers(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 7; verify_case(1, Arg2, countSmoothNumbers(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 3; int Arg2 = 8; verify_case(2, Arg2, countSmoothNumbers(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 20; int Arg2 = 5; verify_case(3, Arg2, countSmoothNumbers(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 100; int Arg2 = 17442; verify_case(4, Arg2, countSmoothNumbers(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SmoothNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

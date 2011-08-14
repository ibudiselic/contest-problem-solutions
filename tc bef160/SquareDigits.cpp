#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class SquareDigits {
	public:
	int sqd(int x) {
		if (x==0) return 0;
		int t = x%10;
		return t*t+sqd(x/10);
	}
	set<int> get_set(int n) {
		set<int> ret;
		for (;;) {
			int t = sqd(n);
			if (ret.find(t)!=ret.end()) break;
			n = t;
			ret.insert(t);
		}
		return ret;
	}
	int smallestResult(int n) {
		int sol = 0;

		for (;;) {
			set<int> s = get_set(sol);
			if (s.find(n)!=s.end()) break;
			++sol;
		}
		return sol;
	}







   // *** WARNING *** No test cases defined for this problem
};

// BEGIN CUT HERE
int main()
    {
    SquareDigits ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

class PointsOnCircle {
	public:
	long long count(int r) {
		vector<long long> D;
		for (long long d=1; d*d<=r; ++d)
			if (r%d == 0) {
				D.push_back(d);
				D.push_back(r/d);
			}

		set<long long> done;
		long long sol = 0;
		for (int i=0; i<(int)D.size(); ++i)
			for (int j=i; j<(int)D.size(); ++j) {
				const long long t = D[i]*D[j];
				if (done.count(t))
					continue;
				done.insert(t);
				switch (t%4) {
					case 1: ++sol; break;
					case 3: --sol; break;
				}
			}

		return 4*sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 4LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2000000000; long long Arg1 = 76LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 1053; long long Arg1 = 12LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PointsOnCircle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

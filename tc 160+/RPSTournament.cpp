#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

int N;
set<int> S;
int bound[(1<<16)+1];

bool canWin(int x, int r) {
	//cerr << x << ' ' << r << '\n';
	if (r == 0)
		return true;

	set<int> active;
	active.insert(x);

	while (r--) {
		vector<int> newActive;
		for (set<int>::iterator it=active.begin(); it!=active.end(); ++it) {
			set<int>::iterator strongestAvailable = S.lower_bound(bound[*it]);
			if (strongestAvailable == S.end())
				return false;

			newActive.push_back(*strongestAvailable);
			S.erase(strongestAvailable);
		}
		active.insert(newActive.begin(), newActive.end());
	}

	return true;
}
class RPSTournament {
	public:
	int greatestSeed(int rounds, int C) {
		N = 1<<rounds;

		bound[0] = 0;
		bound[1] = 1; // can beat everybody
		for (int i=2; i<=N; ++i) {
			int x = max(1, (int)(i-sqrt(C*i))-2);
			while ((long long)(i-x)*(i-x) > C*i)
				++x;
			bound[i] = x;
			//cerr << i << ' ' << bound[i] << '\n';
		}

		int lo = 1, hi = N+1;
		while (lo+1 < hi) {
			int mid = lo + (hi-lo)/2;

			for (int i=1; i<=N; ++i)
				S.insert(i);

			S.erase(mid);

			//cerr << lo << ' ' << hi << ' ' << mid << '\n';
			if (canWin(mid, rounds))
				lo = mid;
			else
				hi = mid;
		}

		return lo;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, greatestSeed(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 6; verify_case(1, Arg2, greatestSeed(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 9; verify_case(2, Arg2, greatestSeed(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 3; int Arg2 = 50; verify_case(3, Arg2, greatestSeed(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 180; int Arg2 = 9755; verify_case(4, Arg2, greatestSeed(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RPSTournament ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

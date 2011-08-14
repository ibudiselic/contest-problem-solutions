#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class RoomNumber {
	public:
	int numberOfSets(int roomNumber) {
		vector<int> cnt(10, 0);
		while (roomNumber > 0) {
			++cnt[roomNumber%10];
			roomNumber /= 10;
		}

		int sol = 0;
		for (int i=0; i<10; ++i)
			if (i!=6 && i!=9)
				sol = max(sol, cnt[i]);

		return max(sol, (cnt[6]+cnt[9]+1)/2);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 122; int Arg1 = 2; verify_case(0, Arg1, numberOfSets(Arg0)); }
	void test_case_1() { int Arg0 = 9999; int Arg1 = 2; verify_case(1, Arg1, numberOfSets(Arg0)); }
	void test_case_2() { int Arg0 = 12635; int Arg1 = 1; verify_case(2, Arg1, numberOfSets(Arg0)); }
	void test_case_3() { int Arg0 = 888888; int Arg1 = 6; verify_case(3, Arg1, numberOfSets(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RoomNumber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt2[5000001];
int cnt3[5000001];
int cnt5[5000001];
/* 	  i!     ---------------       j! * (i-j)! */
class PascalCount {
	public:
	int howMany(int n, int d) {
		if (n < 2)
			return 0;

		memset(cnt2, 0, sizeof cnt2);
		memset(cnt3, 0, sizeof cnt3);
		memset(cnt5, 0, sizeof cnt5);
		for (int i=2; i<=n; ++i) {
			if (i%2 == 0)
				cnt2[i] = cnt2[i/2]+1;
			if (i%3 == 0)
				cnt3[i] = cnt3[i/3]+1;
			if (i%5 == 0)
				cnt5[i] = cnt5[i/5]+1;
		}
		for (int i=2; i<=n; ++i) {
			cnt2[i] += cnt2[i-1];
			cnt3[i] += cnt3[i-1];
			cnt5[i] += cnt5[i-1];
		}

		int sol = 0;
		for (int i=1; i<n; ++i)
			switch (d) {
				case 2: if (cnt2[n] > cnt2[i]+cnt2[n-i]) ++sol; break;
				case 3: if (cnt3[n] > cnt3[i]+cnt3[n-i]) ++sol; break;
				case 4: if (cnt2[n] > cnt2[i]+cnt2[n-i]+1) ++sol; break;
				case 5: if (cnt5[n] > cnt5[i]+cnt5[n-i]) ++sol; break;
				case 6: if (cnt2[n]>cnt2[i]+cnt2[n-i] && cnt3[n]>cnt3[i]+cnt3[n-i]) ++sol; break;
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 1; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 3; int Arg2 = 0; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PascalCount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

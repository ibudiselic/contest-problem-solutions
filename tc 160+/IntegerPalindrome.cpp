#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

long long cnt[19];

class IntegerPalindrome {
	public:
	long long findByIndex(int K) {
		if (K < 9)
			return K+1;

		cnt[0] = 9;
		long long pot10 = 1;
		for (int i=1; i<19; ++i) {
			cnt[i] = cnt[i-1] + 9*pot10;
			if (i%2 == 1)
				pot10 *= 10;
		}
		int i=0;
		for (i=1; i<19; ++i)
			if (cnt[i] > K)
				break;
		long long cur = 1;

		for (int j=0; j<i/2; ++j)
			cur *= 10;

		cur += K-cnt[i-1];
		ostringstream ss;
		ss << cur;
		string s = ss.str();
		string t = s.substr(0, s.size() - (i%2 == 0 ? 1:0));
		reverse(t.begin(), t.end());
		s += t;
		istringstream is(s);
		long long sol;
		is >> sol;
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; long long Arg1 = 9LL; verify_case(0, Arg1, findByIndex(Arg0)); }
	void test_case_1() { int Arg0 = 9; long long Arg1 = 11LL; verify_case(1, Arg1, findByIndex(Arg0)); }
	void test_case_2() { int Arg0 = 19; long long Arg1 = 111LL; verify_case(2, Arg1, findByIndex(Arg0)); }
	void test_case_3() { int Arg0 = 235; long long Arg1 = 13731LL; verify_case(3, Arg1, findByIndex(Arg0)); }
	void test_case_4() { int Arg0 = 23746; long long Arg1 = 137484731LL; verify_case(4, Arg1, findByIndex(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IntegerPalindrome ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

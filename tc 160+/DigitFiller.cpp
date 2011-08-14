#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
enum {
	N = 10000
};
ull a[N], b[N];
ull *p, *q;
class DigitFiller {
	public:
	long long howMany(string k, int num) {
		p = a;
		q = b;
		memset(p, 0, N * sizeof p[0]);
		memset(q, 0, N * sizeof q[0]);
		p[(k[0]-'0')%num] = 1;
		for (int i=1; i<(int)k.size(); ++i) {
			for (int r=0; r<num; ++r)
				if (k[i] == 'X')
					for (int dig=0; dig<10; ++dig)
						q[(10*r+dig)%num] += p[r];
				else
					q[(10*r+k[i]-'0')%num] += p[r];
			ull *t = p; p = q; q = t;
			memset(q, 0, N * sizeof q[0]);
		}
		return p[0];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "8X"; int Arg1 = 9; long long Arg2 = 1LL; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1XX"; int Arg1 = 10; long long Arg2 = 10LL; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "14"; int Arg1 = 7; long long Arg2 = 1LL; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "9999999999999X"; int Arg1 = 3; long long Arg2 = 4LL; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "23X34XX24XX34X"; int Arg1 = 17; long long Arg2 = 58823LL; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DigitFiller ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

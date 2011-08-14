#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int bc(int x) {
	int ret = 0;

	while (x > 0) {
		++ret;
		x &= (x-1);
	}

	return ret;
}
class QuickSums {
	public:
	int minSums(string numbers, int sum) {
		int n = numbers.size()-1;
		int best = 1234567890;

		for (int m=0; m<(1<<n); ++m) {
			long long num = numbers[0]-'0';
			long long cur = 0;

			int t = m<<1;
			for (int i=1; i<=n; ++i)
				if (t & (1<<i)) {
					cur += num;
					num = numbers[i]-'0';
				} else {
					num = (num*10) + numbers[i]-'0';
				}
			cur += num;

			if (cur == sum)
				best = min(best, bc(m));
		}

		return best==1234567890 ? -1 : best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "99999"; int Arg1 = 45; int Arg2 = 4; verify_case(0, Arg2, minSums(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1110"; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, minSums(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0123456789"; int Arg1 = 45; int Arg2 = 8; verify_case(2, Arg2, minSums(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "99999"; int Arg1 = 100; int Arg2 = -1; verify_case(3, Arg2, minSums(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "382834"; int Arg1 = 100; int Arg2 = 2; verify_case(4, Arg2, minSums(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "9230560001"; int Arg1 = 71; int Arg2 = 4; verify_case(5, Arg2, minSums(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    QuickSums ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

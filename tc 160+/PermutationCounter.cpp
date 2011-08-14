#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

long long choose[51][51] = {0};
class PermutationCounter {
	public:
	long long go(const vector<int> &cnt, int n) {
		long long ret = 1;

		for (int i=0; n>0 && i<(int)cnt.size(); ++i) {
			assert(cnt[i] >= 0);
			assert(cnt[i] <= n);
			if (cnt[i]) {
				ret *= choose[cnt[i]][n];
				n -= cnt[i];
			}
		}
		return ret;
	}

	long long count(string n) {
		choose[0][0] = 0;
		choose[0][1] = 1;
		choose[1][1] = 1;

		for (int i=2; i<51; ++i)
			for (int j=0; j<=i; ++j)
				choose[j][i] = choose[j][i-1] + ((j!=0)?choose[j-1][i-1]:0);

		long long sol = 0;
		for (int i=0; i<(int)n.size(); ++i)
			if (n[i]!='0') {
				const int dig = n[i]-'0';
				vector<int> cnt(10, 0);
				for (int j=i+1; j<(int)n.size(); ++j)
					++cnt[n[j]-'0'];

				for (int j=0; j<dig; ++j) {
					if (cnt[j]) {
						--cnt[j]; ++cnt[dig];
						sol += go(cnt, (int)n.size()-i-1);
						--cnt[dig]; ++cnt[j];
					}
				}
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1020"; long long Arg1 = 7LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "50000000000000"; long long Arg1 = 13LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "1030000040000"; long long Arg1 = 1414LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "1901712530271201432987123"; long long Arg1 = 141588146596382454LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PermutationCounter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

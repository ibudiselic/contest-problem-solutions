#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int mFact[2000001]; // smallest factor is a prime number...
int cntFact[2000001];
class RefactorableNumber {
	public:
	int count(int low, int high) {
		memset(mFact, 0, sizeof mFact);

		for (int i=2; i<=high; ++i)
			if (mFact[i] == 0) {
				mFact[i] = i;
				for (long long j = (long long)i*i; j<=high; j+=i)
					mFact[j] = i;
			}

		cntFact[1] = 1;
		for (int i=2; i<=high; ++i) {
			int p = mFact[i];
			int pot = 0;
			int x = i;
			while (x % p == 0) {
				x /= p;
				++pot;
			}
			cntFact[i] = (pot+1)*cntFact[x];
		}

		int sol = 0;
		while (low <= high) {
			sol += (low % cntFact[low] == 0);
			++low;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 100; int Arg2 = 12; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 25; int Arg1 = 35; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 4567; int Arg2 = 315; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RefactorableNumber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

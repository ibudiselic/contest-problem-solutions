#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class KLastNonZeroDigits {
	public:
	string getKDigits(int N, int K) {
		long long fact = 1;
		long long pot10 = 1;

		int t = K;
		while (t--)
			pot10 *= 10;

		bool over = false;
		for (int i=1; i<=N; ++i) {
			fact *= i;
			while (fact % 10 == 0)
				fact /= 10;

			if (fact >= pot10)
				over = true;
			fact %= 100000000000000000LL;
		}

		ostringstream os;
		os << fact%pot10;
		return (over ? string(K-os.str().size(), '0'):"") + os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; string Arg2 = "288"; verify_case(0, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 1; string Arg2 = "2"; verify_case(1, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 3; string Arg2 = "72"; verify_case(2, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 2; string Arg2 = "04"; verify_case(3, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 9; string Arg2 = "200817664"; verify_case(4, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "1"; verify_case(5, Arg2, getKDigits(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    KLastNonZeroDigits ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

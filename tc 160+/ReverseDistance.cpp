#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long pot10[18];
int n;
long long factor(int k) {
	return pot10[n-1-k] - pot10[k];
}
long long calc(long long diff, int pos, bool firstDigit) {
	if (pos >= n/2)
		return (diff==0 ? 0 : -1);

	bool usedDigDiff[20] = {0};
	for (int l=firstDigit; l<10; ++l) {
		long long curBest = 123456789012345678LL;
		long long ret = -1;
		for (int r=0; r<10; ++r) {
			int d = l-r;
			if (!usedDigDiff[d+9]) {
				usedDigDiff[d+9] = 1;
				long long t = calc(diff - d*factor(pos), pos+1, 0);
				if (t!=-1 && t<curBest) {
					curBest = t;
					ret = pot10[(n-1-pos) - pos]*l + t*10 + r;
				}
			}
		}
		if (ret != -1)
			return ret;
	}
	return -1;
}
string str(long long x) {
	ostringstream os;
	os << x;
	return os.str();
}
class ReverseDistance {
	public:
	string find(int difference) {
		pot10[0] = 1;
		for (int i=1; i<18; ++i)
			pot10[i] = pot10[i-1]*10;

		for (n=2; n<=12; ++n) {
			long long t = calc(difference, 0, 1);
			if (t != -1)
				return str(t);
		}

		return "NONE";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 18; string Arg1 = "20"; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 15; string Arg1 = "NONE"; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 4275; string Arg1 = "5080"; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 900; string Arg1 = "101001"; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { int Arg0 = 1989; string Arg1 = "100990"; verify_case(4, Arg1, find(Arg0)); }
	void test_case_5() { int Arg0 = 857232; string Arg1 = "860300"; verify_case(5, Arg1, find(Arg0)); }
	void test_case_6() { int Arg0 = 45; string Arg1 = "50"; verify_case(6, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ReverseDistance ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

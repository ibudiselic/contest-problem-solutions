#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N, K, A;
string sol;
bool test(int n) {
	for (int l=1; l<n; ++l)
		for (int i=0; i+l<=n; ++i) {
			int j = i;
			while (j+l<=n && sol.substr(i, l)==sol.substr(j, l))
				j += l;
			if ((j-i)/l >= K)
				return false;
			i = j-l;
		}
	return true;
}
bool go(int x) {
	if (x == N)
		return test(N);

	for (char c='A'; c<'A'+A; ++c) {
		sol[x] = c;
		if (test(x+1) && go(x+1))
			return true;
	}
	return false;
}
class UnrepeatableWords {
	public:
	string getWord(int k, int n, int allowed) {
		K = k;
		N = n;
		A = allowed;
		sol.assign(n, ' ');

		if (go(0))
			return sol;

		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 2; string Arg3 = "AABAA"; verify_case(0, Arg3, getWord(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; string Arg3 = ""; verify_case(1, Arg3, getWord(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 2; string Arg3 = "AABAABABAA"; verify_case(2, Arg3, getWord(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 50; int Arg2 = 2; string Arg3 = "AABAABABAABAABBAABAABABAABAABBAABAABABAABABBAABAAB"; verify_case(3, Arg3, getWord(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UnrepeatableWords ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long a, b;
int sol;
long long merge(long long left, long long right, long long pot10) {
	double x = double(left)*pot10 + right;
	if (x > b+1000000000)
		return -1;
	return left*pot10 + right;
}
inline bool test(long long x) {
	return a<=x && x<=b;
}
void goMid(long long left, long long right, long long pot10) {
	sol += test(merge(left, right, pot10*10));
	sol += test(merge(left, right + pot10*1, pot10*10));
	sol += test(merge(left, right + pot10*8, pot10*10));
}
void goDouble(int pos, long long left, long long right, long long pot10) {
	if (pos > 9)
		return;
	sol += test(merge(left, right, pot10));

	if (pos > 0)
		goDouble(pos+1, left*10 + 0, right, pot10*10);
	goDouble(pos+1, left*10 + 1, right + pot10 * 1, pot10*10);
	goDouble(pos+1, left*10 + 8, right + pot10 * 8, pot10*10);
	goDouble(pos+1, left*10 + 2, right + pot10 * 5, pot10*10);
	goDouble(pos+1, left*10 + 5, right + pot10 * 2, pot10*10);

	goMid(left, right, pot10);
}
class MirrorNumber {
	public:
	int count(string A, string B) {
		{
			istringstream is(A);
			is >> a;
		}
		{
			istringstream is(B);
			is >> b;
		}

		sol = 0;

		goDouble(0, 0, 0, 1);

		return sol-(a==0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0"; string Arg1 = "10"; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "0"; string Arg1 = "100"; int Arg2 = 7; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "143"; string Arg1 = "23543"; int Arg2 = 54; verify_case(2, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MirrorNumber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

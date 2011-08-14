#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (a==0) return b;
	else return gcd(b%a, a);
}
class Synchro {
	public:
	double resynch(vector <int> watch) {
		sort(watch.begin(), watch.end());
		watch.erase(unique(watch.begin(), watch.end()), watch.end());

		if (watch.size() == 1)
			return 0;

		long long g = watch[1]-watch[0];
		for (int i=2; i<(int)watch.size(); ++i) g = gcd(g, watch[i]-watch[0]);
		double hr = 60.0/g;
		return fmod(watch[0]*hr, 60.0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {59,59,59}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(0, Arg1, resynch(Arg0)); }
	void test_case_1() { int Arr0[] = {60,53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 34.28571428571427; verify_case(1, Arg1, resynch(Arg0)); }
	void test_case_2() { int Arr0[] = {120,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 30.0; verify_case(2, Arg1, resynch(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 4, 8, 16, 32, 64, 128}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, resynch(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Synchro ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

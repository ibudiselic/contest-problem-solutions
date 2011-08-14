#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> V;
double sol;
int N;

void go(int pos, int n, int sum, int cnt, double m, double M) {
	if (M-m >= sol)
		return;

	if (n == 0) {
		if (pos == (int)V.size())
			sol = min(sol, M-m);
		return;
	}

	const double t = double(sum+V[pos])/(cnt+1);
	go(pos+1, n-1, 0, 0, min(m, t), max(M, t));
	if ((int)V.size()-pos >= n)
		go(pos+1, n, sum+V[pos], cnt+1, m, M);
}
class GroupingNumbers {
	public:
	double minRange(vector <int> numbers, int n) {
		V = numbers;
		N = n;
		sol = 1e32;

		sort(V.begin(), V.end());
		do
			go(0, N, 0, 0, 1e10, -1e10);
		while (next_permutation(V.begin(), V.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,99,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.0; verify_case(0, Arg2, minRange(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,3,3,3,3,3,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 0.0; verify_case(1, Arg2, minRange(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,3,5,7,11,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 0.33333333333333304; verify_case(2, Arg2, minRange(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 2, 998, 667}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.0; verify_case(3, Arg2, minRange(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GroupingNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

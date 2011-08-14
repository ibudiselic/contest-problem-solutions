#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;

int dist(int a, int b, int x, int y) {
	return abs(x-a) + abs(y-b);
}
int calc(int a, int b, const vector<int> &x, const vector<int> &y) {
	int ret = 0;
	for (int i=0; i<(int)x.size(); ++i)
		ret += dist(a, b, x[i], y[i]);

	return ret;
}
class TournamentPlan {
	public:
	int getTravelDistance(vector <int> X, vector <int> Y) {
		set<int> x(X.begin(), X.end());
		set<int> y(Y.begin(), Y.end());

		for (int i=0; i<(int)X.size(); ++i)
			for (int j=i+1; j<(int)X.size(); ++j) {
				int sum = X[i] + X[j];
				x.insert(sum/2);
				if (sum%2 == 1)
					x.insert((sum+1)/2);
				sum = Y[i] + Y[j];
				y.insert(sum/2);
				if (sum%2 == 1)
					y.insert((sum+1)/2);
			}

		int sol = 1234567890;

		vector<int> A(x.begin(), x.end());
		vector<int> B(y.begin(), y.end());
		for (int i=0; i<(int)A.size(); ++i)
			for (int j=0; j<(int)B.size(); ++j)
				sol = min(sol, calc(A[i], B[j], X, Y));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,0,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,2,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, getTravelDistance(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2000000; verify_case(1, Arg2, getTravelDistance(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, getTravelDistance(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, getTravelDistance(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TournamentPlan ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

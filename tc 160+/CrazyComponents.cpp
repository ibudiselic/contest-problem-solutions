#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool done[50][1<<15];
double dp[50][1<<15];
int N;
vector<int> I, E, M;
double go(int k, int have) {
	if (k == -1)
		return 0.0;
	if (done[k][have])
		return dp[k][have];

	done[k][have] = 1;
	double &ret = dp[k][have];

	ret = 0.0;

	for (int i=0; i<N; ++i)
		if ((have & M[i]) == M[i])
			ret += max(go(k-1, have), I[i]-E[i] + go(k-1, (have | (1<<i))));
		else
			ret += go(k-1, have);

	ret /= N;

	return ret;
}

class CrazyComponents {
	public:
	double expectedProfit(int k, vector <string> components, vector <int> income, vector <int> expense) {
		N = components.size();
		I = income;
		E = expense;
		memset(done, 0, sizeof done);
		M.assign(N, 0);

		for (int i=0; i<N; ++i) {
			istringstream is(components[i]);
			int x;
			while (is >> x)
				M[i] |= (1<<x);
		}

		return go(k-1, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arr1[] = { "", "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1.5; verify_case(0, Arg4, expectedProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = { "1", "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 10, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1.5; verify_case(1, Arg4, expectedProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = { "1 2", "", "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 100, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 7.407407407407408; verify_case(2, Arg4, expectedProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; string Arr1[] = { "1", "2", "0", "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 4, 5, 6, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 0, 0, 8 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.0; verify_case(3, Arg4, expectedProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10; string Arr1[] = { "", "", "", "", "", "", "", "", "", "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 142352, 2342, 34534, 2344, 12346, 7589, 79872, 973453, 96233, 34567 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 12432, 2345, 3678, 456, 345, 457, 56758, 4564, 774, 34567 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1269258.9999999998; verify_case(4, Arg4, expectedProfit(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CrazyComponents ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

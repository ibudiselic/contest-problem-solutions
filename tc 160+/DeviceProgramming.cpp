#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<long long> O, S;
long long M, OV;
long long dp[52][1001];

long long go(int pos, int n) {
	long long &ret = dp[pos][n];
	if (ret != -1)
		return ret;
	if (pos == (int)O.size())
		return (ret = 0);

	long long next = O[pos-1]+S[pos-1]+n;
	long long start = max(O[pos], next);
	long long cnt = (O[pos]+S[pos] - start + M-1)/M;

	long long max_end = start + cnt*M;
	long long max_cost = cnt*(OV+M);
	ret = 123456789123456789LL;
	for (long long x=O[pos]+S[pos]; x<=max_end; ++x)
		ret = min(ret, max_cost-(max_end-x) + go(pos+1, x-(O[pos]+S[pos])));

	return ret;
}
class DeviceProgramming {
	public:
	long long minBytes(vector <int> offset, vector <int> size, int maxPacketSize, int overhead) {
		O.clear();
		S.clear();
		O.push_back(-1);
		S.push_back(1);

		for (int i=0; i<(int)offset.size(); ++i) {
			O.push_back(offset[i]);
			S.push_back(size[i]);
		}
		for (int i=0; i<(int)O.size(); ++i)
			for (int j=i+1; j<(int)O.size(); ++j)
				if (O[i] > O[j]) {
					swap(O[i], O[j]);
					swap(S[i], S[j]);
				}
		OV = overhead;
		M = maxPacketSize-OV;

		memset(dp, 0xff, sizeof dp);

		return go(1, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 42, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 15, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 26; int Arg3 = 6; long long Arg4 = 78LL; verify_case(0, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0, 42, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 15, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 26; int Arg3 = 6; long long Arg4 = 92LL; verify_case(1, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0, 2, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 5; long long Arg4 = 26LL; verify_case(2, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {10264, 111, 357, 100066, 714}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {117, 134, 235, 2395, 23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 10; long long Arg4 = 3254LL; verify_case(3, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1, 100000000, 450000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99999999, 315000000, 500000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 30; long long Arg4 = 943298999LL; verify_case(4, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0, 1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 999; long long Arg4 = 2000000000000LL; verify_case(5, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DeviceProgramming ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

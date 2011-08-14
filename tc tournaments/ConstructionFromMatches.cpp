#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[50][13][13];
vector<int> T, B, C;
int go(int pos, int t, int b) {
	if (pos == (int)T.size())
		return 0;
	if (t >= T[pos] || b >= B[pos])
		return 123456789;

	if (dp[pos][t][b] != -1)
		return dp[pos][t][b];
	int &ret = dp[pos][t][b];

	ret = 123456789;
	for (int i=1; i<=(int)C.size(); ++i) {
		if (t+i >= T[pos])
			break;
		for (int j=1; j<=(int)C.size(); ++j) {
			if (b+j >= B[pos])
				break;
			for (int mid=1; mid<=(int)C.size(); ++mid) {
				if (t+i+mid >= T[pos] || b+j+mid >= B[pos])
					break;
				int tt = (T[pos]-(t+i+mid));
				int bb = (B[pos]-(b+j+mid));
				if (tt > (int)C.size() || bb > (int)C.size())
					continue;

				ret = min(ret, go(pos+1, i, j) + C[i-1]+C[j-1]+C[mid-1]+C[tt-1]+C[bb-1]);
			}
		}
	}
	return ret;
}
class ConstructionFromMatches {
	public:
	int minimumCost(vector <int> cost, vector <int> top, vector <int> bottom) {
		T = top;
		B = bottom;
		C = cost;
		memset(dp, 0xff, sizeof dp);

		int t = 123456789;
		for (int i=1; i<=(int)C.size(); ++i)
			for (int j=1; j<=(int)C.size(); ++j)
				t = min(t, go(0, i, j) + C[i-1]+C[j-1]);

		return (t>=123456789 ? -1 : t);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, minimumCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minimumCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 5, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 56; verify_case(2, Arg3, minimumCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 3, 4, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13, 14, 13, 11, 9, 7, 11, 8, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {18, 14, 17, 10, 8, 4, 8, 13, 14, 13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 194; verify_case(3, Arg3, minimumCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ConstructionFromMatches ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

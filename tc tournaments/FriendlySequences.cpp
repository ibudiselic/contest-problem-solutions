#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

bool F[50][50];
set<int> s(int x) {
	set<int> ret;
	do {
		ret.insert(x%10);
		x /= 10;
	} while (x != 0);
	return ret;
}
bool f(int x, int y) {
	return s(x) == s(y);
}
bool is_friendly(const vector<int> &v, int l, int r) {
	for (int i=l; i<r; ++i)
		for (int j=i+1; j<r; ++j)
			if (!F[i][j])
				return false;
	return true;
}
class FriendlySequences {
	public:
	int count(vector <int> array) {
		memset(F, 0, sizeof F);
		for (int i=0; i<(int)array.size(); ++i)
			for (int j=i+1; j<(int)array.size(); ++j)
				F[i][j] = f(array[i], array[j]);

		int sol = 0;


		for (int i=0; i<(int)array.size(); ++i)
			for (int j=i+2; j<=(int)array.size(); ++j)
				sol += is_friendly(array, i, j);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {112, 12, 21, 354, 534345, 345, 2221}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 1100, 10101, 111, 1111, 11111, 11, 1, 111}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {123456890, 213456890, 198654320} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FriendlySequences ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

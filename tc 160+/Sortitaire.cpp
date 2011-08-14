#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> T, S;
bool dp[50][50][100];
bool done[50][50][100];

bool go(int posT, int posS, int last) {
	if (posT == (int)T.size())
		return true;
	if (done[posT][posS][last])
		return dp[posT][posS][last];

	done[posT][posS][last] = 1;
	bool &ret = dp[posT][posS][last];

	ret = (T[posT]>=last) && go(posT+1, posS, T[posT]); // don't change this one...

	if (!ret && posS<(int)S.size())
		ret |= (S[posS]>=last) && go(posT+1, posS+1, S[posS]); // change this one to posSth element

	if (!ret && posS+1<(int)S.size())
		ret |= go(posT, posS+1, last);

	return ret;
}
class Sortitaire {
	public:
	int turns(vector <int> tableau, vector <int> stock) {
		T = tableau;
		S.clear();
		memset(done, 0, sizeof done);

		if (go(0, 0, 0))
			return 0;

		for (int i=0; i<(int)stock.size(); ++i) {
			int j = 0;
			while (j<(int)S.size() && S[j]<stock[i])
				++j;
			S.insert(S.begin()+j, stock[i]);

			memset(done, 0, sizeof done);
			if (go(0, 0, 0))
				return i+1;
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 25, 19, 41, 36, 28, 40 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 27, 36, 24, 39, 30 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, turns(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 1, 1, 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, turns(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 5, 4, 3, 2, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 20, 40 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, turns(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 40, 50, 60, 70, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 7, 6, 5, 4, 3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, turns(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 19, 7, 23, 38, 23, 90, 81, 22, 71, 30, 87,
  32, 99, 5, 80, 17, 19, 43, 67, 50, 88, 11 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 24, 89, 70, 35, 55, 43, 92, 10, 33, 18, 8,
  40, 14, 22, 56, 4, 98, 57, 89, 31, 30, 14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 19; verify_case(4, Arg2, turns(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Sortitaire ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

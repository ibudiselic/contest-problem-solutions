#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
inline int index(int i, int j, int k) {
	return i*9 + j*3 + k;
}
int calc(const vector<int> &v) {
	int m = 1234567890;
	int M = 0;

	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j) {
			int x = 0;
			for (int k=0; k<3; ++k)
				x += v[index(i, j, k)];
			m = min(m, x);
			M = max(M, x);
		}
	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j) {
			int x = 0;
			for (int k=0; k<3; ++k)
				x += v[index(k, i, j)];
			m = min(m, x);
			M = max(M, x);
		}
	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j) {
			int x = 0;
			for (int k=0; k<3; ++k)
				x += v[index(j, k, i)];
			m = min(m, x);
			M = max(M, x);
		}

	return M-m;
}
class MagicCube {
	public:
	int getScore(vector <int> nums) {
		int best = calc(nums);

		for (int i=0; i<27; ++i)
			for (int j=i+1; j<27; ++j) {
				swap(nums[i], nums[j]);
				best = min(best, calc(nums));
				swap(nums[i], nums[j]);
			}

		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getScore(Arg0)); }
	void test_case_1() { int Arr0[] = {23,4,10,1,27,21,25,7,17,9,15,13,20,3,11,2,22,18,12,24,14,26,8,6,5,19,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(1, Arg1, getScore(Arg0)); }
	void test_case_2() { int Arr0[] = {23,2,10,1,27,21,25,7,17,9,15,13,20,3,11,4,22,18,12,24,14,26,8,6,5,19,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(2, Arg1, getScore(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MagicCube ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

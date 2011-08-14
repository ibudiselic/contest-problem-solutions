#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class MNS {
	public:
	int perm(int x) {
		int ret = 1;
		for (int i=2; i<=x; ++i)
			ret *= i;
		return ret;
	}
	int combos(vector <int> num) {
		sort(num.begin(), num.end());
		int sol = 0;
		do {
			int t = num[0]+num[1]+num[2];
			if (num[3]+num[4]+num[5] != t) continue;
			if (num[6]+num[7]+num[8] != t) continue;
			if (num[0]+num[3]+num[6] != t) continue;
			if (num[1]+num[4]+num[7] != t) continue;
			if (num[2]+num[5]+num[8] != t) continue;

			++sol;
		} while (next_permutation(num.begin(), num.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,3,2,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(0, Arg1, combos(Arg0)); }
	void test_case_1() { int Arr0[] = {4,4,4,4,4,4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, combos(Arg0)); }
	void test_case_2() { int Arr0[] = {1,5,1,2,5,6,2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(2, Arg1, combos(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,6,6,6,4,2,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, combos(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MNS ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

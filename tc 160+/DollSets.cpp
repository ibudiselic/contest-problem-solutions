#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DollSets {
	public:
	int maximumQuantity(vector <int> dollSizes, int K) {
		sort(dollSizes.begin(), dollSizes.end());
		int sol = 0;
		vector<int> used(dollSizes.size(), 0);
		for (int i=0; i<(int)dollSizes.size(); ++i) {
			if (!used[i]) {
				for (int j=i+1; j<(int)dollSizes.size(); ++j)
					if (!used[j] && (long long)dollSizes[i]*K == dollSizes[j]) {
						used[i] = used[j] = 1;
						++sol;
						goto kraj;
					}
			}
			kraj: ;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,1,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, maximumQuantity(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(1, Arg2, maximumQuantity(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,4,1,2,3,4,5,67,8,9,8,7,15,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(2, Arg2, maximumQuantity(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; int Arg2 = 0; verify_case(3, Arg2, maximumQuantity(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,9,81,729,1,81}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 2; verify_case(4, Arg2, maximumQuantity(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(5, Arg2, maximumQuantity(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DollSets ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

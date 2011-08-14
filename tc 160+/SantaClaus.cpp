#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int e[50][50], d1[50][50], d2[50][50];
class SantaClaus {
	public:
	vector <int> exchange(vector <string> value) {
		int n = value.size();

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				e[i][j] = value[i][j] - value[i][i];

		memcpy(d1, e, sizeof d1);
		for (int len=2; len<=n; ++len) {
			for (int i=0; i<n; ++i)
				for (int j=0; j<n; ++j) {
					int d = -1234567890;
					for (int k=0; k<n; ++k)
						d = max(d, d1[i][k] + e[k][j]);
					d2[i][j] = d;
				}
			memcpy(d1, d2, sizeof d1);
			int best = 0;
			for (int i=0; i<n; ++i)
				best = max(best, d1[i][i]);
			if (best > 0) {
				vector<int> sol(2, 0);
				sol[0] = len;
				sol[1] = best;
				return sol;
			}
		}

		return vector<int>(2, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ABCDE","ABCDE","ABCDE","ABCDE","ABCDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, exchange(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABC","BCD","ZAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 26 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, exchange(Arg0)); }
	void test_case_2() { string Arr0[] = {"BCAAA","ADEAA","AAXYA","AAAKL","EAAAD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, exchange(Arg0)); }
	void test_case_3() { string Arr0[] = {"VWAAA","ADEAA","AAXYA","AAAKL","EAAAD"}  ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, exchange(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SantaClaus ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

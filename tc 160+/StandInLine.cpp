#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class StandInLine {
	public:
	vector <int> reconstruct(vector <int> left) {
		vector<int> order(left.size(), 0);
		for (int i=0; i<(int)left.size(); ++i)
			order[i] = i+1;

		vector<int> cnt(left.size(), 0);
		do {
			bool ok = true;
			for (int i=0; i<(int)cnt.size(); ++i) {
				cnt[i] = 0;
				for (int j=i-1; j>=0; --j)
					cnt[i] += (order[j]>order[i]);
				if (cnt[i] != left[order[i]-1]) {
					ok = false;
					break;
				}
			}
			if (ok)
				return order;
		} while (next_permutation(order.begin(), order.end()));

		return vector<int>();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2, 1, 1, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { int Arr0[] = {5, 4, 3, 2, 1, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 5, 4, 3, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { int Arr0[] = {6, 1, 1, 1, 2, 0, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 2, 3, 4, 7, 5, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reconstruct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StandInLine ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

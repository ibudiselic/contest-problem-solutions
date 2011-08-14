#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(const vector<int> &v) {
	int ret = 0;
	for (int i=0; i<(int)v.size(); ++i) {
		for (int j=i+1; j<(int)v.size(); ++j) {
			if (v[j] <= v[j-1]) {
				ret = max(ret, j-i);
				i = j - 1;
				break;
			} else if (j+1 == (int)v.size()) {
				ret = max(ret, j-i+1);
			}
		}
	}

	return ret;
}
class MonotoneSequence {
	public:
	int longestMonotoneSequence(vector <int> seq) {
		if (seq.size() == 1) {
			return 1;
		}
		int sol = calc(seq);
		reverse(seq.begin(), seq.end());
		sol = max(sol, calc(seq));
	
		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 7, 7, 8, 3, 6, 7, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, longestMonotoneSequence(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, longestMonotoneSequence(Arg0)); }
	void test_case_2() { int Arr0[] = {10, 20, 30, 25, 20, 19, 20, 18, 23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, longestMonotoneSequence(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 2, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, longestMonotoneSequence(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MonotoneSequence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

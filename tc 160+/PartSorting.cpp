#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class PartSorting {
	public:
	vector <int> process(vector <int> data, int nSwaps) {
		vector<int> sol;
		vector<bool> used(data.size(), false);
		data.push_back(-1);
		for (int i=0; i<(int)data.size()-1; ++i) {
			int besti = data.size()-1;
			int cnt = 0;
			for (int j=0; j<(int)data.size()-1; ++j) {
				if (!used[j] && data[j]>data[besti] && cnt<=nSwaps)
					besti = j;
				if (!used[j])
					++cnt;
			}
			if (besti == (int)data.size()-1)
				break;
			used[besti] = 1;
			for (int j=0; j<besti; ++j)
				if (!used[j])
					--nSwaps;
			sol.push_back(data[besti]);
		}

		for (int i=0; i<(int)data.size()-1; ++i)
			if (!used[i])
				sol.push_back(data[i]);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {10, 20, 30, 40, 50, 60, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {20, 10, 30, 40, 50, 60, 70 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, process(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3, 5, 1, 2, 4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {5, 3, 2, 1, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, process(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {19, 20, 17, 18, 15, 16, 13, 14, 11, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, process(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PartSorting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

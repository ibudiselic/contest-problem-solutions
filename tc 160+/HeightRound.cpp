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
	int ret = abs(v.back()-v[0]);
	for (int i=1; i<(int)v.size(); ++i)
		ret = max(ret, abs(v[i]-v[i-1]));
	return ret;
}
class HeightRound {
	public:
	vector <int> getBestRound(vector <int> heights) {
		sort(heights.begin(), heights.end());

		for (int diff=0; diff<heights.back()-heights[0]; ++diff) {
			vector<bool> used(heights.size(), 0);
			int cur = heights[0];
			int start = 1;
			vector<int> v;
			while (cur+diff < heights.back()) {
				int i = start;
				while (cur+diff >= heights[i])
					++i;
				--i;
				if (i < start)
					goto NEXT;
				used[i] = i;
				start = i+1;
				cur = heights[i];
				v.push_back(heights[i]);
			}
			v.push_back(heights.back());
			for (int i=(int)heights.size()-2; i>=0; --i)
				if (!used[i])
					v.push_back(heights[i]);
			if (calc(v) <= diff) {
				reverse(v.begin(), v.end());
				return v;
			}
			NEXT:;
		}

		return heights;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getBestRound(Arg0)); }
	void test_case_1() { int Arr0[] = {1000,500,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 500, 1000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getBestRound(Arg0)); }
	void test_case_2() { int Arr0[] = {1,3,4,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 5, 7, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getBestRound(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getBestRound(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HeightRound ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

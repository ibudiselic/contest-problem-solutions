#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

class StackingBoxes {
	public:
	int highestStack(vector <string> weight, vector <string> canCarry) {
		vector<int> w;
		vector<int> c;
		for (int i=0; i<(int)weight.size(); ++i) {
			istringstream is(weight[i]);
			int x;
			while (is >> x)
				w.push_back(x);
		}
		for (int i=0; i<(int)canCarry.size(); ++i) {
			istringstream is(canCarry[i]);
			int x;
			while (is >> x)
				c.push_back(x);
		}

		int n = w.size();
		vector< pair<int, int> > v;
		for (int i=0; i<n; ++i)
			v.push_back(make_pair(w[i]+c[i], w[i]));

		sort(v.begin(), v.end());
		vector<int> bestW(n+1, 1234567890);
		bestW[0] = 0;
		for (int i=0; i<n; ++i)
			for (int stackSz=i+1; stackSz>0; --stackSz)
				if (v[i].first-v[i].second >= bestW[stackSz-1])
					bestW[stackSz] = min(bestW[stackSz], bestW[stackSz-1] + v[i].second);

		for (int i=n; i>=0; --i)
			if (bestW[i] < 1234567890)
				return i;
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10 20 30"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"11", "100 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, highestStack(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"11 20 30"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"11", "100 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, highestStack(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"10", "20", "91"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"11", "100 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, highestStack(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"100000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, highestStack(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"100 100", "1000 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"90", "91 92 93"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, highestStack(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"200 200 600 700 400"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1000 20 150 700 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(5, Arg2, highestStack(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StackingBoxes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

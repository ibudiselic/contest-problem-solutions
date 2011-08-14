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

class HardDequeSort {
	public:
	bool possible(const vector< pair<int, int> > &v, int start, int end) {
		vector< pair<int, int> > t;
		for (int i=start; i<end; ++i)
			t.push_back(make_pair(v[i].second, v[i].first));

		sort(t.begin(), t.end());
		int l = t[0].second;
		int r = t[0].second;

		for (int i=1; i<(int)t.size(); ++i) {
			if (l<t[i].second && t[i].second<r)
				return false;
			l = min(l, t[i].second);
			r = max(r, t[i].second);
		}

		return true;
	}
	int minDeques(vector <int> data) {
		vector< pair<int, int> > v;
		for (int i=0; i<(int)data.size(); ++i)
			v.push_back(make_pair(data[i], i));

		sort(v.begin(), v.end());
		int sol = 0;
		int start = 0;
		while (start < (int)data.size()) {
			for (int end=start+1; end<=(int)data.size(); ++end)
				if (!possible(v, start, end)) {
					start = end-1;
					break;
				} else if (end==(int)data.size()) {
					start = end;
				}
			++sol;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {50, 45, 55, 60, 45, 65,
 40, 70, 70, 35, 30, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minDeques(Arg0)); }
	void test_case_1() { int Arr0[] = {3, 6, 0, 9, 6, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minDeques(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 2, 1, 4, 3, 6, 5, 8, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, minDeques(Arg0)); }
	void test_case_3() { int Arr0[] = {454,537,7,976,537,908,976,908,-94,454,908,64,454,-731,908,-646,537}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minDeques(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HardDequeSort ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

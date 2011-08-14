#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt[50];
int num[50];
vector<int> sol;
int n;

bool go(int x, int start) {
	if (x == (int)sol.size())
		return true;

	for (int i=0; i<n; ++i)
		if (num[i]!=start+1 && cnt[i]>0) {
			--cnt[i];
			sol[x] = num[i];
			if (go(x+1, num[i]))
				return true;
			++cnt[i];
		}
	return false;
}
class WeirdSort {
	public:
	vector <int> sortArray(vector <int> data) {
		sort(data.begin(), data.end());

		memset(cnt, 0, sizeof cnt);
		memset(num, 0, sizeof num);
		n = 0;
		for (int i=0; i<(int)data.size(); ++i) {
			const int x = data[i];
			int cur = 0;
			int j = i;
			while (j<(int)data.size() && data[j]==x) {
				++cur;
				++j;
			}
			i = j-1;
			cnt[n] = cur;
			num[n++] = x;
		}

		sol.assign(data.size(), 0);
		go(0, -2);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortArray(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortArray(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1, 1, 1, 2, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2, 2, 2, 1, 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortArray(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 2, 4, 6, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortArray(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 1, 2, 2, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 3, 3, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, sortArray(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WeirdSort ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> W;
vector<string> S;
int me;
int sol;

int f(int x, const vector<int> &order, int val) {
	int ret = 0;
	int i = 0;
	while (i<(int)order.size() && val >= 0) {
		if (S[x][order[i]] > '1') {
			val -= W[order[i]];
			++ret;
		}
		++i;
	}

	return val<0 ? ret : 1234;
}
int calc() {
	vector<int> order(W.size(), 0);
	for (int i=0; i<(int)order.size(); ++i)
		order[i] = i;

	for (int i=0; i<(int)order.size(); ++i)
		for (int j=i+1; j<(int)order.size(); ++j)
			if (W[order[i]] < W[order[j]])
				swap(order[i], order[j]);

	vector<int> scores(S.size(), 0);
	for (int i=0; i<(int)scores.size(); ++i)
		for (int j=0; j<(int)W.size(); ++j)
			scores[i] += W[j]*(S[i][j]-'0');

	int x = me;
	vector<int> best(S.size(), 0);
	for (int i=0; i<(int)best.size(); ++i)
		best[i] = i;

	for (int i=0; i<(int)scores.size(); ++i)
		for (int j=i+1; j<(int)scores.size(); ++j)
			if (scores[best[i]] < scores[best[j]]) {
				if (x == i)
					x = j;
				else if (x == j)
					x = i;

				swap(best[i], best[j]);
			}

	if (x == 0)
		return 0;

	assert(me == best[x]);

	int curVal = scores[me];
	int done = 0;
	int tt = 0;
	for (int j=0; j<x; ++j)
		tt += f(best[j], order, scores[best[j]]-curVal);
	int ret = tt;
	for (int i=0; i<(int)order.size(); ++i)
		if (S[me][order[i]] < '9') {
			++done;
			curVal += W[order[i]];

			int add = 0;
			for (int j=0; j<x; ++j)
				add += f(best[j], order, scores[best[j]]-curVal);

			ret = min(ret, done+add);
		}

	return ret;
}
void go(int pos, int cnt) {
	if (pos == (int)W.size()) {
		sol = min(sol, cnt + calc());
		return;
	}

	go(pos+1, cnt);
	if (W[pos] > 1) {
		--W[pos];
		go(pos+1, cnt+1);
		++W[pos];
	}
	if (W[pos] < 9) {
		++W[pos];
		go(pos+1, cnt+1);
		--W[pos];
	}
}
class Rationalization {
	public:
	int minTweaks(vector <int> weights, vector <string> scores, int desired) {
		me = desired;
		S = scores;
		W = weights;

		sol = 1234;
		go(0, 0);

		return sol<1234 ? sol : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 3, 2, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "6354",
  "5532",
  "4626" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 3, 2, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "6354",
  "5532",
  "4626" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(1, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 3, 2, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "555",
  "333" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = -1; verify_case(2, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "9234",
  "1334" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 3; verify_case(3, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = { 8, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "55",
  "92" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 6; verify_case(4, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = { 2, 8, 7, 3, 6, 5, 2, 4, 7, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "9197287893", "9492555365", "3459972761", "4886112198", "5963616776",
  "6325897129", "3248793133", "7984474438", "4518544769", "1592681682" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 17; verify_case(5, Arg3, minTweaks(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Rationalization ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

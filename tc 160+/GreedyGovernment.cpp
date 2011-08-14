#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool v[10];
int cnt[100];
vector<string> T;
int N;
int total;
int count_;
int P[10];
#define PATH(x, y) ((x)*N + (y))
void go(int pos, int len, int w) {
	if (pos == N-1) {
		++count_;
		total += w;
		P[len] = pos;
		for (int i=0; i<len; ++i)
			++cnt[PATH(P[i], P[i+1])];
		return;
	}
	P[len] = pos;
	v[pos] = true;
	for (int i=0; i<N; ++i)
		if (!v[i] && T[pos][i]!='X')
			go(i, len+1, w+T[pos][i]-'0');
	v[pos] = false;
}
class GreedyGovernment {
	public:
	double maxAverageCost(vector <string> tolls, int tollHike) {
		T = tolls;
		N = T.size();
		total = count_ = 0;

		memset(cnt, 0, sizeof cnt);
		memset(v, 0, sizeof v);
		P[0] = 0;
		go(0, 0, 0);

		if (count_ == 0)
			return 0;

		int best = max_element(cnt, cnt+100) - cnt;

		return double(total + cnt[best]*tollHike)/count_;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X324", "XXX2", "12X5", "991X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; double Arg2 = 10.0; verify_case(0, Arg2, maxAverageCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"X324", "5X22", "12X5", "991X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 57; double Arg2 = 29.2; verify_case(1, Arg2, maxAverageCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"X11", "2X1", "37X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 76; double Arg2 = 39.5; verify_case(2, Arg2, maxAverageCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"X32X", "XXXX", "XXXX", "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; double Arg2 = 0.0; verify_case(3, Arg2, maxAverageCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GreedyGovernment ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

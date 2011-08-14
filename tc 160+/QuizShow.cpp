#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool isWin(const vector<int> &s) {
	return s[0] > s[1] && s[0] > s[2];
}
int winProb(const vector<int> &s, const vector<int> &w) {
	int ret = 0;

	for (int mask=0; mask<8; ++mask) {
		vector<int> ss = s;
		for (int i=0; i<3; ++i)
			if (mask & (1<<i))
				ss[i] += w[i];
			else
				ss[i] -= w[i];
		ret += isWin(ss);
	}

	return ret;
}
class QuizShow {
	public:
	int wager(vector <int> scores, int wager1, int wager2) {
		vector<int> w(3, 0);
		w[1] = wager1;
		w[2] = wager2;
		int prob = 0;
		int best = 0;
		for (int i=0; i<=scores[0]; ++i) {
			w[0] = i;
			const int t = winProb(scores, w);
			if (t > prob) {
				prob = t;
				best = i;
			}
		}
		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 100, 100, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; int Arg2 = 75; int Arg3 = 76; verify_case(0, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 10, 50, 60 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 41; int Arg3 = 0; verify_case(1, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 10, 50, 60 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; int Arg2 = 41; int Arg3 = 10; verify_case(2, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 2, 2, 12 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 10; int Arg3 = 1; verify_case(3, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = { 10000, 10000, 10000 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9998; int Arg2 = 9997; int Arg3 = 9999; verify_case(4, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = { 5824, 4952, 6230 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 364; int Arg2 = 287; int Arg3 = 694; verify_case(5, Arg3, wager(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    QuizShow ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

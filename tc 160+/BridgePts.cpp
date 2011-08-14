#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

bool have[52];
class BridgePts {
	public:
	int pointValue(vector <int> hand) {
		memset(have, 0, sizeof have);
		for (int i=0; i<(int)hand.size(); ++i)
			have[hand[i]-1] = true;

		int score = 0;
		for (int i=0; i<4; ++i)
			score += 4*have[i*13]; // aces

		for (int i=0; i<4; ++i) // J, Q, K
			for (int j=10; j<13; ++j)
				score += (j-9)*have[i*13 + j];

		for (int i=0; i<4; ++i) {
			int cnt = accumulate(have + i*13, have + (i+1)*13, 0);
			if (cnt == 2)
				++score;
			else if (cnt == 1)
				score += 2;
			else if (cnt == 0)
				score += 3;
		}

		return score;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25,14,15,16,17,18,19,20,21,22,23,24,26}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, pointValue(Arg0)); }
	void test_case_1() { int Arr0[] = {2,3,4,15,18,28,29,30,41,42,43,16,17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, pointValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BridgePts ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
Looking over your scorecard, you realize that the only four remaining items are
 full house (three of a kind and two of a kind), worth 25 points
 small straight (4 consecutive values, no wrapping), worth 30 points,
 large straight (all five dice are consecutive values), worth 40 points,
 and Yahtzee (all five dice show the same value), worth 50 points.
*/

double score(vector<int> dice) {
	int x = dice[0];
	bool gotIt = true;
	for (int i=1; i<5; ++i)
		if (dice[i] != x) {
			gotIt = false;
			break;
		}
	if (gotIt)
		return 50.0;

	sort(dice.begin(), dice.end());

	gotIt = true;
	for (int i=1; i<5; ++i)
		if (dice[i] != dice[i-1]+1) {
			gotIt = false;
			break;
		}
	if (gotIt)
		return 40.0;

	vector<int> seq;
	unique_copy(dice.begin(), dice.end(), back_inserter(seq));
	while (seq.size() < 5)
		seq.push_back(0);
	gotIt = true;
	for (int i=1; i<4; ++i)
		if (seq[i] != seq[i-1]+1) {
			gotIt = false;
			break;
		}
	if (gotIt)
		return 30.0;

	gotIt = true;
	for (int i=2; i<5; ++i)
		if (seq[i] != seq[i-1]+1) {
			gotIt = false;
			break;
		}
	if (gotIt)
		return 30.0;

	if (dice[0]==dice[1] && dice[2]==dice[3] && dice[3]==dice[4] || dice[0]==dice[1] && dice[1]==dice[2] && dice[3]==dice[4])
		return 25.0;

	return 0.0;
}

double val(vector<int> dice, int mask, int pos) {
	if (pos == 5)
		return score(dice);

	if ((mask & (1<<pos)) == 0)
		return val(dice, mask, pos+1);

	double ret = 0.0;
	for (int i=1; i<=6; ++i) {
		dice[pos] = i;
		ret += val(dice, mask, pos+1);
	}
	return ret/6;
}
class YahtzeeRoll {
	public:
	double bestChoice(vector <int> dice) {
		double sol = 0.0;
		for (int mask=0; mask<(1<<5); ++mask)
			sol = max(sol, val(dice, mask, 0));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 1, 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 8.333333333333334; verify_case(0, Arg1, bestChoice(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 1, 1, 2, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 25.0; verify_case(1, Arg1, bestChoice(Arg0)); }
	void test_case_2() { int Arr0[] = { 2, 3, 4, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 33.333333333333336; verify_case(2, Arg1, bestChoice(Arg0)); }
	void test_case_3() { int Arr0[] = { 2, 2, 3, 4, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 17.77777777777778; verify_case(3, Arg1, bestChoice(Arg0)); }
	void test_case_4() { int Arr0[] = { 6, 1, 3, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.722222222222221; verify_case(4, Arg1, bestChoice(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    YahtzeeRoll ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

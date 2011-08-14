#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class TeamPhoto {
	public:
	int eval(vector<int>::const_iterator beg, vector<int>::const_iterator end) {
		int ret = 0;
		while (++beg!=end)
			ret += abs(*beg-*(beg-1));
		return ret;
	}
	int go(int a, int b, int c, int d, int e, int f, int g, int h) {
		return abs(a-b)+abs(c-d)+abs(d-e)+abs(e-f)+abs(g-h);
	}
	int minDiff(vector <int> height) {
		vector<int> players(height.begin()+3, height.end());
		const int hc=height[0], as1=height[1], as2=height[2];

		sort(players.begin(), players.end());
		const int pll = players[0];
		const int plr = players[players.size()/2-1];
		const int mid = (players.size()%2==0 ? hc:players[players.size()/2]);
		const int prl = (players.size()%2==0 ? players[players.size()/2]:players[players.size()/2+1]);
		const int prr = players[players.size()-1];
		const int left = eval(players.begin(), players.begin()+players.size()/2);
		const int right = eval(players.size()%2==0 ? players.begin()+players.size()/2:players.begin()+players.size()/2+1, players.end());

		int best = 0x7fff;
		best <?= go(as1, pll, plr, mid, hc, prl, prr, as2);
		best <?= go(as2, pll, plr, mid, hc, prl, prr, as1);
		best <?= go(as1, pll, plr, hc, mid, prl, prr, as2);
		best <?= go(as2, pll, plr, hc, mid, prl, prr, as1);
		best <?= go(as1, prl, prr, mid, hc, pll, plr, as2);
		best <?= go(as2, prl, prr, mid, hc, pll, plr, as1);
		best <?= go(as1, prl, prr, hc, mid, pll, plr, as2);
		best <?= go(as2, prl, prr, hc, mid, pll, plr, as1);
		best <?= go(as1, plr, pll, mid, hc, prl, prr, as2);
		best <?= go(as2, plr, pll, mid, hc, prl, prr, as1);
		best <?= go(as1, plr, pll, hc, mid, prl, prr, as2);
		best <?= go(as2, plr, pll, hc, mid, prl, prr, as1);
		best <?= go(as1, prl, prr, mid, hc, plr, pll, as2);
		best <?= go(as2, prl, prr, mid, hc, plr, pll, as1);
		best <?= go(as1, prl, prr, hc, mid, plr, pll, as2);
		best <?= go(as2, prl, prr, hc, mid, plr, pll, as1);

		return left+best+right;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {80, 82, 81, 50, 90, 65}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 79; verify_case(0, Arg1, minDiff(Arg0)); }
	void test_case_1() { int Arr0[] = {70,82,91,50,50,50,50,50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 113; verify_case(1, Arg1, minDiff(Arg0)); }
	void test_case_2() { int Arr0[] = {13, 17, 11, 12, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minDiff(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TeamPhoto ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

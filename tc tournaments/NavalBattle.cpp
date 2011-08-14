#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> hits, misses;
bool dp[50][51][51][2];
bool done[50][51][51][2];
int L, SL;
vector<int> shots;
string ans;

bool go(int pos, int hit, int miss, bool haveShip) {
	if (pos == L)
		return (haveShip && hit==(int)hits.size() && miss==(int)misses.size());
	if (pos > L)
		return false;

	if (done[pos][hit][miss][haveShip])
		return dp[pos][hit][miss][haveShip];

	done[pos][hit][miss][haveShip] = 1;
	bool &ret = dp[pos][hit][miss][haveShip];

	if (miss<(int)misses.size() && misses[miss]==pos)
		return ret = go(pos+1, hit, miss+1, haveShip);

	if (hit==(int)hits.size() || hits[hit]!=pos)
		if (go(pos+1, hit, miss, haveShip))
			return ret = 1;

	// there is a ship starting at pos
	int npos = pos + SL;

	if (miss<(int)misses.size() && misses[miss]<npos)
		return ret = 0;

	int nhit = hit;
	while (nhit<(int)hits.size() && hits[nhit]<npos)
		++nhit;
	if (nhit<(int)hits.size() && hits[nhit]==npos)
		return ret = 0;

	return ret = go(npos+(npos<L), nhit, miss + (miss==(int)misses.size() ? 0 : misses[miss]==npos), 1);
}
bool canBeTrue(int cnt) {
	hits.clear();
	misses.clear();

	for (int i=0; i<cnt; ++i)
		if (ans[i] == '1')
			hits.push_back(shots[i]);
		else
			misses.push_back(shots[i]);

	sort(hits.begin(), hits.end());
	sort(misses.begin(), misses.end());
	hits.erase(unique(hits.begin(), hits.end()), hits.end());
	misses.erase(unique(misses.begin(), misses.end()), misses.end());
	int i=0, j=0;
	while (i<(int)hits.size() && j<(int)misses.size())
		if (hits[i] == misses[j])
			return false;
		else if (hits[i] < misses[j])
			++i;
		else
			++j;

	memset(done, 0, sizeof done);

	return go(0, 0, 0, 0);
}
class NavalBattle {
	public:
	int firstDishonestMove(int fieldLength, int shipLength, vector <int> shots_, string answers) {
		shots = shots_;
		ans = answers;
		L = fieldLength;
		SL = shipLength;

		if (canBeTrue(shots.size()))
			return -1;


		int lo = 1;
		int hi = shots.size();

		while (lo < hi) {
			int mid = lo + (hi-lo)/2;
			if (!canBeTrue(mid))
				hi = mid;
			else
				lo = mid+1;
		}

		return lo-1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1"; int Arg4 = -1; verify_case(0, Arg4, firstDishonestMove(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {0, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "110"; int Arg4 = 1; verify_case(1, Arg4, firstDishonestMove(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {0, 4, 1, 3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "11110"; int Arg4 = -1; verify_case(2, Arg4, firstDishonestMove(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 1; int Arr2[] = {4, 7, 8, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "0110"; int Arg4 = 2; verify_case(3, Arg4, firstDishonestMove(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {4, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "01"; int Arg4 = 0; verify_case(4, Arg4, firstDishonestMove(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NavalBattle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

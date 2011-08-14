#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> P;
int L, N;
int dp[51][51][51];
bool take[51][51][51];

int dist;

bool go(int pos, int cnt, int last) {
	if (pos == (int)P.size())
		return cnt==0;
	if (cnt == 0)
		return 1;

	if (dp[pos][cnt][last] != -1)
		return dp[pos][cnt][last];

	bool canTake = false;
	if (last==0 || P[pos]-P[last]>=dist)
		canTake = go(pos+1, cnt-1, pos);

	if (canTake) {
		take[pos][cnt][last] = 1;
		return dp[pos][cnt][last] = 1;
	}

	return dp[pos][cnt][last] = go(pos+1, cnt, last);
}
class RaceTrack {
	public:
	string judgePositions(int length, int judges, vector <int> pos) {
		P = pos;
		N = judges;
		L = length;
		P.insert(P.begin(), 0);

		int lo = 1;
		int hi = L;

		while (lo < hi) {
			dist = lo + (hi-lo+1)/2;

			memset(dp, 0xff, sizeof dp);
			if (go(1, N, 0))
				lo = dist;
			else
				hi = dist-1;
		}

		memset(dp, 0xff, sizeof dp);
		memset(take, 0, sizeof take);
		dist = lo;
		go(1, N, 0);

		int last = 0;
		int cnt = N;
		string sol((int)P.size()-1, '0');
		for (int i=1; i<(int)P.size(); ++i)
			if (take[i][cnt][last]) {
				sol[i-1] = '1';
				--cnt;
				last = i;
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 3; int Arr2[] = {0, 5, 10, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1110"; verify_case(0, Arg3, judgePositions(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 2; int Arr2[] = {0, 5, 10, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1001"; verify_case(1, Arg3, judgePositions(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 4; int Arr2[] = {0, 5, 10, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1111"; verify_case(2, Arg3, judgePositions(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 5; int Arr2[] = {6, 9, 33, 59, 100, 341, 431, 444, 565, 857}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1000010111"; verify_case(3, Arg3, judgePositions(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RaceTrack ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

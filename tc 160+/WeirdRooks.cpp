#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> N;
int M;
bool dp[1<<10][8][9][81];
bool done[1<<10][8][9][81];

bool ok(int used, int i, int cnt, int spec) {
	if (spec < 0)
		return 0;
	if (i < 0)
		return cnt==0 && spec==0;

	if (done[used][i][cnt][spec])
		return dp[used][i][cnt][spec];

	done[used][i][cnt][spec] = 1;

	int add = 0;
	for (int j=0; j<N[i]; ++j)
		if ((used & (1<<j)) == 0)
			++add;

	if (ok(used, i-1, cnt, spec-add))
		return dp[used][i][cnt][spec] = 1;

	if (cnt > 0) {
		int nspec = spec;
		for (int j=N[i]-1; j>=0; --j)
			if ((used & (1<<j)) == 0) {
				if (ok(used | (1<<j), i-1, cnt-1, nspec))
					return dp[used][i][cnt][spec] = 1;
				--nspec;
			}
	}

	return dp[used][i][cnt][spec] = 0;
}
class WeirdRooks {
	public:
	string describe(vector <int> cols) {
		N = cols;
		M = N.size();
		memset(done, 0, sizeof done);

		ostringstream os;
		for (int cnt=0; cnt<=M; ++cnt)
			for (int spec=0; spec<=80; ++spec)
				if (ok(0, M-1, cnt, spec))
					os << ' ' << cnt << ',' << spec;

		return os.str().substr(1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0,9 1,4 1,5 1,6 1,7 1,8 2,1 2,2 2,3 2,4 2,5 2,6 3,0 3,1 3,2 3,3"; verify_case(0, Arg1, describe(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0,6 1,3 1,4 1,5 2,1 2,2 2,3 3,0"; verify_case(1, Arg1, describe(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0,1 1,0"; verify_case(2, Arg1, describe(Arg0)); }
	void test_case_3() { int Arr0[] = {2,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0,11 1,2 1,3 1,4 1,5 1,6 1,7 1,8 1,9 1,10 2,0 2,1 2,2 2,3 2,4 2,5 2,6 2,7 2,8"; verify_case(3, Arg1, describe(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WeirdRooks ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

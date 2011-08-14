#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> G;
int sum[50][50];
int minVal;
int maxDiff;
void makeSums() {
	for (int i=0; i<(int)G.size(); ++i)
		sum[i][i] = G[i];

	for (int l=1; l<(int)G.size(); ++l)
		for (int i=0; i+l<(int)G.size(); ++i)
			sum[i][i+l] = sum[i][i+l-1] + G[i+l];
}

bool done[50][50];
bool dp[50][50];
bool ok(int pos, int cutLeft) {
	assert(pos < (int)G.size());
	if (cutLeft == 0)
		return sum[pos][G.size()-1]>=minVal && sum[pos][G.size()-1]-minVal<=maxDiff;

	if (done[pos][cutLeft])
		return dp[pos][cutLeft];

	done[pos][cutLeft] = 1;

	for (int i=pos; i+1<(int)G.size(); ++i) {
		if (sum[pos][i] < minVal)
			continue;
		if (sum[pos][i] - minVal > maxDiff)
			break;
		if (ok(i+1, cutLeft-1))
			return dp[pos][cutLeft] = true;
	}
	return dp[pos][cutLeft] = false;
}
bool canMake(int n, int maxD) {
	maxDiff = maxD;
	for (int i=0; i<(int)G.size(); ++i) {
		makeSums();
		for (int j=0; j+1<(int)G.size(); ++j) {
			minVal = sum[0][j];
			memset(done, 0, sizeof done);
			if (ok(j+1, n-2))
				return true;
		}

		int t = G.back();
		G.pop_back();
		G.insert(G.begin(), t);
	}

	return false;
}
class Necklaces {
	public:
	int inequity(int n, vector <int> gems) {
		if (n == 1)
			return 0;

		int lo = 0;
		int hi = 5000000;
		G = gems;

		while (lo < hi) {
			int mid = (lo+hi)/2;
			if (canMake(n, mid))
				hi = mid;
			else
				lo = mid+1;
		}

		return lo;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {5,12,2,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, inequity(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {5,12,9,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, inequity(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {100,92,133,201,34,34,34,94,108}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 29; verify_case(2, Arg2, inequity(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Necklaces ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

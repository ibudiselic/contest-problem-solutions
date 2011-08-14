#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

const int ANY = 0;
int dp[50][101][101];
typedef pair<int, int> pii;

vector<pii> V;

int go(int i, int llim, int rlim) {
	if (i == (int)V.size()) {
		return (rlim == ANY);
	}
	int &ret = dp[i][llim][rlim];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	if (rlim == ANY) {
		if (V[i].first <= llim) { // can't take
			ret += go(i+1, llim, ANY); // don't take
		} else {
			ret += go(i+1, llim, V[i].second); // don't take
			ret += go(i+1, V[i].second, ANY); // take
		}
	} else {
		if (V[i].first <= llim) { // can't take
			assert(0); // should never happen
		} else if (V[i].first <= rlim) {
			ret += go(i+1, llim, min(rlim, V[i].second)); // don't take
			ret += go(i+1, V[i].second, ANY); // take
		}
	}

	return ret;
}

class IntervalSubsets {
	public:
	int numberOfSubsets(vector <int> start, vector <int> finish) {
		V.clear();
		for (int i=0; i<(int)start.size(); ++i) {
			V.push_back(pii(start[i], finish[i]));
		}
		sort(V.begin(), V.end());

		memset(dp, 0xff, sizeof dp);
		int sol = 0;
		int llim = V[0].second;
		for (int i=0; i<(int)V.size(); ++i) {
			if (V[i].first <= llim) {
				sol += go(i+1, V[i].second, ANY);
				llim = min(llim, V[i].second);
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {68,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {75,64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5,4,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3,4,4,4,4,2,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,5,4,5,4,5,3,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(3, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 1, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, numberOfSubsets(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IntervalSubsets ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
bool done[1<<15];
bool dp[1<<15];

bool win(int mask) {
	if (done[mask])
		return dp[mask];

	done[mask] = 1;
	for (int i=0; i<N-1; ++i)
		if (mask & (1<<i))
			for (int j=i+1; j<N; ++j)
				for (int k=j; k<N; ++k)
					if (!win(mask ^ (1<<i) ^ (1<<j) ^ (1<<k)))
						return dp[mask] = 1;
	return dp[mask] = 0;
}
class Roxor {
	public:
	vector <int> play(vector <int> piles) {
		N = piles.size();
		int mask = 0;
		for (int i=0; i<(int)piles.size(); ++i) {
			if (piles[i]%2 == 1)
				mask |= (1<<i);
		}

		memset(done, 0, sizeof done);

		for (int i=0; i<N-1; ++i)
			if (piles[i] > 0)
				for (int j=i+1; j<N; ++j)
					for (int k=j; k<N; ++k)
						if (!win(mask ^ (1<<i) ^ (1<<j) ^ (1<<k))) {
							vector<int> sol;
							sol.push_back(i);
							sol.push_back(j);
							sol.push_back(k);
							return sol;
						}
		return vector<int>();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 1, 0, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  4,  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, play(Arg0)); }
	void test_case_1() { int Arr0[] = {1000, 1000, 1000, 1000, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, play(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 1, 1, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, play(Arg0)); }
	void test_case_3() { int Arr0[] = {14, 301, 391, 410, 511, 681, 58, 259, 981, 81, 5, 42, 251, 401, 120}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  5,  14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, play(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Roxor ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

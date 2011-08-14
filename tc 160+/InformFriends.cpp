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
int M[1<<15];
bool done[16][1<<15];
bool dp[16][1<<15];
int ALL;

bool go(int facts, int covered) {
	if (done[facts][covered]) {
		return dp[facts][covered];
	}
	done[facts][covered] = 1;
	if (facts == 0) {
		dp[facts][covered] = 1;
		return true;
	}

	for (int m=0; m<=ALL; m=(m+covered+1)&~covered) {
		assert((covered & m) == 0);
		if (M[m] == ALL) {
			if (go(facts-1, covered | m)) {
				dp[facts][covered] = 1;
				return true;
			}
		}
	}

	dp[facts][covered] = 0;
	return false;
}

class InformFriends {
	public:
	int maximumGroups(vector <string> friends) {
		memset(M, 0, sizeof M);
		N = friends.size();
		ALL = (1<<N) - 1;
		for (int i=0; i<N; ++i) {
			int m = (1<<i);
			for (int j=0; j<N; ++j) {
				if (friends[i][j] == 'Y') {
					m |= (1<<j);
				}
			}
			M[(1<<i)] = m;
		}
		M[0] = 0;
		for (int m=0; m<(1<<N); ++m) {
			for (int i=0; i<N; ++i) {
				if ((m>>i) & 1) {
					M[m] |= M[1<<i];
				}
			}
		}

		memset(done, 0, sizeof done);
		int lo = 1;
		int hi = N;
		while (lo < hi) {
			int mid = lo + (hi-lo+1)/2;
			if (go(mid, 0)) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}

		return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYYN",
 "YNYY",
 "YYNY",
 "NYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maximumGroups(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYN",
 "YNYN",
 "YYNN",
 "NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, maximumGroups(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYNNNY",
 "YNYNNN",
 "NYNYNN",
 "NNYNYN",
 "NNNYNY",
 "YNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, maximumGroups(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNY",
 "YNYN",
 "NYNY",
 "YNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, maximumGroups(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    InformFriends ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

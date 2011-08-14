#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string s, t;

int dp[51][51][51][51];
bool done[51][51][51][51];

int go(int sl, int sr, int tl, int tr) {
	if (done[sl][sr][tl][tr])
		return dp[sl][sr][tl][tr];
	if (sl==sr && tl==tr-1 || tl==tr && sl==sr-1) {
		done[sl][sr][tl][tr] = 1;
		return dp[sl][sr][tl][tr] = 1;
	}
	if (sr-sl + tr-tl == 2) {
		done[sl][sr][tl][tr] = 1;
		if (sr-sl == 2) {
			if (s[sl] == s[sl+1]) return dp[sl][sr][tl][tr] = 2;
			else return dp[sl][sr][tl][tr] = 0;
		} else if (tr-tl == 2) {
			if (t[tl] == t[tl+1]) return dp[sl][sr][tl][tr] = 2;
			else return dp[sl][sr][tl][tr] = 0;
		} else {
			if (s[sl] == t[tl]) return dp[sl][sr][tl][tr] = 2;
			else return dp[sl][sr][tl][tr] = 0;
		}
	}
	int ret = 0;

	if (sr > sl) { // ima znakova u s
		if (sr > sl+1) { // vise znakova u s
			if (s[sl] == s[sr-1]) {
				const int x = go(sl+1, sr-1, tl, tr);
				if (x > 0)
					ret = max(ret, x+2);
			}
			if (tr > tl) { // ima znakova u t
				if (tr > tl+1) { // vise znakova u t
					if (s[sl] == t[tr-1]) {
						const int x = go(sl+1, sr, tl, tr-1);
						if (x > 0)
							ret = max(ret, x+2);
					}
					if (t[tl] == s[sr-1]) {
						const int x = go(sl, sr-1, tl+1, tr);
						if (x > 0)
							ret = max(ret, x+2);
					}
					if (t[tl] == t[tr-1]) {
						const int x = go(sl, sr, tl+1, tr-1);
						if (x > 0)
							ret = max(ret, x+2);
					}
				} else { // jedan znak u t
					if (t[tl] == s[sr-1]) {
						const int x = go(sl, sr-1, tl+1, tr);
						if (x > 0)
							ret = max(ret, x+2);
					}
					if (s[sl] == t[tl]) {
						const int x = go(sl+1, sr, tl+1, tr);
						if (x > 0)
							ret = max(ret, x+2);
					}
				}
			}
		} else { // jedan znak u s
			if (tr > tl+1) { // vise znakova u t
				if (t[tl] == t[tr-1]) {
					const int x = go(sl, sr, tl+1, tr-1);
					if (x > 0)
						ret = max(ret, x+2);
				}
				if (t[tl] == s[sl]) {
					const int x = go(sl+1, sr, tl+1, tr);
					if (x > 0)
						ret = max(ret, x+2);
				}
				if (s[sl] == t[tr-1]) {
					const int x = go(sl+1, sr, tl, tr-1);
					if (x > 0)
						ret = max(ret, x+2);
				}
			}
		}
	} else { // nema znakova u s
		if (tr > tl+1) { // vise znakova u t
			if (t[tl] == t[tr-1]) {
				const int x = go(sl, sr, tl+1, tr-1);
				if (x > 0)
					ret = max(ret, x+2);
			}
		}
	}
	done[sl][sr][tl][tr] = 1;
	return dp[sl][sr][tl][tr] = ret;
}

class InterleavePal {
	public:
	int longestPal(string s_, string t_) {
		s = s_;
		t = t_;
		memset(done, 0, sizeof done);
		int sol = 0;
		for (int i=0; i<(int)s.size(); ++i)
			for (int j=i; j<=(int)s.size(); ++j)
				for (int x=0; x<(int)t.size(); ++x)
					for (int y=x; y<=(int)t.size(); ++y)
						sol = max(sol, go(i, j, x, y));
		for (int i=0; i<(int)t.size(); ++i)
			for (int j=i; j<=(int)t.size(); ++j)
				sol = max(sol, go(0, 0, i, j));
		for (int i=0; i<(int)s.size(); ++i)
			for (int j=i; j<=(int)s.size(); ++j)
				sol = max(sol, go(i, j, 0, 0));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AA"; string Arg1 = "BB"; int Arg2 = 4; verify_case(0, Arg2, longestPal(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = ""; string Arg1 = "JAVA"; int Arg2 = 3; verify_case(1, Arg2, longestPal(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = ""; string Arg1 = ""; int Arg2 = 0; verify_case(2, Arg2, longestPal(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ONCEUPONATIMETHEREWASAYOUNGPROGRAMMERWHOLEARNED"; string Arg1 = "TOPROGRAMJOINEDTOPCODERANDEVENTUALLYBECAMERED"; int Arg2 = 9; verify_case(3, Arg2, longestPal(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InterleavePal ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

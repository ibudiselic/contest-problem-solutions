#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long mod = 12345678;
int M, N;
vector<string> D;
long long sol;
int bc[1<<8];
int dp[28][1<<8];
int pd[1<<8]; // possible dots after the masked Xs have been assigned
int sgn;
int init_cnt;
int total_cnt;
bool pd_arr[4][7];

bool valid(int i, int j) {
	if (i<0 || j<0 || i>=M || j>=N) {
		return false;
	}
	return true;
}
bool neighborX(int i, int j) {
	for (int di=-1; di<2; ++di) {
		for (int dj=-1; dj<2; ++dj) {
			if (di!=0 || dj!=0) {
				int r = i + di;
				int c = j + dj;
				if (valid(r, c) && D[r][c]=='X') {
					return true;
				}
			}
		}
	}
	return false;
}

int do_pd_precalc(int i, int j, int k, int mask) {
	if (i == M) {
		assert(mask == 0);
		return 0;
	}

	if (j == N) {
		return do_pd_precalc(i+1, 0, k, mask);
	}

	int nk = k;
	int nmask = mask;
	int new_possible = 0;
	if (D[i][j] == 'X') {
		++nk;
		if (mask & (1<<k)) {
			nmask ^= (1<<k);
			for (int di=-1; di<2; ++di) {
				for (int dj=-1; dj<2; ++dj) {
					if (di!=0 || dj!=0) {
						int r = i + di;
						int c = j + dj;
						if (valid(r, c) && pd_arr[r][c]==0) {
							pd_arr[r][c] = 1;
							++new_possible;
						}
					}
				}
			}
		}
	}

	return new_possible + do_pd_precalc(i, j+1, nk, nmask);
}

void precalc_pd() {
	memset(pd, 0, sizeof pd);
	for (int m=0; m<(1<<total_cnt); ++m) {
		memset(pd_arr, 0, sizeof pd_arr);
		pd[m] = N*M-total_cnt - do_pd_precalc(0, 0, 0, (~m) & ((1<<total_cnt)-1));
	}
}
long long go(int k, int assigned) {
	if (k == M*N) {
		return (assigned == (1<<total_cnt)-1);
	}

	int &ret = dp[k][assigned];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int i=0; i<total_cnt; ++i) {
		if ((assigned & (1<<i)) == 0) {
			ret = (ret + go(k+1, assigned | (1<<i))) % mod;
		}
	}

	int possible_dots = pd[assigned] - (k-bc[assigned]);
	ret = (ret + possible_dots*go(k+1, assigned)) % mod;

	return int(ret);
}
void add_x(int i, int j, int cnt_added) {
	if (i == M) {
		sgn = (cnt_added%2==0 ? 1 : -1);
		total_cnt = init_cnt + cnt_added;
		memset(dp, 0xff, sizeof dp);
		precalc_pd();
		sol = (sol + sgn*go(0, 0) + 2*mod) % mod;
		return;
	}
	if (j == N) {
		add_x(i+1, 0, cnt_added);
		return;
	}

	add_x(i, j+1, cnt_added);

	if (D[i][j]=='.' && !neighborX(i, j)) {
		D[i][j] = 'X';
		add_x(i, j+1, cnt_added+1);
		D[i][j] = '.';
	}
}
class MountainMap {
	public:
	int count(vector <string> data) {
		D = data;
		M = D.size();
		N = D[0].size();

		bc[0] = 0;
		for (int i=1; i<(1<<8); ++i) {
			bc[i] = bc[i>>1] + (i&1);
		}

		init_cnt = 0;
		for (int i=0; i<M; ++i) {
			for (int j=0; j<N; ++j) {
				if (D[i][j] == 'X') {
					++init_cnt;
					if (neighborX(i, j)) {
						return 0;
					}
				}
			}
		}
		if (init_cnt == 0) {
			return 0;
		}

		sol = 0;
		add_x(0, 0, 0);

		return int(sol);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"X.",
 ".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"X.",
 "..",
 ".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"X.X",
 "...",
 "X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4800; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { string Arr0[] = {"..X.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(5, Arg1, count(Arg0)); }
	void test_case_6() { string Arr0[] = {"....X.",
 "......",
 ".X...X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 869490; verify_case(6, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MountainMap ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

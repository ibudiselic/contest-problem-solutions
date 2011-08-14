#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int M, N;
long long used;
long long mask[4][6][6];
bool canUse[4][6][6];
int sol;
int sz;

void rotate(vector<string> &v) {
	int m = v.size();
	int n = v[0].size();
	vector<string> t(n, string(m, '.'));
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			if (v[i][j] == 'X')
				t[j][m-1-i] = 'X';

	v = t;
}
void go(int cur) {
	sol = max(sol, cur);

	for (int k=0; k<4; ++k)
		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				if ((M-i)*(N-j)*2/sz+cur > sol && canUse[k][i][j] && (used&mask[k][i][j])==0) {
					used |= mask[k][i][j];
					go(cur+1);
					used ^= mask[k][i][j];
				}
}
class PatternCutting {
	public:
	int getMax(int width, int height, vector <string> pattern) {
		M = height;
		N = width;
		sz = pattern.size()*pattern[0].size();
		if (pattern.size()==1 && pattern[0].size()==1)
			return M*N;
		if (pattern.size()==2 && pattern[0].size()==1 || pattern.size()==1 && pattern[0].size()==2)
			return M*N/2;

		memset(mask, 0, sizeof mask);
		memset(canUse, 1, sizeof canUse);
		for (int t=0; t<4; ++t) {
			for (int i=0; i<6; ++i)
				for (int j=0; j<6; ++j)
					if (i+(int)pattern.size()>M || j+(int)pattern[0].size()>N) {
						canUse[t][i][j] = 0;
					} else {
						long long m = 0;
						for (int r=0; r<(int)pattern.size(); ++r)
							for (int c=0; c<(int)pattern[0].size(); ++c)
								if (pattern[r][c] == 'X')
									m |= (1LL<<((i+r)*6 + (j+c)));

						mask[t][i][j] = m;
						for (int k=0; k<t; ++k)
							if (canUse[k][i][j] && mask[k][i][j]==m) {
								canUse[t][i][j] = 0;
								break;
							}
					}

			rotate(pattern);
		}

		used = 0;
		sol = 0;
		go(0);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 5; string Arr2[] = {"XXX",
 ".X."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 5; string Arr2[] = {"XX",
 "XX"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(1, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; string Arr2[] = {"XXXXX",
 "XX..."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 6; string Arr2[] = {"XXX",
 "X.X",
 "XXX"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(3, Arg3, getMax(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PatternCutting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

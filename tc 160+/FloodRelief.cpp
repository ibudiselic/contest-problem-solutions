#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool done[50][50];
int M, N;
int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
vector<string> H;
bool valid(int i, int j) {
	if (i<0 || j<0 || i>=M || j>=N) {
		return false;
	}
	return true;
}
void dfs(int i, int j) {
	done[i][j] = 1;
	for (int d=0; d<4; ++d) {
		int r = i + di[d];
		int c = j + dj[d];
		if (valid(r, c) && !done[r][c] && H[r][c]>=H[i][j]) {
			dfs(r, c);
		}
	}
}
class FloodRelief {
	public:
	int minimumPumps(vector <string> H) {
		::H = H;
		memset(done, 0, sizeof done);
		M = H.size();
		N = H[0].size();

		int sol = 0;
		for (char l='a'; l<='z'; ++l) {
			for (int i=0; i<M; ++i) {
				for (int j=0; j<N; ++j) {
					if (!done[i][j] && H[i][j]==l) {
						++sol;
						dfs(i, j);
					}
				}
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ccccc",
 "cbbbc",
 "cbabc",
 "cbbbc",
 "ccccc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumPumps(Arg0)); }
	void test_case_1() { string Arr0[] = {"cbabcbabc",
 "cbabcbabc",
 "cbabcbabc",
 "cbabcbabc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimumPumps(Arg0)); }
	void test_case_2() { string Arr0[] = {"ccccccccccc",
 "caaaaaaaaac",
 "caaaaaaaaac",
 "caazpppzaac",
 "caapdddpaac",
 "caapdddpaac",
 "caapdddpaac",
 "caazpppzaac",
 "caaaaaaaaac",
 "caaaaaaaaac",
 "ccccccccccc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minimumPumps(Arg0)); }
	void test_case_3() { string Arr0[] = {"ab",
 "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, minimumPumps(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FloodRelief ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

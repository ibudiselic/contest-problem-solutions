#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;


int dp[10][1<<10];
vector<string> A;
int M, N;
int ban[10];

int go(int r, int v_mask) {
	if (r == M) {
		return 0;
	}
	int &ret = dp[r][v_mask];
	if (ret != -1) {
		return ret;
	}

	ret = 123456789;
	for (int v=0; v<(1<<N); v=(v+ban[r]+1)&~ban[r]) {
		assert((v & ban[r]) == 0);
		int cost = 0;
		bool in_hor = false;
		for (int j=0; j<N; ++j) {
			if (A[r][j] == '#') {
				in_hor = false;
			} else {
				if (v & (1<<j)) {
					in_hor = false;
					if ((v_mask & (1<<j)) == 0) {
						++cost;
					}
				} else {
					if (!in_hor) {
						in_hor = true;
						++cost;
					}
				}
			}
		}

		ret = min(ret, cost + go(r+1, v));
	}

	return ret;
}
class FloorBoards {
	public:
	int layout(vector <string> room) {
		A = room;
		M = A.size();
		N = A[0].size();
		memset(ban, 0, sizeof ban);
		for (int i=0; i<M; ++i) {
			for (int j=0; j<N; ++j) {
				if (A[i][j] == '#') {
					ban[i] |= (1<<j);
				}
			}
		}

		memset(dp, 0xff, sizeof dp);
		return go(0, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....."
,"....."
,"....."
,"....."
,"....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, layout(Arg0)); }
	void test_case_1() { string Arr0[] = {"......."
,".#..##."
,".#....."
,".#####."
,".##..#."
,"....###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, layout(Arg0)); }
	void test_case_2() { string Arr0[] = {"####"
,"####"
,"####"
,"####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, layout(Arg0)); }
	void test_case_3() { string Arr0[] = {"...#.."
,"##...."
,"#.#..."
,".#...."
,"..#..."
,"..#..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, layout(Arg0)); }
	void test_case_4() { string Arr0[] = {".#...."
,"..#..."
,".....#"
,"..##.."
,"......"
,".#..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, layout(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FloorBoards ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

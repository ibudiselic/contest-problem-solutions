#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

bool used[20][20][20][20];
int n, m;
int ai, aj, bi, bj;

struct State {
	int ai, aj, bi, bj;
	int step;
	State(int ai_, int aj_, int bi_, int bj_, int s): ai(ai_), aj(aj_), bi(bi_), bj(bj_), step(s) {}
};
class PathFinding {
	public:
	bool inbounds(int i, int j) {
		return i>=0 && i<n && j>=0 && j<m;
	}
	int minTurns(vector <string> board) {
		n = (int)board.size();
		m = (int)board[0].size();
		queue<State> q;
		memset(used, 0, sizeof used);
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (board[i][j] == 'A') {
					ai = i; aj = j;
					board[i][j] = '.';
				} else if (board[i][j] == 'B') {
					bi = i; bj = j;
					board[i][j] = '.';
				}
		used[ai][aj][bi][bj] = true;
		q.push(State(ai, aj, bi, bj, 0));

		while (!q.empty()) {
			State old_s = q.front();
			q.pop();
			for (int dai=-1; dai<=1; ++dai)
				for (int daj=-1; daj<=1; ++daj)
					for (int dbi=-1; dbi<=1; ++dbi)
						for (int dbj=-1; dbj<=1; ++dbj) {
							State new_s = old_s;
							new_s.ai += dai; new_s.aj += daj;
							new_s.bi += dbi; new_s.bj += dbj;
							++new_s.step;
							if (!inbounds(new_s.ai, new_s.aj) || !inbounds(new_s.bi, new_s.bj)) continue;
							if (used[new_s.ai][new_s.aj][new_s.bi][new_s.bj]) continue;
							if (board[new_s.ai][new_s.aj]=='X' || board[new_s.bi][new_s.bj]=='X') continue;
							if (new_s.ai==old_s.bi && new_s.aj==old_s.bj && new_s.bi==old_s.ai && new_s.bj==old_s.aj) continue;
							if (new_s.ai==new_s.bi && new_s.aj==new_s.bj) continue;
							if (new_s.ai==bi && new_s.aj==bj && new_s.bi==ai && new_s.bj==aj) return new_s.step;
							used[new_s.ai][new_s.aj][new_s.bi][new_s.bj] = true;
							q.push(new_s);
						}
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....",
 ".A..",
 "..B.",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minTurns(Arg0)); }
	void test_case_1() { string Arr0[] = {"XXXXXXXXX",
 "A...X...B",
 "XXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, minTurns(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXXXXXXX",
 "A.......B",
 "XXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minTurns(Arg0)); }
	void test_case_3() { string Arr0[] = {"XXXXXXXXX",
 "A.......B",
 "XXXX.XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, minTurns(Arg0)); }
	void test_case_4() { string Arr0[] = {"...A.XXXXX.....",
 ".....XXXXX.....",
 "...............",
 ".....XXXXX.B...",
 ".....XXXXX....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, minTurns(Arg0)); }
	void test_case_5() { string Arr0[] = {"AB.................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "...................X",
 ".XXXXXXXXXXXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 379; verify_case(5, Arg1, minTurns(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PathFinding ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

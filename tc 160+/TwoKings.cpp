#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
bool attacks(int x, int y, int x2, int y2) {
    return (x == x2 || y == y2 || x2-x == y2-y || x-x2 == y2-y);
  }


  int solve(int qx, int qy, int kx1, int ky1, int kx2, int ky2, int t, int depth) {
    if (t == 0) {
      if (attacks(qx, qy, kx1, ky1) || attacks(qx, qy, kx2, ky2)) return 1;
      if (depth == 1) return 1000;

      int best = 100, d, i;
      for (d = 0; d < 8; d++)
      for (i = 0; i < 100; i++) {
        int qx2 = qx + dx[d] * i;
        int qy2 = qy + dy[d] * i;
        if (qx2 < 0 || qy2 < 0 || qx2 >= 100 || qy2 >= 100) break;
        best <?= (solve(qx2, qy2, kx1, ky1, kx2, ky2, 1-t, depth-1)+1);
      }
      return best;
    } else {
      int best = 0, d;
      for (d = 0; d < 8; d++) {
        int kx3 = kx1 + dx[d];
        int ky3 = ky1 + dy[d];
        if (kx3 < 0 || ky3 < 0 || kx3 >= 100 || ky3 >= 100 || (kx3 == kx2 && ky3 == ky2) || (kx3 == qx && ky3 == qy)) continue;
        best >?= solve(qx, qy, kx3, ky3, kx2, ky2, 1-t, depth);
      }
      for (d = 0; d < 8; d++) {
        int kx3 = kx2 + dx[d];
        int ky3 = ky2 + dy[d];
        if (kx3 < 0 || ky3 < 0 || kx3 >= 100 || ky3 >= 100 || (kx3 == kx1 && ky3 == ky1) || (kx3 == qx && ky3 == qy)) continue;
        best >?= solve(qx, qy, kx1, ky1, kx3, ky3, 1-t, depth);
      }
      return best;
    }
  }
void parse(const string &s, int &i, int &j) {
	sscanf(s.c_str(), "%d %d", &i, &j);
}
class TwoKings {
	public:
	int captureKing(string queen, string king1, string king2) {
		int qx, qy, k1x, k1y, k2x, k2y;
		parse(queen, qx, qy);
		parse(king1, k1x, k1y);
		parse(king2, k2x, k2y);

		return solve(qx, qy, k1x, k1y, k2x, k2y, 0, 3) <? 4;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0 0"; string Arg1 = "99 0"; string Arg2 = "0 99"; int Arg3 = 1; verify_case(0, Arg3, captureKing(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "98 98"; string Arg1 = "0 97"; string Arg2 = "99 0"; int Arg3 = 2; verify_case(1, Arg3, captureKing(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "16 35"; string Arg1 = "53 36"; string Arg2 = "23 40"; int Arg3 = 3; verify_case(2, Arg3, captureKing(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "22 53"; string Arg1 = "95 64"; string Arg2 = "30 76"; int Arg3 = 4; verify_case(3, Arg3, captureKing(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TwoKings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

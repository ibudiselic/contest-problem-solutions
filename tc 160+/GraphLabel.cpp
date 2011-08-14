#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> G;
int N;
int num[9];
bool used[9];
int sol;
void go(int x, int cur) {
	if (x == N) {
		sol = min(sol, cur);
		return;
	}
	for (int i=0; i<N; ++i)
		if (!used[i]) {
			num[x] = i;
			used[i] = 1;
			int dist = 0;
			for (int j=0; j<N; ++j)
				if (num[j]!=-1 && G[x][j]=='1')
					dist = max(dist, abs(i-num[j]));
			if (dist < sol)
				go(x+1, max(cur, dist));
			used[i] = 0;
		}
	num[x] = -1;
}

class GraphLabel {
	public:
	int adjacentDifference(vector <string> graph) {
		G = graph;
		N = G.size();

		sol = 1234567890;
		memset(num, 0xff, sizeof num);
		memset(used, 0, sizeof used);

		go(0, 0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"010000",
 "101111",
 "010111",
 "011010",
 "011101",
 "011010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, adjacentDifference(Arg0)); }
	void test_case_1() { string Arr0[] = {"01111001",
 "10101000",
 "11000101",
 "10000111",
 "11000111",
 "00111000",
 "00011000",
 "10111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, adjacentDifference(Arg0)); }
	void test_case_2() { string Arr0[] = {"011110101",
 "100111000",
 "100000111",
 "110011011",
 "110101001",
 "010110110",
 "101001010",
 "001101101",
 "101110010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, adjacentDifference(Arg0)); }
	void test_case_3() { string Arr0[] = {"011111111",
 "101111111",
 "110111111",
 "111011111",
 "111101111",
 "111110111",
 "111111011",
 "111111101",
 "111111110"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, adjacentDifference(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GraphLabel ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

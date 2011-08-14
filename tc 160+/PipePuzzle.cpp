#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
string dirs = "NESW";

bool used[20][20];
vector<string> P;
int M, N;
int L;

bool valid(int i, int j) {
	if (i<0 || j<0 || i>=M || j>=N)
		return false;
	return true;
}
int len(int i, int j, int d, int mask) {
	memset(used, 0, sizeof used);
	int ret = 0;

	i += di[d];
	j += dj[d];
	while (valid(i, j)) {
		if (dirs.find(P[i][j]) != string::npos)
			break;
		if (used[i][j] && P[i][j]!='+')
			break;
		used[i][j] = 1;
		++ret;
		if (P[i][j] < L) {
			if (mask & (1<<P[i][j]))
				d = (d+1)%4;
			else
				d = (d+3)%4;
		}
		i += di[d];
		j += dj[d];
	}

	return ret;
}
class PipePuzzle {
	public:
	int longest(vector <string> pipes) {
		P = pipes;
		M = P.size();
		N = P[0].size();

		int starti = -1;
		int startj = -1;
		int startdir = -1;
		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				if (dirs.find(P[i][j]) != string::npos) {
					starti = i;
					startj = j;
					startdir = dirs.find(P[i][j]);
					goto FOUND_START;
				}
		FOUND_START:;

		L = 0;
		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				if (P[i][j] == 'L')
					P[i][j] = L++;

		int sol = 0;
		for (int m=0; m<(1<<L); ++m)
			sol = max(sol, len(starti, startj, startdir, m));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"LL-L-",
 "L+L+L",
 "--NL-",
 "L+--L",
 "LL+L-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, longest(Arg0)); }
	void test_case_1() { string Arr0[] = {"ELLL",
 "LLLL",
 "LLLL",
 "LLLL"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(1, Arg1, longest(Arg0)); }
	void test_case_2() { string Arr0[] = {"ELLLLL+",
 "++++++L",
 "L+++++L",
 "L+++++L",
 "L+++++L",
 "L+++++L",
 "+LLLLLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 71; verify_case(2, Arg1, longest(Arg0)); }
	void test_case_3() { string Arr0[] = {"-+-+-+-+-+-+-+-+-+-W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(3, Arg1, longest(Arg0)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, longest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PipePuzzle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

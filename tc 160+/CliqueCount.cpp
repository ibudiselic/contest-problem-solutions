#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

int bc[1<<20];
int cnt[21];
int N;
vector<string> G;
bool connected(int x, int mask) {
	for (int i=0; i<N; ++i)
		if ((mask & (1<<i)) && G[x][i]=='0')
			return false;
	return true;
}
bool maximal(int mask) {
	for (int i=0; i<N; ++i)
		if ((mask & (1<<i)) == 0 && connected(i, mask))
			return false;
	return true;
}
void go(int x, int mask) {
	if (x == N) {
		if (maximal(mask))
			++cnt[bc[mask]];
		return;
	}

	go(x+1, mask);
	if (connected(x, mask))
		go(x+1, mask | (1<<x));
}
class CliqueCount {
	public:
	int countCliques(vector <string> graph) {
		bc[0] = 0;
		for (int i=1; i<(1<<20); ++i)
			bc[i] = bc[i>>1] + (i&1);
		memset(cnt, 0, sizeof cnt);
		G = graph;
		N = G.size();

		go(0, 0);

		return accumulate(cnt, cnt+21, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"010",
 "100",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, countCliques(Arg0)); }
	void test_case_1() { string Arr0[] = {"011",
 "101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countCliques(Arg0)); }
	void test_case_2() { string Arr0[] = {"00010000000000100000",
 "00110000000000000000",
 "01011001000000011000",
 "11101000000100010110",
 "00110000001100000000",
 "00000000010000000001",
 "00000000000000011001",
 "00100000000010000001",
 "00000000000100011000",
 "00000100000010000010",
 "00001000000000000010",
 "00011000100001000101",
 "00000001010000000000",
 "00000000000100000010",
 "10000000000000000010",
 "00110010100000000000",
 "00100010100000000000",
 "00010000000100000000",
 "00010000011001100000",
 "00000111000100000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(2, Arg1, countCliques(Arg0)); }
	void test_case_3() { string Arr0[] = {"00",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, countCliques(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CliqueCount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

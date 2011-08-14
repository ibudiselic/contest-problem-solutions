#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

vector<string> G;
int N;
bool done[50][901];

bool bfs(int from, int to, int len) {
	queue< pair<int, int> > Q;
	memset(done, 0, sizeof done);

	Q.push(make_pair(from, 0));

	while (!Q.empty()) {
		int d = Q.front().second;
		int x = Q.front().first;
		Q.pop();

		if (x==to && d==len)
			return true;

		if (d > len)
			continue;

		if (done[x][d])
			continue;

		done[x][d] = 1;
		for (int i=0; i<N; ++i)
			if (G[x][i]!='X' && (i!=x || G[x][i]!='0'))
				Q.push(make_pair(i, d+G[x][i]-'0'));
	}

	return 0;
}
class Paths {
	public:
	int secondBest(vector <string> graph, int from, int to) {
		G = graph;
		N = G.size();

		bool foundBest = false;

		for (int len=0; len<=900; ++len)
			if (bfs(from, to, len))
				if (foundBest)
					return len;
				else
					foundBest = true;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01111",
 "10111",
 "11011",
 "11101",
 "11110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; verify_case(0, Arg3, secondBest(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; verify_case(1, Arg3, secondBest(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"X1119",
 "1X119",
 "11X19",
 "111X1",
 "9111X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 4; int Arg3 = 3; verify_case(2, Arg3, secondBest(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"X1110",
 "1X111",
 "11111",
 "111X1",
 "0111X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 4; int Arg3 = 2; verify_case(3, Arg3, secondBest(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "XX9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X9X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X99X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X9999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X99999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X9999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X99999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X9999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X99999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X9999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X99999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X999999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X9999999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X99999999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X999999999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X9999999999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X99999999999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X999999999999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXXX",
 "X9999999999999999999999X9XXXXXXXXXXXXXXXXXXXXXXXXX",
 "X99999999999999999999999X9XXXXXXXXXXXXXXXXXXXXXXXX",
 "X999999999999999999999999X9XXXXXXXXXXXXXXXXXXXXXXX",
 "X9999999999999999999999999X9XXXXXXXXXXXXXXXXXXXXXX",
 "X99999999999999999999999999X9XXXXXXXXXXXXXXXXXXXXX",
 "X999999999999999999999999999X9XXXXXXXXXXXXXXXXXXXX",
 "X9999999999999999999999999999X9XXXXXXXXXXXXXXXXXXX",
 "X99999999999999999999999999999X9XXXXXXXXXXXXXXXXXX",
 "X999999999999999999999999999999X9XXXXXXXXXXXXXXXXX",
 "X9999999999999999999999999999999X9XXXXXXXXXXXXXXXX",
 "X99999999999999999999999999999999X9XXXXXXXXXXXXXXX",
 "X999999999999999999999999999999999X9XXXXXXXXXXXXXX",
 "X9999999999999999999999999999999999X9XXXXXXXXXXXXX",
 "X99999999999999999999999999999999999X9XXXXXXXXXXXX",
 "X999999999999999999999999999999999999X9XXXXXXXXXXX",
 "X9999999999999999999999999999999999999X9XXXXXXXXXX",
 "X99999999999999999999999999999999999999X9XXXXXXXXX",
 "X999999999999999999999999999999999999999X9XXXXXXXX",
 "X9999999999999999999999999999999999999999X9XXXXXXX",
 "X99999999999999999999999999999999999999999X9XXXXXX",
 "X999999999999999999999999999999999999999999X9XXXXX",
 "X9999999999999999999999999999999999999999999X9XXXX",
 "X99999999999999999999999999999999999999999999X9XXX",
 "X999999999999999999999999999999999999999999999X9XX",
 "X9999999999999999999999999999999999999999999999X9X",
 "X99999999999999999999999999999999999999999999999X9",
 "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 49; int Arg3 = 459; verify_case(4, Arg3, secondBest(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = -1; verify_case(5, Arg3, secondBest(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Paths ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

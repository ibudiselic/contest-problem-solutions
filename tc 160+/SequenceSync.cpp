#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int T[20][4];
int N;
bool done[1<<20];
int bc[1<<20];

int bfs(int states) {
	done[states] = 1;
	int t = 0;
	int ret = -1;
	queue<int> Q;
	Q.push(states);

	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++ret;
		}
		--t;
		states = Q.front();
		Q.pop();

		for (int i=0; i<4; ++i) {
			int ns = 0;
			for (int j=0; j<N; ++j)
				if (states & (1<<j))
					ns |= (1<<T[j][i]);

			if (!done[ns]) {
				if (bc[ns] == 1)
					return ret+1;
				done[ns] = 1;
				Q.push(ns);
			}
		}
	}
	return -1;
}
class SequenceSync {
	public:
	int getLength(vector <string> transitions) {
		N = transitions.size();
		if (N == 1)
			return 0;

		for (int i=0; i<N; ++i)
			sscanf(transitions[i].c_str(), "%d %d %d %d", &T[i][0], &T[i][1], &T[i][2], &T[i][3]);

		bc[0] = 0;
		for (int i=1; i<(1<<N); ++i)
			bc[i] = bc[i>>1] + (i&1);

		memset(done, 0, sizeof done);

		return bfs((1<<N)-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 1 1 1",
 "1 1 1 2",
 "0 2 2 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 1 1 1",
 "2 2 2 2",
 "3 3 3 3",
 "0 0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"1 1 1 0",
 "2 2 2 1",
 "3 3 3 2",
 "4 4 4 3",
 "5 5 5 5",
 "6 6 6 6",
 "7 7 7 0",
 "0 0 0 8",
 "8 8 8 8",
 "9 9 9 8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(3, Arg1, getLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SequenceSync ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

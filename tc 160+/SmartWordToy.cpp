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

bool cantUse[50][4][26];
bool done[26][26][26][26];
int cntF;
void set(const vector<int> &v) {
	done[v[0]][v[1]][v[2]][v[3]] = 1;
}
bool test(const vector<int> &v) {
	return done[v[0]][v[1]][v[2]][v[3]];
}
vector<int> win;
bool isWin(const vector<int> &v) {
	return win[0]==v[0] && win[1]==v[1] && win[2]==v[2] && win[3]==v[3];
}
bool valid(const vector<int> &v) {
	for (int i=0; i<cntF; ++i) {
		bool ok = false;
		for (int j=0; j<4; ++j)
			if (!cantUse[i][j][v[j]]) {
				ok = true;
				break;
			}
		if (!ok)
			return false;
	}
	return true;
}
int bfs(vector<int> v) {
	int t = 0;
	int sol = -1;
	queue< vector<int> > Q;
	Q.push(v);
	set(v);

	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++sol;
		}
		--t;

		v = Q.front();
		Q.pop();

		for (int i=0; i<4; ++i) {
			++v[i];
			if (v[i] == 26)
				v[i] = 0;
			if (!test(v) && valid(v)) {
				if (isWin(v))
					return sol+1;
				set(v);
				Q.push(v);
			}
			--v[i];
			if (v[i] == -1)
				v[i] = 25;

			--v[i];
			if (v[i] == -1)
				v[i] = 25;

			if (!test(v) && valid(v)) {
				if (isWin(v))
					return sol+1;
				set(v);
				Q.push(v);
			}
			++v[i];
			if (v[i] == 26)
				v[i] = 0;
		}
	}
	return -1;
}
class SmartWordToy {
	public:
	int minPresses(string start, string finish, vector <string> forbid) {
		if (start == finish)
			return 0;

		vector<int> v;
		for (int i=0; i<4; ++i)
			v.push_back(start[i]-'a');

		win.clear();
		for (int i=0; i<4; ++i)
			win.push_back(finish[i]-'a');

		memset(cantUse, 0, sizeof cantUse);
		cntF = forbid.size();
		for (int i=0; i<cntF; ++i) {
			istringstream is(forbid[i]);
			string w;
			for (int j=0; j<4; ++j) {
				is >> w;
				for (int k=0; k<(int)w.size(); ++k)
					cantUse[i][j][w[k]-'a'] = 1;
			}
		}

		memset(done, 0, sizeof done);
		return bfs(v);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "aaaa"; string Arg1 = "bbbb"; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "mmnn"; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; verify_case(2, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"bz a a a", "a bz a a", "a a bz a", "a a a bz"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"cdefghijklmnopqrstuvwxyz a a a",
 "a cdefghijklmnopqrstuvwxyz a a",
 "a a cdefghijklmnopqrstuvwxyz a",
 "a a a cdefghijklmnopqrstuvwxyz"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(4, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "aaaa"; string Arg1 = "bbbb"; string Arr2[] = {"b b b b"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(5, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "zzzz"; string Arg1 = "aaaa"; string Arr2[] = {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(6, Arg3, minPresses(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SmartWordToy ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

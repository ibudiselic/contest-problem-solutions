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

inline int encode(int v[7]) {
	int ret = 0;
	for (int i=0; i<7; ++i)
		ret = ret*7 + v[i];
	return ret;
}
inline void decode(int code, int v[7]) {
	for (int i=6; i>=0; --i) {
		v[i] = code%7;
		code /= 7;
	}
}
bool done[823543];
vector<string> B;
string sol;
int solCode;

const int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool isWin(int v[7]) {
	for (int j=0; j<7; ++j)
		for (int i=0; i<v[j]; ++i) {
			char p = B[5-i][j];
			if (p == '.')
				continue;
			for (int d=0; d<8; ++d) {
				int r = i+di[d];
				int c = j+dj[d];
				int len = 1;
				bool flag = false;
				while (5-r>=0 && 5-r<6 && c>=0 && c<7 && r<v[c] && B[5-r][c]==p) {
					flag = true;
					++len;
					r += di[d];
					c += dj[d];
				}

				if (len >= 4)
					return true;
			}
		}
	return false;
}
bool valid() {
	if (solCode == 0) {
		sol = "first player moves";
		return true;
	}

	memset(done, 0, sizeof done);
	done[0] = 1;

	int code = 0;
	int v[7] = {0};
	queue<int> Q;
	Q.push(0);
	int t = 0;
	int cnt = -1;

	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++cnt;
		}
		--t;

		code = Q.front();
		Q.pop();

		char c = (cnt%2 ? 'O' : 'X'); // second, first

		decode(code, v);

		for (int j=0; j<7; ++j)
			if (v[j]<6 && B[5-v[j]][j]==c) {
				++v[j];
				int ncode = encode(v);
				if (done[ncode]) {
					--v[j];
					continue;
				}

				if (isWin(v)) {
					if (ncode == solCode) {
						sol = string((cnt%2 ? "second":"first")) + " player wins";
						return true;
					}
					--v[j];
					continue;
				}

				if (ncode == solCode) {
					if (ncode == 823542)
						sol = "draw game";
					else
						sol = string((cnt%2-1 ? "second":"first")) + " player moves";
					return true;
				}
				done[ncode] = 1;
				Q.push(ncode);
				--v[j];
			}
	}

	return false;
}
class ConnectFour {
	public:
	string judge(vector <string> board) {
		B = board;
		int v[7] = {0};
		for (int j=0; j<7; ++j)
			for (int i=0; i<6; ++i) {
				if (B[5-i][j] != '.')
					v[j] = i+1;
				if (i>0 && B[5-i][j]!='.' && B[5-i+1][j]=='.')
					return "invalid";
			}
		solCode = encode(v);

		if (!valid())
			return "invalid";

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
".......",
".......",
".......",
".......",
".......",
"......."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first player moves"; verify_case(0, Arg1, judge(Arg0)); }
	void test_case_1() { string Arr0[] = {
".......",
".......",
".......",
"...X...",
"...O...",
"...X..."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "second player moves"; verify_case(1, Arg1, judge(Arg0)); }
	void test_case_2() { string Arr0[] = {
".......",
".......",
"X......",
"OX.....",
"XOXO...",
"OXOX..."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first player wins"; verify_case(2, Arg1, judge(Arg0)); }
	void test_case_3() { string Arr0[] = {
".......",
".......",
".X.....",
".X.....",
".X..XX.",
"XOOOOOO"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "second player wins"; verify_case(3, Arg1, judge(Arg0)); }
	void test_case_4() { string Arr0[] = {
"OOXOXOX",
"XXXOXOO",
"OXXOOXO",
"XOOXXOO",
"XXXOOXX",
"XOOXXOO"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "draw game"; verify_case(4, Arg1, judge(Arg0)); }
	void test_case_5() { string Arr0[] = {
"...X...",
".......",
".......",
".......",
"...X...",
"...O..."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "invalid"; verify_case(5, Arg1, judge(Arg0)); }
	void test_case_6() { string Arr0[] = {
".......",
".......",
".......",
".......",
"OOOO...",
"XXXX..."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "invalid"; verify_case(6, Arg1, judge(Arg0)); }
	void test_case_7() { string Arr0[] = {
"XXO.XOX",
"OOX.OXX",
"XXO.XXO",
"OOXXOOO",
"XXOOXOO",
"OOXOOXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "invalid"; verify_case(7, Arg1, judge(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ConnectFour ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> b;
int m, n;

const int INF = 2000000000;
struct Grupa {
	int color, sz;
	int mini;
	int minj[51];
	vector<char *> members;

	Grupa(int c): color(c), sz(0), mini(INF) {
		for (int i=0; i<51; ++i)
			minj[i] = INF;
	}
};
bool operator<(const Grupa &a, const Grupa &b) {
	if (a.color != b.color)
		return a.color < b.color;
	else if (a.sz != b.sz)
		return a.sz < b.sz;
	else if (a.mini != b.mini)
		return a.mini < b.mini;
	else {
		for (int i=0; i<51; ++i)
			if (a.minj[i]!=INF && b.minj[i]!=INF)
				return a.minj[i] < b.minj[i];
	}
	return false;
}
const int di[] = { -1,  0,  1,  0 };
const int dj[] = {  0,  1,  0, -1 };

bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}

int used[51][51];
vector<Grupa> grupe;
int stanje = INF;
void fill(int i, int j) {
	assert(!used[i][j]);

	if (stanje == INF) {
		grupe.push_back(Grupa(b[i][j]));
		stanje = grupe.size()-1;
	}

	used[i][j] = 1;
	++grupe[stanje].sz;
	grupe[stanje].mini <?= i;
	grupe[stanje].minj[i] <?= j;
	grupe[stanje].members.push_back(&b[i][j]);
	for (int dir=0; dir<4; ++dir) {
		const int ii = i+di[dir];
		const int jj = j+dj[dir];
		if (valid(ii, jj) && !used[ii][jj] && b[ii][jj]==grupe[stanje].color)
			fill(ii, jj);
	}
}
void fix(void) {
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			if (b[i][j]=='-')
				for (int k=i; k>0; --k) {
					b[k][j] = b[k-1][j];
					b[k-1][j] = '-';
				}

	for (int j=0; j<n; ++j) {
		int cnt = 0;
		for (int i=0; i<m; ++i)
			cnt += (b[i][j]!='-');
		if (cnt==0) {
			for (int i=0; i<m; ++i)
				for (int k=j; k<n-1; ++k) {
					b[i][k] = b[i][k+1];
					b[i][k+1] = '-';
				}
		}
	}
}
class SameGame {
	public:
	int get_order(char c, const string &o) {
		for (int i=0; i<(int)o.size(); ++i)
			if (o[i]==c)
				return i;
		assert(0);
		return -1;
	}

	int getScore(vector <string> board, string order) {
		b = board;
		m = (int)b.size();
		n = (int)b[0].size();

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (b[i][j] != '-')
					b[i][j] = get_order(b[i][j], order);

		int sol = 0;
		for (;;) {
			grupe.clear();
			memset(used, 0, sizeof used);
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j)
					if (!used[i][j] && b[i][j]!='-') {
						stanje = INF;
						fill(i, j);
					}
			vector<Grupa> grp;
			for (int i=0; i<(int)grupe.size(); ++i)
				if (grupe[i].sz>1)
					grp.push_back(grupe[i]);

			if (grp.size()==0)
				break;

			sort(grp.begin(), grp.end());

			vector<char *> &t = grp[0].members;
			for (int i=0; i<(int)t.size(); ++i)
				*t[i] = '-';
			sol += grp[0].sz * (grp[0].sz-1) /2;
			fix();
		}
		int cnt=0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				cnt += (b[i][j]!='-');
		if (cnt==0)
			sol *= 4;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RBB",
 "RRR",
 "RBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "RB"; int Arg2 = 64; verify_case(0, Arg2, getScore(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ABCD",
 "ABCD",
 "ABCD",
 "ABCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCD"; int Arg2 = 96; verify_case(1, Arg2, getScore(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ABCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCD"; int Arg2 = 0; verify_case(2, Arg2, getScore(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"ACCAA",
 "ABAAA",
 "ABBBA",
 "AAACD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "EABCD"; int Arg2 = 28; verify_case(3, Arg2, getScore(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ABABABABABABABABABAB",
 "ABABABABABABABABABAB",
 "CDCDCDCDCDCDCDCDCDCD",
 "CDCDCDCDCDCDCDCDCDCD",
 "EFEFEFEFEFEFEFEFEFEF",
 "EFEFEFEFEFEFEFEFEFEF",
 "GHGHGHGHGHGHGHGHGHGH",
 "GHGHGHGHGHGHGHGHGHGH",
 "IJIJIJIJIJIJIJIJIJIJ",
 "IJIJIJIJIJIJIJIJIJIJ",
 "KLKLKLKLKLKLKLKLKLKL",
 "KLKLKLKLKLKLKLKLKLKL",
 "MNMNMNMNMNMNMNMNMNMN",
 "MNMNMNMNMNMNMNMNMNMN",
 "OPOPOPOPOPOPOPOPOPOP",
 "OPOPOPOPOPOPOPOPOPOP",
 "QRQRQRQRQRQRQRQRQRQR",
 "QRQRQRQRQRQRQRQRQRQR",
 "STSTSTSTSTSTSTSTSTST",
 "STSTSTSTSTSTSTSTSTST",
 "UVUVUVUVUVUVUVUVUVUV",
 "UVUVUVUVUVUVUVUVUVUV",
 "WXWXWXWXWXWXWXWXWXWX",
 "WXWXWXWXWXWXWXWXWXWX",
 "YZYZYZYZYZYZYZYZYZYZ",
 "YZYZYZYZYZYZYZYZYZYZ",
 "WXWXWXWXWXWXWXWXWXWX",
 "WXWXWXWXWXWXWXWXWXWX",
 "UVUVUVUVUVUVUVUVUVUV",
 "UVUVUVUVUVUVUVUVUVUV",
 "STSTSTSTSTSTSTSTSTST",
 "STSTSTSTSTSTSTSTSTST",
 "MNMNMNMNMNMNMNMNMNMN",
 "MNMNMNMNMNMNMNMNMNMN",
 "QRQRQRQRQRQRQRQRQRQR",
 "QRQRQRQRQRQRQRQRQRQR",
 "OPOPOPOPOPOPOPOPOPOP",
 "OPOPOPOPOPOPOPOPOPOP",
 "KLKLKLKLKLKLKLKLKLKL",
 "KLKLKLKLKLKLKLKLKLKL",
 "IJIJIJIJIJIJIJIJIJIJ",
 "IJIJIJIJIJIJIJIJIJIJ",
 "GHGHGHGHGHGHGHGHGHGH",
 "GHGHGHGHGHGHGHGHGHGH",
 "EFEFEFEFEFEFEFEFEFEF",
 "EFEFEFEFEFEFEFEFEFEF",
 "CDCDCDCDCDCDCDCDCDCD",
 "CDCDCDCDCDCDCDCDCDCD",
 "ABABABABABABABABABAB",
 "ABABABABABABABABABAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; int Arg2 = 2720; verify_case(4, Arg2, getScore(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SameGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

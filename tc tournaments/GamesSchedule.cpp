#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <numeric>

using namespace std;

int cntGames[5];
int colors[5];
int gameColor[5];
int K, sol, n;
vector<string> S;

/*
n teams play in a tournament. There are n games in the tournament, and each game is played by k teams.
During each game, each participating team is assigned one of k colors, and each of those teams must have a distinct color.
The k colors are represented by the first k uppercase letters in the alphabet. Each team must play exactly k games,
and they must be assigned a different color in each of their games. In addition, all teams participating in the same game must have the same experience.
The experience of a team is the number of games it has played before the current game.
*/
void game(int);
void work(int g, int pos, int missingTeams, int q, int exp) {
	if (pos == n) {
		if (missingTeams == 0)
			game(g+1);
		return;
	}

	if (S[g][pos] == '?') {
		if (missingTeams == 0) {
			work(g, pos+1, 0, q-1, exp);
		} else {
			if (q > missingTeams)
				work(g, pos+1, missingTeams, q-1, exp); // skip this team

			if (exp!=-1 && exp!=cntGames[pos])
				return; // can't take this one
			if (cntGames[pos] == K)
				return;

			// assing this team to the game
			for (int clr=0; clr<K; ++clr) {
				if (colors[pos] & (1<<clr))
					continue;
				if (gameColor[g] & (1<<clr))
					continue;

				colors[pos] |= (1<<clr);
				gameColor[g] |= (1<<clr);
				++cntGames[pos];
				work(g, pos+1, missingTeams-1, q-1, (exp==-1 ? cntGames[pos]-1 : exp));
				--cntGames[pos];
				gameColor[g] ^= (1<<clr);
				colors[pos] ^= (1<<clr);
			}
		}
	} else if (S[g][pos] == '-') {
		work(g, pos+1, missingTeams, q, exp);
	} else {
		int clr = S[g][pos]-'A';

		if (colors[pos] & (1<<clr))
			return;
		if (gameColor[g] & (1<<clr))
			return;
		if (cntGames[pos] == K)
			return;

		colors[pos] |= (1<<clr);
		gameColor[g] |= (1<<clr);
		++cntGames[pos];
		work(g, pos+1, missingTeams, q, exp);
		--cntGames[pos];
		gameColor[g] ^= (1<<clr);
		colors[pos] ^= (1<<clr);
	}
}
void game(int g) {
	if (g == n) {
		sol += (accumulate(cntGames, cntGames+n, 0) == n*K);
		return;
	}

	int teamsInGame = 0;
	int q = 0;
	for (int i=0; i<n; ++i) {
		teamsInGame += (isupper(S[g][i])!=0);
		q += (S[g][i]=='?');
	}

	if (teamsInGame > K)
		return;

	int cnt = -1;
	if (teamsInGame >= 1) {
		for (int i=0; i<n; ++i)
			if (isupper(S[g][i])) {
				cnt = cntGames[i];
				break;
			}
		for (int i=0; i<n; ++i)
			if (isupper(S[g][i]) && cnt!=cntGames[i])
				return;
	}

	const int missingTeams = K-teamsInGame;

	if (missingTeams > q)
		return;

	work(g, 0, missingTeams, q, cnt);
}
class GamesSchedule {
	public:
	int howMany(vector <string> schedule, int k) {
		K = k;
		S = schedule;
		n = S.size();
		memset(cntGames, 0, sizeof cntGames);
		memset(colors, 0, sizeof colors);
		memset(gameColor, 0, sizeof gameColor);

		sol = 0;

		game(0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AB", "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"??", "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"?-?A", "????", "????", "??-?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 10; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"?C?", "A?B", "???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"???", "A??", "???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; verify_case(4, Arg2, howMany(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"???", "A?A", "???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(5, Arg2, howMany(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"???B","?D?A","A???","????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(6, Arg2, howMany(Arg0, Arg1)); }
	void test_case_7() { string Arr0[] = {"????D","?????","E????","?????","?????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6048; verify_case(7, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GamesSchedule ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

struct Player {
	int score;
	string name;
	Player(int score_, const string &name_): score(score_), name(name_) {}
};
bool operator<(const Player &a, const Player &b) {
	if (a.score != b.score)
		return a.score > b.score;
	return a.name < b.name;
}
struct Team {
	int score;
	string name;
	vector<Player> p;
	Team(int score_, const string &name_): score(score_), name(name_) {}
};
bool operator<(const Team &a, const Team &b) {
	if (a.score != b.score)
		return a.score > b.score;
	return a.name < b.name;
}

int getInd(const string &s, map<string, int> &ind, vector<string> &names, vector<int> &scores, vector<int> &team) {
	if (ind.count(s) == 0) {
		ind[s] = names.size();
		names.push_back(s);
		scores.push_back(0);
		team.push_back(0);
	}
	return ind[s];
}
string toStr(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
class Paintball {
	public:
	vector <string> getLeaderboard(vector <string> players, vector <string> messages) {
		map<string, int> teamInd;
		vector<string> teamNames;
		vector<int> teamsScore;
		vector<int> dummy;
		map<string, int> playerInd;
		vector<string> playerNames;
		vector<int> playersScore;
		vector<int> playersTeam;

		for (int i=0; i<(int)players.size(); ++i) {
			string p, t;
			istringstream is(players[i]);
			is >> p >> t;
			int pp = getInd(p, playerInd, playerNames, playersScore, playersTeam);
			int tt = getInd(t, teamInd, teamNames, teamsScore, dummy);
			playersTeam[pp] = tt;
		}

		for (int i=0; i<(int)messages.size(); ++i) {
			string p1_, p2_, t;
			istringstream is(messages[i]);
			is >> p1_ >> t >> p2_;
			assert(t == "SPLATTERED");
			int p1 = getInd(p1_, playerInd, playerNames, playersScore, playersTeam);
			int p2 = getInd(p2_, playerInd, playerNames, playersScore, playersTeam);

			if (playersTeam[p1] != playersTeam[p2]) {
				++playersScore[p1];
				++teamsScore[playersTeam[p1]];
				--playersScore[p2];
				--teamsScore[playersTeam[p2]];
			} else {
				--playersScore[p1];
				--teamsScore[playersTeam[p1]];
			}
		}

		vector<Team> T;
		for (int i=0; i<(int)teamsScore.size(); ++i)
			T.push_back(Team(teamsScore[i], teamNames[i]));
		for (int i=0; i<(int)playerNames.size(); ++i)
			T[playersTeam[i]].p.push_back(Player(playersScore[i], playerNames[i]));

		vector<string> sol;
		sort(T.begin(), T.end());
		for (int i=0; i<(int)T.size(); ++i) {
			sol.push_back(T[i].name + ' ' + toStr(T[i].score));
			sort(T[i].p.begin(), T[i].p.end());
			for (int j=0; j<(int)T[i].p.size(); ++j)
				sol.push_back("  " + T[i].p[j].name + ' ' + toStr(T[i].p[j].score));
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"A RED", "B BLUE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A SPLATTERED B"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"RED 1", "  A 1", "BLUE -1", "  B -1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"LISA RED", "BART RED", "HOMER BLUE", "MARGE BLUE", "MAGGIE GREEN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"MAGGIE SPLATTERED HOMER", "MAGGIE SPLATTERED MARGE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"GREEN 2", "  MAGGIE 2", "RED 0", "  BART 0", "  LISA 0", "BLUE -2", "  HOMER -1", "  MARGE -1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"TODD STRIKEFORCE",
 "BART OMEGA",
 "DATA STRIKEFORCE",
 "MILHOUSE OMEGA",
 "NELSON DISCOVERYCHANNEL",
 "MARTIN DISCOVERYCHANNEL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BART SPLATTERED MARTIN","TODD SPLATTERED MARTIN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"OMEGA 1", "  BART 1", "  MILHOUSE 0", "STRIKEFORCE 1", "  TODD 1", "  DATA 0", "DISCOVERYCHANNEL -2", "  NELSON 0", "  MARTIN -2" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"DR COHO", "ST COHO", "PE COHO"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"DR SPLATTERED ST",
 "ST SPLATTERED PE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"COHO -2", "  PE 0", "  DR -1", "  ST -1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"A B", "AA AA", "AAA AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A SPLATTERED AAA", "A SPLATTERED AAA", "A SPLATTERED AAA",
"AA SPLATTERED AAA", "AA SPLATTERED AAA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"B 3", "  A 3", "AA 2", "  AA 2", "AAA -5", "  AAA -5" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getLeaderboard(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Paintball ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

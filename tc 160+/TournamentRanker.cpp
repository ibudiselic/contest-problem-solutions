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

struct player {
	int cntWin;
	string lt;
	string name;
	player(int cntWin_, const string &lt_, const string &name_): cntWin(cntWin_), lt(lt_), name(name_) {}
};
map<string, int> M;
vector<player> P;
bool operator>(const player &a, const player &b) {
	if (a.cntWin != b.cntWin)
		return a.cntWin > b.cntWin;
	else if (a.lt!="" && b.lt!="")
		return P[M[a.lt]] > P[M[b.lt]];
	else
		return a.lt=="";
}
class TournamentRanker {
	public:
	vector <string> rankTeams(vector <string> names, vector <string> lostTo) {
		M.clear();
		P.clear();

		for (int i=0; i<(int)names.size(); ++i) {
			P.push_back(player(0, "", names[i]));
			M[names[i]] = i;
		}

		for (int i=0; i<(int)names.size(); ++i)
			if (lostTo[i] != "") {
				P[i].lt = lostTo[i];
				++P[M[lostTo[i]]].cntWin;
			}

		for (int i=0; i<(int)P.size()-1; ++i)
			for (int j=i+1; j<(int)P.size(); ++j)
				if (P[j] > P[i]) {
					swap(M[P[i].name], M[P[j].name]);
					swap(P[i], P[j]);
				}

		vector<string> sol;
		for (int i=0; i<(int)P.size(); ++i)
			sol.push_back(P[i].name);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"RODDICK", "SCHUETTLER", "FERREIRA", "AGASSI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SCHUETTLER", "AGASSI", "AGASSI", ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "AGASSI",  "SCHUETTLER",  "FERREIRA",  "RODDICK" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, rankTeams(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"DUKE", "SETON HALL", "ILLINOIS", "CINCINNATI",
 "NORTH CAROLINA", "TEXAS", "XAVIER", "MISSISSIPPI STATE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"", "DUKE", "DUKE", "ILLINOIS",
 "TEXAS", "XAVIER", "DUKE", "XAVIER"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "DUKE",  "XAVIER",  "ILLINOIS",  "TEXAS",  "SETON HALL",  "MISSISSIPPI STATE",  "CINCINNATI",  "NORTH CAROLINA" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, rankTeams(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"JAVA", "VISUAL BASIC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"VISUAL BASIC", ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "VISUAL BASIC",  "JAVA" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, rankTeams(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TournamentRanker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

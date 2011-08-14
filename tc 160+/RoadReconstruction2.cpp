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

vector<string> names;
vector< vector<int> > G;
vector< vector<int> > repCost;
vector< vector<string> > roadId;
vector<int> C;
map<string, int> M;
int getInd(const string &s) {
	if (M.count(s) == 0) {
		M[s] = names.size();
		names.push_back(s);
	}
	return M[s];
}
vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}
class RoadReconstruction {
	public:
	string selectReconstruction(vector <string> roads) {
		M.clear();
		names.clear();
		G.assign(100, vector<int>(100, 0));
		repCost.assign(100, vector<int>(100, 1234567890));
		roadId.assign(100, vector<string>(100, ""));

		for (int i=0; i<(int)roads.size(); ++i) {
			vector<string> t = cutUp(roads[i]);
			if (t.size() == 3) {
				int a = getInd(t[1]);
				int b = getInd(t[2]);
				G[a][b] = G[b][a] = 1;
			} else {
				assert(t.size() == 4);
				int a = getInd(t[1]);
				int b = getInd(t[2]);
				int x;
				sscanf(t[3].c_str(), "%d", &x);
				if (x < repCost[a][b] || x==repCost[a][b] && t[0]<roadId[a][b]) {
					repCost[a][b] = repCost[b][a] = x;
					roadId[a][b] = roadId[b][a] = t[0];
				}
			}
		}

		int n = names.size();
		for (int k=0; k<n; ++k) {
			G[k][k] = 1;
			for (int i=0; i<n; ++i)
				if (G[i][k])
					for (int j=0; j<n; ++j)
						if (G[k][j])
							G[i][j] = 1;
		}

		vector<string> ids;
		while (1) {
			int best = 1234567891;
			int a = -1, b = -1;
			for (int i=0; i<n; ++i)
				for (int j=i+1; j<n; ++j)
					if (!G[i][j])
						if (repCost[i][j] < best || repCost[i][j]==best && roadId[i][j]<roadId[a][b]) {
							best = repCost[i][j];
							a = i;
							b = j;
						}
			if (best == 1234567891)
				break;
			if (best == 1234567890)
				return "IMPOSSIBLE";
			ids.push_back(roadId[a][b]);
			G[a][b] = G[b][a] = 1;
			for (int i=0; i<n; ++i)
				if (G[i][a])
					for (int j=0; j<n; ++j)
						if (G[b][j])
							G[i][j] = 1, G[j][i] = 1;
		}

		sort(ids.begin(), ids.end());
		string sol;
		for (int i=0; i<(int)ids.size(); ++i)
			sol += ' ' +ids[i];
		return sol.size() > 0 ? sol.substr(1) : "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"M1 Moscow Kiev 1", "M2 Minsk Kiev", "M3 Minsk Warsaw"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "M1"; verify_case(0, Arg1, selectReconstruction(Arg0)); }
	void test_case_1() { string Arr0[] = {"R1 NY Washington", "M1 Moscow StPetersburg 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IMPOSSIBLE"; verify_case(1, Arg1, selectReconstruction(Arg0)); }
	void test_case_2() { string Arr0[] = {"B1 Bratislava Havka"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(2, Arg1, selectReconstruction(Arg0)); }
	void test_case_3() { string Arr0[] = {"M1 Moscow StPetersburg 1", "M2 Moscow Saratov 2", "S0 Saratov StPetersburg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "M1"; verify_case(3, Arg1, selectReconstruction(Arg0)); }
	void test_case_4() { string Arr0[] = {"O1 Beetown Fearnot 6","N7 Fearnot Hornytown","M8 Hornytown Belcher 10",
 "L5 Belcher Fearnot 8","C7 Fearnot Beetown 4","K7 Quiggleville Beetown 12",
 "H4 Beetown DryFork 6","Z0 Hornytown Belcher 1","O5 Belcher Quiggleville 10",
 "U7 Quiggleville Fearnot 2","A8 Fearnot Quiggleville 8","T6 Beetown DryFork 17",
 "E8 Quiggleville DryFork 8","Y4 DryFork Quiggleville 4","Q8 Hornytown DryFork 2",
 "J9 Quiggleville DryFork 19","M4 DryFork Quiggleville 7","T1 DryFork Fearnot 9",
 "G4 Fearnot DryFork 6","V9 Hornytown Beetown 5","O6 Quiggleville Beetown 4",
 "L8 Beetown Roachtown 5","D5 Belcher DryFork 8","W5 Belcher DryFork 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C7 L8 U7 W5 Z0"; verify_case(4, Arg1, selectReconstruction(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RoadReconstruction ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

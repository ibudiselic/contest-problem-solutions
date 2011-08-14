#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

int P[2500][2500];
class TournamentSeeding {
	public:
	vector <string> getSeeds(vector <string> teams_, vector <string> games_, vector <int> seeds) {
        vector<string> teams;
        string s;
        for (int i=0; i<(int)teams_.size(); ++i) {
            s += teams_[i];
        }

        {
        istringstream is(s);
        string t;
        while (is >> t) {
            teams.push_back(t);
        }
        }

        sort(teams.begin(), teams.end());

        map<string, int> teamtable;
        int n = teams.size();
        for (int i=0; i<n; ++i) {
            teamtable[teams[i]] = i;
        }

        string g;
        for (int i=0; i<(int)games_.size(); ++i) {
            g += games_[i];
        }

        vector<int> W(n, 0), L(n, 0);
        memset(P, 0, sizeof P);

        {
        istringstream is(g);
        string w, l;
        while (is >> w >> l) {
            ++W[teamtable[w]];
            if (++L[teamtable[l]] > 1) {
                return vector<string>();
            }
            P[teamtable[w]][teamtable[l]] = 1;
            P[teamtable[l]][teamtable[w]] = -1;
        }
        }

        vector<int> current(n, 0);
        for (int i=0; i<n; ++i) {
            current[i] = i;
        }
        vector< vector<int> > gamesplayed(n);
		
        int r = 0;
        while (current.size() > 1) {
            sort(current.begin(), current.end());
            vector<int> advancers;
            for (int i=0; i<(int)current.size(); ++i) {
                if (W[current[i]] > r) {
                    int j;
                    for (j=0; j<n; ++j) {
                        if (P[current[i]][j]==1 && W[j]==r) {
                            break;
                        }
                    }
                    if (j == n) {
                        return vector<string>();
                    }
                    advancers.push_back(current[i]);
                    gamesplayed[current[i]].push_back(j);
                    gamesplayed[j].push_back(current[i]);
                } else if (L[current[i]]==0 && gamesplayed[current[i]].size()==r) {
                    int j;
                    for (j=(int)current.size()-1; j>=0; --j) {
                        if (L[current[j]]==0 && W[current[j]]<=r) {
                            break;
                        }
                    }
                    if (j < 0) {
                        return vector<string>();
                    }
                    advancers.push_back(current[i]);
                    gamesplayed[current[i]].push_back(current[j]);
                    gamesplayed[current[j]].push_back(current[i]);
                    ++L[current[j]];
                }
            }
            current = advancers;
            ++r;
        }

        vector<string> final(n);
        queue<int> Q;
        Q.push(current[0]);
        final[0] = teams[current[0]];

        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            int seed = 0;
            while (teams[cur] != final[seed]) {
                ++seed;
            }

            int n1 = n;
            for (int i=0; i<(int)gamesplayed[cur].size(); ++i, n1/=2) {
                if (final[n1-1-seed] == "") {
                    final[n1-1-seed] = teams[gamesplayed[cur][i]];
                    Q.push(gamesplayed[cur][i]);
                }
            }
        }

        vector<string> ret(seeds.size());
        for (int i=0; i<(int)seeds.size(); ++i) {
            ret[i] = final[seeds[i]];
        }

        return ret;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"CELTICS ", "LAKER", "S SPURS PISTONS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CELTICS LAKERS CELTICS PISTONS LAKERS SPURS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"CELTICS", "LAKERS", "SPURS", "PISTONS" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getSeeds(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"GIANTS PATRIOTS CHARGERS PACKERS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"PATRIOTS CHARGERS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2, 1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"PACKERS", "CHARGERS", "PATRIOTS", "GIANTS" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getSeeds(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"REDSOX PHILLIES METS DODGER",
 "S ORIOLES BLUEJAYS CUBS AN",
 "GELS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"METS ANGELS",
 " METS CU",
 "BS ORIO",
 "LES ANGELS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4, 5, 5, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getSeeds(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"REDSOX PHILLIES METS DODGER",
 "S ORIOLES BLUEJAYS CUBS AN",
 "GELS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"METS ANGELS",
 " METS CU",
 "BS CU",
 "BS DODGERS REDSOX PHILLIES"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"BLUEJAYS", "METS", "CUBS", "REDSOX", "PHILLIES", "DODGERS", "ANGELS", "ORIOLES" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getSeeds(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"A B C D E F 8 H I 3 9 L 4 N O P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"P A B H D C D E E N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2, 0, 0, 3, 4, 7, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"3", "8", "3", "3", "D", "E", "P", "8" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, getSeeds(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"A B C D E F G H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A B C D A C E F"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"A", "E", "G", "C", "D", "H", "F", "B" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, getSeeds(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"NEWYORKISLANDERS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NEWYORKISLANDERS" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(6, Arg3, getSeeds(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TournamentSeeding ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

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

const int INF = 987654321;
int val(char c) {
    if ('a'<=c && c<='z') {
        return c-'a'+27;
    } else if ('A'<=c && c<='Z') {
        return c-'A'+1;
    } else {
        return INF;
    }
}
int G[25][25];
int best[25][1<<13];
int n;
struct state {
    int p, dist, mask;
    state(int p_, int dist_, int mask_): p(p_), dist(dist_), mask(mask_) {}
};
bool operator<(const state &a, const state &b) {
    if (a.dist != b.dist) {
        return a.dist > b.dist;
    } else if (a.p != b.p) {
        return a.p < b.p;
    } else {
        return a.mask < b.mask;
    }
}
class ThirteenHard {
	public:
	int calcTime(vector <string> city) {
	    n = city.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = val(city[i][j]);
                if (G[i][j]%13 == 0) {
                    G[i][j] = INF;
                }
            }
        }
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<(1<<13); ++j) {
                best[i][j] = INF;
            }
        }
        priority_queue<state> PQ;
        PQ.push(state(0, 0, 1));
        best[0][1] = 0;
        while (!PQ.empty()) {
            const state t = PQ.top();
            int p = t.p;
            int dist = t.dist;
            int mask = t.mask;
            PQ.pop();
            
            if (dist > best[p][mask]) {
                continue;
            }
            for (int q=0; q<n; ++q) {
                if (G[p][q] < INF) {
                    int ndist = dist + G[p][q];
                    if (ndist % 13 == 0) {
                        continue;
                    }
                    int nmask = (1<<(G[p][q]%13));
                    for (int i=0; i<13; ++i) {
                        if (mask & (1<<i)) {
                            int x = (i + G[p][q]) % 13;
                            if (x == 0) {
                                ndist = INF+1;
                                break;
                            }
                            nmask |= (1<<x);
                        }
                    }
                    
                    if (ndist < best[q][nmask]) {
                        best[q][nmask] = ndist;
                        PQ.push(state(q, ndist, nmask));
                    }
                }
            }
        }
        
        int sol = INF;
        for (int mask=1; mask<(1<<12); ++mask) {
            sol = min(sol, best[n-1][mask<<1]);
        }
        
        return sol==INF ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "#AB##",
  "###A#",
  "###C#",
  "####K",
  "#####" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, calcTime(Arg0)); }
	void test_case_1() { string Arr0[] = { "#Z",
  "Z#" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, calcTime(Arg0)); }
	void test_case_2() { string Arr0[] = { "Good#####",
  "#Luck####",
  "##and####",
  "##Have###",
  "####Fun##",
  "#####in##",
  "#####the#",
  "CHALLENGE",
  "##PHASE##" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 137; verify_case(2, Arg1, calcTime(Arg0)); }
	void test_case_3() { string Arr0[] = { "###No#####",
  "####Zaphod",
  "#####Just#",
  "######very",
  "####very##",
  "improbable",
  "##########",
  "##########",
  "##########",
  "##########" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 103; verify_case(3, Arg1, calcTime(Arg0)); }
	void test_case_4() { string Arr0[] = { "#B#C##T#M",
  "##K######",
  "########A",
  "####R####",
  "#####U###",
  "########C",
  "#######H#",
  "########S",
  "#########" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; verify_case(4, Arg1, calcTime(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ThirteenHard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

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

struct state {
    int cost, moves, tps, p;
    state(int cost_, int moves_, int tps_, int p_): cost(cost_), moves(moves_), tps(tps_), p(p_) {}
};
bool operator<(const state &a, const state &b) {
    if (a.cost != b.cost) {
        return a.cost > b.cost;
    } else if (a.moves != b.moves) {
        return a.moves > b.moves;
    } else if (a.tps != b.tps) {
        return a.tps > b.tps;
    } else {
        return a.p > b.p;
    }
}

int fewest[50][100001];
int ltp[50][100001];
int best[50];
vector<int> CP;

void go(int c, int m, int t, int p, priority_queue<state> &pq, int tp=-1) {
    if (p<0 || p>=(int)CP.size()) {
        return;
    }
    if (CP[p] == -1) {
        return;
    }

    int nc = c + (tp==-1 ? CP[p] : tp+t);
    int nt = t + (tp!=-1);
    int nm = m + 1;
    if (nc > best[(int)CP.size()-1]) {
        return;
    }
    best[p] = min(best[p], nc);

    if (fewest[p][nc]>nm || ltp[p][nc]>nt) {
        fewest[p][nc] = min(fewest[p][nc], nm);
        ltp[p][nc] = min(ltp[p][nc], nt);
        pq.push(state(nc, nm, nt, p));
    }
}
class CheapestRoute {
	public:
	vector <int> routePrice(vector <int> cellPrice, vector <int> enterCell, vector <int> exitCell, int teleportPrice) {
		memset(fewest, 0x3f, sizeof fewest);
        int inf = 0x3f3f3f3f;
        CP = cellPrice;
        int n = cellPrice.size();
        vector< vector<int> > to(n, vector<int> ());
        memset(best, 0x3f, sizeof best);
        memset(ltp, 0x3f, sizeof ltp);
        for (int i=0; i<(int)enterCell.size(); ++i) {
            if (cellPrice[exitCell[i]] != -1) {
                to[enterCell[i]].push_back(exitCell[i]);
            }
        }

        priority_queue<state> PQ;
        PQ.push(state(0, 0, 0, 0));
        fewest[0][0] = 0;
        best[0] = 0;
        int limit = 1000000;
        while (!PQ.empty() && --limit) {
            const state &s = PQ.top();
            int cost = s.cost;
            int moves = s.moves;
            int tps = s.tps;
            int p = s.p;
            PQ.pop();
            if (cost > 90000) {
                break;
            }

            go(cost, moves, tps, p-1, PQ);
            go(cost, moves, tps, p+1, PQ);
            for (int i=0; i<(int)to[p].size(); ++i) {
                go(cost, moves, tps, to[p][i], PQ, teleportPrice);
            }
        }

        if (best[n-1] >= inf) {
            return vector<int> ();
        }

        vector<int> sol;
        sol.push_back(best[n-1]);
        sol.push_back(fewest[n-1][best[n-1]]);
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000; int Arr4[] = {0, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, routePrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,-1,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000; int Arr4[] = {1000, 2 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, routePrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; int Arr4[] = {5, 2 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, routePrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1,0,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, routePrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {4,2,1,0,5,6,0,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,3,7,5,4,2,5,8,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,3,5,0,5,4,5,0,8,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arr4[] = {14, 6 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, routePrice(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CheapestRoute ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

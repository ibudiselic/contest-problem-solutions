#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <queue>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
int R[10], C[10], T[10];
int nslime;
int D[10][10];
int S[10];
const int inf = 987654321;
int G[50][50];
vector<string> field;
int m, n;
void precalc(int i, int j, int dist[10]) {
    for (int k=0; k<nslime; ++k) {
        dist[k] = inf;
    }
    memset(G, 0xff, sizeof G);
    queue< pair<int, int> > Q;
    Q.push(make_pair(i, j));
    G[i][j] = 0;
    int d = 0;
    int sz = 0;
    while (!Q.empty()) {
        if (sz == 0) {
            sz = Q.size();
            ++d;
        }
        --sz;
        pair<int, int> tmp = Q.front(); Q.pop();
        i = tmp.first;
        j = tmp.second;
        for (int k=0; k<4; ++k) {
            int r = i + di[k];
            int c = j + dj[k];
            if (r<0 || c<0 || r>=m || c>=n || field[r][c]=='#') {
                continue;
            }
            if (field[r][c] < nslime) {
                dist[(int)field[r][c]] = min(dist[(int)field[r][c]], d);
            }
            if (G[r][c] == -1) {
                G[r][c] = d;
                Q.push(make_pair(r, c));
            }
        }
    }
    
}
class SlimeXResidentSlime {
	public:
	int exterminate(vector <string> field_) {
        field = field_;
		int si = -1;
        int sj = -1;
        m = field.size();
        n = field[0].size();
        nslime = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (field[i][j] == '$') {
                    si = i;
                    sj = j;
                    field[i][j] = '.';
                } else if (isdigit(field[i][j])) {
                    R[nslime] = i; 
                    C[nslime] = j;
                    T[nslime] = field[i][j]-'0';
                    field[i][j] = nslime;
                    if (++nslime > 9) {
                        return -1;
                    }
                }
            }
        }
        
        precalc(si, sj, S);
        for (int i=0; i<nslime; ++i) {
            precalc(R[i], C[i], D[i]);
        }
        
        vector<int> order;
        for (int i=0; i<nslime; ++i) {
            order.push_back(i);
        }
        
        int sol = inf;
        do {
            int cand = S[order[0]];
            vector<int> at(nslime, -1);
            at[order[0]] = cand;
            for (int i=0; i+1<nslime; ++i) {
                if (D[order[i]][order[i+1]] == inf) {
                    break;
                }
                cand += D[order[i]][order[i+1]];
                at[order[i+1]] = cand;
            }
            if (cand > sol) {
                continue;
            }
            bool ok = true;
            for (int i=0; i<nslime; ++i) {
                if (at[i]==-1 || cand-at[i]>=T[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                sol = cand;
            }
        } while (next_permutation(order.begin(), order.end()));
        
        return sol==inf ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = 
{
"#1$",
".2."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, exterminate(Arg0)); }
	void test_case_1() { string Arr0[] = {
"$",
"1",
"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, exterminate(Arg0)); }
	void test_case_2() { string Arr0[] = {
"$124"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, exterminate(Arg0)); }
	void test_case_3() { string Arr0[] = {"$.#2"
,"#..1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, exterminate(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SlimeXResidentSlime ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

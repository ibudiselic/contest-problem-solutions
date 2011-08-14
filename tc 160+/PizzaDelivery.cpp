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

int T[20];
int dest[50][50];
int N;
int best[50][50];
const int inf = (1<<29);
struct state {
    int t, i, j;
    state(int t_, int i_, int j_): t(t_), i(i_), j(j_) {}
};
bool operator<(const state &a, const state &b) {
    if (a.t != b.t) {
        return a.t > b.t;
    } else if (a.i != b.i) {
        return a.i < b.i;
    } else {
        return a.j < b.j;
    }
}

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
class PizzaDelivery {
	public:
	int deliverAll(vector <string> terrain) {
        for (int i=0; i<20; ++i) {
            T[i] = inf;
        }
        int si, sj;
        const int m = terrain.size();
        const int n = terrain[0].size();
        memset(dest, 0xff, sizeof dest);
        N = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (terrain[i][j] == 'X') {
                    si = i;
                    sj = j;
                } else if (terrain[i][j] == '$') {
                    dest[i][j] = N++;
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                best[i][j] = inf;
            }
        }
        
        best[si][sj] = 0;
        priority_queue<state> PQ;
        PQ.push(state(0, si, sj));
        while (!PQ.empty()) {
            const state temp = PQ.top();
            PQ.pop();
            const int i = temp.i;
            const int j = temp.j;
            const int t = temp.t;
            if (t > best[i][j]) {
                continue;
            }
            best[i][j] = t;
            if (dest[i][j] != -1) {
                T[dest[i][j]] = t;
            }
            
            for (int d=0; d<4; ++d) {
                const int ii = i + di[d];
                const int jj = j + dj[d];
                if (ii<0 || jj<0 || ii>=m || jj>=n) {
                    continue;
                }
                int nt = t;
                if (terrain[ii][jj]=='X' || terrain[ii][jj]=='$' || terrain[i][j]=='X' || terrain[i][j]=='$') {
                    nt += 2;
                } else {
                    int diff = abs(terrain[i][j] - terrain[ii][jj]);
                    if (diff > 1) {
                        continue;
                    }
                    nt += 1 + (diff==1)*2;
                }
                if (nt < best[ii][jj]) {
                    best[ii][jj] = nt;
                    PQ.push(state(nt, ii, jj));
                }
            }
        }
        
        for (int i=0; i<N; ++i) {
            if (T[i] == inf) {
                return -1;
            }
        }
        
        int sol = inf;
        for (int mask=0; mask<(1<<N); ++mask) {
            int farthest1 = 0;
            int farthest2 = 0;
            int one = 0;
            int two = 0;
            for (int i=0; i<N; ++i) {
                if ((mask>>i) & 1) {
                    farthest1 = max(farthest1, T[i]);
                    one += 2*T[i];
                } else {
                    farthest2 = max(farthest2, T[i]);
                    two += 2*T[i];
                }
            }
            
            sol = min(sol, max(one-farthest1, two-farthest2));
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3442211",
 "34$221X",
 "3442211"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, deliverAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"001000$",
 "$010X0$",
 "0010000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(1, Arg1, deliverAll(Arg0)); }
	void test_case_2() { string Arr0[] = {"001000$",
 "$010X0$",
 "0010000",
 "2232222",
 "2222222",
 "111$111"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, deliverAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"001000$",
 "$010X0$",
 "0010000",
 "1232222",
 "2222222",
 "111$111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, deliverAll(Arg0)); }
	void test_case_4() { string Arr0[] = {"X$$",
 "$$$"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(4, Arg1, deliverAll(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PizzaDelivery ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

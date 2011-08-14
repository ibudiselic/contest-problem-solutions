#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int buddy_index[256];
long long G[100][100];
const string CITY_STRING = "!@#$";
int N;
int F[50][50];
long long C[100];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
vector<string> field;
int getval(int i, int j) {
    const char c = field[i][j];
    if (c == '0') {
        return 100000;
    } else if (c <= '9') {
        return (c-'0')*10000;
    } else if (c <= 'Z') {
        return (c-'A'+1)*100;
    } else {
        return (c-'a'+1);
    }
}
int m, n;
void dfs(int i, int j, int comp) {
    F[i][j] = comp;
    for (int d=0; d<4; ++d) {
        const int r = i + di[d];
        const int c = j + dj[d];
        if (r<0 || c<0 || r>=m || c>=n || F[r][c]!=-1 || field[i][j]!=field[r][c]) {
            continue;
        }
        dfs(r, c, comp);
    }
}
int edges_done[100];
const long long INF = 987654321987654LL;
bool vis[50][50];
void dfs2(int i, int j, int comp) {
    vis[i][j] = 1;
    for (int d=0; d<4; ++d) {
        const int r = i + di[d];
        const int c = j + dj[d];
        if (r<0 || c<0 || r>=m || c>=n) {
            continue;
        }
        if ((F[r][c]==comp || field[r][c]=='.') && !vis[r][c]) {
            dfs2(r, c, comp);
        } else if (F[r][c]!=-1 && F[r][c]!=comp) {
            G[comp][F[r][c]] = C[F[r][c]];
        }
    }
}
long long dp[1<<8][100];
int has_unpaired(int mask) {
    for (int i=0; i<4; ++i) {
        int val = (mask & 3);
        mask >>= 2;
        if (val==1 || val==2) {
            return 1;
        }
    }
    return 0;
}
class BuildingRoads {
	public:
	int destroyRocks(vector <string> field_) {
		memset(buddy_index, 0xff, sizeof buddy_index);
        memset(F, 0xff, sizeof F);
        memset(C, 0, sizeof C);
        field = field_;
        int city_cnt = 0;
        m = field.size();
        n = field[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (CITY_STRING.find(field[i][j]) != string::npos) {
                    if (buddy_index[field[i][j]] == -1) {
                        buddy_index[field[i][j]] = city_cnt;
                        F[i][j] = 2*city_cnt++;
                    } else {
                        F[i][j] = 2*buddy_index[field[i][j]] + 1;
                    }
                }
            }
        }
        N = 2*city_cnt;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (field[i][j]!='.' && F[i][j]==-1) {
                    C[N] = getval(i, j);
                    dfs(i, j, N++);
                }
            }
        }
        
        memset(edges_done, 0, sizeof edges_done);
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                G[i][j] = G[j][i] = INF;
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (F[i][j]!=-1 && !edges_done[F[i][j]]) {
                    edges_done[F[i][j]] = true;
                    memset(vis, 0, sizeof vis);
                    dfs2(i, j, F[i][j]);
                }
            }
        }
        
        for (int k=0; k<N; ++k) {
            for (int i=0; i<N; ++i) {
                if (G[i][k] < INF) {
                    for (int j=0; j<N; ++j) {
                        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                    }
                }
            }
        }

        city_cnt *= 2;
        for (int i=0; i<(1<<city_cnt); ++i) {
            for (int j=0; j<N; ++j) {
                dp[i][j] = INF;
            }
        }
        for (int i=0; i<city_cnt; ++i) {
            dp[1<<i][i] = 0;
        }
        
        for (int city_mask=1; city_mask<(1<<city_cnt); ++city_mask) {
            for (int u=0; u<N; ++u) {
                if (dp[city_mask][u] < INF) {
                    continue;
                }
                for (int submask=(city_mask-1)&city_mask; submask>0; submask=(submask-1)&city_mask) {
                    dp[city_mask][u] = min(dp[city_mask][u],
                                            dp[submask][u] + dp[city_mask-submask][u]
                                            - has_unpaired(submask)*has_unpaired(city_mask-submask)*C[u]); // only subtract if both actually built roads to get to u
                }
            }
            for (int u=0; u<N; ++u) {
                for (int v=0; v<N; ++v) {
                    dp[city_mask][u] = min(dp[city_mask][u], dp[city_mask][v] + has_unpaired(city_mask)*G[v][u]); // only add cost if we build a road for some pair
                }
            }
        }
        
        return int(*min_element(dp[(1<<city_cnt)-1], dp[(1<<city_cnt)-1] + N));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"!1.!",
 "aab2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, destroyRocks(Arg0)); }
	void test_case_1() { string Arr0[] = {"#@",
 "A.",
 "A1",
 "@#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(1, Arg1, destroyRocks(Arg0)); }
	void test_case_2() { string Arr0[] = {"$....",
 "BBBBB",
 "B000B",
 "B0$0B",
 "B000B",
 "BBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100200; verify_case(2, Arg1, destroyRocks(Arg0)); }
	void test_case_3() { string Arr0[] = {"$a",
 ".B",
 "$3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, destroyRocks(Arg0)); }
	void test_case_4() { string Arr0[] = {".#!@.$",
 ".11111",
 "..AB..",
 "33AB..",
 "$3AB..",
 "88888a",
 "#!@..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30301; verify_case(4, Arg1, destroyRocks(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BuildingRoads ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

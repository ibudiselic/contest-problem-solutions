#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

vector<string> A;
int m, n;
long long dist[20][20][20][20];
bool done[3000][20];
int T[20][2];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
void calc_dist(int si, int sj) {
    queue< pair<int, int> > Q;
    memset(done, 0, sizeof done);
    int offset = 30*m;
    si += offset;
    done[si][sj] = 1;
    Q.push(make_pair(si, sj));
    int cur = 0;
    dist[si-offset][sj][si-offset][sj] = 0;
    int layer_sz = 0;
    
    while (!Q.empty()) {
        if (layer_sz == 0) {
            layer_sz = Q.size();
            ++cur;
        }
        const pair<int, int> t = Q.front();
        int i = t.first;
        int j = t.second;
        Q.pop();
        --layer_sz;

        for (int d=0; d<4; ++d) {
            const int r = i + di[d];
            const int c = j + dj[d];
            if (r<0 || c<0 || r>=60*m || c>=n || done[r][c] || A[r%m][c]=='#') {
                continue;
            }
            done[r][c] = 1;
            if (r-offset>=0 && r-offset<m) {
                dist[si-offset][sj][r-offset][c] = cur;
            }
            Q.push(make_pair(r, c));
        }

        if (A[i%m][j] == 'T') {
            const int r = i;
            const int c = (j==T[i%m][0] ? T[i%m][1] : T[i%m][0]);
            assert(A[r%m][c] == 'T');
            if (!done[r][c]) {
                done[r][c] = 1;
                if (r-offset>=0 && r-offset<m) {
                    dist[si-offset][sj][r-offset][c] = cur;
                }
                Q.push(make_pair(r, c));
            }
        }
    }
}

const long long inf = (1LL<<62)-50;
bool is_valid_col[20];

long long price[64][20][20]; // [segment_cnt_exponent][enter_col][exit_col]
long long best[2][20][20]; // [enter_col][exit_col], two rows for DP
class InfiniteLab {
	public:
	long long getDistance(vector <string> A_, long long r1, int c1, long long r2, int c2) {
	    A = A_;
        m = A.size();
        n = A[0].size();
        
        memset(T, 0xff, sizeof T);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] == 'T') {
                    if (T[i][0] == -1) {
                        T[i][0] = j;
                    } else {
                        T[i][1] = j;
                    }
                }
            }
        }
        
        for (int j=0; j<n; ++j) {
            is_valid_col[j] = (A[0][j]!='#' && A[m-1][j]!='#');
        }

        memset(dist, 0xff, sizeof dist);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] != '#') {
                    calc_dist(i, j);
                }
            }
        }
        
        if (r1 > r2) {
            swap(r1, r2);
            swap(c1, c2);
        }
        
        if (r1 < 0) {
            long long segs = (-r1+m-1)/m;
            r1 += segs*m;
            r2 += segs*m;
        } else if (r1 >= m) {
            long long segs = r1/m;
            r1 -= segs*m;
            r2 -= segs*m;
        }
        assert(r1>=0 && r1<m);
        
        if (r2 < m) {
            return dist[r1][c1][r2][c2];
        } else if (r2 < 2*m) {
            r2 -= m;
            long long sol = inf;
            for (int c=0; c<n; ++c) {
                if (dist[r1][c1][m-1][c]!=-1 && dist[0][c][r2][c2]!=-1) {
                    sol = min(sol, dist[r1][c1][m-1][c] + dist[0][c][r2][c2] + 1);
                }
            }
            return sol==inf ? -1 : sol;
        } else {
            for (int k=0; k<64; ++k) {
                for (int i=0; i<20; ++i) {
                    for (int j=0; j<20; ++j) {
                        price[k][i][j] = inf;
                    }
                }
            }
            
            for (int j1=0; j1<n; ++j1) {
                for (int j2=0; j2<n; ++j2) {
                    if (dist[0][j1][m-1][j2] != -1) {
                        price[0][j1][j2] = dist[0][j1][m-1][j2];
                    }
                }
            }
            
            long long seg_cnt = r2/m - r1/m - 1;
            assert(seg_cnt >= 1);
            long long cur = 2;
            long long len_exp = 1;
            while (cur <= seg_cnt) {
                for (int j1=0; j1<n; ++j1) {
                    for (int j2=0; j2<n; ++j2) {
                        for (int j3=0; j3<n; ++j3) {
                            price[len_exp][j1][j3] = min(price[len_exp][j1][j3],
                                    price[len_exp-1][j1][j2] + price[len_exp-1][j2][j3] + 1);
                        }
                    }
                }
                cur <<= 1;
                ++len_exp;
            }
            
            for (int i=0; i<2; ++i) {
                for (int j=0; j<n; ++j) {
                    for (int k=0; k<n; ++k) {
                        best[i][j][k] = inf;
                    }
                }
            }
            for (int c=0; c<n; ++c) {
                if (is_valid_col[c]) {
                    best[0][c][c] = -1;
                }
            }
            len_exp = 0;
            cur = 1;
            while (cur <= seg_cnt) {
                if (seg_cnt & cur) {
                    for (int i=0; i<n; ++i) {
                        for (int j=0; j<n; ++j) {
                            best[(len_exp+1)&1][i][j] = inf;
                            for (int c=0; c<n; ++c) {
                                best[(len_exp+1)&1][i][j] = min(best[(len_exp+1)&1][i][j],
                                        best[len_exp&1][i][c] + price[len_exp][c][j] + 1);
                            }
                        }
                    }
                } else {
                    memcpy(best[(len_exp+1)&1], best[len_exp&1], sizeof best[(len_exp+1)&1]);
                }
                cur <<= 1;
                ++len_exp;
            }
            
            r2 %= m;
            long long sol = inf;
            for (int j1=0; j1<n; ++j1) {
                for (int j2=0; j2<n; ++j2) {
                    if (dist[r1][c1][m-1][j1]!=-1 && dist[0][j2][r2][c2]!=-1) {
                        sol = min(sol, dist[r1][c1][m-1][j1] + best[len_exp&1][j1][j2] + dist[0][j2][r2][c2] + 2);
                    }
                }
            }
            return sol==inf ? -1 : sol;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#...##",
 ".##...",
 "..#.##",
 "#.#.##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; int Arg2 = 0; long long Arg3 = 5LL; int Arg4 = 3; long long Arg5 = 7LL; verify_case(0, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"##.#.",
 ".#T#T",
 "...#.",
 "##.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; int Arg2 = 4; long long Arg3 = 1LL; int Arg4 = 0; long long Arg5 = 9LL; verify_case(1, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"..######.#",
 ".###T###.T",
 "..T#.##T##",
 ".######..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; int Arg2 = 0; long long Arg3 = 6LL; int Arg4 = 4; long long Arg5 = 11LL; verify_case(2, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"..#..",
 ".#.#.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -29LL; int Arg2 = 2; long long Arg3 = 19LL; int Arg4 = 2; long long Arg5 = 54LL; verify_case(3, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {".#.#.",
 "..#..",
 ".....",
 ".....",
 "..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -999LL; int Arg2 = 3; long long Arg3 = 100LL; int Arg4 = 2; long long Arg5 = -1LL; verify_case(4, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    InfiniteLab ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

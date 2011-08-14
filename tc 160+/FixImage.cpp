#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <set>

using namespace std;

struct Block {
    int sz;
    vector< pair<int, int> > hor;
    vector< pair<int, int> > ver;
    Block(int sz_, const vector< pair<int, int> > &h, const vector< pair<int, int> > &v): sz(sz_), hor(h), ver(v) {}
};
bool operator<(const Block &a, const Block &b) {
    if (a.sz != b.sz) {
        return a.sz < b.sz;
    }
    if (a.hor != b.hor) {
        return a.hor < b.hor;
    }
    return a.ver < b.ver;
}

int C[50][50];
vector<string> A;
int M, N;
set<Block> S;

inline bool valid(int i, int j) {
    if (i<0 || j<0 || i>=M || j>=N) {
        return false;
    }
    return true;
}
int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
int dfs(int i, int j, int comp, vector< pair<int, int> > &h, vector< pair<int, int> > &v) {
    C[i][j] = comp;
    int ret = 0;
    h[i].first = min(h[i].first, j);
    h[i].second = max(h[i].second, j);
    v[j].first = min(v[j].first, i);
    v[j].second = max(v[j].second, i);

    for (int d=0; d<4; ++d) {
        int r = i + di[d];
        int c = j + dj[d];
        if (valid(r, c) && A[r][c]=='#' && C[r][c]==-1) {
            ret += dfs(r, c, comp, h, v);
        }
    }

    return ret;
}

class FixImage {
	public:
	vector <string> originalImage(vector <string> A_) {
        A = A_;
        M = A.size();
        N = A[0].size();
        S.clear();

        while (1) {
            bool change = false;
            memset(C, 0xff, sizeof C);
            int comp = 0;
            for (int i=0; i<M; ++i) {
                for (int j=0; j<N; ++j) {
                    if (A[i][j]=='#' && C[i][j]==-1) {
                        vector< pair<int, int> > h(M, make_pair(123, -1));
                        vector< pair<int, int> > v(N, make_pair(123, -1));
                        int sz = dfs(i, j, comp++, h, v);
                        Block B(sz, h, v);
                        if (S.count(B)) {
                            continue;
                        }
                        S.insert(B);
                        int d = 0;
                        for (int r=0; r<M; ++r) {
                            int a = h[r].first;
                            int b = h[r].second;
                            if (a == 123) {
                                continue;
                            }
                            while (++a < b) {
                                if (A[r][a] != '#') {
                                    ++d;
                                    A[r][a] = '#';
                                    C[r][a] = comp-1;
                                }
                            }
                        }

                        for (int c=0; c<N; ++c) {
                            int a = v[c].first;
                            int b = v[c].second;
                            if (a == 123) {
                                continue;
                            }
                            while (++a < b) {
                                if (A[a][c] != '#') {
                                    ++d;
                                    A[a][c] = '#';
                                    C[a][c] = comp-1;
                                }
                            }
                        }

                        if (d > 0) {
                            change = true;
                            B.sz += d;
                            S.insert(B);
                        }
                    }
                }
            }

            if (!change) {
                break;
            }
        }

        return A;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"....",
 ".##.",
 ".##.",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"....", ".##.", ".##.", "...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, originalImage(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
 ".###.",
 ".#.#.",
 ".###.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".....", ".###.", ".###.", ".###.", "....." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, originalImage(Arg0)); }
	void test_case_2() { string Arr0[] = {".......",
 ".###...",
 ".#..##.",
 ".###.#.",
 ".....#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".......", ".###...", ".#####.", ".#####.", ".....#." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, originalImage(Arg0)); }
	void test_case_3() { string Arr0[] =  {".................",
 "#####.#..#..#####",
 "..#...#..#....#..",
 "..#...#..###..#..",
 "................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".................", "#####.#..#..#####", "..#...#..#....#..", "..#...#..###..#..", "................." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, originalImage(Arg0)); }
	void test_case_4() { string Arr0[] =  {"###.####",
  "#.#.#..#",
  ".#...#.#",
  ".#####.#",
  "......#.",
  "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"########", "########", "########", "########", "########", "########" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, originalImage(Arg0)); }
	void test_case_5() { string Arr0[] = {"..###..",
 "..#.#..",
 "##...##",
 "#.....#",
 "#.....#",
 "#.....#",
 "##...##",
 "..#.#..",
 "..###.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..###..", "..###..", "##...##", "##...##", "##...##", "##...##", "##...##", "..###..", "..###.." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, originalImage(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FixImage ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

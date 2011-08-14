#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int mask2id[1<<23];
vector<int> id2mask;
void generate_masks(int p, int lim, int cur) {
    if (p >= lim) {
        mask2id[cur] = id2mask.size();
        id2mask.push_back(cur);
    } else {
        generate_masks(p+1, lim, cur);
        if (p+1 < lim) {
            generate_masks(p+2, lim, cur | (3<<p));
        }
    }
}
int dp[3][46368]; // Fib(24)
int inf;
int shapes[4];
const int horiz[4] = { 3, 2, 1, 1 }; // horizontal sizes of shapes
int advance(int x, int by) {
    int ret = x + by;
    if (ret > 2) {
        ret -= 3;
    }
    return ret;
}
class BrickPuzzle {
	public:
	int leastShapes(vector <string> board) {
        const int H = board.size();
        const int W = board[0].size();
		id2mask.clear();
        memset(mask2id, 0xff, sizeof mask2id);
        generate_masks(0, W+1, 0);
        assert(id2mask.size() <= 46368);
        
        shapes[0] = 15;
        shapes[1] = 3 | (6<<W);
        shapes[2] = 3 | (3<<W);
        shapes[3] = 3 | (3<<(W-1));
        
        memset(&inf, 0x3f, sizeof inf);
        memset(dp, 0x3f, sizeof dp);
        
        int p = 0;
        dp[0][mask2id[0]] = 0;
        for (int h=0; h<H; ++h) {
            for (int w=0; w<W; ++w) {
                for (int id=0; id<(int)id2mask.size(); ++id) {
                    if (dp[p][id] < inf) {
                        int mask = id2mask[id];
                        if (mask & 1) {
                            // can't put shape
                            assert(w+1 < W);
                            assert(mask & 2);
                            int nid = mask2id[mask>>2];
                            assert(nid != -1);
                            int np = advance(p, 2);
                            dp[np][nid] = min(dp[np][nid], dp[p][id]);
                            continue;
                        }
                        
                        if (board[h][w] == 'X') {
                            // try not putting a shape
                            int nid = mask2id[mask>>1];
                            assert(nid != -1);
                            int np = advance(p, 1);
                            dp[np][nid] = min(dp[np][nid], dp[p][id]);
                        }
                        
                        // put shape starting at (h, w)
                        int np = advance(p, 2);
                        for (int i=0; i<4; ++i) {
                            if (w+horiz[i]<W && (i==0 || h+1<H) && (i!=3 || w>0) && (mask&shapes[i])==0) {
                                int nid = mask2id[(mask|shapes[i]) >> 2];
                                assert(nid != -1);
                                dp[np][nid] = min(dp[np][nid], dp[p][id] + 1);
                            }
                        }
                    }
                }
                
                memset(dp[p], 0x3f, sizeof dp[p]);
                p = advance(p, 1);
            }
        }
        
        int sol = dp[p][mask2id[0]];
        return sol==inf ? -1 : sol;
	}





   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..X....",
 "..XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, leastShapes(Arg0)); }
	void test_case_1() { string Arr0[] = {".X",
 "..",
 "X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, leastShapes(Arg0)); }
	void test_case_2() { string Arr0[] = {"..XX....",
 "....X..X",
 "XX..XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, leastShapes(Arg0)); }
	void test_case_3() { string Arr0[] = {"X..XXXX",
 "X.....X",
 "....XX.",
 "X......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, leastShapes(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BrickPuzzle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

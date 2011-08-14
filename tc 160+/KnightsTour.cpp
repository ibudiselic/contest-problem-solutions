#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int dj[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
bool V[8][8];

bool valid(int i, int j) {
    if (i<0 || j<0 || i>=8 || j>=8) {
        return false;
    } else {
        return true;
    }
}
int get_rating(int i, int j) {
    int ret = 0;
    for (int d=0; d<8; ++d) {
        const int r = i + di[d];
        const int c = j + dj[d];
        if (valid(r, c) && !V[r][c]) {
            ++ret;
        }
    }
    return ret;
}
int go(int i, int j) {
    V[i][j] = 1;
    int ii=-1, jj=-1;
    int lowest = 123456;
    for (int d=0; d<8; ++d) {
        const int r = i + di[d];
        const int c = j + dj[d];
        if (valid(r, c) && !V[r][c]) {
            const int t = get_rating(r, c);
            if (t < lowest) {
                lowest = t;
                ii = r;
                jj = c;
            }
        }
    }
    if (ii == -1) {
        return 1;
    } else {
        return 1 + go(ii, jj);
    }
}
class KnightsTour {
	public:
	int visitedPositions(vector <string> board) {
		memset(V, 0, sizeof V);
        int si=-1, sj=-1;
        for (int i=0; i<8; ++i) {
            for (int j=0; j<8; ++j) {
                if (board[i][j] == 'K') {
                    si = i;
                    sj = j;
                }
                if (board[i][j] != '.') {
                    V[i][j] = 1;
                }
            }
        }
        
        return go(si, sj);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"........"
,".*.*...."
,".*......"
,"..K...*."
,"*...*..."
,"...*...."
,"...*.*.."
,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(0, Arg1, visitedPositions(Arg0)); }
	void test_case_1() { string Arr0[] = {"K......."
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, visitedPositions(Arg0)); }
	void test_case_2() { string Arr0[] = {"********"
,"*******."
,"********"
,"**.***.*"
,"********"
,"***.*.**"
,"********"
,"****K***"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, visitedPositions(Arg0)); }
	void test_case_3() { string Arr0[] = {"*.*....*"
,".......*"
,"**...*.."
,"..***..."
,".**.*..."
,"..*.*..K"
,"..***.*."
,"**...*.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(3, Arg1, visitedPositions(Arg0)); }
	void test_case_4() { string Arr0[] = {"..*...*."
,"**.....*"
,"*..*...."
,"*..*...."
,".....*.."
,"....*..K"
,"**.*...*"
,"..**...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(4, Arg1, visitedPositions(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KnightsTour ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

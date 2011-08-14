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



const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const int P[][6] = { { 3, 0, 1, 2, 4, 5 },
                     { 4, 1, 5, 3, 2, 0 },
                     { 1, 2, 3, 0, 4, 5 },
                     { 5, 1, 4, 3, 0, 2 } };
vector<string> F;
bool v[6][6];
int C[6];
int X[6];
int m, n;
void go(int i, int j) {
    v[i][j] = 1;
    assert(F[i][j] == '#');
    if (X[C[0]]==-1 || X[C[0]]==i*n+j) {
        X[C[0]] = i*n + j;
    } else {
        X[C[0]] = -2;
        return;
    }

    int T[6];
    for (int d=0; d<4; ++d) {
        int r = i + di[d];
        int c = j + dj[d];
        if (r<0 || c<0 || r>=m || c>=n || v[r][c] || F[r][c]!='#') {
            continue;
        }
        memcpy(T, C, sizeof T);
        for (int i=0; i<6; ++i) {
            C[P[d][i]] = T[i];
        }
        go(r, c);
        memcpy(C, T, sizeof C);
    }
}

class CubeNets {
	public:
	string isCubeNet(vector <string> figure) {
        m = figure.size();
        n = figure[0].size();
        F = figure;

        for (int i=0; i<6; ++i) {
            C[i] = i;
        }
        memset(X, 0xff, sizeof X);

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (F[i][j] == '#') {
                    memset(v, 0, sizeof v);
                    go(i, j);
                    for (int i=0; i<6; ++i) {
                        if (X[i] < 0) {
                            return "NO";
                        }
                    }
                    return "YES";
                }
            }
        }

        return "NO";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..#.",
 "####",
 "..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isCubeNet(Arg0)); }
	void test_case_1() { string Arr0[] = {"###",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, isCubeNet(Arg0)); }
	void test_case_2() { string Arr0[] = {"..#.",
"####",
".#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isCubeNet(Arg0)); }
	void test_case_3() { string Arr0[] = {"##..",
 ".##.",
 "..##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(3, Arg1, isCubeNet(Arg0)); }
	void test_case_4() { string Arr0[] = {"####",
 "...#",
 "...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isCubeNet(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CubeNets ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
bool G[50][50];
int C[50];
int dfs(int x, int comp) {
    int ret = 1;
    C[x] = comp;
    for (int i=0; i<N; ++i) {
        if (G[x][i] && C[i]==-1) {
            ret += dfs(i, comp);
        }
    }
    return ret;
}
class StrangeCountry {
	public:
	int transform(vector <string> g) {
		N = g.size();
        int edges = 0;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                G[i][j] = (g[i][j]=='Y');
                if (j>i && G[i][j]) {
                    ++edges;
                }
            }
        }
        
        cerr << N << ' ' << edges << '\n';
        if (edges < N-1) {
            return -1;
        }
        
        memset(C, 0xff, sizeof C);
        int comp = 0;
        for (int i=0; i<N; ++i) {
            if (C[i] == -1) {
                if(dfs(i, comp++) == 1) {
                    return -1;
                }
            }
        }
        
        return comp - 1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, transform(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYNN",
 "YNYNN",
 "YYNNN",
 "NNNNY",
 "NNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, transform(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYYNNNN",
 "YNYNNNN",
 "YYNNNNN",
 "NNNNYYN",
 "NNNYNYY",
 "NNNYYNY",
 "NNNNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, transform(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNYNNNNNNNN",
 "YNYNNNNNNNNN",
 "NYNYYNNNNNNN",
 "YNYNNNNNNNNN",
 "NNYNNYYNNNNN",
 "NNNNYNYNNNNN",
 "NNNNYYNNNNNN",
 "NNNNNNNNYYNN",
 "NNNNNNNYNYNN",
 "NNNNNNNYYNNN",
 "NNNNNNNNNNNY",
 "NNNNNNNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, transform(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYNNNN",
 "YNYNNN",
 "NYNYNN",
 "NNYNNN",
 "NNNNNY",
 "NNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, transform(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StrangeCountry ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

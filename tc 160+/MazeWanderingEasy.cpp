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

bool done[50][50];
int val[50][50];
class MazeWanderingEasy {
	public:
	int decisions(vector <string> maze) {
		int m = maze.size();
        int n = maze[0].size();
        
        int si = -1;
        int sj = -1;
        int ei = -1;
        int ej = -1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (maze[i][j] == 'M') {
                    si = i; sj = j;
                } else if (maze[i][j] == '*') {
                    ei = i; ej = j;
                }
            }
        }
        
        memset(done, 0, sizeof done);
        done[si][sj] = 1;
        queue< pair<int, int> > Q;
        Q.push(make_pair(si, sj));
        
        while (!Q.empty()) {
            int i = Q.front().first;
            int j = Q.front().second;
            Q.pop();
            
            if (i==ei && j==ej) {
                return val[i][j];
            }
            
            int cnt = 0;
            for (int di=-1; di<2; ++di) {
                for (int dj=-1; dj<2; ++dj) {
                    if (abs(di) + abs(dj) == 1) {
                        const int r = i + di;
                        const int c = j + dj;
                        if (r<0 || r>=m || c<0 || c>=n || done[r][c] || maze[r][c]=='X') {
                            continue;
                        }
          
                        ++cnt;
                    }
                }
            }
            for (int di=-1; di<2; ++di) {
                for (int dj=-1; dj<2; ++dj) {
                    if (abs(di) + abs(dj) == 1) {
                        const int r = i + di;
                        const int c = j + dj;
                        if (r<0 || r>=m || c<0 || c>=n || done[r][c] || maze[r][c]=='X') {
                            continue;
                        }
          
                        done[r][c] = 1;
                        val[r][c] = val[i][j] + (cnt>1);
                        Q.push(make_pair(r, c));
                    }
                }
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"*.M"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, decisions(Arg0)); }
	void test_case_1() { string Arr0[] = {"*.M",
 ".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, decisions(Arg0)); }
	void test_case_2() { string Arr0[] = {"...",
 "XMX",
 "..*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, decisions(Arg0)); }
	void test_case_3() { string Arr0[] = {".X.X......X",
 ".X*.X.XXX.X",
 ".XX.X.XM...",
 "......XXXX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, decisions(Arg0)); }
	void test_case_4() { string Arr0[] = {"..........*",
 ".XXXXXXXXXX",
 "...........",
 "XXXXXXXXXX.",
 "M.........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, decisions(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MazeWanderingEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

typedef struct Entry Entry;
struct Entry {
  int x, y;
  int len;
};
bool in, out;
bool used[51][51];
bool adj[51][51][51][51];
int sgn(int x)
{
  return (x<0) ? -1 : 1;
}
int sqr(int x)
{
  return x*x;
}
void test(int sx, int sy, int x, int y, int r)
{
  int t = sqr(sx-x)+sqr(sy-y);
  int v = sqr(r);
  if (t > v)
    out = true;
  else if (t < v)
    in = true;
}
bool i_can(const vector<string>& g, int sx, int sy, int x, int y, int i, int j, int r)
{
  for (int xx=min(x, i); xx<max(x, i); ++xx)
    for (int yy=min(y, j); yy<max(y, j); ++yy) {
      if (g[xx][yy] == '.') continue;
      in = out = false;
      test(sx, sy, xx, yy, r);
      test(sx, sy, xx+1, yy, r);
      test(sx, sy, xx, yy+1, r);
      test(sx, sy, xx+1, yy+1, r);
      if (in & out)
        return false;
    }
  return true;
}
void precompute(const vector<string>& g, int maxx, int maxy)
{
  for (int x=0; x<=maxx; ++x)
    for (int y=0; y<=maxy; ++y)
      for (int i=0; i<=maxx; ++i)
        for (int j=0; j<=maxy; ++j) {
          // test (x,y)->(i,j)
          adj[x][y][i][j] = false;
          if ((i==x && j==y) || abs(x-i)!=abs(y-j)) continue; //can't make arc
          int r = abs(x-i);
          int sx = x;
          int sy = j;
          /*if (x==1 && y==1 && i==2 && j==2) {
            cerr << sx << '*'<< sy << ' ' << r << endl;
            cerr << i_can(g, sx, sy, x, y, i, j, r) << endl;
          }*/
          if (i_can(g, sx, sy, x, y, i, j, r)) {
            adj[x][y][i][j] = true;
            continue;
          }
          sx = i; sy = y;
          /*if (x==1 && y==1 && i==2 && j==2) {
            cerr << sx << '*'<< sy << ' ' << r << endl;
            cerr << i_can(g, sx, sy, x, y, i, j, r) << endl;
          }*/
          if (i_can(g, sx, sy, x, y, i, j, r)) {
            adj[x][y][i][j] = true;
            continue;
          }
        }
}         
int bfs(int tx, int ty)
{
  Entry tmp;
  tmp.x = 0;
  tmp.y = 0;
  tmp.len = 0;
  queue<Entry> q;
  
  q.push(tmp);
  while (!q.empty()) {
    tmp = q.front();
    q.pop();
    used[tmp.x][tmp.y] = true;
    //cerr << tmp.x << ' ' << tmp.y << "--->" << endl;
    for (int i=0; i<=tx; ++i)
      for (int j=0; j<=ty; ++j)
        if (adj[tmp.x][tmp.y][i][j] && !used[i][j]) {
          //cerr << "    " << i << ' ' << j << endl;
          if (i==tx && j==ty)
            return tmp.len+1;
          used[i][j] = true;
          Entry t;
          t.x = i; t.y = j; t.len = tmp.len+1;
          q.push(t);
        }
  }
  return -1;
}
class Arcs {
  public:
  int numArcs(vector <string> grid) {
    const int X = grid.size();
    const int Y = grid[0].size();
    memset(used, false, sizeof used);
    precompute(grid, X, Y);
   /*for (int x=0; x<X; ++x)
    for (int y=0; y<Y; ++y)
      for (int i=0; i<=X; ++i)
        for (int j=0; j<=Y; ++j)
          if (adj[x][y][i][j])
            cerr << x << ',' << y << "-->" << i << ',' << j << endl;*/
    return bfs(X, Y);
  }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "..",
  ".." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numArcs(Arg0)); }
	void test_case_1() { string Arr0[] = { "...",
  "..." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, numArcs(Arg0)); }
	void test_case_2() { string Arr0[] = { "....",
  ".##.",
  ".##.",
  ".##.",
  ".##.",
  "...." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, numArcs(Arg0)); }
	void test_case_3() { string Arr0[] =   { "....########",
    "###..###...#",
    "..##..#.##.#",
    "...##..#...#",
    "....#..#...#",
    "....#..###..",
    "....####.##.",
    "..........#." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, numArcs(Arg0)); }
	void test_case_4() { string Arr0[] = { ".....#................",
  "....#.................",
  "....#.................",
  "....#.....#...........",
  "....#.................",
  "....#....#.#..........",
  "....#.......#####.....",
  "....#.....#.....#.....",
  "....#.....#.....#.....",
  "....#....#.#....#.....",
  "....#....#.#.....#....",
  "....#....#.#......#...",
  "....#....#.#.##.#..###",
  "....#....#....#......." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, numArcs(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Arcs ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

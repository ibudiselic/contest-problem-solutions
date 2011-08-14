#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -1, -1, 0, 1, 1,  1,  0, -1 };
const int dj[] = {  0,  1, 1, 1, 0, -1, -1, -1 };
int n, m;
bool used[50][50];
vector<string> a;
class SysFailure {
	public:
	int dfs(int i, int j) {
	  int ret = 1;
	  used[i][j] = 1;
	  for (int dir=0; dir<8; ++dir) {
	    const int ii = i + di[dir];
	    const int jj = j + dj[dir];
	    if (ii>=0 && ii<m && jj>=0 && jj<n && a[ii][jj]=='1' && !used[ii][jj])
	      ret += dfs(ii, jj);
	  }
	  return ret;
	}
	  
	int critical(int cnt, vector <string> state) {
		m = state.size();
		n = state[0].size();
		a = state;
		int sol = 0;
		int cur = 0;
		memset(used, 0, sizeof used);
		for (int i=0; i<m; ++i)
		  for (int j=0; j<n; ++j)
		    if (a[i][j]=='1' && !used[i][j])
		      cur = max(cur, dfs(i, j));
		if (cur < cnt)
		  return -1;
		  
		for (int i=0; i<m; ++i)
		  for (int j=0; j<n; ++j)
		    if (a[i][j] == '1') {
		      a[i][j] = '0';
		      memset(used, 0, sizeof used);
		      cur = 0;
		      for (int r=0; r<m; ++r)
		        for (int c=0; c<n; ++c)
		          if (a[r][c]=='1' && !used[r][c])
		            cur = max(cur, dfs(r, c));
		      if (cur < cnt)
		        ++sol;
		      a[i][j] = '1';
		    }
	  return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; string Arr1[] = { "00000",
  "00000",
  "11111" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, critical(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; string Arr1[] = { "01010",
  "10001",
  "11011",
  "10001",
  "01010"} ; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, critical(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arr1[] = { "111",
  "111" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, critical(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; string Arr1[] = { "101" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, critical(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SysFailure ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

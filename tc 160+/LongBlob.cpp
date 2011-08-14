#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;
const int dr[] = { 1, 0, -1, 0 }; 
const int dc[] = { 0, 1, 0, -1 }; 
bool used[25][25];

inline int sqr(int x) {
  return x*x;
}

class LongBlob {
	public:
	double maxLength(vector <string> a) {
		const int R = a.size();
		const int C = a[0].size();
		memset(used, 0, sizeof used);
		int best = 0;
		
		for (int r=0; r<R; ++r)
		  for (int c=0; c<C; ++c) {
		    vector<pii> q;
		    vector<pii> next;
		    memset(used, 0, sizeof used);
		    q.push_back(make_pair(r, c));
		    used[r][c] = 1;
		    int n = (a[r][c]=='1');
		    while (n <= 4) {
		    while (!q.empty()) {
		      const int rr = q.back().first;
		      const int cc = q.back().second;
		      best = max(best, sqr(rr-r)+sqr(cc-c));
		      q.pop_back();
		      for (int dir=0; dir<4; ++dir) {
		        const int i = rr + dr[dir];
		        const int j = cc + dc[dir];
		        if (i>=0 && i<R && j>=0 && j<C && !used[i][j]) {
		          used[i][j] = 1;
		          if (a[i][j] == '1')
		            next.push_back(make_pair(i, j));
		          else
		            q.push_back(make_pair(i, j));
		        }
		      }
		    }
		    q = next;
		    next.clear();
		    ++n;
		    }
		  }
	  return sqrt((double)best);  
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0010",
 "1001",
 "0011",
 "0111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.242640687119285; verify_case(0, Arg1, maxLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"101010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 7.0; verify_case(1, Arg1, maxLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101",
 "0101010101010101010101010",
 "1010101010101010101010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 8.0; verify_case(2, Arg1, maxLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"01011",
 "11100",
 "01110",
 "11111",
 "01011",
 "11111"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.656854249492381; verify_case(3, Arg1, maxLength(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LongBlob ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

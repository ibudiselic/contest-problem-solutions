#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

bool a[50][50];
bool super[50];
class BobTrouble {
	public:
	int minSupers(vector <string> name, vector <string> boss) {
		vector<int> bobs;
		map<string, int> ind;
		bobs.push_back(-1);
		for (int i=0; i<(int)name.size(); ++i)
		  if (name[i] == "BOB")
		    bobs.push_back(i);
		  else
		    ind[name[i]] = i;
		    
		int sol = 51;
		int cnt = 0;
		for (int x=0; x<(int)bobs.size(); ++x) {
		  memset(a, 0, sizeof a);
		  memset(super, 0, sizeof super);
		  for (int i=0; i<(int)boss.size(); ++i)
		    if (boss[i] == "BOB") {
		      if (x==0)
		        goto skip;
		      a[i][bobs[x]] = 1;
		      super[bobs[x]] = 1;
		    } else if (boss[i] != "*") {
		      const int b = ind[boss[i]];
		      a[i][b] = 1;
		      super[b] = 1;
		    }
		  for (int k=0; k<(int)boss.size(); ++k)
		    for (int i=0; i<(int)boss.size(); ++i)
		      for (int j=0; j<(int)boss.size(); ++j)
		        a[i][j] |= (a[i][k] && a[k][j]);
		  for (int i=0; i<(int)boss.size(); ++i)
		    if (a[i][i])
		      goto skip;
		  cnt = 0;
		  for (int i=0; i<(int)boss.size(); ++i)
		    cnt += super[i];
		  sol = min(sol, cnt);
		  skip: ;
		}
		
		return (sol==51) ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BOB","BOB","BOB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BOB","*","BOB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minSupers(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"JOHN","AL","DON","BOB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"*","*","*","*"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, minSupers(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"BOB","BOB","BOB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"*","*","BOB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, minSupers(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"BOB", "BOB", "JACK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BOB", "BOB", "*"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, minSupers(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BobTrouble ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

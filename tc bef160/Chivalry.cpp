#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Chivalry {
  public:
  string getOrder(string first, string second) {
    string sol;
    int i, j;
    
    for (i=0, j=0; i<first.size() && j<second.size(); )
      if (first[i]==second[j]) {
        sol.push_back(first[i]);
        ++i;
      } else {
        sol += 'W';
        if (first[i]=='W')
          ++i;
        else {
          assert(second[j]=='W');
          ++j;
        }
     }
    while (i<first.size()) {
      sol.push_back(first[i]);
      ++i;
    }
    while (j<second.size()) {
      sol.push_back(second[j]);
      ++j;
    }
    return sol;
  }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "M"; string Arg1 = "W"; string Arg2 = "WM"; verify_case(0, Arg2, getOrder(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "MM"; string Arg1 = "MW"; string Arg2 = "MMMW"; verify_case(1, Arg2, getOrder(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "MMMM"; string Arg1 = "W"; string Arg2 = "WMMMM"; verify_case(2, Arg2, getOrder(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "M"; string Arg1 = "WWW"; string Arg2 = "WWWM"; verify_case(3, Arg2, getOrder(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Chivalry ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

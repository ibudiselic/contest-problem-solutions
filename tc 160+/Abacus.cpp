#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Abacus {
	public:
	int calc(const vector<string> &a) {
	  int ret = 0;
	  for (int i=0; i<(int)a.size(); ++i) {
	    int dig = 0;
	    for (int j=(int)a[i].size()-1; a[i][j]=='o'; --j)
	      ++dig;
	     ret = ret*10 + dig;
	  }
	  return ret;
	}
	vector<string> make(int x) {
	  vector<string> ret(6, string());
	  for (int i=5; i>=0; --i) {
	    int dig = x%10;
	    x /= 10;
	    for (int j=0; j<9-dig; ++j)
	      ret[i] += 'o';
	    for (int j=0; j<3; ++j)
	      ret[i] += '-';
	    for (int j=0; j<dig; ++j)
	      ret[i] += 'o';
	  }
	  return ret;
	}
	vector <string> add(vector <string> a, int val) {
		return make(calc(a)+val);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ooo---oooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "oo---ooooooo",
 "---ooooooooo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arr2[] = {"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "o---oooooooo", "ooooo---oooo" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, add(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ooo---oooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "oo---ooooooo",
 "---ooooooooo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; string Arr2[] = {"oo---ooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, add(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ooooooooo---",
 "---ooooooooo",
 "ooooooooo---",
 "---ooooooooo",
 "oo---ooooooo",
 "---ooooooooo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000; string Arr2[] = {"oooooooo---o", "---ooooooooo", "ooooooooo---", "---ooooooooo", "oo---ooooooo", "---ooooooooo" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, add(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"o---oooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo",
 "---ooooooooo"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arr2[] = {"---ooooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, add(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Abacus ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

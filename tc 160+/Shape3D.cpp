#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Shape3D {
	public:
	vector <string> findCanonical(vector <string> shape) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0 0 0","1 0 0","1 1 0","1 1 1","1 0 1","0 1 1","0 0 1","0 1 0"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 0 0", "0 0 1", "0 1 0", "0 1 1", "1 0 0", "1 0 1", "1 1 0", "1 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findCanonical(Arg0)); }
	void test_case_1() { string Arr0[] = {"100 50 50","100 49 50","100 49 49"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 0 0", "0 0 1", "0 1 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findCanonical(Arg0)); }
	void test_case_2() { string Arr0[] = {"11 11 11","10 11 11","12 11 11"
,"11 11 10","11 11 12","11 10 11"
,"11 12 11","9 11 11","13 11 11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 1", "1 1 1", "2 0 1", "2 1 0", "2 1 1", "2 1 2", "2 2 1", "3 1 1", "4 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findCanonical(Arg0)); }
	void test_case_3() { string Arr0[] = {"100 900 800","101 900 800","102 900 800","102 899 800"
,"102 898 800","102 897 800","102 896 800","102 896 801"
,"102 896 802","102 896 803","102 896 804","102 896 805"
,"102 896 806","102 896 807","102 896 808"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 0 0", "0 0 1", "0 0 2", "0 0 3", "0 0 4", "0 0 5", "0 0 6", "0 0 7", "0 0 8", "0 1 8", "0 2 8", "0 3 8", "0 4 8", "1 4 8", "2 4 8" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findCanonical(Arg0)); }
	void test_case_4() { string Arr0[] = {"2 2 0","2 2 1","2 2 3","2 2 4","2 0 2","2 1 2","2 3 2","2 4 2","0 2 2","1 2 2","3 2 2","4 2 2","2 2 2"}`; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 10 10", "1 10 10", "2 10 10", "2 10 11", "2 10 12", "2 10 8", "2 10 9", "2 11 10", "2 12 10", "2 8 10", "2 9 10", "3 10 10", "4 10 10" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findCanonical(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Shape3D ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

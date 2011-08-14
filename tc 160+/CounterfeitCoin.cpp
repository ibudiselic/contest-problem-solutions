#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CounterfeitCoin {
	public:
	string nextWeighing(int N, vector <string> left, vector <string> right, string result) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = ""; string Arg4 = "ABCD-EFGH"; verify_case(0, Arg4, nextWeighing(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 12; string Arr1[] = { "ABCD", "ABC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "EFGH", "IJK" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "EL"; string Arg4 = "I-J"; verify_case(1, Arg4, nextWeighing(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 12; string Arr1[] = { "ABCD", "ABC", "I" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "EFGH", "IJK", "J" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "ELR"; string Arg4 = ""; verify_case(2, Arg4, nextWeighing(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 6; string Arr1[] = { "AB", "EF" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "CD", "AC" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "EE"; string Arg4 = "error"; verify_case(3, Arg4, nextWeighing(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 7; string Arr1[] = { "ACE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "BDF" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "E"; string Arg4 = "A-G"; verify_case(4, Arg4, nextWeighing(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 20; string Arr1[] = { "ACDJMNOQ", "CD", "G", "ABC", "R"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "BFIKLPST", "AK", "H", "FIK", "G"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "LEEEE"; string Arg4 = "JLM-NOP"; verify_case(5, Arg4, nextWeighing(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 26; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = ""; string Arg4 = "ABCDEFG-HIJKLMN"; verify_case(6, Arg4, nextWeighing(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CounterfeitCoin ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

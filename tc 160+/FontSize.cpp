#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

class FontSize {
	public:
	int getPixelWidth(string sentence, vector <int> uppercase, vector <int> lowercase) {
		int n = sentence.size();
		int sol = n-1;
		for (int i=0; i<n; ++i)
			if (isupper(sentence[i]))
				sol += uppercase[sentence[i]-'A'];
			else if (islower(sentence[i]))
				sol += lowercase[sentence[i]-'a'];
			else
				sol += 3;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Dead Beef"; int Arr1[] = {6,6,6,7,7,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,5,5,4,4,4,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 49; verify_case(0, Arg3, getPixelWidth(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "Hello World"; int Arr1[] = {7,8,8,8,7,8,8,8,7,8,8,8,8,8,7,8,8,8,8,8,7,8,8,8,8,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,6,6,6,5,6,6,6,5,6,6,6,6,6,5,6,6,6,6,6,5,6,6,6,6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 74; verify_case(1, Arg3, getPixelWidth(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "Hello World"; int Arr1[] = {7,7,7,7,7,7,7,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,7,7,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,5,5,6,6,5,5,5,5,5,5,1,5,5,6,5,5,6,5,5,5,5,5,5,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 63; verify_case(2, Arg3, getPixelWidth(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "ThE qUiCk BrOwN fOx JuMpEd OvEr ThE lAzY dOg"; int Arr1[] = {36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 778; verify_case(3, Arg3, getPixelWidth(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "two  spaces"; int Arr1[] = {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 43; verify_case(4, Arg3, getPixelWidth(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FontSize ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

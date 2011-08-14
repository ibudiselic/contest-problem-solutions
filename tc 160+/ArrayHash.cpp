#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/* Value = (Alphabet Position) + (Element of input) + (Position in Element)  */
class ArrayHash {
	public:
	int getHash(vector <string> input) {
		int sol = 0;
		for (int i=0; i<(int)input.size(); ++i)
			for (int j=0; j<(int)input[i].size(); ++j)
				sol += input[i][j]-'A' + i + j;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CBA",
 "DDD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(0, Arg1, getHash(Arg0)); }
	void test_case_1() { string Arr0[] = {"Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; verify_case(1, Arg1, getHash(Arg0)); }
	void test_case_2() { string Arr0[] = {"A",
 "B",
 "C",
 "D",
 "E",
 "F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(2, Arg1, getHash(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4290; verify_case(3, Arg1, getHash(Arg0)); }
	void test_case_4() { string Arr0[] = {"ZZZZZZZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 295; verify_case(4, Arg1, getHash(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ArrayHash ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

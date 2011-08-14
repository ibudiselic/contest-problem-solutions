#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const char *shape[] = { "DIAMOND", "SQUIGGLE", "CIRCLE" };
const char *color[] = { "BLUE", "GREEN", "RED" };
const char *solidity[] = { "SOLID", "EMPTY", "STRIPED" };
const char *number[] = { "ONE", "TWO", "THREE" };

int get(int a, int b) {
	for (int i=0; i<3; ++i)
		if (i != a && i != b)
			return i;
	return -10000;
}
const char* *find(const char* *beg, const char* *end, const char *match) {
	while (beg!=end && strcmp(*beg, match)!=0)
		++beg;
	return beg;
}
class Matching {
	public:
	vector <string> findMatch(vector <string> first, vector <string> second) {
		int sh1, col1, sol1, num1;
		int sh2, col2, sol2, num2;
		vector<string> sol;

		sh1 = find(shape, shape + 3, first[0].c_str()) - shape;
		sh2 = find(shape, shape + 3, second[0].c_str()) - shape;
		if (sh1 == sh2)
			sol.push_back(shape[sh1]);
		else
			sol.push_back(shape[get(sh1, sh2)]);

		col1 = find(color, color + 3, first[1].c_str()) - color;
		col2 = find(color, color + 3, second[1].c_str()) - color;
		if (col1 == col2)
			sol.push_back(color[col1]);
		else
			sol.push_back(color[get(col1, col2)]);

		sol1 = find(solidity, solidity + 3, first[2].c_str()) - solidity;
		sol2 = find(solidity, solidity + 3, second[2].c_str()) - solidity;
		if (sol1 == sol2)
			sol.push_back(solidity[sol1]);
		else
			sol.push_back(solidity[get(sol1, sol2)]);

		num1 = find(number, number + 3, first[3].c_str()) - number;
		num2 = find(number, number + 3, second[3].c_str()) - number;
		if (num1 == num2)
			sol.push_back(number[num1]);
		else
			sol.push_back(number[get(num1, num2)]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"DIAMOND","BLUE","SOLID","ONE"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"DIAMOND","GREEN","SOLID","TWO"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "DIAMOND",  "RED",  "SOLID",  "THREE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findMatch(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"CIRCLE","GREEN","EMPTY","TWO"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"DIAMOND","BLUE","STRIPED","ONE"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "SQUIGGLE",  "RED",  "SOLID",  "THREE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findMatch(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"DIAMOND","RED","SOLID","ONE"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SQUIGGLE","BLUE","SOLID","TWO"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "CIRCLE",  "GREEN",  "SOLID",  "THREE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findMatch(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"SQUIGGLE","RED","STRIPED","ONE"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SQUIGGLE","RED","STRIPED","ONE"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "SQUIGGLE",  "RED",  "STRIPED",  "ONE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findMatch(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Matching ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

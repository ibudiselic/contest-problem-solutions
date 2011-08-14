#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool columnClear(const vector<string> &a, int j) {
	for (int i=0; i<(int)a.size(); ++i)
		if (a[i][j] != ' ')
			return false;

	return true;
}
class FieldPairParse {
	public:
	vector <int> getPairs(vector <string> data) {
		vector<int> sol;
		for (int j=0; j<(int)data[0].size(); ++j)
			if (data[0][j] == ' ') {
				int sz = 0;
				while (columnClear(data, j)) {
					++sz;
					++j;
				}
				if (sz > 0)
					sol.push_back(sz);
			}

		if (sol.size()%2 == 0)
			return vector<int>();
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"XXXXX    XXXXX",
"XXXX    XXXXX "
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPairs(Arg0)); }
	void test_case_1() { string Arr0[] = {
"XXXXXXXXXX     XXXXXXXXXXX",
"XXXXXXXXXXXXXXXXX    XXXXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPairs(Arg0)); }
	void test_case_2() { string Arr0[] = {
"X X X",
"X X X"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPairs(Arg0)); }
	void test_case_3() { string Arr0[] = {
"XXXX      X  X           X X   X",
"XX       XXX XX   X   X   X XXX "
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 1, 3, 3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getPairs(Arg0)); }
	void test_case_4() { string Arr0[] = {"XXXX      X  X           X X   X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 2, 11, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getPairs(Arg0)); }
	void test_case_5() { string Arr0[] = {"XXX XXX XXX XXX XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getPairs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FieldPairParse ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

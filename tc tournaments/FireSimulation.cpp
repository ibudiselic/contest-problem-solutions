#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;


const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

class FireSimulation {
	public:
	vector <string> getState(vector <string> field, int minute) {
		int m = field.size();
		int n = field[0].size();

		vector<string> ret = field;
		ret[0][0] = '*';

		for (int t=1; t<=minute; ++t) {
			vector<string> temp = ret;
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j)
					if (ret[i][j] == '*') {
						--field[i][j];
						if (field[i][j] == '0') {
							temp[i][j] = '.';
							for (int d=0; d<4; ++d) {
								const int r = i + di[d];
								const int c = j + dj[d];
								if (r>=0 && r<m && c>=0 && c<n)
									if (ret[r][c]!='.' && field[r][c]>'0')
										temp[r][c] = '*';
							}
						}
					}
			ret = temp;
		}

		return ret;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"11111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; string Arr2[] = {"....*111" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getState(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"123456789"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arr2[] = {"..*456789" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getState(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"111", "211", "311"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arr2[] = {"..*", "**1", "311" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getState(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FireSimulation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

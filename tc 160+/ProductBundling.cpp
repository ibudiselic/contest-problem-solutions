#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool can_add(int prod, const vector<string> &data, const vector<int> &v) {
	for (int i=0; i<(int)data.size(); ++i) {
		const char first = data[i][prod];
		for (int j=0; j<(int)v.size(); ++j)
			if (data[i][v[j]] != first)
				return false;
	}
	return true;
}
class ProductBundling {
	public:
	int howManyBundles(vector <string> data) {
		vector< vector<int> > sol;
		sol.push_back(vector<int>());
		sol[0].push_back(0);

		for (int i=1; i<(int)data[0].size(); ++i) {
			bool add_new = true;
			for (int j=0; j<(int)sol.size(); ++j)
				if (can_add(i, data, sol[j])) {
					add_new = false;
					sol[j].push_back(i);
					break;
				}
			if (add_new) {
				sol.push_back(vector<int>());
				sol.back().push_back(i);
			}
		}
		return sol.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, howManyBundles(Arg0)); }
	void test_case_1() { string Arr0[] = {"1010",
 "1100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, howManyBundles(Arg0)); }
	void test_case_2() { string Arr0[] = {"1100000000",
 "1100000000",
 "0011000000",
 "0011000000",
 "0000110000",
 "0000110000",
 "0000001100",
 "0000001100",
 "0000000011",
 "0000000011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, howManyBundles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ProductBundling ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

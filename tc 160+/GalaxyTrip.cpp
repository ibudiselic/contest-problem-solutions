#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int a[30][30];
bool used[30];
bool possible[31];
bool can[31][30];
int n;
int dfs(int x) {
	used[x] = true;
	int ret = 1;
	for (int i=0; i<n; ++i)
		if (!used[i] && a[x][i])
			ret += dfs(i);
	return ret;
}
class GalaxyTrip {
	public:
	vector <int> possibleValues(vector <string> dependencies) {
		n = dependencies.size();
		memset(a, 0, sizeof a);
		for (int i=0; i<n; ++i) {
			istringstream is(dependencies[i]);
			int x;
			while (is >> x)
				a[i][x] = 1;
		}

		memset(used, 0, sizeof used);
		vector<int> t;
		for (int i=0; i<n; ++i)
			if (!used[i]) {
				t.push_back(dfs(i));
			}
		memset(can, true, sizeof can);
		memset(possible, false, sizeof possible);
		possible[0] = true;
		for (int i=0; i<n; ++i)
			if (possible[i])
				for (int j=0; j<(int)t.size(); ++j)
					if (can[i][j] && i+t[j]<=n && !possible[i+t[j]]) {
						memmove(can[i+t[j]], can[i], sizeof can[i+t[j]]);
						can[i+t[j]][j] = false;
						possible[i+t[j]] = true;
					}

		vector<int> sol;
		for (int i=1; i<=n; ++i)
			if (possible[i])
				sol.push_back(i);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1 2", "0", "0", ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, possibleValues(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 2", "0 2", "0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, possibleValues(Arg0)); }
	void test_case_2() { string Arr0[] = {"","","",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, possibleValues(Arg0)); }
	void test_case_3() { string Arr0[] = {"4 2", "3", "0 4", "1", "0 2", "6", "5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 4, 5, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, possibleValues(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GalaxyTrip ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

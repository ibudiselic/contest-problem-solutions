#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

bool used[50];
int n;
void dfs(int x, const vector<string> &v) {
	used[x] = 1;
	for (int i=0; i<n; ++i)
		if (!used[i] && v[x][i]=='1')
			dfs(i, v);
}
class TeamBuilder {
	public:
	vector <int> specialLocations(vector <string> paths) {
		vector<int> sol(2, 0);
		n = paths.size();
		for (int pos=0; pos<2; ++pos) {
			for (int i=0; i<n; ++i) {
				memset(used, 0, sizeof used);
				dfs(i, paths);
				sol[pos] += (accumulate(used, used+n, 0) == n);
			}
			for (int i=0; i<n; ++i)
				for (int j=i+1; j<n; ++j)
					swap(paths[i][j], paths[j][i]);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"010","000","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, specialLocations(Arg0)); }
	void test_case_1() { string Arr0[] = {"0010","1000","1100","1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, specialLocations(Arg0)); }
	void test_case_2() { string Arr0[] = {"01000","00100","00010","00001","10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 5,  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, specialLocations(Arg0)); }
	void test_case_3() { string Arr0[] = {"0110000","1000100","0000001","0010000","0110000","1000010","0001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, specialLocations(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TeamBuilder ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

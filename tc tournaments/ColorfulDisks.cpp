#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <functional>

using namespace std;

int rmv(int r, const string &color, map<string, vector<int> > &M) {
	int ret = 0;
	for (map<string, vector<int> >::iterator it=M.begin(); it!=M.end(); ++it)
		if (it->first != color) {
			vector<int> &v = it->second;
			while (v.size()>0 && v[0]==r) {
				v.erase(v.begin());
				++ret;
			}
		}
	return ret;
}
bool cantMake(const string &color, map<string, vector<int> > M, int cnt) {
	vector<int> &v = M[color];
	for (int i=0; i<(int)v.size(); ++i)
		cnt -= rmv(v[i], color, M) + 1;

	return cnt != 0;
}
class ColorfulDisks {
	public:
	vector <string> singleColor(vector <string> disks) {
		int n = disks.size();
		map<string, vector<int> > M;

		vector<string> sol;
		for (int i=0; i<n; ++i) {
			string color;
			int rad;
			istringstream is(disks[i]);
			is >> color >> rad;

			M[color].push_back(rad);

			if (M[color].size() == 1)
				sol.push_back(color);
		}
		for (map<string, vector<int> >::iterator it=M.begin(); it!=M.end(); ++it)
			sort(it->second.begin(), it->second.end(), greater<int>());

		sort(sol.begin(), sol.end());

		for (int i=0; i<(int)sol.size(); ++i)
			if (cantMake(sol[i], M, n))
				sol.erase(sol.begin()+i--);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"red 1", "blue 1", "green 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"blue", "green", "red" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, singleColor(Arg0)); }
	void test_case_1() { string Arr0[] = {"black 2", "white 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, singleColor(Arg0)); }
	void test_case_2() { string Arr0[] = {"black 1", "white 1", "grey 1", "grey 2", "white 3", "black 3", "grey 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"grey" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, singleColor(Arg0)); }
	void test_case_3() { string Arr0[] = {"red 1", "red 2", "red 3", "red 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"red" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, singleColor(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ColorfulDisks ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

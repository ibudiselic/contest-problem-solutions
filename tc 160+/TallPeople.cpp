#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TallPeople {
	public:
	vector <int> getPeople(vector <string> people) {
		vector<vector<int> > v;

		for (int i=0; i<(int)people.size(); ++i) {
			istringstream is(people[i]);
			int x;
			v.push_back(vector<int>());

			while (is >> x)
				v.back().push_back(x);
		}

		vector<int> sol;
		vector<int> cand;
		for (int i=0; i<(int)v.size(); ++i)
			cand.push_back(*min_element(v[i].begin(), v[i].end()));

		sol.push_back(*max_element(cand.begin(), cand.end()));

		cand.clear();
		for (int j=0; j<(int)v[0].size(); ++j) {
			int minval = v[0][j];
			for (int i=1; i<(int)v.size(); ++i)
				minval = max(minval, v[i][j]);
			cand.push_back(minval);
		}
		sol.push_back(*min_element(cand.begin(), cand.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"9 2 3",
 "4 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPeople(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 2",
 "4 5",
 "3 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPeople(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 1",
 "1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPeople(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TallPeople ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

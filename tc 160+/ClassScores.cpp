#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class ClassScores {
	public:
	vector <int> findMode(vector <int> scores) {
		map<int, int> M;
		int x = 0;
		for (int i=0; i<(int)scores.size(); ++i) {
			++M[scores[i]];
			x = max(x, M[scores[i]]);
		}

		vector<int> sol;
		for (map<int, int>::const_iterator it=M.begin(); it!=M.end(); ++it)
			if (it->second == x)
				sol.push_back(it->first);

		sort(sol.begin(), sol.end());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {65, 70, 88, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {70 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findMode(Arg0)); }
	void test_case_1() { int Arr0[] = {88, 70, 65, 70, 88}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {70, 88 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findMode(Arg0)); }
	void test_case_2() { int Arr0[] = {92, 56, 14, 73, 22, 38, 93, 45, 55}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14, 22, 38, 45, 55, 56, 73, 92, 93 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findMode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ClassScores ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int f(int x, const vector<int> &v) {
	int ret = 0;
	for (int i=0; i<x; ++i)
		ret += (v[i]>v[x]);
	for (int i=x+1; i<(int)v.size(); ++i)
		ret += (v[i]<v[x]);

	return ret;
}
class Sortness {
	public:
	double getSortness(vector <int> a) {
		double sum = 0;
		for (int i=0; i<(int)a.size(); ++i)
			sum += f(i, a);

		return double(sum)/a.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,2,1,4,6,7,5,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.25; verify_case(0, Arg1, getSortness(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(1, Arg1, getSortness(Arg0)); }
	void test_case_2() { int Arr0[] = {5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(2, Arg1, getSortness(Arg0)); }
	void test_case_3() { int Arr0[] = {1,5,8,7,9,6,10,12,11,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.166666666666667; verify_case(3, Arg1, getSortness(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Sortness ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

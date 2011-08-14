#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(vector<int> v) {
	for (int i=1; i<(int)v.size(); ++i)
		for (int j=0; j+i<(int)v.size(); ++j)
			v[j] = v[j+1]-v[j];

	return v[0];
}
class DifDif {
	public:
	int predict(vector <int> seq) {
		int lo = -1000000000;
		int hi = 1000000000;

		seq.push_back(0);
		while (lo < hi) {
			int mid = lo + (hi-lo)/2;
			seq.back() = mid;
			if (calc(seq) >= 0)
				hi = mid;
			else
				lo = mid+1;
		}

		return lo;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,-4, 12, 23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, predict(Arg0)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(1, Arg1, predict(Arg0)); }
	void test_case_2() { int Arr0[] = {1,4,9,16,25,36}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(2, Arg1, predict(Arg0)); }
	void test_case_3() { int Arr0[] = {-1000,1000,-1000,1000,-1000,1000,-1000,1000,-1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1023000; verify_case(3, Arg1, predict(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DifDif ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

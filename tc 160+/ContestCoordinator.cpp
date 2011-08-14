#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ContestCoordinator {
	public:
	double bestAverage(vector <int> scores) {
		double best = 0.0;
		sort(scores.begin(), scores.end());
		for (int k=0; k<=((int)scores.size()-1)/2; ++k) {
			int cur = 0;
			for (int i=k; i<(int)scores.size()-k; ++i)
				cur += scores[i];
			best = max(best, double(cur)/((int)scores.size() - 2*k));
		}
		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, bestAverage(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.5; verify_case(1, Arg1, bestAverage(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,999,999,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 999.0; verify_case(2, Arg1, bestAverage(Arg0)); }
	void test_case_3() { int Arr0[] = {1,13,8,6,7,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 7.5; verify_case(3, Arg1, bestAverage(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(4, Arg1, bestAverage(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ContestCoordinator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

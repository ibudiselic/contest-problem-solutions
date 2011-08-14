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

class UsingStats {
	public:
	int getMedian(vector <int> vals, int mean) {
		int sum = accumulate(vals.begin(), vals.end(), 0);
		vals.push_back(mean*(vals.size()+1) - sum);

		sort(vals.begin(), vals.end());
		return vals[vals.size()/2];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {50,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 75; int Arg2 = 75; verify_case(0, Arg2, getMedian(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, getMedian(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 61; int Arg2 = 100; verify_case(2, Arg2, getMedian(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {889,820,404,-901}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 539; int Arg2 = 820; verify_case(3, Arg2, getMedian(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-211,-504,461,283,791,646,205,459,-186,516,-933,762,418,656,746,-368,888,270,-355,-207,-990,435,717,-338}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 845; int Arg2 = 418; verify_case(4, Arg2, getMedian(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UsingStats ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

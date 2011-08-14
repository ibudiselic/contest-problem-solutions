#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TwoTrains {
	public:
	int passengerNewVasyuki(int t1, int t2, vector <int> times) {
		sort(times.begin(), times.end());

		int cur = 0;
		int sol = 0;

		int person = 0;
		for (int t=0; t<=(times.back()+max(t1, t2))/max(t1, t2) * max(t1, t2); ++t) {
			while (person<(int)times.size() && times[person]==t) {
				++cur;
				++person;
			}
			if (t%t1 == 0) {
				sol += cur;
				cur = 0;
			} else if (t%t2 == 0) {
				cur = 0;
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arr2[] = {0,1,2,3,4,10000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(0, Arg3, passengerNewVasyuki(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arr2[] = {0,1,2,3,4,10000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, passengerNewVasyuki(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {0,1,2,3,4,5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(2, Arg3, passengerNewVasyuki(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 13; int Arr2[] = {0,13,10,2002,423,543,212,234,567,890,9876,5443,323,456,7777,8878,8787,8899,9098,23,45}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(3, Arg3, passengerNewVasyuki(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 100; int Arr2[] = {7348,127,33,23,11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(4, Arg3, passengerNewVasyuki(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TwoTrains ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

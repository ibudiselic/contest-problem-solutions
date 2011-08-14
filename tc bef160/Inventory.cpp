#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define EPSILON (1e-9)
class Inventory {
	public:
	int monthlyOrder(vector <int> sales, vector <int> daysAvailable) {
		double sum = 0.0;
		int mnt = 0;

		for (vector<int>::size_type i=0; i<sales.size(); ++i)
			if (daysAvailable[i] != 0) {
				++mnt;
				sum += (double)sales[i]/daysAvailable[i];
			}
		sum /= mnt;
		sum *= 30;
		sum -= EPSILON;
		return (int)ceil(sum);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(0, Arg2, monthlyOrder(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {75,120,0,93}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {24,30,0,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 103; verify_case(1, Arg2, monthlyOrder(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {8773}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16450; verify_case(2, Arg2, monthlyOrder(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1115,7264,3206,6868,7301}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,9,4,18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 36091; verify_case(3, Arg2, monthlyOrder(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Inventory ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

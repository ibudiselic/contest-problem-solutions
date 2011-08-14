#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MedianOfNumbers {
	public:
	int findMedian(vector <int> numbers) {
		sort(numbers.begin(), numbers.end());
		return (numbers.size()%2 == 0 ? -1 : numbers[numbers.size()/2]);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 4, 2, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, findMedian(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 5, 8, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, findMedian(Arg0)); }
	void test_case_2() { int Arr0[] = {7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, findMedian(Arg0)); }
	void test_case_3() { int Arr0[] = {7, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, findMedian(Arg0)); }
	void test_case_4() { int Arr0[] = {66, 53, 47, 86, 18, 21, 97, 92, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 53; verify_case(4, Arg1, findMedian(Arg0)); }
	void test_case_5() { int Arr0[] = {32, 54, 27, 4, 69, 96, 73, 1, 100, 15, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(5, Arg1, findMedian(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MedianOfNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

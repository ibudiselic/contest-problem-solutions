#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int card(int a) {
	int ret = 0;
	for (unsigned i=1; (int)i<=a; i<<=1)
		ret += ((a&i)!=0);
	return ret;
}
bool lt(int a, int b) {
	const int x = card(a);
	const int y = card(b);

	if (x!=y)
		return x<y;
	else
		return a<b;
}
class BinaryCardinality {
	public:
	vector <int> arrange(vector <int> numbers) {
		sort(numbers.begin(), numbers.end(), lt);
		return numbers;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, arrange(Arg0)); }
	void test_case_1() { int Arr0[] = {31,15,7,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  3,  7,  15,  31 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, arrange(Arg0)); }
	void test_case_2() { int Arr0[] = {10,9,8,7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  2,  4,  8,  3,  5,  6,  9,  10,  7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, arrange(Arg0)); }
	void test_case_3() { int Arr0[] = {811385,340578,980086,545001,774872,855585,13848,863414,419523,190151,784903,127461}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 13848,  340578,  545001,  855585,  419523,  811385,  127461,  190151,  774872,  863414,  784903,  980086 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, arrange(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BinaryCardinality ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

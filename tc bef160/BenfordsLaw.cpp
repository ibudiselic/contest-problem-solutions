#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class BenfordsLaw {
	public:
	int questionableDigit(vector <int> transactions, int threshold) {
		vector<int> a(10, 0);

		for (vector<int>::size_type i=0; i<transactions.size(); ++i) {
			stringstream ios;
			ios << transactions[i];
			string t;
			ios >> t;
			++a[t[0]-'0'];
		}
		for (int i=1; i<10; ++i) {
			double b = log10(1 + 1.0/i)*transactions.size();
			if ((double)a[i]*threshold < b || (double)a[i]/threshold > b)
				return i;
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 5236,7290,200,1907,3336,9182,17,4209,8746,7932,
  6375,909,2189,3977,2389,2500,1239,3448,6380,4812 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, questionableDigit(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 1,10,100,2,20,200,2000,3,30,300 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(1, Arg2, questionableDigit(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 9,87,765,6543,54321,43219,321987,21987,1987,345,234,123 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = -1; verify_case(2, Arg2, questionableDigit(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 9; verify_case(3, Arg2, questionableDigit(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 987,234,1234,234873487,876,234562,17,
  7575734,5555,4210,678234,3999,8123 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 8; verify_case(4, Arg2, questionableDigit(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BenfordsLaw ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

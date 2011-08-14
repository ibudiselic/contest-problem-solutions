#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SupermarketDiscount {
	public:
	int minAmount(vector <int> goods) {
		int a = goods[0], b = goods[1], c = goods[2];

		int off = 0;
		if (a >= 50) {
			off += 10;
			if (b >= 50) {
				off += 10;
				if (c >= 50)
					off += 10;
			} else {
				if (b+c >= 50)
					off += 10;
			}
		} else {
			if (b >= 50) {
				off += 10;
				if (a+c >= 50)
					off += 10;
			} else {
				if (c >= 50) {
					off += 10;
					if (b+a >= 50)
						off += 10;
				} else if (a+b+c >= 50) {
					off += 10;
				}
			}
		}

		return a+b+c-off;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {46, 62, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 97; verify_case(0, Arg1, minAmount(Arg0)); }
	void test_case_1() { int Arr0[] = {50, 62, 93}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 175; verify_case(1, Arg1, minAmount(Arg0)); }
	void test_case_2() { int Arr0[] = {5, 31, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 41; verify_case(2, Arg1, minAmount(Arg0)); }
	void test_case_3() { int Arr0[] = {5, 3, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; verify_case(3, Arg1, minAmount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SupermarketDiscount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

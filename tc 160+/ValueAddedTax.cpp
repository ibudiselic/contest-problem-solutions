#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ValueAddedTax {
	public:
	double calculateFinalPrice(string product, int price, vector <string> food) {
		if (find(food.begin(), food.end(), product) != food.end())
			return price*1.1;
		else
			return price*1.18;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "milk"; int Arg1 = 1; string Arr2[] = {"bread", "butter", "milk"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.1; verify_case(0, Arg3, calculateFinalPrice(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "car"; int Arg1 = 100; string Arr2[] = {"bread", "butter", "milk"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 118.0; verify_case(1, Arg3, calculateFinalPrice(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "abc"; int Arg1 = 57; string Arr2[] = {"a", "b", "c"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 67.25999999999999; verify_case(2, Arg3, calculateFinalPrice(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ValueAddedTax ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

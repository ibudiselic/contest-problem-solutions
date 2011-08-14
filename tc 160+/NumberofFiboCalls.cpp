#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
int fibonacci(int n)
	begin
	if n equals 0
		begin
		print(0)
		return 0
		end
	if n equals 1
		begin
		print(1)
		return 1
		end
	return fibonacci(n - 1) + fibonacci(n - 2)
	end
*/
vector<int> M[41];
bool done[41];
vector<int> vZero, vOne;
vector<int> go(int n) {
	if (n == 0)
		return vZero;
	if (n == 1)
		return vOne;
	if (done[n])
		return M[n];

	done[n] = 1;
	vector<int> x = go(n-1);
	vector<int> y = go(n-2);
	x[0] += y[0];
	x[1] += y[1];
	return M[n] = x;
}
class NumberofFiboCalls {
	public:
	vector <int> fiboCallsMade(int n) {
		memset(done, 0, sizeof done);
		vZero.assign(2, 0);
		vZero[0] = 1;
		vOne.assign(2, 0);
		vOne[1] = 1;

		return go(n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 0; int Arr1[] = {1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, fiboCallsMade(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, fiboCallsMade(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {5, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, fiboCallsMade(Arg0)); }
	void test_case_3() { int Arg0 = 22; int Arr1[] = {10946, 17711 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, fiboCallsMade(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NumberofFiboCalls ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

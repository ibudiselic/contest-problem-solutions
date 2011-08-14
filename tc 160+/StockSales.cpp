#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int gcdFrom[50];
int N;
vector<int> V;
vector<int> sol;

long long my_abs(long long x) {
	return x >= 0 ? x : -x;
}

int gcd(int m, int n) {
	return m==0 ? n : gcd(n%m, m);
}
void go(int pos, long long target) {
	if (pos == N-1) {
		sol[N-1] = target/V[N-1];
		//cerr << pos << ' ' << V[pos] << ' ' << target << '\n';
		return;
	}

	//cerr << pos << ' ' << V[pos] << ' ' << target << '\n';

	for (long long x=0; ; ++x) {
		long long t = target - x*V[pos];

		if (my_abs(t)%gcdFrom[pos+1] == 0) {
			sol[pos] = int(x);
			go(pos+1, t);
			return;
		}

		t = target + x*V[pos];
		if (my_abs(t)%gcdFrom[pos+1] == 0) {
			sol[pos] = int(-x);
			go(pos+1, t);
			return;
		}
	}
}
class StockSales {
	public:
	vector <int> getAmounts(vector <int> values) {
		V = values;
		N = V.size();

		gcdFrom[N-1] = V[N-1];
		for (int i=N-2; i>=0; --i)
			gcdFrom[i] = gcd(gcdFrom[i+1], V[i]);

		sol.assign(N, 0);
		go(0, gcdFrom[0]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {6,12,17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  -7,  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getAmounts(Arg0)); }
	void test_case_1() { int Arr0[] = {10,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  -2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getAmounts(Arg0)); }
	void test_case_2() { int Arr0[] = {79}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getAmounts(Arg0)); }
	void test_case_3() { int Arr0[] = {60,60,60,60,60,60,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  0,  0,  0,  0,  0,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getAmounts(Arg0)); }
	void test_case_4() { int Arr0[] = {17,19,37,11,22,110}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  0,  3,  0,  0,  -1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getAmounts(Arg0)); }
	void test_case_5() { int Arr0[] = {1000000,499999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { -249999,  499999 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getAmounts(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StockSales ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

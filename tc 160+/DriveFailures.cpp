#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<double> sol;
vector<double> P;

void go(int pos, int cnt, double p) {
	if (pos == (int)P.size()) {
		sol[cnt] += p;
		return;
	}
	go(pos+1, cnt+1, p*P[pos]);
	go(pos+1, cnt  , p*(1-P[pos]));
}
class DriveFailures {
	public:
	vector <double> failureChances(vector <double> failureProb) {
		P = failureProb;
		sol.assign(P.size()+1, 0.0);

		go(0, 0, 1);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { double Arr0[] = {1.0, 0.25, 0.0}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.0, 0.75, 0.25, 0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, failureChances(Arg0)); }
	void test_case_1() { double Arr0[] = {0.4, 0.7}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.18000000000000002, 0.54, 0.27999999999999997 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, failureChances(Arg0)); }
	void test_case_2() { double Arr0[] = {0.2, 0.3, 0.0, 1.0, 0.8, 0.9}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.0, 0.011199999999999993, 0.15319999999999995, 0.5031999999999999, 0.2892, 0.0432, 0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, failureChances(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DriveFailures ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

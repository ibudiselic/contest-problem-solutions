#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const double sqrt2 = sqrt(2);
double calc(const vector<int> H) {
	vector<double> center;
	center.push_back(H[0]/2.0);

	for (int i=1; i<(int)H.size(); ++i) {
		center.push_back(H[i]/2.0);
		for (int j=0; j<i; ++j) {
		const double w1 = H[j];
		const double w2 = H[i];
		const double a1 = w1/(1+sqrt2);
		const double a2 = w2/(1+sqrt2);
		const double hl1 = sqrt2/2 * a1;
		const double hl2 = sqrt2/2 * a2;
		const double hh1 = hl1 + a1;
		const double hh2 = hl2 + a2;

		if (hh1 <= hl2)
			center[i] = max(center[i], center[j] + a1*(sqrt2 + 1.5) + a2/2);
		else if (hh2 <= hl1)
			center[i] = max(center[i], center[j] + a2*(sqrt2 + 1.5) + a1/2);
		else
			center[i] = max(center[i], center[j] + w1/2 + w2/2);
		}
	}
	double ret = 0;
	for (int i=0; i<(int)center.size(); ++i)
		ret = max(ret, center[i] + H[i]/2.0);

	return ret;
}
class PickupBed {
	public:
	double length(vector <int> ht) {
		sort(ht.begin(), ht.end());

		double sol = 1e32;
		do {
			sol = min(sol, calc(ht));
		} while (next_permutation(ht.begin(), ht.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 15.0; verify_case(0, Arg1, length(Arg0)); }
	void test_case_1() { int Arr0[] =  {17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 17.0; verify_case(1, Arg1, length(Arg0)); }
	void test_case_2() { int Arr0[] = {10,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 10.0; verify_case(2, Arg1, length(Arg0)); }
	void test_case_3() { int Arr0[] = {10,2,2}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 10.97056274847714; verify_case(3, Arg1, length(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PickupBed ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

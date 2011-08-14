#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

double prob[10];
vector<int> chips;
int n;

void go(int m, double p, int cntCoins) {
	if (cntCoins == 0)
		return;

	int cntCards = 0;
	for (int i=0; i<n; ++i)
		if (m & (1<<i))
			cntCards += chips[i];

	for (int i=0; i<n; ++i)
		if (m & (1<<i)) {
			const double pp = p*chips[i]/cntCards;
			prob[i] += pp;
			go(m ^ (1<<i), pp, cntCoins-1);
		}
}
class ChipRace {
	public:
	vector <double> chances(vector <int> chips_) {
		chips = chips_;
		n = chips.size();

		int sum = accumulate(chips.begin(), chips.end(), 0);

		int low = sum/5;
		int high = (sum+4)/5;
		int cntCoins = -1;
		if (sum-low*5 > high*5-sum)
			cntCoins = high;
		else
			cntCoins = low;

		for (int i=0; i<n; ++i)
			prob[i] = 0;

		go((1<<n)-1, 1.0, cntCoins);

		return vector<double> (prob, prob+n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = { 0.0,  0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, chances(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = { 0.3333333333333333,  0.6666666666666666 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, chances(Arg0)); }
	void test_case_2() { int Arr0[] = { 3, 2, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = { 0.725,  0.55,  0.725 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, chances(Arg0)); }
	void test_case_3() { int Arr0[] = { 0, 1, 2, 3, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = { 0.0,  0.23452380952380952,  0.4412698412698413,  0.6083333333333334,  0.7158730158730159 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, chances(Arg0)); }
	void test_case_4() { int Arr0[] =  { 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = { 0.0,  0.25,  0.25,  0.0,  0.0,  0.0,  0.0,  0.25,  0.25,  0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, chances(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChipRace ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

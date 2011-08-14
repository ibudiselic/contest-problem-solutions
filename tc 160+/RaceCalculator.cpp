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

class RaceCalculator {
	public:
	int bestRace(vector <int> d, vector <int> tm) {
		vector<double> badness(d.size(), -1e32);

		for (int i=0; i<(int)d.size(); ++i)
			for (int j=0; j<(int)d.size(); ++j)
				for (int k=0; k<(int)d.size(); ++k)
					if (i!=j && i!=k && j!=k) {
						double t = (tm[i]*exp(log(double(tm[j])/tm[i]) * log(double(d[i])/d[k]) / log(double(d[i])/d[j])));

						badness[k] = max(badness[k], (tm[k]-t)/t);
					}

		return min_element(badness.begin(), badness.end()) - badness.begin();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1600,3200,16000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {299,655,4020}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, bestRace(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1600,2000,3200,3000,5000,9600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {234,306,499,462,802,1629}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, bestRace(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000,2000,3000,4000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {160,330,510,750}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, bestRace(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000,50000,10000,5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {200,70010,2250,1080}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, bestRace(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RaceCalculator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class InequalityChecker {
	public:
	vector <int> getDifferences(int n) {
		int nom, denom;
		nom = denom = 0;
		for (int i=1; i<n; ++i)
			nom += 2*(i*i*i);
		nom += n*n*n;
		nom *= 2;
		nom -= n*n*n*n;

		vector<int> sol;
		denom = 4;
		if (nom%4 == 0) {
			nom /= 4;
			denom = 1;
		} else if (nom%2 == 0) {
			nom /= 2;
			denom = 1;
		}
		sol.push_back(nom);
		sol.push_back(denom);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = { 1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getDifferences(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = { 9,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getDifferences(Arg0)); }
	void test_case_2() { int Arg0 = 100; int Arr1[] = { 2500,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getDifferences(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InequalityChecker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

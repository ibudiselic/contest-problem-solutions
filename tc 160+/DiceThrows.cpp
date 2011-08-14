#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double probA[20001], probB[20001];
class DiceThrows {
	public:
	double winProbability(int numDiceA, vector <int> sidesA, int numDiceB, vector <int> sidesB) {
		for (int i=0; i<20001; ++i)
			probA[i] = probB[i] = 0.0;

		probA[0] = probB[0] = 1.0;

		for (int i=0; i<numDiceA; ++i)
			for (int v=20000; v>=0; --v) {
				probA[v] = 0.0;
				for (int j=0; j<6; ++j)
					if (v >= sidesA[j])
						probA[v] += probA[v-sidesA[j]]/6;
			}
		for (int i=0; i<numDiceB; ++i)
			for (int v=20000; v>=0; --v) {
				probB[v] = 0.0;
				for (int j=0; j<6; ++j)
					if (v >= sidesB[j])
						probB[v] += probB[v-sidesB[j]]/6;
			}

		for (int i=1; i<20001; ++i)
			probB[i] += probB[i-1];

		double sol = 0.0;
		for (int i=1; i<20001; ++i)
			sol += probA[i]*probB[i-1];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arr3[] = {1,2,3,4,5,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.41666666666666663; verify_case(0, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 200; int Arr1[] = {1,3,8,18,45,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; int Arr3[] = {1,4,10,21,53,100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.25240407058279035; verify_case(1, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1,1,1,2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arr3[] = {1,1,1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.25; verify_case(2, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 200; int Arr1[] = {6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; int Arr3[] = {3,4,6,5,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.49416239842107595; verify_case(3, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 100; int Arr1[] = {1,1,1,1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 199; int Arr3[] = {1,1,1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1.5306467074865068E-78; verify_case(4, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DiceThrows ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

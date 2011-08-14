#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Aquarium {
	public:
	int peaceful(int minSize, int maxSize, vector <int> fishSize) {
		int sol = 0;
		for (int i=minSize; i<=maxSize; ++i) {
			for (int j=0; j<(int)fishSize.size(); ++j) {
				if (i*2<=fishSize[j] && i*10>=fishSize[j] || fishSize[j]*2<=i && fishSize[j]*10>=i)
					goto skip;
			}
			++sol;
			skip: ;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 12; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, peaceful(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 36; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(1, Arg3, peaceful(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1000; int Arr2[] = {10, 100, 500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, peaceful(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 880; int Arr2[] = {1, 3, 9, 27, 243, 729}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 121; verify_case(3, Arg3, peaceful(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 997; int Arr2[] = {10, 11, 12, 13, 14, 16, 82, 83, 84, 85, 720, 730, 740, 750, 760, 770}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 147; verify_case(4, Arg3, peaceful(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 999; int Arr2[] = {941, 797, 120, 45, 7, 120}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(5, Arg3, peaceful(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 1; int Arg1 = 791; int Arr2[] = {1, 4, 12, 25, 79, 556, 625, 800, 801, 950, 952, 954, 956, 958, 980, 1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(6, Arg3, peaceful(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Aquarium ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

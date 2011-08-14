#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class WhichData {
	public:
	vector <int> bestVariance(vector <int> sampleData, int varNum, int varDen) {
		double best = 1e32;
		vector<int> sol(sampleData.size(), 1000000);
		int lim = 1<<sampleData.size();
		sort(sampleData.begin(), sampleData.end());
		double target = (double)varNum/varDen;
		for (int mask=1; mask<lim; ++mask) {
			double mean = 0.0;
			int n = 0;
			vector<int> temp;
			for (int i=0; (1<<i)<=mask; ++i)
				if (mask & (1<<i)) {
					mean += sampleData[i];
					++n;
					temp.push_back(sampleData[i]);
				}
			mean /= n;
			double varsum = 0.0;
			for (int i=0; (1<<i)<=mask; ++i)
				if (mask & (1<<i))
					varsum += (mean-sampleData[i])*(mean-sampleData[i]);
			const double var = varsum/n;
			if (best - fabs(var-target) > 1e-9) {
				best = fabs(var-target);
				sol = temp;
			} else if (fabs(fabs(var-target)-best)<1e-9 && temp<sol)
					sol = temp;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5,6,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; int Arg2 = 20; int Arr3[] = { 1,  2,  3,  4,  5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, bestVariance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,6,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 1; int Arr3[] = { 1,  2,  4,  5,  8 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, bestVariance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {-10000,10000,-9999,9999,-9998,9000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10000; int Arg2 = 1; int Arr3[] = { -10000,  -9998 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, bestVariance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {-10000,10000,-9999,9999,-9998,9998,1,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9999; int Arg2 = 10000; int Arr3[] = { -10000,  -9998 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, bestVariance(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {500,500,500,500,500,500,500,580,
 100,100,100,100,100,100,100,180}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 700; int Arg2 = 1; int Arr3[] = { 100,  100,  100,  100,  100,  100,  100,  180 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, bestVariance(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {10,10,10,10,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 9999; int Arr3[] = { 10 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, bestVariance(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {2,5,8,15,-14,0,-2,3,0,-10,-3,-9,6,-13,4,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5787; int Arg2 = 170; int Arr3[] = { -14,  -10,  -3,  -1,  0,  0,  2,  3,  4,  5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(6, Arg3, bestVariance(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arr0[] = {-14,-3,-1,10,-5,0,13,6,11,9,5,6,3,-2,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5061; int Arg2 = 225; int Arr3[] = { -5,  -3,  -2,  -1,  0,  2,  5,  6,  6,  11 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(7, Arg3, bestVariance(Arg0, Arg1, Arg2)); }
	void test_case_8() { int Arr0[] = {0,-13,15,5,5,-7,-6,-7,-8,4,-12,-13,14,9,-3,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9262; int Arg2 = 197; int Arr3[] = { -13,  -13,  -12,  -7,  -7,  -6,  -3,  4,  5,  5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(8, Arg3, bestVariance(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WhichData ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

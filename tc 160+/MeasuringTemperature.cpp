#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool valid(const vector<int> &v, int i) {
	if (v[i] < -273)
		return false;
	if ((i==0 || abs(v[i-1]-v[i])>2)
		&&
		(i<=1 || abs(v[i-2]-v[i])>2)
		&&
		((int)v.size()-1<=i || abs(v[i+1]-v[i])>2)
		&&
		((int)v.size()-2<=i || abs(v[i+2]-v[i])>2))
		return false;

	return true;
}
class MeasuringTemperature {
	public:
	double averageTemperature(vector <int> measuredValues) {
		int sum=0, cnt=0;

		for (int i=0; i<(int)measuredValues.size(); ++i)
			if (valid(measuredValues, i)) {
				++cnt;
				sum += measuredValues[i];
			}

		return (cnt==0 ? -300.0 : double(sum)/cnt);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9, 11, 12, 13, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 12.0; verify_case(0, Arg1, averageTemperature(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 2, 997, -1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.16666666666666666; verify_case(1, Arg1, averageTemperature(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 2, -4, -1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.16666666666666666; verify_case(2, Arg1, averageTemperature(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 0, 0, 2, -3, -1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -0.2857142857142857; verify_case(3, Arg1, averageTemperature(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,3,100,100,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 29.857142857142858; verify_case(4, Arg1, averageTemperature(Arg0)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(5, Arg1, averageTemperature(Arg0)); }
	void test_case_6() { int Arr0[] = {-35, -34, -34, -34, -35, 72, -34, 52, -36, -35, -36, 52, -36, -35, 981, -33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -34.75; verify_case(6, Arg1, averageTemperature(Arg0)); }
	void test_case_7() { int Arr0[] = {-273, -273, -274, -273}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -273.0; verify_case(7, Arg1, averageTemperature(Arg0)); }
	void test_case_8() { int Arr0[] = {10, 20, 30, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -300.0; verify_case(8, Arg1, averageTemperature(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MeasuringTemperature ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

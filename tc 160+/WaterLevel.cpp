#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class WaterLevel {
	public:
	double netAmt(int evapNormal, int evapFlood, vector <int> rain) {
		double level = 0.0;

		for (int i=0; i<(int)rain.size(); ++i) {
			int flood = rain[i]-evapFlood;
			int norm = rain[i]-evapNormal;

			if (level > 1e-9) {
				if (flood >= 0) {
					level += flood;
				} else {
					if (level >= -flood) {
						level += flood;
					} else {
						double t = 1 + level/flood;
						level = 0.0;

						if (norm < 0)
							level += t*norm;
					}
				}
			} else if (level < -1e-9) {
				if (norm <= 0) {
					level += norm;
				} else {
					if (-level >= norm) {
						level += norm;
					} else {
						double t = 1 + level/norm;
						level = 0.0;

						if (flood > 0)
							level += t*flood;
					}
				}
			} else {
				if (flood<=0 && norm>=0) {
					continue;
				} else if (flood>=0 && norm>0) {
					level += flood;
				} else if (flood<=0 && norm<=0) {
					level += norm;
				} else {
					level += norm;
				}
			}
		}

		return level;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arg1 = 40; int Arr2[] = {0,60,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -35.0; verify_case(0, Arg3, netAmt(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 39; int Arr2[] = {0,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 10.5; verify_case(1, Arg3, netAmt(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 40; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -20.0; verify_case(2, Arg3, netAmt(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 200; int Arg1 = 800; int Arr2[] = {0,600}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.0; verify_case(3, Arg3, netAmt(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WaterLevel ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

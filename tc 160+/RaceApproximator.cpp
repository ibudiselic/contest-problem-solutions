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

class RaceApproximator {
	public:
	string timeToBeat(int d1, int t1, int d2, int t2, int raceDistance) {
		int t = (int)(t1*exp(log(double(t2)/t1) * log(double(d1)/raceDistance) / log(double(d1)/d2)));

		char buffer[128];
		sprintf(buffer, "%01d:%02d:%02d", t/3600, t%3600/60, t%3600%60);

		return string(buffer);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 800; int Arg1 = 118; int Arg2 = 5000; int Arg3 = 906; int Arg4 = 1500; string Arg5 = "0:03:57"; verify_case(0, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 400; int Arg1 = 65; int Arg2 = 1600; int Arg3 = 350; int Arg4 = 800; string Arg5 = "0:02:30"; verify_case(1, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1600; int Arg1 = 299; int Arg2 = 10000; int Arg3 = 2360; int Arg4 = 5000; string Arg5 = "0:18:00"; verify_case(2, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 17; int Arg2 = 10000; int Arg3 = 4500; int Arg4 = 9000; string Arg5 = "1:06:00"; verify_case(3, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 156; int Arg1 = 117; int Arg2 = 3863; int Arg3 = 2754; int Arg4 = 1755; string Arg5 = "0:21:06"; verify_case(4, Arg5, timeToBeat(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RaceApproximator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

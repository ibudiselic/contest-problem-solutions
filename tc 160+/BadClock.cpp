#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BadClock {
	public:
	int sgn(int x) {
		if (x < 0)
			return -1;
		else return 1;
	}
	double nextAgreement(string trueTime, string skewTime, int hourlyGain) {
		int h=0, m=0, s=0;
		int t1=0, t2=0;

		sscanf(trueTime.c_str(), "%d:%d:%d", &h, &m, &s);
		t1 = s + m*60 + h*3600;
		sscanf(skewTime.c_str(), "%d:%d:%d", &h, &m, &s);
		t2 = s + m*60 + h*3600;

		int dif = t1-t2;
		if (dif != 0) {
			if (sgn(dif) != sgn(hourlyGain))
				if (sgn(dif) > 0)
					dif -= 12*3600;
				else dif += 12*3600;
		}
		return double(dif)/hourlyGain;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "07:07:07"; string Arg1 = "07:07:07"; int Arg2 = 1776; double Arg3 = 0.0; verify_case(0, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "11:59:58"; string Arg1 = "12:03:28"; int Arg2 = -3; double Arg3 = 70.0; verify_case(1, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "12:03:28"; string Arg1 = "11:59:58"; int Arg2 = 3; double Arg3 = 70.0; verify_case(2, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "03:03:02"; string Arg1 = "03:01:47"; int Arg2 = 5; double Arg3 = 15.0; verify_case(3, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "03:03:02"; string Arg1 = "03:01:47"; int Arg2 = -5; double Arg3 = 8625.0; verify_case(4, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "07:08:09"; string Arg1 = "09:08:07"; int Arg2 = -321; double Arg3 = 22.42367601246106; verify_case(5, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BadClock ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

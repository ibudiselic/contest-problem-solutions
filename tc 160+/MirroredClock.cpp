#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MirroredClock {
	public:
	string whatTimeIsIt(string time) {
		int h, m;
		sscanf(time.c_str(), "%d:%d", &h, &m);

		if (h < 6)
			h = 11-h + (m==0);
		else
			h = 12-h - (m!=0);

		m = (60-m)%60;

		char buff[10];
		sprintf(buff, "%02d:%02d", h%12, m);
		return string(buff);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "10:00"; string Arg1 = "02:00"; verify_case(0, Arg1, whatTimeIsIt(Arg0)); }
	void test_case_1() { string Arg0 = "01:15"; string Arg1 = "10:45"; verify_case(1, Arg1, whatTimeIsIt(Arg0)); }
	void test_case_2() { string Arg0 = "03:40"; string Arg1 = "08:20"; verify_case(2, Arg1, whatTimeIsIt(Arg0)); }
	void test_case_3() { string Arg0 = "00:00"; string Arg1 = "00:00"; verify_case(3, Arg1, whatTimeIsIt(Arg0)); }
	void test_case_4() { string Arg0 = "11:53"; string Arg1 = "00:07"; verify_case(4, Arg1, whatTimeIsIt(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MirroredClock ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int bc[10];
class Bigital {
	public:
	double energy(string tStart, string tEnd) {
		bc[0] = 0;
		for (int i=1; i<60; ++i)
			bc[i] = bc[i>>1] + (i&1);

		int sh, sm, ss, eh, em, es;
		sscanf(tStart.c_str(), "%d:%d:%d", &sh, &sm, &ss);
		sscanf(tEnd.c_str(), "%d:%d:%d", &eh, &em, &es);

		int ws = 0;

		while (1) {
			ws += bc[sh/10]+bc[sh%10] + bc[sm/10]+bc[sm%10] + bc[ss/10]+bc[ss%10];

			if (sh==eh && sm==em && ss==es)
				break;

			++ss;
			if (ss == 60) {
				ss = 0;
				++sm;
			}
			if (sm == 60) {
				sm = 0;
				++sh;
			}
			if (sh == 13)
				sh = 1;
		}

		return ws/3600000.0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "12:00:00"; string Arg1 = "12:00:00"; double Arg2 = 5.555555555555555E-7; verify_case(0, Arg2, energy(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "12:59:59"; string Arg1 = "01:00:00"; double Arg2 = 3.0555555555555556E-6; verify_case(1, Arg2, energy(Arg0, Arg1)); }
	void test_case_2() { string Arg0 =  "12:01:00"; string Arg1 = "12:00:00"; double Arg2 = 0.08392277777777778; verify_case(2, Arg2, energy(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Bigital ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

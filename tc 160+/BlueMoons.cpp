#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
int days[] = {3100, 2800, 3100, 3000, 3100, 3000, 3100, 3100, 3000, 3100, 3000, 3100};
class BlueMoons {
	public:
	void dec(int &d, int &m, int &y) {
		d -= 2953;
		while (d < 0) {
			--m;
			if (m < 0) {
				--y;
				m += 12;
			}
			d += days[m];
			if (m==1 && y%4==0 && (y%400==0 || y%100!=0))
				d += 100;
		}
	}
	void inc(int &d, int &m, int &y) {
		d += 2953;
		int mdays = days[m] + (m==1 && y%4==0 && (y%400==0 || y%100!=0))*100;
		while (d >= mdays) {
			d -= mdays;
			++m;
			if (m > 11) {
				++y;
				m -= 12;
			}
			mdays = days[m] + (m==1 && y%4==0 && (y%400==0 || y%100!=0))*100;
		}
	}
	int count(string interval, string fullMoon) {
		int leftm, lefty, rightm, righty;
		sscanf(interval.c_str(), "%d/%d to %d/%d", &leftm, &lefty, &rightm, &righty);
		--rightm;
		--leftm;

		int a, b, m, y;
		sscanf(fullMoon.c_str(), "%d.%d/%d/%d", &a, &b, &m, &y);

		--m;
		int d = (a-1)*100 + b;

		while (y >= 1900)
			dec(d, m, y);

		int sol = 0;
		int lasty = y, lastm = m;

		while (y<righty || (y==righty && m<=rightm)) {
			inc(d, m, y);
			int thisin = (y>lefty || (y==lefty && m>=leftm)) && (y<righty || (y==righty && m<=rightm));

			if (thisin && lastm==m && lasty==y)
				++sol;

			lastm = m;
			lasty = y;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01/2002 to 05/2002"; string Arg1 = "28.95/01/2002"; int Arg2 = 0; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "01/2002 to 05/2002"; string Arg1 = "01.00/01/2002"; int Arg2 = 2; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "01/2002 to 01/2002"; string Arg1 = "02.46/01/2002"; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "01/2002 to 01/2002"; string Arg1 = "01.00/02/2002"; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BlueMoons ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

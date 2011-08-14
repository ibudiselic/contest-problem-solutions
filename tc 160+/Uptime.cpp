#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
Note that 12:00 PM is considered noon and 12:00 AM is considered midnight of the day that is just starting.
-
You must take leap years into account. Leap years are divisible by 4, except for years divisible by 100, unless they are also divisible by 400. Therefore, 1996 and 2000 were leap years, but 1900 was not, and the year 2100 will not be.
-
The 3-letter month abbreviations are Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec. The number of days in each of the corresponding months in a non-leap year is: 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31.

day month year at hh:mm:ss AM/PM
*/
string mnthstr[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
int mnthday[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isLeap(int y) {
	return (y%4==0 && (y%100!=0 || y%400==0));
}
void parse(const string &str, int &d, int &m, int &y, int &h, int &min, int &s) {
	char mnthbuff[4], modbuff[3];
	sscanf(str.c_str(), "%d %s %d at %d:%d:%d %s", &d, mnthbuff, &y, &h, &min, &s, modbuff);

	m = find(mnthstr, mnthstr+12, mnthbuff)-mnthstr;

	if (string(modbuff) == "AM") {
		if (h == 12)
			h = 0;
	} else { // PM
		if (h != 12)
			h += 12;
	}
}
long long calc(long long d, int m, int y, int h, int min, int s, bool leap) {
	for (int i=0; i<m; ++i)
		d += mnthday[i] + (i==1 && leap);

	long long x = s + min*60 + h*3600 + (d-1)*3600*24;

	int yy = 1900;
	while (yy < y)
		x += (365+isLeap(yy++))*3600*24;

	return x;
}
class Uptime {
	public:
	string calcUptime(string started, string now) {
		int d1, d2, m1, m2, y1, y2, h1, h2, min1, min2, s1, s2;

		parse(started, d1, m1, y1, h1, min1, s1);
		parse(now, d2, m2, y2, h2, min2, s2);

		long long sec1 = calc(d1, m1, y1, h1, min1, s1, isLeap(y1));
		long long sec2 = calc(d2, m2, y2, h2, min2, s2, isLeap(y2));

		/*cerr << started << '\n' << d1 << ' ' << m1 << ' ' << y1 << ' ' << h1 << ' ' << min1 << ' ' << s1 << '\n';
		cerr << now << '\n' << d2 << ' ' << m2 << ' ' << y2 << ' ' << h2 << ' ' << min2 << ' ' << s2 << '\n';

		cerr << started << ' ' << sec1 << '\n';
		cerr << now << ' ' << sec2 << '\n';*/

		long long sol = sec2 - sec1;

		int s, m, h, d;
		s = sol%60;
		sol /= 60;
		m = sol%60;
		sol /= 60;
		h = sol%24;
		sol /= 24;
		d = sol;

		bool haveSome = 0;
		ostringstream os;
		if (d > 0) {
			haveSome = 1;
			os << d << 'd';
		}
		if (h > 0) {
			if (haveSome)
				os << ' ';
			haveSome = 1;
			os << h << 'h';
		}
		if (m > 0) {
			if (haveSome)
				os << ' ';
			haveSome = 1;
			os << m << 'm';
		}
		if (s > 0) {
			if (haveSome)
				os << ' ';
			haveSome = 1;
			os << s << 's';
		}

		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "7 Jun 2004 at 04:41:32 PM"; string Arg1 = "8 Jun 2004 at 07:16:28 PM"; string Arg2 = "1d 2h 34m 56s"; verify_case(0, Arg2, calcUptime(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "7 Jun 2004 at 04:41:32 PM"; string Arg1 = "7 Jun 2004 at 04:41:32 PM"; string Arg2 = ""; verify_case(1, Arg2, calcUptime(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "28 Feb 2004 at 01:23:45 PM"; string Arg1 = "1 Mar 2004 at 12:34:56 AM"; string Arg2 = "1d 11h 11m 11s"; verify_case(2, Arg2, calcUptime(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "28 Feb 2005 at 01:23:45 PM"; string Arg1 = "1 Jan 2015 at 12:34:56 AM"; string Arg2 = "3593d 11h 11m 11s"; verify_case(3, Arg2, calcUptime(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "25 Jan 1922 at 05:58:52 AM"; string Arg1 = "26 Feb 2190 at 11:53:14 AM"; string Arg2 = "97918d 5h 54m 22s"; verify_case(4, Arg2, calcUptime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Uptime ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

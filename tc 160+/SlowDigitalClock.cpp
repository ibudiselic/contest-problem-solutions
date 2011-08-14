#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool isBadDig(int d) {
	return d==3 || d==4 || d==7;
}
int invD(int d) {
	assert(!isBadDig(d));

	if (d == 6)
		return 9;
	if (d == 9)
		return 6;
	return d;
}
int inv(int x) {
	return invD(x%10)*10 + invD(x/10);
}
struct Time {
	int h, m, s, spm;
	Time(const string &t, int spm_=60): s(0), spm(spm_) {
		sscanf(t.c_str(), "%d:%d", &h, &m);
	}
	Time(int h_, int m_, int s_=0, int spm_=60): h(h_), m(m_), s(s_), spm(spm_) {}
	void advance(int secs) {
		s += secs;
		m += s/spm;
		s %= spm;
		h += m/60;
		m %= 60;
		h %= 24;
	}
	int notMeaningful() {
		if (isBadDig(h/10))
			return 10*60*spm;
		if (isBadDig(h%10))
			return 60*spm;
		if (isBadDig(m/10))
			return 10*spm;
		if (isBadDig(m%10))
			return spm;
		return 0;
	}
	bool valid() const {
		return h>=0 && h<24 && m>=0 && m<60;
	}
	Time invert() {
		int H = inv(m);
		int M = inv(h);

		return Time(H, M);
	}
	string rep() {
		static char buff[20];
		sprintf(buff, "%02d:%02d", h, m);
		return string(buff);
	}
};
bool operator==(const Time &a, const Time &b) {
	if (!b.valid())
		return false;
	return a.h==b.h && a.m==b.m;
}
class SlowDigitalClock {
	public:
	string firstCorrectTime(string currentTime, string clockTime, int secsPerMinute) {
		Time real(currentTime);
		Time clock(clockTime, secsPerMinute);

		for (int i=0; i<10000000; ++i) {
			int t = clock.notMeaningful();
			if (t == 0) {
				const Time tt = clock.invert();
				if (real == tt) {
					return real.rep();
				} else {
					real.advance(1);
					clock.advance(1);
				}
			} else {
				real.advance(t);
				clock.advance(t);
			}
		}

		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01:11"; string Arg1 = "21:09"; int Arg2 = 61; string Arg3 = "01:12"; verify_case(0, Arg3, firstCorrectTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "01:10"; string Arg1 = "21:09"; int Arg2 = 61; string Arg3 = "01:12"; verify_case(1, Arg3, firstCorrectTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "12:50"; string Arg1 = "05:21"; int Arg2 = 125; string Arg3 = "12:50"; verify_case(2, Arg3, firstCorrectTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "05:46"; string Arg1 = "23:50"; int Arg2 = 240; string Arg3 = "11:10"; verify_case(3, Arg3, firstCorrectTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "12:34"; string Arg1 = "23:45"; int Arg2 = 197; string Arg3 = "02:11"; verify_case(4, Arg3, firstCorrectTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "12:34"; string Arg1 = "23:45"; int Arg2 = 300; string Arg3 = ""; verify_case(5, Arg3, firstCorrectTime(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "00:00"; string Arg1 = "00:01"; int Arg2 = 86; string Arg3 = "01:22"; verify_case(6, Arg3, firstCorrectTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SlowDigitalClock ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

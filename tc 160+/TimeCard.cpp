#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int getTime(const string &s) {
	int h, m;
	char mod;
	sscanf(s.c_str(), "%d:%d,%cm", &h, &m, &mod);

	if (mod=='a' && h==12)
		h = 0;
	if (mod=='p' && h!=12)
		h += 12;

	return h*60 + m;
}
string encodeTime(int m) {
	int h = m/60;
	m %= 60;
	char *mod = "";

	if (h == 24)
		h = 0;

	if (h >= 12) {
		mod = "pm";
		if (h > 12)
			h -= 12;
	} else {
		mod = "am";
	}

	if (h == 0)
		h = 12;

	static char buff[16];
	sprintf(buff, (string("%02d:%02d,") + mod).c_str(), h, m);
	return string(buff);
}
class TimeCard {
	public:
	string leave(vector <string> time) {
		int maxWork = 20*60;
		int have = 0;
		for (int i=0; i+1<(int)time.size(); i+=2) {
			int start = getTime(time[i]);
			int end = getTime(time[i+1]);
			if (end < start)
				end += 24*60;
			have += end-start;
		}

		if (have < 20*60)
			return "BELOW 40";
		if (have > 40*60)
			return "ABOVE 40";

		int need = 40*60 - have;
		assert(need>=0 && need<=maxWork);

		int start = getTime(time.back());
		int end = start + need;
		if (end > 24*60)
			end -= 24*60;

		return encodeTime(end);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"03:00,pm"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BELOW 40"; verify_case(0, Arg1, leave(Arg0)); }
	void test_case_1() { string Arr0[] = {"09:00,am","05:00,pm","09:00,am","05:00,pm",
    "09:00,am","05:00,pm","09:00,am","05:00,pm","09:00,am"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "05:00,pm"; verify_case(1, Arg1, leave(Arg0)); }
	void test_case_2() { string Arr0[] = {"12:00,am","08:00,pm","12:00,am","08:00,pm","12:00,am"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "12:00,am"; verify_case(2, Arg1, leave(Arg0)); }
	void test_case_3() { string Arr0[] = {"12:00,pm","08:00,pm","12:00,am","08:00,pm","12:00,am"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "12:00,pm"; verify_case(3, Arg1, leave(Arg0)); }
	void test_case_4() { string Arr0[] = {"09:00,am","04:31,pm","09:00,am","04:31,pm",
     "09:00,am","05:00,pm","09:00,am","05:00,pm","03:53,am"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "12:51,pm"; verify_case(4, Arg1, leave(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TimeCard ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

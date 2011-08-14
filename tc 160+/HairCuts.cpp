#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int parse(const string &s) {
	int h, m;
	sscanf(s.c_str(), "%d:%d", &h, &m);
	if (h < 9)
		h += 12;

	return h*60 + m;
}
bool isPossible(const vector<int> &t, int x) {
	int cur = 0;
	for (int i=0; i<(int)t.size(); ++i)
		cur = max(t[i], cur) + 5;

	return cur <= x;
}
double calc(const vector<int> &t, double x) {
	double cur = 0;
	for (int i=0; i<(int)t.size(); ++i)
		cur = max(double(t[i]), cur) + x;

	return cur;
}

class HairCuts {
	public:
	double maxCut(vector <string> enter, string lastExit) {
		vector<int> t;
		for (int i=0; i<(int)enter.size(); ++i)
			t.push_back(parse(enter[i]));
		sort(t.begin(), t.end());

		int x = parse(lastExit);

		if (!isPossible(t, x))
			return -1;

		double lo = 5;
		double hi = 100000;
		for (int i=0; i<300; ++i) {
			double mid = (lo+hi)/2;
			if (calc(t, mid) < x)
				lo = mid;
			else
				hi = mid;
		}

		return (lo+hi)/2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"04:22","09:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "05:52"; double Arg2 = 90.0; verify_case(0, Arg2, maxCut(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"09:00","09:22","09:22"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "10:11"; double Arg2 = 23.666666666666863; verify_case(1, Arg2, maxCut(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"09:00","04:00","04:02"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "04:09"; double Arg2 = -1.0; verify_case(2, Arg2, maxCut(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {  "04:40", "10:54", "12:30", "03:46", "04:48", "01:57", "04:47", "10:29", "10:39"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "05:21"; double Arg2 = 13.6666666666669; verify_case(3, Arg2, maxCut(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HairCuts ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

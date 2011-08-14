#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n;
inline string reverse(const string &a) {
	return string(a.rbegin(), a.rend());
}
unsigned make_mask(const string &s) {
	unsigned ret = 0;

	for (int i=0; i<(int)s.size(); ++i)
		ret = (ret<<1)|(s[i]-'0');
	return ret;
}
unsigned maximize(unsigned x) {
	unsigned ret = x;

	for (int i=0; i<n; ++i) {
		x = ((x<<1)&((1<<n)-1))|(x>>(n-1));
		ret >?= x;
	}
	return ret;
}
class CircleBugs {
	public:
	char doit(char c) {
		if (c=='R')
			return '0';
		else
			return '1';
	}
	int cycleLength(string form) {
		for (int i=0; i<(int)form.size(); ++i)
			form[i] = doit(form[i]);

		n = (int)form.size();
		map<unsigned, int> memo;
		for (int step=0; ; ++step) {
			unsigned t = maximize(make_mask(reverse(form)));
			if (memo.count(t) != 0)
				return step-memo[t];
			t = maximize(make_mask(form));
			if (memo.count(t) != 0)
				return step-memo[t];

			memo[t] = step;
			string next;
			for (int i=0; i<(int)form.size(); ++i)
				if (form[i]==form[(i+1)%form.size()])
					next.push_back('0');
				else
					next.push_back('1');
			form.swap(next);
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRG"; int Arg1 = 1; verify_case(0, Arg1, cycleLength(Arg0)); }
	void test_case_1() { string Arg0 = "RRGRG"; int Arg1 = 3; verify_case(1, Arg1, cycleLength(Arg0)); }
	void test_case_2() { string Arg0 = "RRRRRRRRRR"; int Arg1 = 1; verify_case(2, Arg1, cycleLength(Arg0)); }
	void test_case_3() { string Arg0 = "RGGGGGGGGG"; int Arg1 = 6; verify_case(3, Arg1, cycleLength(Arg0)); }
	void test_case_4() { string Arg0 = "GGRRGGRGRGRRGRRRGGR"; int Arg1 = 511; verify_case(4, Arg1, cycleLength(Arg0)); }
	void test_case_5() { string Arg0 = "RGGGGGGGGGGGGGGGGGGGGGGGGGGGR"; int Arg1 = 16383; verify_case(5, Arg1, cycleLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CircleBugs ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

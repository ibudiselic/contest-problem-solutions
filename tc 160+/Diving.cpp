#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool test(int diff, int need, vector<int> r, int res) {
	r.push_back(res);
	sort(r.begin(), r.end());
	int sum = 0;
	for (int i=1; i<(int)r.size()-1; ++i)
		sum += r[i];

	return sum*diff >= need;
}
class Diving {
	public:
	string needed(string difficulty, string need_, string ratings) {
		int diff, t;
		if (difficulty[0] == '.')
			difficulty = '0' + difficulty;
		sscanf(difficulty.c_str(), "%d.%d", &diff, &t);
		diff = diff*10 + t;

		int need;
		if (need_[0] == '.')
			need_ = '0' + need_;
		sscanf(need_.c_str(), "%d.%d", &need, &t);
		need = need*100 + t;

		vector<int> r;
		istringstream is(ratings);
		string s;
		while (is >> s) {
			if (s[0] == '.')
				s = '0' + s;
			if (s[0] != '?') {
				int x;
				sscanf(s.c_str(), "%d.%d", &x, &t);
				r.push_back(x*10 + t);
			}
		}

		for (int res=0; res<=100; res+=5)
			if (test(diff, need, r, res)) {
				ostringstream os;
				os << res/10 << '.' << res%10;
				return os.str();
			}

		return "-1.0";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "3.2"; string Arg1 = "50.32"; string Arg2 = "5.5 7.5 10.0 ?.? 4.5"; string Arg3 = "0.0"; verify_case(0, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "3.2"; string Arg1 = "50.32"; string Arg2 = "5.5 5.5 10.0 ?.? 4.5"; string Arg3 = "5.0"; verify_case(1, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "4.0"; string Arg1 = "120.00"; string Arg2 = "9.5 10.0 ?.? 10.0 10.0"; string Arg3 = "10.0"; verify_case(2, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "4.0"; string Arg1 = "120.00"; string Arg2 = "9.5 10.0 ?.? 9.5 10.0"; string Arg3 = "-1.0"; verify_case(3, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "2.3"; string Arg1 = ".01"; string Arg2 = "0.0 0.0 ?.? 0.0 0.5"; string Arg3 = "0.5"; verify_case(4, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "3.3"; string Arg1 = "47.85"; string Arg2 = "0.5 5.5 3.5 7.0 ?.?"; string Arg3 = "5.5"; verify_case(5, Arg3, needed(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Diving ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class ExerciseMachine {
	public:
	int getPercentages(string time) {
		int s = 0;
		int t = 0;
		int i = 0;

		for (; i<(int)time.size() && time[i] != ':'; ++i)
			s = s*10 + time[i]-'0';
		for (++i; i<(int)time.size() && time[i] != ':'; ++i)
			t = t*10 + time[i]-'0';
		s *= 3600;
		s += t*60;
		for (++i, t=0; i<(int)time.size(); ++i)
			t = t*10 + time[i]-'0';
		s += t;
		for (t=1; t<13*3600; ++t)
			if ((t*100)%s == 0)
				return s/t-1;
		return 0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "00:30:00"; int Arg1 = 99; verify_case(0, Arg1, getPercentages(Arg0)); }
	void test_case_1() { string Arg0 = "00:28:00"; int Arg1 = 19; verify_case(1, Arg1, getPercentages(Arg0)); }
	void test_case_2() { string Arg0 = "23:59:59"; int Arg1 = 0; verify_case(2, Arg1, getPercentages(Arg0)); }
	void test_case_3() { string Arg0 = "00:14:10"; int Arg1 = 49; verify_case(3, Arg1, getPercentages(Arg0)); }
	void test_case_4() { string Arg0 = "00:19:16"; int Arg1 = 3; verify_case(4, Arg1, getPercentages(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ExerciseMachine ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

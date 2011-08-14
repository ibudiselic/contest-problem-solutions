#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct team {
	int home, away;
	team(int h=0, int a=0): home(h), away(a) {}
};
bool operator<(const team &a, const team &b) {
	if (a.home+a.away != b.home+b.away)
		return a.home+a.away < b.home+b.away;
	else
		return a.away < b.away;
}
class SoccerCommentator {
	public:
	int goalsToWin(string score1, string score2, int host) {
		vector<team> v(2);
		int x, y;
		--host;
		sscanf(score1.c_str(), "%d:%d", &x, &y);
		v[0].home += (host==0)*x;
		v[0].away += (host==1)*x;
		v[1].home += (host==1)*y;
		v[1].away += (host==0)*y;
		sscanf(score2.c_str(), "%d:%d", &x, &y);
		host = 1-host;
		v[0].home += (host==0)*x;
		v[0].away += (host==1)*x;
		v[1].home += (host==1)*y;
		v[1].away += (host==0)*y;

		int sol = 0;
		while (v[0]<v[1] || (!(v[0]<v[1]) && !(v[1]<v[0]))) {
			++sol;
			if (host == 1)
				++v[0].away;
			else
				++v[0].home;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0:0"; string Arg1 = "0:0"; int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, goalsToWin(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "0:2"; string Arg1 = "0:3"; int Arg2 = 1; int Arg3 = 5; verify_case(1, Arg3, goalsToWin(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "0:2"; string Arg1 = "0:3"; int Arg2 = 2; int Arg3 = 6; verify_case(2, Arg3, goalsToWin(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SoccerCommentator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

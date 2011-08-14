#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct State {
	int pos, cur, last, prelast, val;
	State(int pos_, int cur_, int last_, int prelast_, int val_): pos(pos_), cur(cur_), last(last_), prelast(prelast_), val(val_) {}
};

int source[53], target[50];
int N;
int dp[53][10][10][10];
bool seen[53][10][10][10];
int dist(int a, int b) {
	const int t = abs(a-b);
	int best = min(t, 10-t);

	return (best+2)/3;
}

bool done(const State &s) {
	return dp[s.pos][s.cur][s.last][s.prelast] != -1;
}
int get(const State &s) {
	return dp[s.pos][s.cur][s.last][s.prelast];
}
void set(const State &s, int val) {
	dp[s.pos][s.cur][s.last][s.prelast] = val;
}
void inc10(int &x) {
	if (++x == 10)
		x = 0;
}
bool wasSeen(const State &s) {
	return seen[s.pos][s.cur][s.last][s.prelast];
}
void setSeen(const State &s) {
	seen[s.pos][s.cur][s.last][s.prelast] = 1;
}
int go(int pos, int cur, int last, int prelast) {
	State s(pos, cur, last, prelast, 0);
	set(s, 0);
	deque<State> D;
	D.push_back(s);

	while (!D.empty()) {
		s = D.front();
		D.pop_front();

		if (s.pos == N+2)
			return s.val;

		if (done(s) && get(s)<s.val)
			continue;

		set(s, s.val);

		if (s.prelast == target[s.pos-2]) {
			State ns(s.pos+1, source[s.pos+1], s.cur, s.last, s.val);
			if (!done(ns)) {
				set(ns, s.val);
				D.push_front(ns);
			}
		}

		// turn prelast only
		{
			State ns(s.pos, s.cur, s.last, (s.prelast+10-4)%10, s.val+1);
			for (int i=-3; i<=3; ++i) {
				inc10(ns.prelast);
				if (i!=0 && !done(ns) && !wasSeen(ns)) {
					setSeen(ns);
					D.push_back(ns);
				}
			}
		}
		// turn last and prelast
		if (s.pos < N+1) {
			State ns(s.pos, s.cur, (s.last+10-4)%10, (s.prelast+10-4)%10, s.val+1);
			for (int i=-3; i<=3; ++i) {
				inc10(ns.prelast);
				inc10(ns.last);
				if (i!=0 && !done(ns) && !wasSeen(ns)) {
					setSeen(ns);
					D.push_back(ns);
				}
			}
		}
		// turn cur, last and prelast
		if (s.pos < N) {
			State ns(s.pos, (s.cur+10-4)%10, (s.last+10-4)%10, (s.prelast+10-4)%10, s.val+1);
			for (int i=-3; i<=3; ++i) {
				inc10(ns.prelast);
				inc10(ns.last);
				inc10(ns.cur);
				if (i!=0 && !done(ns) && !wasSeen(ns)) {
					setSeen(ns);
					D.push_back(ns);
				}
			}
		}
	}
	return -1;
}

class BikeLock {
	public:
	int minTurns(string current, string desired) {
		N = current.size();
		for (int i=0; i<N; ++i) {
			source[i] = current[i]-'0';
			target[i] = desired[i]-'0';
		}
		for (int i=N; i<=N+2; ++i)
			source[i] = 0;

		memset(dp, 0xff, sizeof dp);
		memset(seen, 0, sizeof seen);
		return go(2, source[2], source[1], source[0]);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "555"; string Arg1 = "464"; int Arg2 = 2; verify_case(0, Arg2, minTurns(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1234"; string Arg1 = "3456"; int Arg2 = 2; verify_case(1, Arg2, minTurns(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "06012005"; string Arg1 = "06012005"; int Arg2 = 0; verify_case(2, Arg2, minTurns(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "123456789"; string Arg1 = "567412490"; int Arg2 = 5; verify_case(3, Arg2, minTurns(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "23887547676234543215443276347856987698648735634265"; string Arg1 = "14327805497625497814327632146531429785698765309822"; int Arg2 = 34; verify_case(4, Arg2, minTurns(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BikeLock ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

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

bool canMake[361];
bool A[21][21][21][361];

struct State {
	int a, b, c, interval;
	State(int a_, int b_, int c_, int interval_): a(a_), b(b_), c(c_), interval(interval_) {}
};
bool done(const State &s) {
	return A[s.a][s.b][s.c][s.interval];
}
void set(const State &s) {
	A[s.a][s.b][s.c][s.interval] = 1;
}

void bfs(const vector<int> &timers, int maxTime) {
	int t = 0;
	int time = -1;
	State s(timers[0], timers[1], timers[2], 0);
	memset(A, 0, sizeof A);
	set(s);

	queue<State> Q;
	Q.push(s);
	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++time;
			if (time >= maxTime)
				return;
		}
		--t;

		s = Q.front();
		Q.pop();

		if (s.a==1 || s.b==1 || s.c==1) {
			canMake[s.interval+1] = 1;
			int na = max(s.a-1, 0);
			int nb = max(s.b-1, 0);
			int nc = max(s.c-1, 0);
			State ns(na, nb, nc, s.interval+1);
			for (int i=0; i<2; ++i) {
				ns.a = (i ? timers[0]-na : na);
				for (int j=0; j<2; ++j) {
					ns.b = (j ? timers[1]-nb : nb);
					for (int k=0; k<2; ++k) {
						ns.c = (k ? timers[2]-nc : nc);
						for (int next=0; next<2; ++next) {
							ns.interval = (next ? s.interval+1 : 0);
							if (!done(ns)) {
								set(ns);
								Q.push(ns);
							}
						}
					}
				}
			}
		} else {
			int na = max(s.a-1, 0);
			int nb = max(s.b-1, 0);
			int nc = max(s.c-1, 0);
			State ns(na, nb, nc, s.interval+1);
			if (!done(ns)) {
				set(ns);
				Q.push(ns);
			}
		}
	}
}
class SandTimers {
	public:
	vector <int> badIntervals(vector <int> timers, int maxInterval, int maxTime) {
		memset(canMake, 0, sizeof canMake);

		while (timers.size() < 3)
			timers.push_back(0);
		bfs(timers, maxTime);

		vector<int> sol;
		for (int i=1; i<=maxInterval; ++i)
			if (!canMake[i])
				sol.push_back(i);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { 5, 7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 10; int Arr3[] = {1, 6, 8 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, badIntervals(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 2, 10, 20 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 40; int Arr3[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, badIntervals(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 2, 5, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 360; int Arg2 = 360; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, badIntervals(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; int Arg2 = 47; int Arr3[] = {1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15, 17, 18, 19, 21, 22, 23 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, badIntervals(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = { 20, 13 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 30; int Arr3[] = {1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 28, 29, 30 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, badIntervals(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = { 20, 17, 13 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; int Arg2 = 30; int Arr3[] = {18, 19 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, badIntervals(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SandTimers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

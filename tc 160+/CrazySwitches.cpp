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
typedef unsigned short us;

bool done[1<<16][16];
class CrazySwitches {
	public:
	int minimumActions(vector <int> switches) {
		int n = switches.size();
		memset(done, 0, sizeof done);

		vector< vector<int> > s(n, vector<int>());
		for (int i=0; i<n; ++i)
			s[switches[i]].push_back(i);

		us goal = (1<<(n-1));

		deque<us> state;
		deque<int> pos;
		deque<int> len;
		state.push_back(1);
		pos.push_back(0);
		len.push_back(0);

		done[1][0] = true;
		while (!state.empty()) {
			us t = state.front(); state.pop_front();
			int p = pos.front(); pos.pop_front();
			int l = len.front(); len.pop_front();

			if (t == goal)
				return l;
			for (int i=0; i<(int)s[p].size(); ++i) {
				if (s[p][i] == p) continue;
				us next = t;
				next ^= (1 << s[p][i]);
				if (!done[next][p]) {
					done[next][p] = true;
					state.push_front(next);
					pos.push_front(p);
					len.push_front(l);
				}
			}
			for (int i=0; i<n; ++i)
				if (((1<<i)&t) && !done[t][i]) {
					done[t][i] = true;
					state.push_back(t);
					pos.push_back(i);
					len.push_back(l+1);
				}
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumActions(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, minimumActions(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, minimumActions(Arg0)); }
	void test_case_3() { int Arr0[] = {4, 4, 3, 0, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, minimumActions(Arg0)); }
	void test_case_4() { int Arr0[] = {7, 11, 1, 12, 6, 3, 0, 2, 6, 0, 0, 5, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(4, Arg1, minimumActions(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CrazySwitches ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

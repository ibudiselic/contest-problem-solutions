#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

struct str {
	string s;
	int pos, cnt;
	str(const string &s_, int pos_, int cnt_): s(s_), pos(pos_), cnt(cnt_) {}
};
bool operator<(const str &a, const str &b) {
	if (a.pos != b.pos)
		return a.pos < b.pos;
	else
		return a.s < b.s;
}

class LexStringWriter {
	public:
	int minMoves(string s) {
		set<str> used;
		queue<str> q;
		int sol = -1;
		int t = 0;
		const str temp(s, 0, s.size());
		q.push(temp);
		used.insert(temp);
		sort(s.begin(), s.end());

		while (!q.empty()) {
			if (t == 0) {
				++sol;
				t = q.size();
			}
			--t;

			const str x = q.front();
			q.pop();
			if (x.cnt == 0)
				return sol;
			const char next = s[s.size()-x.cnt];
			str y = x;
			if (x.s[x.pos] == next) {
				y.s[y.pos] = ' ';
				--y.cnt;
				if (!used.count(y)) {
					used.insert(y);
					q.push(y);
				}
				++y.cnt;
				y.s[y.pos] = next;
			} else {
				if (x.pos > 0) {
					--y.pos;
					if (!used.count(y)) {
						used.insert(y);
						q.push(y);
					}
					++y.pos;
				}
				if (y.pos < (int)s.size()) {
					++y.pos;
					if (!used.count(y)) {
						used.insert(y);
						q.push(y);
					}
				}
			}
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaa"; int Arg1 = 5; verify_case(0, Arg1, minMoves(Arg0)); }
	void test_case_1() { string Arg0 = "ba"; int Arg1 = 4; verify_case(1, Arg1, minMoves(Arg0)); }
	void test_case_2() { string Arg0 = "abba"; int Arg1 = 9; verify_case(2, Arg1, minMoves(Arg0)); }
	void test_case_3() { string Arg0 = "acbbc"; int Arg1 = 12; verify_case(3, Arg1, minMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LexStringWriter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

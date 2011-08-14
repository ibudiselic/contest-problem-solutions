#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calcSwap(const vector<int> &order) {
	vector<bool> used(order.size(), 0);
	int ret = 0;
	for (int i=0; i<(int)order.size(); ++i)
		if (!used[i]) {
			int cyclen = 0;
			int x = i;
			while (!used[x]) {
				used[x] = 1;
				++cyclen;
				x = order[x];
			}
			ret += cyclen-1;
		}

	return ret;
}
int calcIncDec(const string &a, const vector<int> &order, const string &b) {
	int ret = 0;
	for (int i=0; i<(int)a.size(); ++i)
		ret += abs((a[order[i]]-'0')-(b[i]-'0'));

	return ret;
}
class NumberChanger {
	public:
	int transform(string start, string finish) {
		if (start == finish)
			return 0;

		vector<int> order(start.size(), 0);
		for (int i=1; i<(int)order.size(); ++i)
			order[i] = i;

		int sol = 1234567890;
		do {
			sol = min(sol, calcSwap(order) + calcIncDec(start, order, finish));
		} while (next_permutation(order.begin(), order.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01234567"; string Arg1 = "01234567"; int Arg2 = 0; verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "11119999"; string Arg1 = "99991111"; int Arg2 = 4; verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "55555555"; string Arg1 = "12345678"; int Arg2 = 16; verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "77771111"; string Arg1 = "00446688"; int Arg2 = 16; verify_case(3, Arg2, transform(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "12"; string Arg1 = "30"; int Arg2 = 3; verify_case(4, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NumberChanger ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

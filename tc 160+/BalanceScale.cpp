#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int gcd(int m, int n) {
	return m==0 ? n : gcd(n%m, m);
}
struct State {
	int pos, gcd1, gcd2;
	State(int pos_, int gcd1_, int gcd2_): pos(pos_), gcd1(gcd1_), gcd2(gcd2_) {}
};
bool operator<(const State &a, const State &b) {
	if (a.pos != b.pos)
		return a.pos < b.pos;
	else if (a.gcd1 != b.gcd1)
		return a.gcd1 < b.gcd1;
	else
		return a.gcd2 < b.gcd2;
}
vector<int> W;
map<State, int> M;
int go(int pos, int gcd1, int gcd2) {
	if (pos == (int)W.size())
		if (gcd1 == 0)
			return 1234567890;
		else
			return (gcd2%gcd1==0 ? 0 : 1234567890);

	const State state(pos, gcd1, gcd2);
	if (M.count(state))
		return M[state];

	return (M[state] = min(go(pos+1, gcd(gcd1, W[pos]), gcd2)+1, go(pos+1, gcd1, gcd(gcd2, W[pos]))));
}
class BalanceScale {
	public:
	int takeWeights(vector <int> weight) {
		M.clear();
		W = weight;

		return go(0, 0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 5, 4, 1, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, takeWeights(Arg0)); }
	void test_case_1() { int Arr0[] = { 2, 3, 8, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, takeWeights(Arg0)); }
	void test_case_2() { int Arr0[] = { 60, 105, 490, 42 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, takeWeights(Arg0)); }
	void test_case_3() { int Arr0[] = { 15, 25, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, takeWeights(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BalanceScale ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

int P[20];
int cnt;
vector<pii> F;
bool is_palin(const string &s) {
	for (int i=0; i<(int)s.size()/2; ++i)
		if (s[i] != s[s.size()-1-i])
			return false;
	return true;
}
bool go(int x) {
	if (x == cnt) {
		ostringstream os;
		for (int i=0; i<x; ++i)
			os << P[i];
		return is_palin(os.str());
	}
	for (int i=0; i<(int)F.size(); ++i)
		if (F[i].second > 0) {
			--F[i].second;
			P[x] = F[i].first;
			if (go(x+1))
				return true;
			++F[i].second;
		}
	return false;
}
bool is_pp(int x) {
	F.clear();
	int d = 2;
	int last = -1;
	cnt = 0;
	while (d <= x) {
		while (x%d == 0) {
			if (last == d)
				++F[F.size()-1].second;
			else {
				F.push_back(make_pair(d, 1));
				last = d;
			}
			x /= d;
			++cnt;
		}
		++d;
	}
	if (x != 1) {
		F.push_back(make_pair(x, 1));
		++cnt;
	}

	return go(0);
}
class PrimePalindromic {
	public:
	int count(int A, int B) {
		int sol = 0;
		for (int i=A; i<=B; ++i)
			sol += is_pp(i);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2260; int Arg1 = 2262; int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 9; int Arg2 = 7; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 100; int Arg2 = 36; verify_case(2, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PrimePalindromic ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int to_K[10];
long long next[1000001];
map<long long, long long> M;
map<long long, long long> happ;
set<long long> marked;

void calc(int x) {
	int t = x;
	int ret = 0;
	while (x > 0) {
		ret += to_K[x%10];
		x /= 10;
	}
	next[t] = ret;
}
long long g(long long x) {
	long long &ret = M[x];
	if (ret != 0)
		return ret;
	while (x > 0) {
		ret += to_K[x%10];
		x /= 10;
	}
	return ret;
}
long long f(long long x) {
	long long &ret = happ[x];

	if (ret != 0)
		return ret;

	marked.insert(x);

	long long xx = (x<=1000000 ? next[x] : g(x));
	if (marked.count(xx)) {
		// cycle
		set<long long> S;
		while (S.insert(xx).second)
			xx = (xx<=1000000 ? next[xx] : g(xx));
		for (set<long long>::const_iterator it=S.begin(); it!=S.end(); ++it)
			happ[*it] = *S.begin();
		marked.erase(x);
		return ret;
	}

	long long y = f(xx);
	marked.erase(x);
	return ret = min(x, y);
}
class ExtendedHappyNumbers {
	public:
	long long calcTheSum(int A, int B, int K) {
		to_K[0] = 0;
		to_K[1] = 1;
		for (int i=2; i<10; ++i) {
			to_K[i] = 1;
			for (int j=0; j<K; ++j)
				to_K[i] *= i;
		}

		next[0] = 0;
		next[1] = 1;
		for (int x=2; x<=1000000; ++x) {
			calc(x);
		}

		long long sol = 0;
		M.clear();
		happ.clear();
		marked.clear();
		happ[0] = 0;
		happ[1] = 1;

		for (int x=A; x<=B; ++x)
			sol += f(x);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; int Arg1 = 13; int Arg2 = 2; long long Arg3 = 1LL; verify_case(0, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 2; long long Arg3 = 14LL; verify_case(1, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 99; int Arg2 = 1; long long Arg3 = 450LL; verify_case(2, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 535; int Arg1 = 538; int Arg2 = 3; long long Arg3 = 820LL; verify_case(3, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 400000; int Arg2 = 6; long long Arg3 = 5169721292LL; verify_case(4, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ExtendedHappyNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

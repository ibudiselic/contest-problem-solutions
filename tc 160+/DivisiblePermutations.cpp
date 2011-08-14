#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

long long mul;
string Left, Right;
set<string> done;
string N;
long long M;
long long A[50], B[50];

inline long long getNum(const string &s) {
	long long ret = 0;
	for (int i=0; i<(int)s.size(); ++i)
		ret = ret*10 + s[i]-'0';

	return ret;
}
void f(long long *R, string num, long long m) {
	do {
		++R[getNum(num)*m % M];
	} while (next_permutation(num.begin(), num.end()));
}
long long calc() {
	if (done.insert(Left).second == false)
		return 0;

	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);

	f(A, Left, mul);
	f(B, Right, 1);

	long long ret = A[0]*B[0];
	for (int i=1; i<M; ++i)
		ret += A[i]*B[M-i];

	return ret;
}
long long go(int pos, int l, int r, int rem) {
	if (pos == (int)N.size()) {
		return calc();
	}

	long long ret = 0;
	if ((int)N.size()-pos > rem) {
		Right[r] = N[pos];
		ret += go(pos+1, l, r+1, rem);
	}
	if (rem > 0) {
		Left[l] = N[pos];
		ret += go(pos+1, l+1, r, rem-1);
	}

	return ret;
}
class DivisiblePermutations {
	public:
	long long count(string N_, int M_) {
		N = N_;
		M = M_;
		sort(N.begin(), N.end());
		if (N.size() < 5) {
			memset(A, 0, sizeof A);
			f(A, N, 1);
			return A[0];
		}

		int n = (int)N.size()/2;
		mul = 1;
		for (int i=0; i<(N.size()-n); ++i) {
			mul *= 10;
		}

		done.clear();
		Left = string(n, ' ');
		Right = string(N.size()-n, ' ');

		return go(0, 0, 0, n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "133"; int Arg1 = 7; long long Arg2 = 1LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "2753"; int Arg1 = 5; long long Arg2 = 6LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1112225"; int Arg1 = 5; long long Arg2 = 20LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "123456789"; int Arg1 = 17; long long Arg2 = 21271LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "987654321999999"; int Arg1 = 39; long long Arg2 = 19960896LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DivisiblePermutations ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

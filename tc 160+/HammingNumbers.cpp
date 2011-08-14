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


class HammingNumbers {
	public:
	int getNumber(vector <int> factors, int n) {
		set<int> f_(factors.begin(), factors.end());
		vector<int> f(f_.begin(), f_.end());

		set<long long> S;
		S.insert(1);

		long long M = (1LL<<31)-1;
		long long curMax = 0;
		while (1) {
			if ((int)S.size() >= n)
				M = curMax;

			if (S.empty())
				return -1;
			long long x = *S.begin();
			S.erase(S.begin());
			if (--n == 0)
				return x;

			for (int i=0; i<(int)f.size(); ++i) {
				const long long t = x*f[i];
				if (t < M) {
					curMax = max(curMax, t);
					S.insert(t);
				}
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
	void test_case_0() { int Arr0[] = {2,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 24; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,2,2,4,4,4,8,8,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; int Arg2 = 1024; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {7,9,14,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 52; int Arg2 = 4802; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,11,15,21,29,28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2841; int Arg2 = 2146636800; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,
97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,
181,191,193,197,199,211,223,227,229}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000; int Arg2 = 532287; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HammingNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

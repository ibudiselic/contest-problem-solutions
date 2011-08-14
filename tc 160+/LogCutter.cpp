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

class LogCutter {
	public:
	string bestCut(int L, int A, int K, int C) {
		vector<int> V;
		for (int i=1; i<=K; ++i)
			V.push_back(((long long)A*i)%(L-1) + 1);

		sort(V.begin(), V.end());
		int lo = 1;
		int hi = L;
		int global = -1;
		C = min(C, K);
		while (lo < hi) {
			int mid = lo + (hi-lo)/2;
			int last = L;
			int cnt = 0;
			int i = (int)V.size()-1;
			while (cnt < C) {
				if (last-V[i] > mid)
					break;
				while (i>=0 && last-V[i]<=mid)
					--i;
				last = V[i+1];
				++cnt;
			}
			if (last <= mid) {
				hi = mid;
				global = last;
			} else {
				lo = mid+1;
			}
		}

		ostringstream os;
		os << lo << ' ' << global;
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 2; int Arg3 = 1; string Arg4 = "5 4"; verify_case(0, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; string Arg4 = "3 3"; verify_case(1, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 5; int Arg3 = 3; string Arg4 = "2 1"; verify_case(2, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10000; int Arg1 = 999983; int Arg2 = 5000; int Arg3 = 1000; string Arg4 = "13 2"; verify_case(3, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 100; int Arg3 = 100; string Arg4 = "1 1"; verify_case(4, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LogCutter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

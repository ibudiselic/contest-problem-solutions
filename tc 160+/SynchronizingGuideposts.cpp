#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
vector<long long> pos, lim;
int C;
long long myabs(long long x) {
	return x<0 ? -x:x;
}
class SynchronizingGuideposts {
	public:
	long long eval(long long x) {
		long long ret = 0;
		for (int i=0; i<(int)pos.size(); ++i)
			ret += min(lim[i], myabs(x-pos[i])) + max(0ll, myabs(x-pos[i])-lim[i])*(C+1);
		return ret;
	}

	long long minCost(vector <string> guideposts, int C_) {
		pos.clear();
		lim.clear();
		C = C_;
		for (int i=0; i<(int)guideposts.size(); ++i) {
			long long p, d, l;
			istringstream is(guideposts[i]);
			is >> p >> d >> l;
			pos.push_back(p+d);
			lim.push_back(l);
		}
		long long lo = 0ll;
		long long hi = 3000000000ll;

		while (hi-lo > 100) {
			long long m1 = lo + (hi-lo)/3;
			long long m2 = lo + 2*(hi-lo)/3;
			if (eval(m1) < eval(m2))
				hi = m2;
			else
				lo = m1;
		}
		long long sol = eval(lo);
		for (int i=lo+1; i<=hi; ++i)
			sol = min(sol, eval(i));
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"6 -1 5","2 10 4","10 0 5","8 6 5","20 -6 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; long long Arg2 = 15LL; verify_case(0, Arg2, minCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"59 23 13","9 8 28","91 18 50","32 10 80","110 61 120","54 45 18","73 24 118","30 8 73"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; long long Arg2 = 479LL; verify_case(1, Arg2, minCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"79 4 114","68 41 102","80 80 68","48 1 50","59 17 34","118 59 17","29 3 11","31 26 48","74 27 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 5731LL; verify_case(2, Arg2, minCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1 -2 10","2 -3 20","3 -4 30","4 -5 40","5 -6 50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 333; long long Arg2 = 5LL; verify_case(3, Arg2, minCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SynchronizingGuideposts ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

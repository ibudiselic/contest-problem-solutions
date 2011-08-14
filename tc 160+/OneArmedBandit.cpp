#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cntAll;
long long getProb(const vector< vector<int> > &cnt, string s) {
	long long ret = 1;
	for (int i=0; i<(int)s.size(); ++i)
		if (s[i] == '-')
			ret *= cntAll;
		else
			ret *= cnt[i][s[i]-'A'];
	return ret;
}
class OneArmedBandit {
	public:
	double progressiveJackpot(vector <string> wheels, string jackpotLine, vector <string> payoffTable) {
		int n = wheels.size();
		vector< vector<int> > cnt(n, vector<int> (26, 0));

		for (int i=0; i<n; ++i)
			for (int j=0; j<(int)wheels[i].size(); ++j)
				++cnt[i][wheels[i][j]-'A'];

		cntAll = wheels[0].size();

		long long all = 1;
		for (int i=0; i<n; ++i)
			all *= wheels[i].size();

		long long jckpProb = getProb(cnt, jackpotLine);

		long long expect = 0;
		for (int i=0; i<(int)payoffTable.size(); ++i) {
			string w;
			int v;
			istringstream is(payoffTable[i]);
			is >> w >> v;
			long long prob = getProb(cnt, w);

			double test = double(expect) + double(prob)*v;
			if (test*(1+1e-9) > all)
				return 0.0;
			expect += prob*v;
			if (expect >= all)
				return 0.0;
		}

		if (jckpProb == 0)
			return -1.0;

		return double(all-expect)/jckpProb;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC", "ABC", "ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAA"; string Arr2[] = {"BBB 5", "CCC 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 20.0; verify_case(0, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"ABC", "ABC", "ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAA"; string Arr2[] = {"AAB 4", "AA- 3", "AB- 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 8.0; verify_case(1, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"ABC", "ABC", "ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAA"; string Arr2[] = {"AA- 5", "A-- 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.0; verify_case(2, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"ABC", "ABC", "BBC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAA"; string Arr2[] = {"AAB 4", "AA- 3", "AB- 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -1.0; verify_case(3, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"DABCDBCDCD", "BCDBDACDCD", "DCDADBCDBC", "DBDCABCDCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAAA"; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 10000.0; verify_case(4, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"DABCDBCDCD", "BCDBDACDCD", "DCDADBCDBC", "DBDCABCDCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAAA"; string Arr2[] = {"AAAE 20"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 10000.0; verify_case(5, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"KACACEIBGCVDAKMACAAW",
 "CECMBDBJCLHFNDCBDDNB",
 "BYAGBJFDAGBHEGEFVXDR",
 "UDWFABFAHDXACICQHAEH",
 "EBHOCHABAHBDAUBZHHAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "KJ--Z"; string Arr2[] = {"Z-U-U 23",
 "YUBSA 142",
 "Q-AN- 92",
 "ZA-CX 133",
 "-BE-Z 125"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 3500.0; verify_case(6, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OneArmedBandit ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

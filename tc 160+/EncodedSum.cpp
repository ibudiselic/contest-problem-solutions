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

long long cnt[10];
class EncodedSum {
	public:
	long long maximumSum(vector <string> numbers) {
		set<char> S;

		for (int i=0; i<(int)numbers.size(); ++i)
			for (int j=0; j<(int)numbers[i].size(); ++j)
				S.insert(numbers[i][j]);

		memset(cnt, 0, sizeof cnt);
		for (int i=0; i<(int)numbers.size(); ++i) {
			long long mul = 1;
			for (int j=(int)numbers[i].size()-1; j>=0; --j, mul*=10)
				cnt[numbers[i][j]-'A'] += mul;
		}

		string m(S.begin(), S.end());

		long long sol = 0;
		do {
			bool ok = true;
			if (m.size() == 10)
				for (int i=0; i<(int)numbers.size(); ++i)
					if (numbers[i][0] == m[9]) {
						ok = false;
						break;
					}
			if (!ok)
				continue;
			long long cur = 0;
			for (int i=0; i<(int)m.size(); ++i)
				cur += cnt[m[i]-'A']*(9-i);

			sol = max(sol, cur);
		} while (next_permutation(m.begin(), m.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC",
 "BCA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1875LL; verify_case(0, Arg1, maximumSum(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABCDEFGHIJ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9876543210LL; verify_case(1, Arg1, maximumSum(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABCDEFGHIJ",
 "J"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9876543202LL; verify_case(2, Arg1, maximumSum(Arg0)); }
	void test_case_3() { string Arr0[] = {"A",
 "BB",
 "CCC",
 "DDDD",
 "EEEEE",
 "FFFFFF",
 "GGGGGGG",
 "HHHHHHHH",
 "IIIIIIIII",
 "AJJJJJJJJJ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9973936905LL; verify_case(3, Arg1, maximumSum(Arg0)); }
	void test_case_4() { string Arr0[] = {"GHJIDDD",
 "AHHCCCA",
 "IIJCEJ",
 "F",
 "HDBIGFJAAJ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9888114550LL; verify_case(4, Arg1, maximumSum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EncodedSum ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool ok(const string &s, int n) {
	string t;
	ostringstream os;
	for (int i=1; i<=n; ++i)
		os << i;
	t = os.str();

	int i = 0;
	int j = 0;

	while (i<(int)s.size() && j<(int)t.size() && (s.size()-i <= t.size()-j)) {
		if (s[i] == t[j])
			++i;
		++j;
	}

	return i==(int)s.size();
}
class StringOfNumbers {
	public:
	int getLeastN(vector <string> leftDigits) {
		string s;

		for (int i=0; i<(int)leftDigits.size(); ++i)
			s += leftDigits[i];

		int lo = 1;
		int hi = 1;

		while (!ok(s, hi)) {
			lo = hi;
			hi *= 2;
		}

		while (lo < hi) {
			int mid = lo + (hi-lo)/2;

			if (ok(s, mid))
				hi = mid;
			else
				lo = mid+1;
		}

		return lo;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getLeastN(Arg0)); }
	void test_case_1() { string Arr0[] = {"234092"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(1, Arg1, getLeastN(Arg0)); }
	void test_case_2() { string Arr0[] = {"000000000000000000000000000", "0000000000000000000000", "0000000000000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 400; verify_case(2, Arg1, getLeastN(Arg0)); }
	void test_case_3() { string Arr0[] = {"3450298340230498203948023", "3490924098203984203948", "3294792934790209"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 279; verify_case(3, Arg1, getLeastN(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StringOfNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

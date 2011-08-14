#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool test(const vector<string> &v, int k) {
	string last = v[0].substr(0, k);
	for (int i=1; i<(int)v.size(); ++i) {
		string next;
		int x = 0;
		for (int j=0; x<k && j<(int)v[i].size(); ++j)
			if (v[i][j] >= last[x]) {
				++x;
				next += v[i][j];
			}
		if (x < k)
			return false;
		last.swap(next);
	}
	return true;
}
class LongestSubanagramChain {
	public:
	int getLength(vector <string> B) {
		int K = 1234567890;
		int n = B.size();
		for (int i=0; i<n; ++i) {
			K = min(K, (int)B[i].size());
			sort(B[i].begin(), B[i].end());
		}

		while (!test(B, K)) {
			if (--K == 0)
				break;
		}

		return K;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"abaa", "abab", "aaba", "babb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"aa", "bbb", "ccc", "ddd", "eee"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"coder", "coding", "topcoder", "program"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"b", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, getLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LongestSubanagramChain ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long calc(const string &w) {
	long long ret = 0;

	for (int i=0; i<(int)w.size(); ++i)
		ret = ret*26 + (w[i]-'a');

	return ret;
}
long long f(const string &w, int k) {
	int n = w.size();

	if (n < k)
		return f(w + string(k-n, 'a'), k);
	else if (n == k)
		return calc(w);
	else
		return f(w.substr(0, k), k) + 1;
}
class LikelyWord {
	public:
	int likely(vector <string> dictionary, int k) {
		int sol = 0;
		long long val = f(dictionary[0], k);

		if (dictionary.back() < string(k, 'z'))
			dictionary.push_back(string(k+1, 'z'));
		for (int i=1; i<(int)dictionary.size(); ++i) {
			long long cur = f(dictionary[i], k)-f(dictionary[i-1], k)-((int)dictionary[i-1].size()==k);
			if (cur > val) {
				sol = i;
				val = cur;
			} else if (cur == val) {
				sol = -1;
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"time","zoology"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(0, Arg2, likely(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"az","ma","xz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, likely(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"az","ma","xz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(2, Arg2, likely(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"a","m","y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(3, Arg2, likely(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LikelyWord ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

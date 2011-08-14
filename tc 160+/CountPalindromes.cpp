#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

vector<string> W;
int N;
int mod = 835454957;
map< pair<int, string>, int > Ml, Mr;

void inc(int &a, int b) {
	a = (a+b)%mod;
}

bool is_palin(const string &s) {
	for (int i=0; i<(int)s.size()/2; ++i)
		if (s[i] != s[s.size()-1-i])
			return false;

	return true;
}
bool match(const string &a, const string &b) {
	assert(a.size() == b.size());
	for (int i=0; i<(int)a.size(); ++i)
		if (a[i] != b[b.size()-1-i])
			return false;

	return true;
}
int r(int, const string &);
int l(int k, const string &s) {
	if (k < 0)
		return 0;

	int &ret = Ml[make_pair(k, s)];
	if (ret > 0)
		return ret;

	ret = is_palin(s);

	for (int i=0; i<N; ++i)
		if (s.size() == W[i].size()) {
			if (match(s, W[i]))
				inc(ret, l(k-W[i].size()-1, ""));
		} else if (s.size() > W[i].size()) {
			if (match(s.substr(0, W[i].size()), W[i]))
				inc(ret, l(k-W[i].size()-1, s.substr(W[i].size())));
		} else { // s.size() < W[i].size()
			if (match(s, W[i].substr(W[i].size()-s.size())))
				inc(ret, r(k-W[i].size()-1, W[i].substr(0, W[i].size()-s.size())));
		}

	return ret;
}
int r(int k, const string &s) {
	if (k < 0)
		return 0;

	int &ret = Mr[make_pair(k, s)];
	if (ret > 0)
		return ret;

	ret = is_palin(s);

	for (int i=0; i<N; ++i)
		if (s.size() == W[i].size()) {
			if (match(s, W[i]))
				inc(ret, l(k-W[i].size()-1, ""));
		} else if (s.size() > W[i].size()) {
			if (match(s.substr(s.size()-W[i].size()), W[i]))
				inc(ret, r(k-W[i].size()-1, s.substr(0, s.size()-W[i].size())));
		} else { // s.size() < W[i].size()
			if (match(s, W[i].substr(0, s.size())))
				inc(ret, l(k-W[i].size()-1, W[i].substr(s.size())));
		}

	return ret;
}
class CountPalindromes {
	public:
	int count(vector <string> words, int k) {
		W = words;
		N = words.size();
		Ml.clear(), Mr.clear();

		int sol = 0;
		for (int i=0; i<N; ++i)
			inc(sol, l(k-W[i].size(), W[i]));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"tragic","cigar"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"z","zz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"aba","acaba","baca","cac","b","c","a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; int Arg2 = 370786966; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"hello"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CountPalindromes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

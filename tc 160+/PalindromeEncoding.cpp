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
set<long long> S;
int sol;
long long code(const string &s) {
	long long ret = 1ll<<s.size();
	for (int i=0; i<(int)s.size(); ++i)
		if (s[i] == '1')
			ret |= 1ll<<i;
	return ret;
}
void go(const string &s) {
	const long long t = code(s);
	if (S.count(t))
		return;
	S.insert(t);
	sol = min(sol, (int)s.size());
	vector< vector<bool> > is_palin(s.size(), vector<bool>(s.size(), false));
	for (int i=0; i<(int)s.size(); ++i)
		is_palin[i][i] = 1;

	for (int len=2; len<=(int)s.size(); ++len)
		for (int i=0; i+len<=(int)s.size(); ++i) {
			const int j = i+len-1;
			if (s[i]==s[j] && (len==2 || is_palin[i+1][j-1]))
				is_palin[i][j] = 1;
		}
	for (int len=2; len<=(int)s.size(); len += 2)
		for (int i=0; i+len<=(int)s.size(); ++i) {
			const int j = i+len-1;
			if (is_palin[i][j])
				go(s.substr(0, i+len/2) + s.substr(j+1));
		}
}
class PalindromeEncoding {
	public:
	int getLength(string s) {
		S.clear();
		sol = s.size();

		go(s);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0111001"; int Arg1 = 2; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arg0 = "0"; int Arg1 = 1; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arg0 = "01010111100110101110000001011000101000010111000111"; int Arg1 = 6; verify_case(2, Arg1, getLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PalindromeEncoding ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

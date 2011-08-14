#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

map<string, string> memo;
string s;
bool is_palin(const string &t) {
	for (int i=0, j=(int)t.size()-1; i<j; ++i, --j)
		if (t[i] != t[j])
			return false;
	return true;
}
string get_common(const string &t) {
	string ret;
	int i=0, j=(int)t.size()-1;
	while (i<j && t[i++]==t[j--])
		ret += t[i-1];

	return ret;
}
inline string reverse(const string &t) {
	return string(t.rbegin(), t.rend());
}
class ShortPalindromes {
	public:
	string go(int offset, int len) {
		assert(len > 0);
		if (len == 1)
			return s.substr(offset, len);

		if (is_palin(s.substr(offset, len)))
			return s.substr(offset, len);

		if (memo.count(s.substr(offset, len)) != 0)
			return memo[s.substr(offset, len)];

		string common;
		common = get_common(s.substr(offset, len));
		if (common.size()==0) {
			string t = s[offset] + go(offset+1, len-1) + s[offset];
			string v = s[offset+len-1] + go(offset, len-1) + s[offset+len-1];
			if (t.size() != v.size())
				return memo[s.substr(offset, len)] = ((t.size() < v.size())? t:v);
			else
				return memo[s.substr(offset, len)] = ((t<v)? t:v);
		} else
			return memo[s.substr(offset, len)] = common + go(offset+(int)common.size(), len-2*(int)common.size()) + reverse(common);
	}
	string shortest(string base) {
		memo.clear();
		s = base;
		return go(0, base.size());
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RACE"; string Arg1 = "ECARACE"; verify_case(0, Arg1, shortest(Arg0)); }
	void test_case_1() { string Arg0 = "TOPCODER"; string Arg1 = "REDTOCPCOTDER"; verify_case(1, Arg1, shortest(Arg0)); }
	void test_case_2() { string Arg0 = "Q"; string Arg1 = "Q"; verify_case(2, Arg1, shortest(Arg0)); }
	void test_case_3() { string Arg0 = "MADAMIMADAM"; string Arg1 = "MADAMIMADAM"; verify_case(3, Arg1, shortest(Arg0)); }
	void test_case_4() { string Arg0 = "ALRCAGOEUAOEURGCOEUOOIGFA"; string Arg1 = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA"; verify_case(4, Arg1, shortest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ShortPalindromes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

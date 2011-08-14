#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Palindromize {
	public:
	bool is_palin(const string &s) {
		for (int i=0; i<(int)s.size()/2; ++i)
			if (s[i] != s[s.size()-1-i])
				return false;
		return true;
	}
	string make(string s, int cnt) {
		string t = s.substr(0, cnt);
		reverse(t.begin(), t.end());

		return s + t;
	}
	string minAdds(string s) {
		for (int i=0; i<(int)s.size(); ++i)
			if (is_palin(make(s, i)))
				return make(s, i);

		return make(s, s.size());
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "add"; string Arg1 = "adda"; verify_case(0, Arg1, minAdds(Arg0)); }
	void test_case_1() { string Arg0 = "cigartragic"; string Arg1 = "cigartragic"; verify_case(1, Arg1, minAdds(Arg0)); }
	void test_case_2() { string Arg0 = "redocpot"; string Arg1 = "redocpotopcoder"; verify_case(2, Arg1, minAdds(Arg0)); }
	void test_case_3() { string Arg0 = "acaba"; string Arg1 = "acabaca"; verify_case(3, Arg1, minAdds(Arg0)); }
	void test_case_4() { string Arg0 = "abczyxyz"; string Arg1 = "abczyxyzcba"; verify_case(4, Arg1, minAdds(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Palindromize ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

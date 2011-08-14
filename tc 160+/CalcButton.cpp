#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CalcButton {
	public:
	string getDigits(vector <string> sequence) {
		string s;
		for (int i=0; i<(int)sequence.size(); ++i)
			s += sequence[i];

		string sol(3, '0'), cur(3, ' ');
		int best = 0;
		for (cur[0]='0'; cur[0]<='9'; ++cur[0])
			for (cur[1]='0'; cur[1]<='9'; ++cur[1])
				for (cur[2]='0'; cur[2]<='9'; ++cur[2]) {
					int t = 0;
					for (int i=0; i+3<=(int)s.size(); ++i)
						if (cur == s.substr(i, 3)) {
							++t;
							i += 2;
						}
					if (t > best) {
						best = t;
						sol = cur;
					}
				}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"100002000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "000"; verify_case(0, Arg1, getDigits(Arg0)); }
	void test_case_1() { string Arr0[] = {"777777777"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "777"; verify_case(1, Arg1, getDigits(Arg0)); }
	void test_case_2() { string Arr0[] = {"6503","210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "032"; verify_case(2, Arg1, getDigits(Arg0)); }
	void test_case_3() { string Arr0[] = {"0993034","6","4137","45959935","25939","93993","0","9358333"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "993"; verify_case(3, Arg1, getDigits(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CalcButton ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

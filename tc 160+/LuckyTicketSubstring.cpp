#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool f(const string &s) {
	int l = 0;
	for (int i=0; i<(int)s.size()/2; ++i) {
		l += (s[i]-'0');
	}

	int r = 0;
	for (int i=0; i<(int)s.size()/2; ++i) {
		r += s[s.size()/2 + i]-'0';
	}

	return l == r;
}
class LuckyTicketSubstring {
	public:
	int maxLength(string s) {
		int sol = 0;
		for (int i=0; i<(int)s.size(); ++i) {
			for (int l=2; i+l<=(int)s.size(); l+=2) {
				if (f(s.substr(i, l))) {
					sol = max(sol, l);
				}
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123231"; int Arg1 = 6; verify_case(0, Arg1, maxLength(Arg0)); }
	void test_case_1() { string Arg0 = "74233285"; int Arg1 = 4; verify_case(1, Arg1, maxLength(Arg0)); }
	void test_case_2() { string Arg0 = "986561517416921217551395112859219257312"; int Arg1 = 36; verify_case(2, Arg1, maxLength(Arg0)); }
	void test_case_3() { string Arg0 = "1"; int Arg1 = 0; verify_case(3, Arg1, maxLength(Arg0)); }
	void test_case_4() { string Arg0 = "112"; int Arg1 = 2; verify_case(4, Arg1, maxLength(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LuckyTicketSubstring ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

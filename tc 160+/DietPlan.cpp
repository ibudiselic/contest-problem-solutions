#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DietPlan {
	public:
	string chooseDinner(string d, string b, string l) {
		int cnt[26] = {0};
		for (int i=0; i<(int)d.size(); ++i) {
			++cnt[d[i]-'A'];
		}
		for (int i=0; i<(int)b.size(); ++i) {
			--cnt[b[i]-'A'];
		}
		for (int i=0; i<(int)l.size(); ++i) {
			--cnt[l[i]-'A'];
		}

		string sol;
		for (int i=0; i<26; ++i) {
			if (cnt[i] < 0) {
				return "CHEATER";
			}
			sol += string(cnt[i], ('A'+i));
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCD"; string Arg1 = "AB"; string Arg2 = "C"; string Arg3 = "D"; verify_case(0, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "ABEDCS"; string Arg1 = ""; string Arg2 = ""; string Arg3 = "ABCDES"; verify_case(1, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "EDSMB"; string Arg1 = "MSD"; string Arg2 = "A"; string Arg3 = "CHEATER"; verify_case(2, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = ""; string Arg1 = ""; string Arg2 = ""; string Arg3 = ""; verify_case(3, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "IWANTSODER"; string Arg1 = "SOW"; string Arg2 = "RAT"; string Arg3 = "DEIN"; verify_case(4, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DietPlan ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

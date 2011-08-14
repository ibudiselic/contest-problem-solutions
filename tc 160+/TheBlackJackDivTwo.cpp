#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

int val(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (c == 'A') {
        return 11;
    } else {
        return 10;
    }
}
class TheBlackJackDivTwo {
	public:
	int score(vector <string> cards) {
		int ret = 0;
        for (int i=0; i<(int)cards.size(); ++i) {
            ret += val(cards[i][0]);
        }
        return ret;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4S", "7D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(0, Arg1, score(Arg0)); }
	void test_case_1() { string Arr0[] = {"KS", "TS", "QC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(1, Arg1, score(Arg0)); }
	void test_case_2() { string Arr0[] = {"AS", "AD", "AH", "AC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(2, Arg1, score(Arg0)); }
	void test_case_3() { string Arr0[] = {"3S", "KC", "AS", "7C", "TC", "9C", "4H", "4S", "2S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(3, Arg1, score(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBlackJackDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

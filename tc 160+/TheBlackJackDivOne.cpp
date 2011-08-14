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

int rem[12];
int rem_cnt;
int val(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (c == 'A') {
        return 11;
    } else {
        return 10;
    }
}

double calc(int cur, int step, double p) {
    if (cur >= 21) {
        return p*step;
    }
    double ret = 0.0;
    for (int i=2; i<12; ++i) {
        if (rem[i] > 0) {
            --rem[i];
            --rem_cnt;
            ret += calc(cur+i, step+1, p*(rem[i]+1)/(1+rem_cnt));
            ++rem[i];
            ++rem_cnt;
        }
    }
    
    return ret;
}
class TheBlackJackDivOne {
	public:
	double expected(vector <string> cards) {
        for (int i=2; i<10; ++i) {
            rem[i] = 4;
        }
        rem[10] = 16;
        rem[11] = 4;
        rem_cnt = 52;
        
        int cur = 0;
        for (int i=0; i<(int)cards.size(); ++i) {
            const int t = val(cards[i][0]);
            cur += t;
            --rem[t];
            --rem_cnt;
        }
        
        return calc(cur, 0, 1.0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"JS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.105854341736695; verify_case(0, Arg1, expected(Arg0)); }
	void test_case_1() { string Arr0[] = {"KD", "8S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.08; verify_case(1, Arg1, expected(Arg0)); }
	void test_case_2() { string Arr0[] = {"KD", "2S", "2C", "2D", "2H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(2, Arg1, expected(Arg0)); }
	void test_case_3() { string Arr0[] = {"AS", "KS", "9S", "JC", "2D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, expected(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBlackJackDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

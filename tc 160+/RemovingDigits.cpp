#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt[10];
int rem[10];
int done;
bool can_do(const string &n, int x) {
    vector<int> cnt2(10, 0);
    for (int i=0; i<x; ++i) {
        ++cnt2[n[i]-'0'];
    }

    for (int i=0; i<10; ++i) {
        if (cnt2[i] > cnt[i]) {
            return false;
        }
    }

    return true;
}

void doit(string &n, int x) {
    for (int i=0; i<x; ++i) {
        --cnt[n[i]-'0'];
        --rem[n[i]-'0'];
    }
    --rem[n[x]-'0'];
    n = (x+1<(int)n.size() ? n.substr(x+1) : string());
}

class RemovingDigits {
	public:
	string maxNumber(string number, string digits) {
		memset(cnt, 0, sizeof cnt);
        memset(rem, 0, sizeof rem);
        for (int i=0; i<(int)digits.size(); ++i) {
            ++cnt[digits[i]-'0'];
        }
        for (int i=0; i<(int)number.size(); ++i) {
            ++rem[number[i]-'0'];
        }

        int final = (int)number.size() - digits.size();
        string sol;
        for (int i=0; i<final; ++i) {
            int bestj = -1;
            assert(number.size() > 0);
            for (int j=0; j<(int)number.size(); ++j) {
                if (rem[number[j]-'0']>cnt[number[j]-'0'] && (bestj==-1 || number[j]>number[bestj]) && can_do(number, j)) {
                    bestj = j;
                }
            }
            assert(bestj != -1);
            sol += number[bestj];
            doit(number, bestj);
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "12345"; string Arg1 = "513"; string Arg2 = "24"; verify_case(0, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "112352"; string Arg1 = "1123"; string Arg2 = "52"; verify_case(1, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "123456654321"; string Arg1 = "612534"; string Arg2 = "654321"; verify_case(2, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "654321123456"; string Arg1 = "612534"; string Arg2 = "654321"; verify_case(3, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "2654982765982365"; string Arg1 = "2345978"; string Arg2 = "698265265"; verify_case(4, Arg2, maxNumber(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RemovingDigits ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

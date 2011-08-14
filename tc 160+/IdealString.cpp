#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int dp[101][101][27];
int L;
int go(int p, int taken, int left) {
    int &ret = dp[p][taken][left];
    if (ret != -1) {
        return ret;
    }

    if (taken > L-p) {
        return (ret = 0);
    }
    if (p == L) {
        return (ret = (taken==0));
    }
    if (left == 0) {
        return (ret = (taken==L-p));
    }

    if (taken > 0) {
        if (go(p+1, taken-1, left)) {
            return (ret = 1);
        }
    }
    if (go(p+1, taken + p, left-1)) {
        return (ret = 2);
    }
    return (ret = 0);
}

class IdealString {
	public:
	string construct(int length) {
        L = length;
		memset(dp, 0xff, sizeof dp);
        if (!go(0, 0, 26)) {
            return "";
        }

        queue<int> ind;
        queue<int> cnt;
        int i = 0;
        int taken = 0;
        int left = 26;
        string sol;
        for (int p=0; p<L; ++p) {
            if (dp[p][taken][left] == 1) {
                assert(ind.size() > 0);
                int v = ind.front();
                if (--cnt.front() == 0) {
                    cnt.pop();
                    ind.pop();
                }
                sol += char('A' + v);
                --taken;
            } else {
                --left;
                int v = i++;
                sol += char('A' + v);
                if (p > 0) {
                    taken += p;
                    ind.push(v);
                    cnt.push(p);
                }
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "A"; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "ABB"; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 2; string Arg1 = ""; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 6; string Arg1 = "ABCBCC"; verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { int Arg0 = 7; string Arg1 = "ABBCCCC"; verify_case(4, Arg1, construct(Arg0)); }
	void test_case_5() { int Arg0 = 5; string Arg1 = ""; verify_case(5, Arg1, construct(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IdealString ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

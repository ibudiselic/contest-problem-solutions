#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class VerifyCreditCard {
	public:
	string checkDigits(string n) {
		vector<int> t;
        for (int i=0; i<(int)n.size(); ++i) {
            t.push_back(n[i] - '0');
        }

        int x = 0;
        if (t.size() % 2) {
            x = 1;
        }
        for (int i=0; i<(int)t.size(); ++i) {
            if (i%2 == x) {
                t[i] *= 2;
            }
        }

        int sol = 0;
        for (int i=0; i<(int)t.size(); ++i) {
            while (t[i] > 0) {
                sol += t[i] % 10;
                t[i] /= 10;
            }
        }

        return sol%10==0 ? "VALID" : "INVALID";

	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "21378"; string Arg1 = "VALID"; verify_case(0, Arg1, checkDigits(Arg0)); }
	void test_case_1() { string Arg0 = "31378"; string Arg1 = "INVALID"; verify_case(1, Arg1, checkDigits(Arg0)); }
	void test_case_2() { string Arg0 = "11111101"; string Arg1 = "VALID"; verify_case(2, Arg1, checkDigits(Arg0)); }
	void test_case_3() { string Arg0 = "50005"; string Arg1 = "VALID"; verify_case(3, Arg1, checkDigits(Arg0)); }
	void test_case_4() { string Arg0 = "542987223412"; string Arg1 = "INVALID"; verify_case(4, Arg1, checkDigits(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    VerifyCreditCard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

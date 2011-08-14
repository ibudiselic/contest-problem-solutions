#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool sw(const string &a, const string &b) {
    if (b.size() > a.size()) {
        return false;
    } else {
        return a.substr(0, b.size()) == b;
    }
}

class TheLotteryBothDivs {
	public:
	double find(vector <string> suf) {
        for (int i=0; i<(int)suf.size(); ++i) {
            reverse(suf[i].begin(), suf[i].end());
        }
        sort(suf.begin(), suf.end());
        vector<string> suf2;
        suf2.push_back(suf[0]);
        for (int i=1; i<(int)suf.size(); ++i) {
            if (!sw(suf[i], suf2.back())) {
                suf2.push_back(suf[i]);
            }
        }
        int sol = 0;
        for (int i=0; i<(int)suf2.size(); ++i) {
            int add = 1;
            for (int j=0; j<9-(int)suf2[i].size(); ++j) {
                add *= 10;
            }
            sol += add;
        }
        return sol/1000000000.0;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"4", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"47", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.01; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"47", "58", "4747", "502"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.021; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.201100101; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLotteryBothDivs ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

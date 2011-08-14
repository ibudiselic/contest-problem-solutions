#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class RunningLetters {
	public:
	int newsLength(vector <string> running) {
		string s;
        for (int i=0; i<(int)running.size(); ++i) {
            s += running[i];
        }
        istringstream is(s);
        int x;
        string t, S;
        while (is >> x >> t) {
            while (x--) {
                S += t;
            }
        }

        int n = S.size();
        vector<int> f(n+1, 0);
        for (int i=1; i<n; ++i) {
            int p = f[i];
            while (p!=0 && S[p]!=S[i]) {
                p = f[p];
            }
            f[i+1] = p + (S[p]==S[i]);
        }

        return n - f[n];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 abc 1 ab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, newsLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 babaaba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, newsLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 ba 1 c 1 bacba 3 cba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, newsLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"42 runningletters 42 runningletters 1 running"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(3, Arg1, newsLength(Arg0)); }
	void test_case_4() { string Arr0[] = {"1 b ", "1 a ", "1 b ", "1 a", " 1 b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, newsLength(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RunningLetters ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

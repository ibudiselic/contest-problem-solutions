#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int f(const string &s) {
    int ret = 1;
    for (int i=0; i<(int)s.size(); ++i) {
        ret *= s[i] - '0';
    }
    return ret;
}
bool is_mult(const string &a, const string &b) {
    return f(a) == f(b);
}
class MultiNumber {
	public:
	string check(int number) {
        ostringstream os;
        os << number;
        string s = os.str();
		for (int i=1; i<(int)s.size(); ++i) {
            if (is_mult(s.substr(0, i), s.substr(i))) {
                return "YES";
            }
        }
        
        return "NO";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "NO"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { int Arg0 = 1221; string Arg1 = "YES"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { int Arg0 = 1236; string Arg1 = "YES"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { int Arg0 = 4729382; string Arg1 = "NO"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { int Arg0 = 42393338; string Arg1 = "YES"; verify_case(4, Arg1, check(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MultiNumber ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

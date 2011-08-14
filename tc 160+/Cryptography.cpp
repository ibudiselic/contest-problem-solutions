#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long calc(const vector<int> &v, int i) {
    long long ret = 1;
    for (int j=0; j<(int)v.size(); ++j) {
        ret *= v[j] + (i==j);
    }
    return ret;
}
class Cryptography {
	public:
	long long encrypt(vector <int> numbers) {
		long long sol = 0;
        for (int i=0; i<(int)numbers.size(); ++i) {
            sol = max(sol, calc(numbers, i));
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 12LL; verify_case(0, Arg1, encrypt(Arg0)); }
	void test_case_1() { int Arr0[] = {1,3,2,1,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 36LL; verify_case(1, Arg1, encrypt(Arg0)); }
	void test_case_2() { int Arr0[] = {1000,999,998,997,996,995}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 986074810223904000LL; verify_case(2, Arg1, encrypt(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(3, Arg1, encrypt(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Cryptography ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

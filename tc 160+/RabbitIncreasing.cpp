#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long M = 1000000009;
long long fastexp(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = ret*x%M;
        }
        x = x*x%M;
        n >>= 1;
    }
    return ret;
}
class RabbitIncreasing {
	public:
	int getNumber(vector <int> leaving, int k) {
		if (leaving[0] < 3) {
            return 0;
        }
        long long inv2 = fastexp(2, M-2);
        long long start_of_year = 3;
        long long mod2 = (1LL<<leaving.size());
        long long breeders = 1; // mod M
        long long young = 0; // mod M
        long long breeders2 = 1; // mod 2^leaving.size
        long long young2 = 0; // mod 2^leaving.size
        for (int i=0; i<(int)leaving.size() && start_of_year<=k; ++i) {
            for (int j=start_of_year; j<leaving[i]; ++j) {
                long long nbreeders = (breeders + young) % M;
                young = breeders;
                breeders = nbreeders;
                
                nbreeders = (breeders2 + young2) % mod2;
                young2 = breeders2;
                breeders2 = nbreeders;
            }
            
            if (young2 & 1) {
                young2 += mod2 - 1; // sub 1
                young += M - 1;
            }
            
            long long nyoung = breeders;
            breeders = young * inv2 % M;
            young = nyoung;
            
            nyoung = breeders2;
            breeders2 = young2/2; // actually should divide the mod by 2, but since we only care about parity, it doesn't matter
            young2 = nyoung;
            start_of_year = leaving[i] + 1;
        }
        
        while (start_of_year++ <= k) {
            long long nbreeders = (breeders + young) % M;
            young = breeders;
            breeders = nbreeders;
        }
        
        return (young+breeders) % M;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 5, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 6; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 5, 10, 15 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arg2 = 212; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10000000; int Arg2 = 0; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 195, 211, 227, 230, 260, 
  297, 346, 350, 403, 411, 
  428, 485, 594, 606, 876 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 975206486; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RabbitIncreasing ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

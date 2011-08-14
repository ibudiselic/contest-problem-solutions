#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
    
class LotteryCheating {
	public:
	int minimalChange(string ID) {
        int z = count(ID.begin(), ID.end(), '0');
        long long p10 = 1;
        for (int i=0; i<(int)ID.size(); ++i) {
            p10 *= 10;
        }
        int sol = (int)ID.size()-z;;
        for (long long i=1; i*i<p10; ++i) {
            ostringstream os;
            os << i*i;
            string t = os.str();
            t = string(ID.size()-t.size(), '0') + t;
            int cnt = 0;
            for (int j=0; j<(int)t.size(); ++j) {
                cnt += (ID[j]!=t[j]);
            }
            sol = min(sol, cnt);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1"; int Arg1 = 0; verify_case(0, Arg1, minimalChange(Arg0)); }
	void test_case_1() { string Arg0 = "1234"; int Arg1 = 2; verify_case(1, Arg1, minimalChange(Arg0)); }
	void test_case_2() { string Arg0 = "9000000000"; int Arg1 = 1; verify_case(2, Arg1, minimalChange(Arg0)); }
	void test_case_3() { string Arg0 = "4294967296"; int Arg1 = 0; verify_case(3, Arg1, minimalChange(Arg0)); }
	void test_case_4() { string Arg0 = "7654321"; int Arg1 = 3; verify_case(4, Arg1, minimalChange(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LotteryCheating ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

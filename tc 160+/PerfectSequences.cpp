#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class PerfectSequences {
	public:
	string fixIt(vector <int> seq) {
        if (seq.size() == 1) {
            return "Yes";
        }
		long long all = accumulate(seq.begin(), seq.end(), 0LL);
        
        for (int i=0; i<(int)seq.size(); ++i) {
            long long sum = all - seq[i];
            if (sum == 0) {
                return seq[i]==0 ? "No" : "Yes";
            }
            long long prod = 1;
            for (int j=0; j<(int)seq.size(); ++j) {
                if (j != i) {
                    if (seq[j]>0 && prod>(sum+1)/seq[j]) {
                        prod = -1;
                        break;
                    } else {
                        prod *= seq[j];
                    }
                }
            }
            
            if (prod == -1) {
                continue;
            }
            long long x = -1;
            if (prod > 1) {
                x = sum/(prod-1);
            }
            if (x>=0 && x!=seq[i] && x*prod==sum+x) {
                return "Yes";
            }
        }
        return "No";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(0, Arg1, fixIt(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(1, Arg1, fixIt(Arg0)); }
	void test_case_2() { int Arr0[] = {1,4,2,4,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(2, Arg1, fixIt(Arg0)); }
	void test_case_3() { int Arr0[] = {1000000,1,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(3, Arg1, fixIt(Arg0)); }
	void test_case_4() { int Arr0[] = {8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(4, Arg1, fixIt(Arg0)); }
	void test_case_5() { int Arr0[] = {2,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(5, Arg1, fixIt(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PerfectSequences ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

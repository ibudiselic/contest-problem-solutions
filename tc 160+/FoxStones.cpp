#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

long long F[40000];
long long mod = 1000000009LL;
class FoxStones {
	public:
	int getCount(int M, int N, vector <int> sx, vector <int> sy) {
		map< vector<int>, int> sig_cnt;
        for (int i=1; i<=M; ++i) {
            for (int j=1; j<=N; ++j) {
                vector<int> sig;
                for (int k=0; k<(int)sx.size(); ++k) {
                    sig.push_back(max(abs(sx[k]-i), abs(sy[k]-j)));
                }
                ++sig_cnt[sig];
            }
        }
        
        F[0] = 1;
        for (int i=1; i<40001; ++i) {
            F[i] = F[i-1]*i%mod;
        }
        long long sol = 1;
        for (map< vector<int>, int>::const_iterator it=sig_cnt.begin(); it!=sig_cnt.end(); ++it) {
            sol = sol*F[it->second]%mod;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(0, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(1, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 8; verify_case(2, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 34; int Arr2[] = {5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {11,12,13,14,15,16}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 410850247; verify_case(3, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxStones ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

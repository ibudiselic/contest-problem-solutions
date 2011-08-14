#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> S;
bool can_get(double x, long long maxCuts, long long pos) {
    long long cur = -1;
    for (int i=0; i<(int)S.size(); ++i) {
        if (S[i] < x) {
            cur = i;
            break;
        }
    }
    if (cur == -1) {
        cur = (int)S.size();
    }
    long long k = cur;
    for (int i=0; i<k && maxCuts>0; ++i) {
        long long cnt = (long long)(S[i]/x);
        long long cuts = min(cnt-1, maxCuts);
        if (cuts <= 0) {
            break;
        }
        maxCuts -= cuts;
        cur += cuts;
    }
    
    return cur>pos;
}
class CutSticks {
	public:
	double maxKth(vector <int> sticks, long long C, long long K) {
		S = sticks;
        sort(S.begin(), S.end());
        reverse(S.begin(), S.end());
        --K;
        
        if (K == 0) {
            return S[0];
        }
        
        double lo = 0.0;
        double hi = S[0];
        for (int t=0; t<500; ++t) {
            double mid = (lo+hi)/2.0;
            if (can_get(mid, C, K)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        
        return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; double Arg3 = 8.0; verify_case(0, Arg3, maxKth(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; double Arg3 = 5.0; verify_case(1, Arg3, maxKth(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; double Arg3 = 4.0; verify_case(2, Arg3, maxKth(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1000000000, 1000000000, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; double Arg3 = 1.0; verify_case(3, Arg3, maxKth(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 789; int Arg2 = 456; double Arg3 = 34.92; verify_case(4, Arg3, maxKth(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CutSticks ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

long long S[3001];
inline long long my_abs(long long x) {
    return (x>=0 ? x : -x);
}
class KSubstring {
	public:
	vector <int> maxSubstring(int A0, int X, int Y, int M, int n) {
		vector<long long> A(n, 0);
        A[0] = A0;
        for (int i=1; i<n; ++i) {
            A[i] = (A[i-1]*X + Y) % M;
        }
        memset(S, 0, sizeof S);
        S[0] = 0;
        for (int i=1; i<=n; ++i) {
            S[i] = S[i-1] + A[i-1];
        }

        long long best_val = S[n] + 1;
        int best_k = 0;

        for (int k=n/2; k>0 && best_val>0; --k) {
            set<long long> D;
            for (int i=0; i+k<=n; ++i) {
                if (i >= k) {
                    D.insert(S[i]-S[i-k]);
                }
                long long d = S[i+k] - S[i];
                set<long long>::iterator p = D.lower_bound(d);
                if (p != D.end()) {
                    if (*p-d < best_val) {
                        best_val = *p-d;
                        best_k = k;
                    }
                }
                if (p != D.begin()) {
                    --p;
                    if (d - *p < best_val) {
                        best_val = d - *p;
                        best_k = k;
                    }
                }
            }
        }

        vector<int> sol(2, 0);
        sol[0] = best_k;
        sol[1] = (int)best_val;

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 4; int Arg3 = 25; int Arg4 = 5; int Arr5[] = {2, 1 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, maxSubstring(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 19; int Arg2 = 17; int Arg3 = 2093; int Arg4 = 12; int Arr5[] = {5, 161 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, maxSubstring(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 53; int Arg1 = 13; int Arg2 = 9; int Arg3 = 65535; int Arg4 = 500; int Arr5[] = {244, 0 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, maxSubstring(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 34; int Arg2 = 55; int Arg3 = 7890; int Arg4 = 123; int Arr5[] = {35, 4 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(3, Arg5, maxSubstring(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KSubstring ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long road[400002], flight[400002], T[400002], T2[400002];
void gen(long long *A, int N, int first, int mod, int prod, int add) {
    A[0] = 0;
    A[1] = first % mod;
    for (int i=2; i<=N; ++i) {
        A[i] = (A[i-1]*prod + add) % mod;
    }
    for (int i=2; i<=N; ++i) {
        A[i] += A[i-1];
    }
}
int fly_from[400002];
class RoadOrFlightHard {
	public:
	long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K) {
		gen(road, N, roadFirst, roadMod, roadProd, roadAdd);
		gen(flight, N, flightFirst, flightMod, flightProd, flightAdd);
        
        memcpy(T, road, sizeof T);
        while (K--) {
            fly_from[0] = -1;
            for (int i=1; i<=N; ++i) {
                if (fly_from[i-1] == -1) {
                    fly_from[i] = (flight[i]-flight[i-1] < T[i]-T[i-1] ? i-1 : -1);
                } else {
                    fly_from[i] = (flight[i]-flight[fly_from[i-1]] < T[i]-T[fly_from[i-1]] ? fly_from[i-1] : -1);
                }
            }
            memcpy(T2, T, sizeof T2);
            for (int i=1; i<=N; ++i) {
                T2[i] = min(T2[i], T2[i-1] + road[i]-road[i-1]);
                if (fly_from[i] != -1) {
                    T2[i] = min(T2[i], T[fly_from[i]] + flight[i]-flight[fly_from[i]]);
                }
            }
            memcpy(T, T2, sizeof T);
        }
        
        return T[N];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 14; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10; int Arg5 = 18; int Arg6 = 1; int Arg7 = 10; int Arg8 = 17; int Arg9 = 1; long long Arg10 = 14LL; verify_case(0, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10; int Arg5 = 1; int Arg6 = 1; int Arg7 = 10; int Arg8 = 17; int Arg9 = 2; long long Arg10 = 11LL; verify_case(1, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10; int Arg5 = 1; int Arg6 = 1; int Arg7 = 6; int Arg8 = 9; int Arg9 = 1; long long Arg10 = 12LL; verify_case(2, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 85739; int Arg2 = 94847; int Arg3 = 93893; int Arg4 = 98392; int Arg5 = 92840; int Arg6 = 93802; int Arg7 = 93830; int Arg8 = 92790; int Arg9 = 3; long long Arg10 = 122365LL; verify_case(3, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RoadOrFlightHard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CubePacking {
	public:
	int getMinimumVolume(int m, int n, int L) {
	    int V = n*L*L*L + m;
        int hmin = L;
        while (hmin*hmin*hmin < V) {
            ++hmin;
        }
        while (1) {
            for (int h=L; h*h<=V; ++h) {
                if (V%h != 0) {
                    continue;
                }
                if (h >= hmin) {
                    int H = h;
                    int A = V/H;
                    for (int a=max(L, (A+H-1)/H); a*a<=A; ++a) {
                        if (A%a != 0) {
                            continue;
                        }
                        int b = A/a;
                        long long cnt = (long long)(a/L)*(b/L)*(H/L);
                        if (cnt >= n) {
                            return V;
                        }
                    }
                }
                int H = V/h;
                int A = V/H;
                for (int a=max(L, (A+H-1)/H); a*a<=A; ++a) {
                    if (A%a != 0) {
                        continue;
                    }
                    int b = A/a;
                    long long cnt = (long long)(a/L)*(b/L)*(H/L);
                    if (cnt >= n) {
                        return V;
                    }
                }
            }
            
            ++V;
            if (hmin*hmin*hmin < V) {
                ++hmin;
            }
        }
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 20; verify_case(0, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 19; int Arg1 = 1; int Arg2 = 2; int Arg3 = 27; verify_case(1, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 51; int Arg1 = 7; int Arg2 = 5; int Arg3 = 950; verify_case(2, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12345; int Arg1 = 987; int Arg2 = 10; int Arg3 = 999400; verify_case(3, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CubePacking ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

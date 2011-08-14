#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long LIMIT = (1LL<<63) - 1;

bool is_prime(long long x) {
    if (x < 2) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x%2 == 0) {
        return false;
    }

    for (long long d=3; d<=x/d; d+=2) {
        if (x%d == 0) {
            return false;
        }
    }

    return true;
}

inline bool can_mul(long long x, long long y) {
    return x <= LIMIT/y;
}
long long calc(long long x, int n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) {
            if (!can_mul(ret, x)) {
                return LIMIT;
            }
            ret *= x;
        }
        if (!can_mul(x, x)) {
            if ((n>>1) > 0) {
                return LIMIT;
            }
        } else {
            x *= x;
        }
        n >>= 1;
    }

    return ret;
}

class StrongPrimePower {
	public:
	vector <int> baseAndExponent(string n) {
	    long long x;
        sscanf(n.c_str(), "%lld", &x);

        for (int k=64; k>1; --k) {
            int lo = 0;
            int hi = 1234567890;
            while (lo <= hi) {
                int mid = lo + (hi-lo)/2;
                long long t = calc(mid, k);
                if (t == x) {
                    if (is_prime(mid)) {
                        vector<int> sol(2, mid);
                        sol[1] = k;
                        return sol;
                    } else {
                        return vector<int>();
                    }
                } else if (t > x) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }

        return vector<int>();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "27"; int Arr1[] = {3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, baseAndExponent(Arg0)); }
	void test_case_1() { string Arg0 = "10"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, baseAndExponent(Arg0)); }
	void test_case_2() { string Arg0 = "7"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, baseAndExponent(Arg0)); }
	void test_case_3() { string Arg0 = "1296"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, baseAndExponent(Arg0)); }
	void test_case_4() { string Arg0 = "576460752303423488"; int Arr1[] = {2, 59 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, baseAndExponent(Arg0)); }
	void test_case_5() { string Arg0 = "999999874000003969"; int Arr1[] = {999999937, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, baseAndExponent(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StrongPrimePower ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

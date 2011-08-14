#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long mod = 1000000007LL;
int to[50];
bool done[50];
int n;
long long choose_mod(int a, int b) {
    long long ret = 1;
    for (int i=0; i<b; ++i) {
        ret *= (a-i);
        ret /= (i+1); // (50 choose 25) fits in long long
    }
    return ret % mod;
}

int SZ;
long long dp[51][51][3][3];
long long go(int rem, int need, int last, int prev_02) {
    long long &ret = dp[rem][need][last][prev_02];
    if (ret != -1) {
        return ret;
    }
    if (rem == 0) {
        return (ret = (need==0));
    }
    ret = 0;
    int placed = SZ - need;
    if (need == 0) {
        if (last == 0) {
            ret = 0;
        } else if (last == 1) {
            if (prev_02 == 0) {
                ret = 0;
            } else {
                ret = go(rem-1, 0, 0, 0);
            }
        } else {
            ret = go(rem-1, 0, 0, 0);
        }
    } else {
        if (last == 0) {
            ret = (placed+1) * go(rem-1, need-1, 1, 0);
            if (need > 1) {
                ret += (placed+1)*(placed+2)/2*go(rem-1, need-2, 2, 2);
            }
        } else if (last == 1) {
            ret = (placed+1) * go(rem-1, need-1, 1, prev_02);
            if (prev_02 != 0) {
                ret += go(rem-1, need, 0, 0);
            }
            if (prev_02!=2 && need>1) {
                ret += (placed+1)*(placed+2)/2*go(rem-1, need-2, 2, 2);
            }
        } else {
            ret = (placed+1) * go(rem-1, need-1, 1, 2);
            ret += go(rem-1, need, 0, 0);
        }
    }
    
    ret %= mod;
//    cerr << rem << ' ' << need << ' ' << last << ' ' << prev_02 << ' ' << placed << "** " << ret << '\n';
    return ret;
}
long long fastexp(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * x) % mod;
        }
        n >>= 1;
        x = (x * x) % mod;
    }
    return ret;
}
long long mul_inv(long long x) {
    return fastexp(x, mod-2);
}
long long inv2 = mul_inv(2);
long long cnt_ways(int size, int cnt_pairs) {
    long long ret = choose_mod(size, 2*cnt_pairs)*(cnt_pairs==0 ? 1 : 2);
    for (int i=0; i<size; ++i) {
        ret = (ret * (i+1)) % mod;
    }
    
    for (int i=0; i<cnt_pairs; ++i) {
        ret = (ret * inv2) % mod;
    }

    return ret;
}
void calc(int u, int &size, long long &ways) {
    done[u] = true;
    int v = to[u];
    size = 1;
    while (v != u) {
        done[v] = true;
        v = to[v];
        ++size;
    }
    
    /*SZ = size;
    memset(dp, 0xff, sizeof dp);
    ways = go(size, size, 1, 1);*/
    ways = 0;
    for (int k=0; 2*k<=size; ++k) {
        ways += cnt_ways(size, k);
    }
    ways %= mod;
}
class TwoSidedCards {
	public:
	int theCount(vector <int> taro, vector <int> hanako) {
		n = taro.size();
        for (int i=0; i<n; ++i) {
            to[taro[i]-1] = hanako[i]-1;
        }
        
        int cur_size = 0;
        long long cur_ways = 1;
        memset(done, 0, sizeof done);
        for (int i=0; i<n; ++i) {
            if (!done[i]) {
                int cyc_size = 0;
                long long cyc_ways = 0;
                calc(i, cyc_size, cyc_ways);
                //cerr << ' '  << i << ' ' << cyc_size << ' ' << cyc_ways << '\n';
                cur_ways = (((choose_mod(cur_size+cyc_size, cur_size) * cur_ways) % mod) * cyc_ways) % mod;
                cur_size += cyc_size;
            }
        }
        
        return int(cur_ways);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5, 8, 1, 2, 3, 4, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2177280; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {41, 22, 17, 36, 26, 15, 10, 23, 33, 48, 49, 9, 34, 6, 21, 2, 46, 16, 25, 3, 24, 13, 40, 37, 35,
50, 44, 42, 31, 12, 29, 7, 43, 18, 30, 19, 45, 32, 39, 14, 8, 27, 1, 5, 38, 11, 4, 20, 47, 28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {19, 6, 23, 35, 17, 7, 50, 2, 33, 36, 12, 31, 46, 21, 30, 13, 47, 22, 44, 4, 25, 24, 3, 15, 20,
48, 10, 28, 26, 18, 5, 45, 49, 16, 40, 42, 43, 14, 1, 37, 29, 8, 41, 38, 9, 11, 34, 32, 39, 27}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 529165844; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TwoSidedCards ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

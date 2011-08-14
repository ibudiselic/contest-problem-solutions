#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

bool is_prime(int x) {
    for (int d=2; d*d<=x; ++d) {
        if (x%d == 0) {
            return false;
        }
    }
    return true;
}

int mod = 1000000007;
vector<int> primes;
int lim;
map< vector<int>, int > M;
int go(int p, int rem, vector<int> v) {
    if (p == (int)primes.size()) {
        return 1;
    }
    sort(v.begin(), v.end());
    while (v.size()>0 && v.back()*primes[p]>lim) {
        v.pop_back();
    }
    v.push_back(p);
    v.push_back(rem);
    if (M.count(v)) {
        return M[v];
    }
    int &ret = M[v];
    v.pop_back();
    v.pop_back();
    
    ret = go(p+1, rem, v);
    for (int i=0; i<(int)v.size(); ++i) {
        v[i] *= primes[p];
        ret += go(p+1, rem, v);
        if (ret >= mod) {
            ret -= mod;
        }
        v[i] /= primes[p];
    }
    if (rem > 0) {
        v.push_back(primes[p]);
        ret += go(p+1, rem-1, v);
        if (ret >= mod) {
            ret -= mod;
        }
    }
    
    return ret;
}
    
class SquareFreeSets {
	public:
	int countPerfect(int N, int K) {
        lim = N;
		primes.clear();
        for (int i=2; i<=N; ++i) {
            if (is_prime(i)) {
                primes.push_back(i);
            }
        }
        
        M.clear();
        return (go(0, K, vector<int>()) + mod - 1) % mod;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 3; verify_case(0, Arg2, countPerfect(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 6; verify_case(1, Arg2, countPerfect(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 7; verify_case(2, Arg2, countPerfect(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 9; verify_case(3, Arg2, countPerfect(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 28; int Arg1 = 41; int Arg2 = 1599; verify_case(4, Arg2, countPerfect(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SquareFreeSets ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

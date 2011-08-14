#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> A;
vector<long long> P;
long long K, N;
long long dp[51][105];

long long inf = 123456789123456789LL;
long long calc(int w, int nw) {
    if (P[w] == -1) {
        return K;
    } else if (P[w] == P[nw]) {
        return 0;
    } else if (P[w] < P[nw]) {
        return K - max(P[w]+K - P[nw], 0LL);
    } else {
        return K - max(P[nw]+K - P[w], 0LL);
    }
}
long long go(int p, int w) {
    if (p == (int)A.size()) {
        return 0;
    }
    long long &ret = dp[p][w];
    if (ret != -1) {
        return ret;
    }
    
    int lnw = (A[p]+K>=N ? (int)P.size()-2 : p);
    ret = calc(w, lnw) + go(p+1, lnw);
    int rnw = (A[p]<K ? (int)P.size()-3 : p+(int)A.size());
    long long t = calc(w, rnw) + go(p+1, rnw);
    ret = min(ret, t);
    
    int l = A[p];
    int r = A[p];
    
    for (int q=p+1; q<(int)A.size(); ++q) {
        if (A[q] < l) {
            l = A[q];
            lnw = (A[q]+K>=N ? (int)P.size()-2 : q);
        }
        if (A[q] > r) {
            r = A[q];
            rnw = (A[q]<K ? (int)P.size()-3 : q+(int)A.size());
        }
        if (r-l+1 > K) {
            break;
        }
        
        long long t = calc(w, lnw) + go(q+1, lnw);
        ret = min(ret, t);
        t = calc(w, rnw) + go(q+1, rnw);
        ret = min(ret, t);
    }
    
    return ret;
}

class ContiguousCache {
	public:
	long long minimumReads(int n, int k, vector <int> A_) {
		A = A_;
        N = n;
        K = k;
        P.clear(); 
        for (int i=0; i<(int)A.size(); ++i) {
            P.push_back(min(n-k, A[i]));
        }
        for (int i=0; i<(int)A.size(); ++i) {
            P.push_back(min(n-k, max(A[i]-k+1, 0)));
        }
        P.push_back(0);
        P.push_back(n - k);
        P.push_back(-1);

        memset(dp, 0xff, sizeof dp);
        return go(0, P.size()-1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 3; int Arr2[] = {0, 2, 16, 13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 7LL; verify_case(0, Arg3, minimumReads(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 10; int Arr2[] = {1,10,19,28,30,37}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 29LL; verify_case(1, Arg3, minimumReads(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000000; int Arg1 = 500000000; int Arr2[] = {0, 999999999, 1, 500000000, 500000001, 987654321}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1987654320LL; verify_case(2, Arg3, minimumReads(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 2; int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(3, Arg3, minimumReads(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ContiguousCache ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

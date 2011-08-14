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

int n;
int C[100];
int cnt[2][102];
const long long inf = 12345678912345678LL;

int any(int side, int lo, int hi) { // [lo, hi>
    return (hi>lo ? cnt[side][hi-1]-cnt[side][lo] : 0);
}

const int OFF_A = 5;
long long rec_memo[2][60][26][26][26];
long long rec(int side, int a, int b, int c, int d) {
    if (!any(side, b, c)) {
        return 0;
    }
    assert(a+OFF_A>=0);
    assert(a<52);
    assert(b>=a && c>=a && d>=a);
    assert(b-a<26 && c-a<26 && d-a<26);
    long long &ret = rec_memo[side][a+OFF_A][b-a][c-a][d-a];
    if (ret != -1) {
        return ret;
    }
    
    ret = inf;
    for (int e=b+1; e<c; ++e) {
        ret = min(ret, C[e-a] + rec(side, a, b, e, e) + rec(side, a, e, c, d));
        ret = min(ret, C[d-e] + rec(side, a, b, e, d) + rec(side, e, e, c, d));
    }
    for (int e=a+1; e<=b; ++e) {
        ret = min(ret, C[d-b] + rec(side, e, b, c, d));
    }
    for (int e=c; e<d; ++e) {
        ret = min(ret, C[c-a] + rec(side, a, b, c, e));
    }
    return ret;
}

long long V_memo[100][100];
long long V_shape(int left, int right, int l, int r) {
    if (!any(left, l, 100) && !any(right, r, 100)) {
        return 0;
    }
    long long &ret = V_memo[l][r];
    if (ret != -1) {
        return ret;
    }
    
    ret = inf;
    for (int i=l; i+n/2>r; --i) {
        ret = min(ret, C[n-(l-i)] + V_shape(left, right, l, i + n/2) + rec(right, l - n/2, r, i + n/2, i + n/2));
    }
    for (int i=r; i+n/2>l; --i) {
        ret = min(ret, C[n-(r-i)] + V_shape(left, right, i + n/2, r) + rec(left, r - n/2, l, i + n/2, i + n/2));
    }
    
    return ret;
}

long long solve(int left, int right) {
    memset(V_memo, 0xff, sizeof V_memo);
    long long ret = inf;
    long long base_cost = C[n] + V_shape(left, right, 0, n/2); // left->right +1 slope + remainder above, n/2 since floors are 2 apart
    if (!any(right, 0, n/2)) {
        ret = base_cost;
    } else {
        int i = 0;
        while (i<n/2 && !any(right, 0, i)) {
            ret = min(ret, base_cost + C[n/2 - i] + rec(right, i, i, n/2, n/2));
            ++i;
        }
    }
    
    return ret;
}

class KingdomXEmergencyStaircase {
	public:
	long long determineCost(string left, string right, vector <int> cost) {
		n = cost.size();
        C[0] = 0;
        for (int i=0; i<n; ++i) {
            C[i+1] = cost[i];
        }
        cnt[0][0] = cnt[1][0] = 0;
        for (int i=1; i<102; ++i) {
            cnt[0][i] = cnt[0][i-1] + (i<=(int)left.size() && left[i-1]=='Y');
            cnt[1][i] = cnt[1][i-1] + (i<=(int)right.size() && right[i-1]=='Y');
        }
        
        memset(rec_memo, 0xff, sizeof rec_memo);
        return min(solve(0, 1), solve(1, 0));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNYY"; string Arg1 = "NNNY"; int Arr2[] = {10, 40, 18, 25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 98LL; verify_case(0, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "N"; string Arg1 = "Y"; int Arr2[] = {1, 1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1000LL; verify_case(1, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "NNNNNNNY"; string Arg1 = "NNNNNNNY"; int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 17LL; verify_case(2, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY"; string Arg1 = "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY"; int Arr2[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 100000000000LL; verify_case(3, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "NNY"; string Arg1 = "NNYYY"; int Arr2[] = {10000, 10, 40, 10000, 80, 80}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 220LL; verify_case(4, Arg3, determineCost(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KingdomXEmergencyStaircase ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

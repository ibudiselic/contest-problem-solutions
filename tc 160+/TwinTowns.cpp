#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int n;
int mp, md;
int D[10][10];
bool done[1<<20];
pair<int, int> dp[1<<20];

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}
int get_first(int mask) {
    for (int i=0; i<n; ++i) {
        if (((mask>>(2*i)) & 3) < mp) {
            return i;
        }
    }
    return n;
}

pair<int, int> go(int);

pair<int, int> calc(int a, int b, int mask, int rem) {
    if (rem==0 || b>=n) {
        return go(mask + rem*(1<<(2*a)));
    }
    pair<int, int> t = calc(a, b+1, mask, rem);
    
    int sb = (mask>>(2*b)) & 3;
    if (sb<mp && D[a][b]>=md) {
        pair<int, int> tt = calc(a, b+1, mask+(1<<(2*a))+(1<<(2*b)), rem-1);
        ++tt.first;
        tt.second += D[a][b];
        //cerr << a << ' ' << b << ' ' << tt.first << ' ' << tt.second << '\n';
        if (tt.first>t.first || tt.first==t.first && tt.second<t.second) {
            t = tt;
        }
    }
    
    return t;
}
    
pair<int, int> go(int mask) {
    pair<int, int> &ret = dp[mask];
    if (done[mask]) {
        return ret;
    }
    ret.first = 0;
    ret.second = 0;
    done[mask] = 1;
    int a = get_first(mask);
    if (a == n) {
        return ret;
    }
    int sa = (mask>>(2*a)) & 3;
    assert(sa < mp);
    
    return (ret = calc(a, a+1, mask, mp-sa));
}

class TwinTowns {
	public:
	vector <int> optimalTwinTowns(vector <int> x, vector <int> y, int maxPartners, int minDistance) {
	    n = x.size();
        md = minDistance;
        mp = maxPartners;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                D[i][j] = D[j][i] = dist(x[i], y[i], x[j], y[j]);
            }
        }
        
        memset(done, 0, sizeof done);
        pair<int, int> t = go(0);
        vector<int> sol(2, 0);
        sol[0] = t.first;
        sol[1] = t.second;
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arr4[] = {1, 10 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 11; int Arr4[] = {1, 14 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,10,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,20,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arr4[] = {2, 20 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,10,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,20,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 10; int Arr4[] = {4, 60 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; int Arr4[] = {6, 40 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TwinTowns ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

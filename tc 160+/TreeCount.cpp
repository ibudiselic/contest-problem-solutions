#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool G[50][50];
int n;
long long mod = 112901989;
long long dp[51][51][2][2][2];

int lim;
bool C[50];
long long go(int, int, bool, bool, bool);
long long choose(int y, int x, int p, int rem) {
    if (y==n || rem==0) {
        long long add = 1;
        for (int i=0; i<n; ++i) {
            if (C[i]) {
                assert(i != x);
                add = (add * go(i, x, 1, 1, 0)) % mod;
            } else if (i!=x && i!=p && G[x][i]) {
                add = (add * go(i, x, 1, 0, 1)) % mod;
            }
        }
        return add;
    }

    if (y==p || !G[x][y]) {
        C[y] = 0;
        return choose(y+1, x, p, rem);
    }

    long long ret = choose(y+1, x, p, rem);
    C[y] = 1;
    ret = (ret + choose(y+1, x, p, rem-1)) % mod;
    C[y] = 0;
    return ret;
}

long long go(int x, int p, bool have, bool must, bool mustnt) {
    assert(x != p);
    assert(!(must && mustnt));
    if (lim==0 && have && must) {
        return 0;
    }
    long long &ret = dp[x][p][have][must][mustnt];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    if (!must) {
        ret = 1;
        for (int i=0; i<n; ++i) {
            if (i!=p && G[x][i]) {
                ret = (ret * go(i, x, 0, 0, 0)) % mod;
            }
        }
    }
        
    if (!mustnt) {
        int rem = lim - have;
        for (int i=0; i<n; ++i) {
            if (i!=p && G[x][i]) {
                go(i, x, 1, 1, 0);
                go(i, x, 1, 0, 1);
            }
        }
        ret = (ret + choose(0, x, p, rem)) % mod;
    }

    return ret;
}

class TreeCount {
	public:
	vector <int> count(vector <string> graph) {
        n = graph.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = (graph[i][j] == 'Y');
            }
        }

        vector<int> sol(n, 0);
        for (lim=0; lim<n; ++lim) {
            memset(dp, 0xff, sizeof dp);
            sol[lim] = (int)go(0, n+1, 0, 0, 0);
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"NYY", "YNN", "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 7, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYNNNYY", "YNNNNNN", "NNNNNNY", "NNNNNNY", "NNNNNNY", "YNNNNNN", "YNYYYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {44, 73, 104, 124, 128, 128, 128 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"NY", "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYYYYY", "YNNNNN", "YNNNNN", "YNNNNN", "YNNNNN", "YNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33, 38, 48, 58, 63, 64 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TreeCount ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

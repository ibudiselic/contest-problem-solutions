#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[51][51][51][51];
int F[51][51];
int M, N, S;
int mod = 1000007;

bool valid(int i, int j) {
    if (i<1 || j<1 || i>=M || j>=N) {
        return false;
    }
    return true;
}

int go(int i, int j, int s, int last) {
    if (s < 0) {
        return 0;
    }
    if (i==M-1 && j==N-1) {
        return (s == 0);
    }
    
    int &ret = dp[i][j][s][last];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    int r, c;
    
    r = i + 1;
    c = j;
    if (valid(r, c)) {
        if (F[r][c] == -1) {
            ret = (ret + go(r, c, s, last)) % mod;
        } else if (s>0 && F[r][c]>last) {
            ret = (ret + go(r, c, s-1, F[r][c])) % mod;
        }
    }

    r = i;
    c = j + 1;
    if (valid(r, c)) {
        if (F[r][c] == -1) {
            ret = (ret + go(r, c, s, last)) % mod;
        } else if (s>0 && F[r][c]>last) {
            ret = (ret + go(r, c, s-1, F[r][c])) % mod;
        }
    }

    return ret;
}

class CountPaths {
	public:
	vector <int> difPaths(int r, int c, vector <int> fieldrow, vector <int> fieldcol) {
		S = fieldrow.size();
        memset(F, 0xff, sizeof F);
        for (int i=0; i<S; ++i) {
            F[fieldrow[i]][fieldcol[i]] = i+1;
        }
        M = r+1;
        N = c+1;

        memset(dp, 0xff, sizeof dp);

        vector<int> sol;
        for (int i=0; i<=S; ++i) {
            sol.push_back(go(1, 1, i - (F[1][1]!=-1), (F[1][1]==-1 ? 0 : F[1][1])));
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 3, 2 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, difPaths(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 4; int Arr2[] = {5, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {14, 24, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, difPaths(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {42, 14, 10, 4 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, difPaths(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 35; int Arg1 = 37; int Arr2[] = {3, 28, 28, 27, 27, 5, 15, 23, 21, 3, 8, 25, 34, 31, 33, 35, 13, 34}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {12, 34, 3, 9, 34, 3, 18, 17, 26, 5, 23, 14, 20, 7, 3, 20, 19, 23}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {830519, 709835, 755976, 219563, 868547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, difPaths(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 50; int Arr2[] = {50, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 0, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, difPaths(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CountPaths ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

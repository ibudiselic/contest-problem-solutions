#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[1<<15];
vector<int> L;
vector<int> S;
double T;
int sum[50][50];
double val[15][50][50];
int go(int used) {
    if (used == 0) {
        return L.size();
    }
    int &ret = dp[used];
    if (ret != -1) {
        return ret;
    }

    ret = L.size();
    for (int i=0; i<(int)S.size(); ++i) {
        if (used & (1<<i)) {
            int x = go(used ^ (1<<i));
            if (x == 0) {
                return (ret = 0);
            }
            if (val[i][x-1][x-1] > T) {
                continue;
            }
            int lo = 0;
            int hi = x-1;
            while (lo < hi) {
                int m = (lo+hi) / 2;
                if (val[i][m][x-1] <= T) {
                    hi = m;
                } else {
                    lo = m + 1;
                }
            }
            ret = min(ret, lo);
        }
    }

    return ret;
}
class PaintingBoards {
	public:
	double minimalTime(vector <int> boardLength, vector <int> painterSpeed) {
		L = boardLength;
        S = painterSpeed;
        sort(S.begin(), S.end());
        reverse(S.begin(), S.end());
        memset(sum, 0, sizeof sum);
        for (int i=0; i<(int)L.size(); ++i) {
            sum[i][i] = L[i];
        }
        for (int l=1; l<(int)L.size(); ++l) {
            for (int i=0; i<(int)L.size()-l; ++i) {
                sum[i][i+l] = sum[i][i+l-1] + L[i+l];
            }
        }

        for (int k=0; k<(int)S.size(); ++k) {
            for (int i=0; i<(int)L.size(); ++i) {
                for (int j=0; j<(int)L.size(); ++j) {
                    val[k][i][j] = (double)sum[i][j] / S[k];
                }
            }
        }

        double lo = 0.0;
        double hi = val[0][0][(int)L.size()-1];

        for (int t=0; t<60; ++t) {
            T = (lo+hi) / 2;

            memset(dp, 0xff, sizeof dp);
            if (go((1<<(int)S.size())-1) == 0) {
                hi = T;
            } else {
                lo = T;
            }
        }

        return (lo+hi) / 2;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,1,4,2,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {40, 46, 82, 89, 33, 46, 3, 50, 95, 
81, 69, 40, 94, 93, 90, 98, 17, 34, 
45, 18, 93, 28, 43, 38, 35}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {49, 51, 35, 27, 48, 36, 54, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.686274509803922; verify_case(2, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,3,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.888888888888889; verify_case(3, Arg2, minimalTime(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PaintingBoards ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

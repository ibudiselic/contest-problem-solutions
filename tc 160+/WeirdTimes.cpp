#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> M;

const int INF = 1000000001;
int dp[51][24];
int cnt(int p, int last) {
    int &ret = dp[p][last];
    if (ret != -1) {
        return ret;
    }
    if (p == (int)M.size()) {
        return (ret = 1);
    }
    
    ret = 0;
    for (int i=(M[p]>M[p-1] ? last : last+1); i<24; ++i) {
        ret += cnt(p+1, i);
        if (ret >= INF) {
            ret = INF;
            break;
        }
    }
    return ret;
}
class WeirdTimes {
	public:
	vector <int> hourValues(vector <int> minuteValues, int K) {
		M = minuteValues;
        vector<int> sol(M.size(), -1);
        memset(dp, 0xff, sizeof dp);
        for (int i=0; i<(int)sol.size(); ++i) {
            bool ok = false;
            for (int j=(i==0 ? 0 : (M[i]>M[i-1] ? sol[i-1] : sol[i-1]+1)); j<24; ++j) {
                const int t = cnt(i+1, j);
                if (t >= K) {
                    sol[i] = j;
                    ok = true;
                    break;
                } else {
                    K -= t;
                }
            }
            if (!ok) {
                return vector<int>(1, -1);
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {22, 11, 33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {0, 1, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, hourValues(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, hourValues(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arr2[] = {0, 20 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, hourValues(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arr2[] = {0, 19 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, hourValues(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 15, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {-1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, hourValues(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {45, 12, 0, 3, 2, 7, 4, 9, 23, 6, 17, 33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12345; int Arr2[] = {0, 1, 2, 2, 3, 3, 4, 5, 12, 13, 18, 18 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, hourValues(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {43, 58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 318; int Arr2[] = {-1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, hourValues(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WeirdTimes ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

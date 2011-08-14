#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(long long x1, long long y1, long long x2, long long y2, const vector<int> &D, const vector<int> &H, int n) {
    long long dx = x2-x1;
    long long dy = y2-y1;
    assert(dx > 0);
    
    long long tmp = y1*dx - x1*dy;
    if (tmp < 0) { // lower than 0 at x=0
        return n+1;
    }
    
    tmp += D.back()*dy;
    if (tmp < 0) {
        return n+1; // lower than 0 at rightmost tree
    }
    
    int ret = 0;
    for (int i=0; i<n; ++i) {
        tmp = D[i]*dy + y1*dx - x1*dy;
        if (tmp > dx*H[i]) {
            return n+1;
        }
        ret += (tmp < dx*H[i]);
    }
    return ret;
}
int left_zero(const vector<int> &D, const vector<int> &H, int n) {
    int ret = n+1;
    for (int i=1; i<n; ++i) {
        ret = min(ret, calc(0, 0, D[i], H[i], D, H, n));
    }
    return ret;
}
int right_zero(const vector<int> &D, const vector<int> &H, int n) {
    int ret = n+1;
    for (int i=0; i<n-1; ++i) {
        ret = min(ret, calc(D[i], H[i], D.back(), 0, D, H, n));
    }
    return ret;
}
int two(const vector<int> &D, const vector<int> &H, int n) {
    int ret = n+1;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            ret = min(ret, calc(D[i], H[i], D[j], H[j], D, H, n));
        }
    }
    return ret;
}

class TimeTravellingGardener {
	public:
	int determineUsage(vector <int> distance, vector <int> height) {
        distance.insert(distance.begin(), 0);
        for (int i=1; i<(int)distance.size(); ++i) {
            distance[i] += distance[i-1];
        }
        
        int n = height.size();
        int lo = *min_element(height.begin(), height.end());
        int sol = n - count(height.begin(), height.end(), lo);
        sol = min(sol, left_zero(distance, height, n));
        sol = min(sol, right_zero(distance, height, n));
        sol = min(sol, two(distance, height, n));
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,8,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {476,465,260,484}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {39,13,8,72,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {173,36,668,79,26,544}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {488,743,203,446,444,91,453}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {2,4,2,2,4,2,4,2,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,10,10,10,16,16,22,22,28,28}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(6, Arg2, determineUsage(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TimeTravellingGardener ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

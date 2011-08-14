#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc_lt(const vector<int> &heights) {
    int ret = 0;
    int n = heights.size();
    int i = n - 1;
    int index = 1;
    while (index < n-1) {
        ret += 2*heights[i--];
        index += 2;
    }
    ret += ((n&1) ? -1 : 1)*heights[i--];
    ret -= heights[i--];
    while (i >= 0) {
        ret -= 2*heights[i--];
    }
    return ret;
}
int calc_gt(const vector<int> &heights) {
    int ret = 0;
    int n = heights.size();
    int i = n - 1;
    int index = 2;
    while (index < n-1) {
        ret += 2*heights[i--];
        index += 2;
    }
    ret += heights[i--];
    ret += ((n&1) ? 1 : -1)*heights[i--];
    while (i >= 0) {
        ret -= 2*heights[i--];
    }
    return ret;
}
class CrazyLine {
	public:
	int maxCrazyness(vector <int> heights) {
        if (heights.size() == 1) {
            return 0;
        }
		sort(heights.begin(), heights.end());
        return max(calc_lt(heights), calc_gt(heights));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,10,25,40,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(0, Arg1, maxCrazyness(Arg0)); }
	void test_case_1() { int Arr0[] = {2,3,5,7,11,13,17,19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 82; verify_case(1, Arg1, maxCrazyness(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,501}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; verify_case(2, Arg1, maxCrazyness(Arg0)); }
	void test_case_3() { int Arr0[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, maxCrazyness(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CrazyLine ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

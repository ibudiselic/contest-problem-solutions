#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

bool done[50];
class CircleMarket {
	public:
	int makePurchases(vector <int> openTime, vector <int> closeTime, int travelTime) {
		int t = 0;
        int lim = *max_element(closeTime.begin(), closeTime.end());
        memset(done, 0, sizeof done);
        int p = 0;
        while (t <= lim) {
            if (openTime[p]<=t && t<=closeTime[p] && !done[p]) {
                done[p] = true;
            }
            t += travelTime;
            p = (p+1)%openTime.size();
        }
        
        return accumulate(done, done+(int)openTime.size(), 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 3; verify_case(0, Arg3, makePurchases(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {45, 45, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50, 50, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; int Arg3 = 1; verify_case(1, Arg3, makePurchases(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1000, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1010, 1010}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(2, Arg3, makePurchases(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {999999, 2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000, 22, 44}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, makePurchases(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {363, 237, 382, 232, 392, 3829, 99999, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {365, 1239, 2384, 234, 394, 3831, 100001, 15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 3; verify_case(4, Arg3, makePurchases(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CircleMarket ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

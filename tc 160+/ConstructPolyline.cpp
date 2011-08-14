#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;

// #include <ctime>
double start_time_;
const double CLOCK_LIMIT_ = 1.8 * CLOCKS_PER_SEC; // in secs
void init_time_() {
    start_time_ = clock();
}
bool timeout_() {
    return clock()-start_time_ > CLOCK_LIMIT_;
}

long long d[50];
int subset[10];
bool chosen[50];
long long calc(long long x, long long y, long long z) {
    return x*x + y*y + z*z;
}
class ConstructPolyline {
	public:
	long long maximizeLength(vector <int> x, vector <int> y, vector <int> z) {
		init_time_();
        int n = x.size();
        vector<int> order;
        for (int i=0; i<n; ++i) {
            order.push_back(i);
        }
        
        long long sol = 0;
        while (!timeout_()) {
            for (int rpt=0; rpt<=50-n; ++rpt) {
                random_shuffle(order.begin(), order.end());
                long long dx = 0;
                long long dy = 0;
                long long dz = 0;
                for (int i=0; i<n; ++i) {
                    long long a = 0, b = 0;
                    for (int dir=-1; dir<2; dir+=2) {
                        (dir==-1 ? a : b) = calc(dx+dir*x[order[i]], dy+dir*y[order[i]], dz+dir*z[order[i]]);
                    }
                    if (a > b) {
                        dx -= x[order[i]];
                        dy -= y[order[i]];
                        dz -= z[order[i]];
                    } else {
                        dx += x[order[i]];
                        dy += y[order[i]];
                        dz += z[order[i]];
                    }
                }
                sol = max(sol, calc(dx, dy, dz));
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10,15,-5,-10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,5,-20,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,-5,0,15}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3425LL; verify_case(0, Arg3, maximizeLength(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {51,23,350,-18,-69,200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100,-50,1,45,-69,-70}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {211,-245,56,566,23,24}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1559907LL; verify_case(1, Arg3, maximizeLength(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,-1,2,-2,3,-3,4,-4,5,-5,6,-6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0,0,0,0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0,0,0,0,0,0,0,0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1764LL; verify_case(2, Arg3, maximizeLength(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {-368,-473,135,50,-125,82,-204,272}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {401,-153,39,-283,-37,-40,-347,-358}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-91,-271,450,427,359,396,359,92}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 8705702LL; verify_case(3, Arg3, maximizeLength(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {10,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {21,21,21}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-5,-5,-5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5094LL; verify_case(4, Arg3, maximizeLength(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ConstructPolyline ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

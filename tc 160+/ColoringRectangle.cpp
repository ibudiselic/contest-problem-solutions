#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int inf = 123456;
int W, H;
int go(vector<int> a, vector<int> b) {
    double start = 0.0;
    int ret = 0;
    while (start+1e-9 < W) {
        if (a.size()==0 || a.back()<H) {
            return inf;
        }
        ++ret;
        start += sqrt(a.back()*a.back()-H*H);
        a.pop_back();
        a.swap(b);
    }
    return ret;
}
class ColoringRectangle {
	public:
	int chooseDisks(int width, int height, vector <int> red, vector <int> blue) {
        W = width;
        H = height;
		sort(red.begin(), red.end());
        sort(blue.begin(), blue.end());
        int sol = min(go(red, blue), go(blue, red));
        return sol == inf ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 3; int Arr2[] = {5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 30; int Arg1 = 5; int Arr2[] = {4,10,7,8,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,6,11,7,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 16; int Arg1 = 4; int Arr2[] = {6,5,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(2, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 2; int Arr2[] = {6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColoringRectangle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

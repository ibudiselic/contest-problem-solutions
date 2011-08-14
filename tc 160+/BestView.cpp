#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> H;
int n;

int ccw(long long x1, long long y1, long long x2, long long y2) {
    long long t = x1*y2 - y1*x2;
    if (t > 0) {
        return 1;
    } else if (t == 0) {
        return 0;
    } else {
        return -1;
    }
}
int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    return ccw(x1-x2, y1-y2, x3-x2, y3-y2);
}
bool intersects(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4) {
    return ccw(x3, y3, x1, y1, x2, y2)*ccw(x4, y4, x1, y1, x2, y2) <= 0 &&
           ccw(x1, y1, x3, y3, x4, y4)*ccw(x2, y2, x3, y3, x4, y4) <= 0;
}
bool can_see(int i, int j) {
    for (int k=i+1; k<j; ++k) {
        if (intersects(i, H[i], j, H[j], k, 0, k, H[k])) {
            return false;
        }
    }
    return true;
}
class BestView {
	public:
	int numberOfBuildings(vector <int> heights) {
        int sol = 0;
        H = heights;
        n = H.size();
        for (int i=0; i<n; ++i) {
            int cur = 0;
            for (int j=0; j<i; ++j) {
                cur += can_see(j, i);
            }
            for (int j=i+1; j<n; ++j) {
                cur += can_see(i, j);
            }
            sol = max(sol, cur);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, numberOfBuildings(Arg0)); }
	void test_case_1() { int Arr0[] = {5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, numberOfBuildings(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,7,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, numberOfBuildings(Arg0)); }
	void test_case_3() { int Arr0[] = {1,5,3,2,6,3,2,6,4,2,5,7,3,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, numberOfBuildings(Arg0)); }
	void test_case_4() { int Arr0[] = {1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, numberOfBuildings(Arg0)); }
	void test_case_5() { int Arr0[] = {244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(5, Arg1, numberOfBuildings(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BestView ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

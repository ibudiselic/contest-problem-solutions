#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int right_[351][351], down[351][351];
bool A[350][350];

class DonutsOnTheGrid {
	public:
	long long calc(int m, int n, int seed, int threshold) {
        memset(right_, 0, sizeof right_);
        memset(down, 0, sizeof down);
        int x = seed;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                x = (x*25173 + 13849) % 65536;
                A[i][j] = (x < threshold);
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=n-1; j>=0; --j) {
                if (A[i][j]) {
                    right_[i][j] = right_[i][j+1] + 1;
                } else {
                    right_[i][j] = 0;
                }
            }
        }
        for (int j=0; j<n; ++j) {
            for (int i=m-1; i>=0; --i) {
                if (A[i][j]) {
                    down[i][j] = down[i+1][j] + 1;
                } else {
                    down[i][j] = 0;
                }
            }
        }
        
        long long sol = 0;
        for (int i1=0; i1<m; ++i1) {
            for (int i2=i1+2; i2<m; ++i2) {
                int d = i2-i1+1;
                vector<int> cols;
                for (int j=0; j<n; ++j) {
                    if (down[i1][j] >= d) {
                        cols.push_back(j);
                    }
                }
                int x1 = 0;
                int x2 = 0;
                while (x1 < (int)cols.size()) {
                    const int j1 = cols[x1];
                    int w = min(right_[i1][j1], right_[i2][j1]);
                    if (w >= 3) {
                        while (x2<(int)cols.size() && cols[x2]<=j1+w-1) {
                            ++x2;
                        }
                        int cnt = x2-x1-1;
                        if (cnt > 0) {
                            sol += cnt;
                            if (x1+1<(int)cols.size() && cols[x1+1]==j1+1) {
                                --sol;
                            }
                        }
                    }
                    ++x1;
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 222; int Arg3 = 55555; long long Arg4 = 4LL; verify_case(0, Arg4, calc(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 121; int Arg3 = 58000; long long Arg4 = 3LL; verify_case(1, Arg4, calc(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 6; int Arg3 = 50000; long long Arg4 = 1LL; verify_case(2, Arg4, calc(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; int Arg3 = 65536; long long Arg4 = 9LL; verify_case(3, Arg4, calc(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DonutsOnTheGrid ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

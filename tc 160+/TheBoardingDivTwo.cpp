#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int T;
vector<int> P;
int n;
bool used[8];
int cell[16], arrived_time[16];
int tst() {
    memset(cell, 0xff, sizeof cell);
    for (int i=0; i<n; ++i) {
        cell[i] = P[i];
    }
    int done = 0;
    for (int t=0; t<T; ++t) {
        for (int Y=2*n-1; Y>=0; --Y) {
            if (cell[Y] == -1) {
                continue;
            }
            int X = cell[Y];
            if (Y == X + n) {
                if (t == arrived_time[Y]+74) {
                    ++done;
                } else if (t > arrived_time[Y]+74) {
                    cell[Y] = -1;
                }
            } else if (cell[Y+1] == -1) {
                cell[Y+1] = X;
                cell[Y] = -1;
                arrived_time[Y+1] = t;
            }
        }
    }
    assert(done <= n);
    return (done==n);
}
int go(int pos) {
    if (pos == n) {
        return tst();
    } else if (P[pos] == -1) {
        int ret = 0;
        for (int i=0; i<n; ++i) {
            if (!used[i]) {
                P[pos] = i;
                used[i] = true;
                ret += go(pos + 1);
                used[i] = false;
            }
        }
        P[pos] = -1;
        return ret;
    } else {
        return go(pos + 1);
    }
}
class TheBoardingDivTwo {
	public:
	int find(vector <int> pattern, int boardingTime) {
		T = boardingTime;
        P = pattern;
        n = P.size();
        memset(used, 0, sizeof used);
        for (int i=0; i<(int)P.size(); ++i) {
            if (P[i] != -1) {
                used[--P[i]] = true;
            }
        }
        
        return go(0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 1; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, 2, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 222; int Arg2 = 1; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2, 1, 3, 5, 4, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 155; int Arg2 = 1; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, -1, -1, -1, -1, -1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 198; int Arg2 = 233; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBoardingDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

bool done[100001];
int solve(int a, int b, int x, int y) {
    memset(done, 0, sizeof done);
    queue<int> Q;
    Q.push(a);
    int dist = 0;
    int sz = 0;
    done[a] = true;
    while (!Q.empty()) {
        if (sz == 0) {
            ++dist;
            sz = Q.size();
        }
        a = Q.front();
        Q.pop();
        --sz;
        
        for (int i=1; i<1000; ++i) {
            int move = i*i;
            if (a-move>x && !done[a-move]) {
                if (a-move == b) {
                    return dist;
                }
                done[a-move] = true;
                Q.push(a-move);
            }
            if (a+move<y && !done[a+move]) {
                if (a+move == b) {
                    return dist;
                }
                done[a+move] = true;
                Q.push(a+move);
            }
        }
    }
    
    return -1;
}

int solve(int a, int b) {
    set<long long> squares;
    for (long long i=1; i<50001; ++i) {
        squares.insert(i*i);
    }
    int d = abs(a-b);
    if (squares.count(d)) {
        return 1;
    }
    for (set<long long>::const_iterator it=squares.begin(); it!=squares.end(); ++it) {
        if (*it<d && squares.count(d-*it)) {
            return 2;
        } else if (*it>d && squares.count(*it-d)) {
            return 2;
        }
    }
    return 3;
}
class CubeRoll {
	public:
	int getMinimumSteps(int a, int b, vector <int> P) {
	    sort(P.begin(), P.end());
        if (a < P[0]) {
            if (b < P[0]) {
                return solve(a, b);
            } else {
                return -1;
            }
        } else if (a > P.back()) {
            if (b > P.back()) {
                return solve(a, b);
            } else {
                return -1;
            }
        } else {
            int p = lower_bound(P.begin(), P.end(), a) - P.begin();
            if (P[p-1]<b && b<P[p]) {
                return solve(a, b, P[p-1], P[p]);
            } else {
                return -1;
            }
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(0, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 36; int Arg1 = 72; int Arr2[] = {300, 100, 200, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 21; int Arr2[] = {38,45}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 98765; int Arg1 = 4963; int Arr2[] = {10,20,40,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 68332; int Arg1 = 825; int Arr2[] = {99726,371,67,89210}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(4, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CubeRoll ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

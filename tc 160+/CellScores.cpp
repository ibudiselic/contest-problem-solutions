#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

int n;

// [i][j] is the number of rectangles that have (i, j) as the 
// lower-right corner
vector< vector<int> > calc_upper_left(const vector< vector<int> > &A) {
    vector< vector<int> > B(n, vector<int>(n, 0));
    vector<int> height(n, 0);
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (A[i][j] == 0) {
                ++height[j];
            } else {
                height[j] = 0;
            }
        }
        long long cur = 0;
        stack<int> heights, col;
        heights.push(0); // dummy
        col.push(-1); // should never be used or tested against
        for (int j=0; j<n; ++j) {
            heights.push(height[j] + 1);
            col.push(j);
            while (heights.top() > height[j]) {
                int last_h = heights.top(); heights.pop();
                int last_col = col.top(); col.pop();
                
                cur -= (last_h - heights.top()) * (j - last_col);
                if (heights.top() <= height[j]) {
                    cur += height[j];
                }
                if (heights.top() < height[j]) {
                    cur += (height[j] - heights.top()) * (j - last_col);
                    heights.push(height[j]);
                    col.push(last_col);
                }
            }
            B[i][j] = cur;
        }
    }
    
    return B;
}
// [i][j] is the number of rectangles that have (i, j) on their
// bottom side
vector< vector<int> > calc_top(vector< vector<int> > &A) {
    vector< vector<int> > upper_left = calc_upper_left(A);
    for (int i=0; i<n; ++i) {
        reverse(A[i].begin(), A[i].end());
    }
    vector< vector<int> > upper_right = calc_upper_left(A);
    for (int i=0; i<n; ++i) {
        reverse(A[i].begin(), A[i].end());
        reverse(upper_right[i].begin(), upper_right[i].end());
    }

    vector< vector<int> > B(n, vector<int>(n));
    for (int i=0; i<n; ++i) {
        B[i][0] = upper_right[i][0];
        for (int j=1; j<n; ++j) {
            B[i][j] = B[i][j-1] - upper_left[i][j-1] + upper_right[i][j];
        }
    }
    return B;
}
// [i][j] is the number of rectangles that contain (i, j)
vector< vector<long long> > calc(vector< vector<int> > &A) {
    vector< vector<int> > top = calc_top(A);
    for (int i=0; i<n/2; ++i) {
        swap(A[i], A[n-1-i]);
    }
    vector< vector<int> > bot = calc_top(A);
    for (int i=0; i<n/2; ++i) {
        swap(A[i], A[n-1-i]);
        swap(bot[i], bot[n-1-i]);
    }
    
    vector< vector<long long> > B(n, vector<long long>(n));
    for (int j=0; j<n; ++j) {
        B[0][j] = bot[0][j];
        for (int i=1; i<n; ++i) {
            B[i][j] = B[i-1][j] - top[i-1][j] + bot[i][j];
        }
    }
    
    return B;
}
class CellScores {
	public:
	long long countScores(int N, int M, int K, int X0, int A, int B, int Y0, int C, int D) {
	    n = N;
        X0 %= n;
        Y0 %= n;
        vector< vector<int> > V(n, vector<int>(n, 0));
        for (int i=0; i<M; ++i) {
            V[X0][Y0] = 1;
            X0 = (X0*A + B) % n;
            Y0 = (Y0*C + D) % n;
        }
        
        vector< vector<long long> > T = calc(V);
        long long sol = 0;
        for (int i=0; i<K; ++i) {
            sol += T[X0][Y0];
            X0 = (X0*A + B) % n;
            Y0 = (Y0*C + D) % n;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 0; int Arg2 = 1; int Arg3 = 0; int Arg4 = 1; int Arg5 = 1; int Arg6 = 0; int Arg7 = 1; int Arg8 = 1; long long Arg9 = 100LL; verify_case(0, Arg9, countScores(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; int Arg4 = 1; int Arg5 = 5; int Arg6 = 5; int Arg7 = 1; int Arg8 = 5; long long Arg9 = 75LL; verify_case(1, Arg9, countScores(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 3; int Arg3 = 0; int Arg4 = 1; int Arg5 = 1; int Arg6 = 0; int Arg7 = 1; int Arg8 = 1; long long Arg9 = 194LL; verify_case(2, Arg9, countScores(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 23; int Arg1 = 10; int Arg2 = 30; int Arg3 = 26; int Arg4 = 48; int Arg5 = 76; int Arg6 = 231; int Arg7 = 463; int Arg8 = 707; long long Arg9 = 8088LL; verify_case(3, Arg9, countScores(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 211; int Arg1 = 30; int Arg2 = 12; int Arg3 = 3; int Arg4 = 35; int Arg5 = 82; int Arg6 = 0; int Arg7 = 43; int Arg8 = 15; long long Arg9 = 18196443LL; verify_case(4, Arg9, countScores(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 100; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 0; int Arg8 = 0; long long Arg9 = 900LL; verify_case(5, Arg9, countScores(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CellScores ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

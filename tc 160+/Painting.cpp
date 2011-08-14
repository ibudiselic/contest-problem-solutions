#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// double 2d prefix sums... (misof forum)

int A[51][51], B[51][51];
int m, n;
bool is_SxS(int i, int j, int S) {
    assert(i>=S && j>=S);
    return A[i][j] - A[i-S][j] - A[i][j-S] + A[i-S][j-S] == S*S;
}
bool can_draw(int i, int j, int a, int b) {
    a = min(a, m);
    b = min(b, n);
    return B[a][b] - B[i-1][b] - B[a][j-1] + B[i-1][j-1] > 0;
}
class Painting {
	public:
	int largestBrush(vector <string> P) {
        m = P.size();
        n = P[0].size();
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                A[i][j] = A[i-1][j] + A[i][j-1] - A[i-1][j-1] + (P[i-1][j-1]=='B'); // makes it possible to find number of B-s in a SxS square in O(1) time
            }
        }
        
        int lo = 1;
        int hi = min(m, n);
        while (lo < hi) {
            int mid = lo + (hi-lo+1)/2;
            memset(B, 0, sizeof B);
            for (int i=mid; i<=m; ++i) {
                for (int j=mid; j<=n; ++j) {
                    B[i][j] = B[i-1][j] + B[i][j-1] - B[i-1][j-1] + is_SxS(i, j, mid); // makes it possible to answer the question "can I paint (i, j) using an SxS brush" in O(1)
                }
            }

            bool ok = true;
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (P[i][j] == 'B') {
                        if (!can_draw(i+1, j+1, i+mid, j+mid)) {
                            ok = false;
                            goto DONE;
                        }
                    }
                }
            }
            DONE: ;
            if (ok) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, largestBrush(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, largestBrush(Arg0)); }
	void test_case_2() { string Arr0[] = {"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, largestBrush(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, largestBrush(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, largestBrush(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Painting ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int m[50], M[50];
long long C[51][51];
class RabbitProgramming {
	public:
	long long getTeams(vector <int> points, vector <string> standings, int qualified, int selected) {
	    int total = standings.size();
        memset(m, 0, sizeof m);
        memset(M, 0, sizeof M);
        for (int i=0; i<total; ++i) {
            for (int j=0; j<(int)points.size(); ++j) {
                if (standings[i][j] == 'Y') {
                    if (points[j] > 0) {
                            m[i] += points[j];
                            M[i] += points[j];
                    } else {
                        M[i] += -points[j];
                    }
                }
            }
        }
        C[0][0] = 1;
        for (int i=1; i<=total; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; ++j) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
        
        long long sol = 0;
        for (int i=0; i<total; ++i) {
            // add #ways ith guy is the weakest *selected*
            int better = 0; // are always qualified, but might not be selected
            int better_or_worse = 0; // either qualified (and potentially selected) or not
            for (int j=0; j<i; ++j) {
                if (m[j] >= M[i]) {
                    ++better;
                } else if (M[j] >= M[i]) {
                    ++better_or_worse;
                }
            }
            for (int j=i+1; j<total; ++j) {
                if (m[j] > M[i]) {
                    ++better;
                } else if (M[j] > M[i]) {
                    ++better_or_worse;
                }
            }
            
            if (better+1 > qualified) { // ith guy never qualifies
                continue;
            }
            
            for (int j=0; j<=better && j<=selected-1; ++j) { // j better guys get selected
                // so now a total of j+1 guys are selected
                // better+1 guys are fixed in qualified slots, so there are
                // qualified - better - 1 slots left
                // those slots will be filled by better_or_worse guys (and possibly some worse guys)
                // and selected-j-1 of them will get selected
                // specifically, if selected-j-1 > better_or_worse, then 
                // there is no valid configuration (strictly worse guys can
                // be qualified, but not selected (the ith guy must be the 
                // worst selected to avoid overcounting))
                int rem = selected-j-1;
                if (rem > qualified-better-1) {
                    continue;
                }
                
                sol += C[better][j]*C[better_or_worse][rem];
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, -10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "NY", 
  "YN", 
  "YN",
  "YN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 2; long long Arg4 = 5LL; verify_case(0, Arg4, getTeams(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = { -250, -500, -1000 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "YYY", 
  "YNY", 
  "YYN", 
  "YYN", 
  "YNN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 2; long long Arg4 = 10LL; verify_case(1, Arg4, getTeams(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = { 5, -12, 5, -15, 10, -20, 3, -25, 7, -32, 21, -45 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "YYYYYYYYYNYY", 
  "YYYNYYYYYNNN", 
  "YYYNYNYYNNYN", 
  "YYYYYNYYYYNN", 
  "YYNNYNYNYYNN", 
  "YYYNNNYYNNNN", 
  "YYNNNNYYNNNN", 
  "NNYNYYYNYNNN", 
  "NNNNNNYYYNNN", 
  "YYYNNNYYYNNN" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 3; long long Arg4 = 99LL; verify_case(2, Arg4, getTeams(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RabbitProgramming ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

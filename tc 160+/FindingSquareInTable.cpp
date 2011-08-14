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

bool is_sqr(long long x) {
    long long y = (int)(sqrt(x) + 0.5);
    return y*y == x;
}
class FindingSquareInTable {
	public:
	int findMaximalSquare(vector <string> table) {
	    long long sol = -1;
        int m = table.size();
        int n = table[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int di=-9; di<9; ++di) {
                    for (int dj=-9; dj<9; ++dj) {
                        if (di==0 && dj==0) {
                            continue;
                        }
                        long long x = table[i][j]-'0';
                        int r = i + di;
                        int c = j + dj;
                        while (r>=0 && c>=0 && r<m && c<n) {
                            x = 10*x + table[r][c]-'0';
                            if (x>sol && is_sqr(x)) {
                                sol = x;
                            }
                            r += di;
                            c += dj;
                        }
                        if (x>sol && is_sqr(x)) {
                            sol = x;
                        }
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123",
 "456"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(0, Arg1, findMaximalSquare(Arg0)); }
	void test_case_1() { string Arr0[] = {"00000",
 "00000",
 "00200",
 "00000",
 "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, findMaximalSquare(Arg0)); }
	void test_case_2() { string Arr0[] = {"3791178",
 "1283252",
 "4103617",
 "8233494",
 "8725572",
 "2937261"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 320356; verify_case(2, Arg1, findMaximalSquare(Arg0)); }
	void test_case_3() { string Arr0[] = {"135791357",
 "357913579",
 "579135791",
 "791357913",
 "913579135"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, findMaximalSquare(Arg0)); }
	void test_case_4() { string Arr0[] = {"553333733",
 "775337775",
 "777537775",
 "777357333",
 "755553557",
 "355533335",
 "373773573",
 "337373777",
 "775557777"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, findMaximalSquare(Arg0)); }
	void test_case_5() { string Arr0[] = {"257240281",
 "197510846",
 "014345401",
 "035562575",
 "974935632",
 "865865933",
 "684684987",
 "768934659",
 "287493867"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 95481; verify_case(5, Arg1, findMaximalSquare(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FindingSquareInTable ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

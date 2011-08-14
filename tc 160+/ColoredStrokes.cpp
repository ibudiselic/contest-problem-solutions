#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ColoredStrokes {
	public:
	int getLeast(vector <string> P) {
		int m = P.size();
        int n = P[0].size();
        
        int sol = 0;
        bool change = true;
        while (change) {
            change = false;
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (P[i][j] == 'R') {
                        ++sol;
                        change = true;
                        int jj = j;
                        while (jj>=0 && (P[i][jj]=='R' || P[i][jj]=='G')) {
                            P[i][jj] = (P[i][jj]=='R' ? '.' : 'B');
                            --jj;
                        }
                        jj = j+1;
                        while (jj<n && (P[i][jj]=='R' || P[i][jj]=='G')) {
                            P[i][jj] = (P[i][jj]=='R' ? '.' : 'B');
                            ++jj;
                        }
                    } else if (P[i][j] == 'B') {
                        ++sol;
                        change = true;
                        int ii = i;
                        while (ii>=0 && (P[ii][j]=='B' || P[ii][j]=='G')) {
                            P[ii][j] = (P[ii][j]=='B' ? '.' : 'R');
                            --ii;
                        }
                        ii = i+1;
                        while (ii<m && (P[ii][j]=='B' || P[ii][j]=='G')) {
                            P[ii][j] = (P[ii][j]=='B' ? '.' : 'R');
                            ++ii;
                        }
                    }
                }
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (P[i][j] == 'G') {
                    ++sol;
                    int jj = j;
                    while (jj>=0 && P[i][jj]=='G') {
                        P[i][jj] = 'B';
                        --jj;
                    }
                    jj = j+1;
                    while (jj<n && P[i][jj]=='G') {
                        P[i][jj] = 'B';
                        ++jj;
                    }
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (P[i][j] == 'B') {
                    ++sol;
                    int ii = i;
                    while (ii>=0 && P[ii][j]=='B') {
                        P[ii][j] = '.';
                        --ii;
                    }
                    ii = i+1;
                    while (ii<m && P[ii][j]=='B') {
                        P[ii][j] = '.';
                        ++ii;
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
	void test_case_0() { string Arr0[] = {"...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getLeast(Arg0)); }
	void test_case_1() { string Arr0[] = {"..B.",
 "..B."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getLeast(Arg0)); }
	void test_case_2() { string Arr0[] = {".BB."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getLeast(Arg0)); }
	void test_case_3() { string Arr0[] = {"...B..",
 ".BRGRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getLeast(Arg0)); }
	void test_case_4() { string Arr0[] = {"...B..",
 ".BRBRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, getLeast(Arg0)); }
	void test_case_5() { string Arr0[] = {"GR",
 "BG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, getLeast(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColoredStrokes ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

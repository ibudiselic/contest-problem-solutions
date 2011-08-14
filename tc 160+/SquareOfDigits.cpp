#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SquareOfDigits {
	public:
	int getMax(vector <string> data) {
		int m = data.size();
        int n = data[0].size();
        int sol = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=1; k<1000; ++k) {
                    const int r = i + k;
                    const int c = j + k;
                    if (r>=m || c>=n) {
                        break;
                    }
                    if (data[i][j]==data[i+k][j] && data[i][j]==data[i][j+k] && data[i][j]==data[r][c]) {
                        sol = max(sol, (k+1)*(k+1));
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12",
 "34"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"1255",
 "3455"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, getMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"42101",
 "22100",
 "22101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, getMax(Arg0)); }
	void test_case_3() { string Arr0[] = {"1234567890"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, getMax(Arg0)); }
	void test_case_4() { string Arr0[] = {"9785409507",
 "2055103694",
 "0861396761",
 "3073207669",
 "1233049493",
 "2300248968",
 "9769239548",
 "7984130001",
 "1670020095",
 "8894239889",
 "4053971072"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(4, Arg1, getMax(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SquareOfDigits ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

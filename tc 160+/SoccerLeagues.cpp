#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SoccerLeagues {
	public:
	vector <int> points(vector <string> matches) {
		int n = (int)matches.size();
        
        vector<int> sol(n, 0);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (i != j) {
                    sol[i] += (matches[i][j]=='W' ? 3 : matches[i][j]=='L' ? 0 : 1);
                    sol[j] += (matches[i][j]=='L' ? 3 : matches[i][j]=='W' ? 0 : 1);
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
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"-WW",
 "W-W",
 "WW-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, points(Arg0)); }
	void test_case_1() { string Arr0[] = {"-DD",
 "L-L",
 "WD-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 2, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, points(Arg0)); }
	void test_case_2() { string Arr0[] = {"-DWWD",
 "L-WLL",
 "DD-WD",
 "DDL-L",
 "DDLL-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14, 7, 12, 8, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, points(Arg0)); }
	void test_case_3() { string Arr0[] = {"-LWWLWDLDWWWWWWDDWDW",
 "D-WWLDDWDWDLWDDWLWDD",
 "LL-DLDWDLDLDWWWLWDDW",
 "LDD-LLLDLWLWWWWDWDWL",
 "LWWW-DWDLWDWDWWWDWDW",
 "DLLWD-WWLLDDDLWWDWWW",
 "WWLWDL-LLDWWWWWDWWLW",
 "LLLLLDW-LDLWDDLLLDWL",
 "DWWWWDDD-DWWWWDWWWDW",
 "WWWWLLLWL-LWWWWWLWWW",
 "DWWWWWWWLW-WDWWWWWWW",
 "DDDLLLDWWWL-DDWDWLDD",
 "LWLWLDLLLDLW-DDDWWDD",
 "LLWWLWDDLWLWL-WWWDLL",
 "WWWWLLDDDWLWDD-WWWLW",
 "DLDLLLWWLLLWWLW-DWLL",
 "DLWWWLDLWWDWWDWL-WWD",
 "LLDDLLWLLWLWLDLWW-WW",
 "LLWLLLWWLWLWWDWWLD-W",
 "LLWDLWDWDWLLWWDDWWL-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {72, 62, 41, 41, 83, 63, 53, 35, 86, 50, 90, 32, 34, 41, 45, 36, 51, 32, 51, 45 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, points(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SoccerLeagues ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

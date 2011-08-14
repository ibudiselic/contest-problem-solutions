#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class RevealTriangle {
	public:
	vector <string> calcTriangle(vector <string> A) {
		int n = A.size();
        if (n == 1) {
            return A;
        }

        for (int i=n-2; i>=0; --i) {
            while (1) {
                bool change = false;
                for (int j=0; j<(int)A[i].size(); ++j) {
                    if (A[i][j]!='?' && j>0 && A[i][j-1]=='?') {
                        int d = A[i][j] - '0';
                        int dd = A[i+1][j-1] - '0';
                        int x = dd - d;
                        if (x < 0) x += 10;
                        A[i][j-1] = x + '0';
                        change = true;
                    } else if (A[i][j]!='?' && j+1<(int)A[i].size() && A[i][j+1]=='?') {
                        int d = A[i][j] - '0';
                        int dd = A[i+1][j] - '0';
                        int x = dd - d;
                        if (x < 0) x += 10;
                        A[i][j+1] = x + '0';
                        change = true;
                    }
                }

                if (!change) {
                    break;
                }
            }
        }

        return A;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"4??", 
 "?2", 
 "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"457", "92", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calcTriangle(Arg0)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calcTriangle(Arg0)); }
	void test_case_2() { string Arr0[] = {"???2", "??2", "?2", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0002", "002", "02", "2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calcTriangle(Arg0)); }
	void test_case_3() { string Arr0[] = {"??5?", "??9", "?4", "6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7054", "759", "24", "6" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calcTriangle(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RevealTriangle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool used[50][50];
const int di[] = { 0, 1, 0, -1 };
const int dj[] = { 1, 0, -1, 0 };

class SpiralWalking {
	public:
	int totalPoints(vector <string> A) {
		int m = A.size();
        int n = A[0].size();

        int sol = A[0][0]-'0';
        memset(used, 0, sizeof used);
        used[0][0] = 1;

        int i = 0;
        int j = 0;
        int dir = 0;
        int cnt = 1;

        while (cnt < m*n) {
            int r = i + di[dir];
            int c = j + dj[dir];
            if (r<0 || c<0 || r>=m || c>=n || used[r][c]) {
                dir = (dir+1) % 4;
                sol -= A[i][j]-'0';
            } else {
                used[r][c] = 1;
                sol += A[r][c]-'0';
                i = r;
                j = c;
                ++cnt;
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111",
 "111",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, totalPoints(Arg0)); }
	void test_case_1() { string Arr0[] = {"101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, totalPoints(Arg0)); }
	void test_case_2() { string Arr0[] = {"00",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, totalPoints(Arg0)); }
	void test_case_3() { string Arr0[] = {"86850",
 "76439",
 "15863",
 "24568",
 "45679",
 "71452",
 "05483"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 142; verify_case(3, Arg1, totalPoints(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SpiralWalking ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

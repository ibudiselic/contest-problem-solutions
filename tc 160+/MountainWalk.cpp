#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int di[] = { 1, 0, -1, 0 };
int dj[] = { 0, -1, 0, 1 };
bool done[50][50];
class MountainWalk {
	public:
	int cellsVisited(vector <string> A, int D) {
	    int M, N;
        M = A.size();
        N = A[0].size();
        memset(done, 0, sizeof done);
        int sol = 0;

        int i = 0;
        int j = 0;
        while (1) {
            ++sol;
            done[i][j] = 1;
            vector<int> pos;
            for (int d=0; d<4; ++d) {
                int r = i + di[d];
                int c = j + dj[d];
                if (r<0 || c<0 || r>=M || c>=N || done[r][c]) {
                    continue;
                }
                if (abs(A[r][c]-A[i][j]) <= D) {
                    pos.push_back(d);
                }
            }

            if (pos.size() == 0) {
                return sol;
            }
            i += di[pos[0]];
            j += dj[pos[0]];
        }

        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"056",
 "135",
 "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 5; verify_case(0, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"056",
 "195",
 "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 8; verify_case(1, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"865",
 "123",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 9; verify_case(2, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00009876543210",
 "00009876543210",
 "00009876543210",
 "00009876543210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 16; verify_case(3, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"0000",
 "0000",
 "0000",
 "0000",
 "9999",
 "8888",
 "7777",
 "6666",
 "5555",
 "4444",
 "3333",
 "2222",
 "1111",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 16; verify_case(4, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"173642855131893831828253420",
 "126290035950506994475683704",
 "381277675415026563959463393",
 "019782700912864681764582260",
 "496448425114634806770407597",
 "049628433145840178727435051",
 "117194708226266248973780562",
 "398138380998246682323622510",
 "408178777661559971959512111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 135; verify_case(5, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(6, Arg2, cellsVisited(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MountainWalk ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

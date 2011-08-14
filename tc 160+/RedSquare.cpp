#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int board[51][51];
class RedSquare {
	public:
	int countTheEmptyReds(int maxRank, int maxFile, vector <int> rank, vector <int> file) {
		memset(board, 0xff, sizeof board);
		int cur = 0;
		int rowFirst = 0;

		for (int y=1; y<=maxRank; ++y) {
			for (int x=maxFile; x>0; --x) {
				board[y][x] = cur;
				cur = 1-cur;
			}
			cur = 1-rowFirst;
			rowFirst = cur;
		}

		for (int i=0; i<(int)rank.size(); ++i)
			board[rank[i]][file[i]] = 2;

		int sol = 0;
		for (int y=1; y<=maxRank; ++y)
			for (int x=1; x<=maxFile; ++x)
				sol += (board[y][x]==1);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; verify_case(0, Arg4, countTheEmptyReds(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {1,2,3,1,2,3,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,2,2,2,3,3,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, countTheEmptyReds(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1,1,2,2,2,3,3,4,4,4,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,4,1,3,5,2,4,1,3,5,2,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, countTheEmptyReds(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 6; int Arr2[] = {1,1,2,2,2,3,3,4,4,4,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,4,1,3,5,2,4,1,3,5,2,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 15; verify_case(3, Arg4, countTheEmptyReds(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(4, Arg4, countTheEmptyReds(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 50; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1249; verify_case(5, Arg4, countTheEmptyReds(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 50; int Arr2[] = {1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1,1,1,1,1,1,1,
 2,2,2,2,2,2,2,2,2,2,
 3,3,3,3,3,3,3,3,3,3,
 4,4,4,4,4,4,4,4,4,4,
 5,5,5,5,5,5,5,5,5,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1225; verify_case(6, Arg4, countTheEmptyReds(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RedSquare ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

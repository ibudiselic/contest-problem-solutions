#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
char good[2][15] = {
										 { 'X', '0', '0', 'X', '8', 'X', '0', 'X', '0', 'X', 'X', '0', 'X', '0', '0' },
										 { '0', 'X', 'X', '0', '8', '0', 'X', '0', 'X', '0', '0', 'X', '0', 'X', 'X' }
									 };
class Pool {
	public:
	int rackMoves(vector <int> triangle) {
		char rack[15];
		for (int i=0; i<(int)triangle.size(); ++i) {
			if (triangle[i]>8)
				rack[i] = 'X';
			else if (triangle[i]==8)
				rack[i] = '8';
			else
				rack[i] = '0';
		}

		int t[2] = {0};

		for (int i=0; i<15; ++i)
			for (int j=0; j<2; ++j)
				if (good[j][i]!=rack[i])
					++t[j];

		return min((t[0]+1)/2 , (t[1]+1)/2);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6, 12, 14, 1, 8, 2, 11, 3, 9, 4, 7, 13, 5, 15, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, rackMoves(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 10, 7, 1, 8, 12, 6, 11, 4, 9, 13, 3, 14, 15, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, rackMoves(Arg0)); }
	void test_case_2() { int Arr0[] = {8, 15, 9, 4, 10, 6, 11, 3, 14, 7, 2, 1, 13, 12, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, rackMoves(Arg0)); }
	void test_case_3() { int Arr0[] = {15, 5, 8, 13, 2, 14, 10, 3, 4, 6, 7, 9, 1, 12, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, rackMoves(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 5, 15, 6, 10, 9, 11, 13, 7, 4, 3, 8, 2, 12, 14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, rackMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Pool ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

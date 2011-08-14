#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


/*** real code starts here ***/

int dx[] = { -1, -2, -2, -1,  1,  2,  2,  1 };
int dy[] = { -2, -1,  1,  2,  2,  1, -1, -2 };
#define PROB (1.0/8.0)
double prob[8][8][101];

inline bool inbounds(int x, int y) {
	return x>=0&&x<8 && y>=0&&y<8;
}

class ChessKnight {
	public:
	double probability(int x, int y, int n) {
		--x; --y;
		
		for (int i=0; i<8; ++i)
			for (int j=0; j<8; ++j) {
				prob[i][j][0] = 1;
				for (int t=0; t<n; ++t)
					prob[i][j][t+1] = 0;
			}
		for (int t=0; t<n; ++t)
			for (int i=0; i<8; ++i)
				for (int j=0; j<8; ++j)
					for (int k=0; k<8; ++k)
						if (inbounds(i+dx[k], j+dy[k]))
							prob[i][j][t+1] += prob[i+dx[k]][j+dy[k]][t];
		for (int t=0; t<n; ++t)
			prob[x][y][n] /= 8.0;
		return prob[x][y][n];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.1875; verify_case(0, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; double Arg3 = 1.0; verify_case(1, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 10; double Arg3 = 0.0522148497402668; verify_case(2, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 50; double Arg3 = 8.356427906809618E-7; verify_case(3, Arg3, probability(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ChessKnight ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

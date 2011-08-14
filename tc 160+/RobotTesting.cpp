#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> PII;
int grid[1000][1000];
int n;
vector<PII> moves;
bool valid(int i, int j) {
	return i>=0 && i<n && j>=0 && j<n;
}
class RobotTesting {
	public:
	int go(int i, int j) {
		if (grid[i][j] != 0) return grid[i][j];

		grid[i][j] = 50000;
		for (int m=0; m<(int)moves.size(); ++m)
			if (!valid(i+moves[m].first, j+moves[m].second))
				return grid[i][j] = m+1;
		int t = go(i+moves[moves.size()-1].first, j+moves[moves.size()-1].second);
		return grid[i][j] = min(50000, (int)moves.size() + t);
	}
	double estimateCommands(int N, string program) {
		memset(grid, 0, sizeof grid);
		n = N;
		moves.clear();
		PII par(0, 0);
		for (int i=0; i<(int)program.size(); ++i) {
			par.first += (program[i]=='D') - (program[i]=='U');
			par.second += (program[i]=='R') - (program[i]=='L');
			moves.push_back(par);
		}

		double sol = 0.0;
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j) {
				if (grid[i][j] == 0)
					go(i, j);
				sol += (double)grid[i][j]/N/N;
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arg1 = "L"; double Arg2 = 1.5; verify_case(0, Arg2, estimateCommands(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "LURD"; double Arg2 = 12501.0; verify_case(1, Arg2, estimateCommands(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arg1 = "LDLDLDRRR"; double Arg2 = 3.375; verify_case(2, Arg2, estimateCommands(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 29; string Arg1 = "RRULDD"; double Arg2 = 53.236623067776456; verify_case(3, Arg2, estimateCommands(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 697; string Arg1 = "LLLLLDRRRRR"; double Arg2 = 3806.5179340028694; verify_case(4, Arg2, estimateCommands(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RobotTesting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

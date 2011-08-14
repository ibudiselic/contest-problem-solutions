#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
double dp[1<<12];
bool done[1<<12];
int bc[1<<12];
vector< vector<int> > seatMask;
vector<int> P;
int cutOffMask;

double go(int takenSeats) {
	if (done[takenSeats])
		return dp[takenSeats];

	done[takenSeats] = 1;
	dp[takenSeats] = 0.0;

	for (int i=0; i<(int)P.size(); ++i) {
		double prob = double(P[i])/100;
		double contrib = 0.0;
		int cntPossible = 0;
		for (int j=0; j<(int)seatMask[i].size(); ++j) {
			if ((takenSeats & seatMask[i][j])==0 && (seatMask[i][j] & cutOffMask)==seatMask[i][j]) {
				++cntPossible;
				contrib += go(takenSeats | seatMask[i][j]);
			}
		}
		if (cntPossible == 0)
			dp[takenSeats] += prob*bc[takenSeats];
		else
			dp[takenSeats] += prob/cntPossible * contrib;
	}

	return dp[takenSeats];
}

class TableSeating {
	public:
	double getExpected(int numTables, vector <int> probs) {
		cutOffMask = (1<<numTables)-1;
		int cur = 0;
		seatMask.clear();
		for (int i=0; i<(int)probs.size(); ++i) {
			seatMask.push_back(vector<int> ());
			cur = (cur<<1) | 1;
			int x = cur;
			seatMask.back().push_back(x);
			x <<= 1;
			while ((x & cutOffMask) == x) {
				seatMask.back().push_back(x);
				x <<= 1;
			}
		}
		P = probs;
		memset(done, 0, sizeof done);
		bc[0] = 0;
		for (int i=1; i<(1<<12); ++i)
			bc[i] = bc[i>>1] + (i&1);
		return go(0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.0; verify_case(0, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.3333333333333335; verify_case(1, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {0,0,0,0,0,50,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 12; int Arr1[] = {9,9,9,9,9,9,9,9,9,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.871087929710551; verify_case(3, Arg2, getExpected(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TableSeating ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

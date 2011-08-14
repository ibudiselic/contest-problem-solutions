#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int portal[100];
double P[4][100];
double PP[4][100];
void clear(double v[4][100]) {
	for (int i=0; i<4; ++i)
		for (int j=0; j<100; ++j)
			v[i][j] = 0.0;
}
double p[13];
class ChutesAndLadders {
	public:
	vector <double> winningChance(vector <int> startLadder, vector <int> endLadder, vector <int> players) {
		int n = players.size();

		for (int i=0; i<100; ++i)
			portal[i] = i;
		for (int i=0; i<(int)startLadder.size(); ++i)
			portal[startLadder[i]] = endLadder[i];

		clear(P);
		for (int i=0; i<n; ++i)
			P[i][players[i]] = 1.0;

		vector<double> sol(4, 0.0);
		for (int i=0; i<13; ++i)
			p[i] = 0.0;
		for (int i=1; i<=6; ++i)
			for (int j=1; j<=6; ++j)
				p[i+j] += 1.0/36.0;

		double noWin = 1.0;
		for (int cnt=0; cnt<10000; ++cnt) {
			clear(PP);
			for (int i=0; i<n; ++i) {
				for (int pos=0; pos<99; ++pos)
					for (int d=2; d<=12; ++d)
						if (pos+d < 99)
							PP[i][portal[pos+d]] += P[i][pos]*p[d];
						else
							PP[i][99] += P[i][pos]*p[d];

				sol[i] += noWin*PP[i][99];

				noWin *= (1 - PP[i][99]);
				for (int pos=0; pos<99; ++pos)
					P[i][pos] = PP[i][pos]/(1 - PP[i][99]);
			}
		}

		sol.resize(n);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.6063557826968836, 0.3936442173031164 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 7, 23, 42, 58, 87}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {35, 91, 11, 31, 22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.2850398049975441, 0.2591808222220256, 0.23726366951493458, 0.21851570326549555 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.013280440302841312, 0.9867195596971587 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {79, 70, 50, 27,  3,  8, 35, 20, 97, 94, 92, 86, 53, 63, 61, 46, 48, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {98, 90, 66, 83, 13, 30, 43, 41, 77, 74, 72, 23, 52, 59, 18, 25, 10,  5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {21, 32, 56, 41}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.17890364754713348, 0.13868643400691752, 0.5037066355391879, 0.17870328290676118 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, winningChance(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChutesAndLadders ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

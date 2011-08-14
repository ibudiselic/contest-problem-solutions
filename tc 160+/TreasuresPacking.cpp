#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

double a1[10001], a2[10001];
double *novo, *staro;
class TreasuresPacking {
	public:
	double maximizeCost(vector <string> treasures, int W) {
		vector<int> av, aw;
		vector<double> b;

		for (int i=0; i<(int)treasures.size(); ++i) {
			istringstream is(treasures[i]);
			int w, v;
			char c;
			is >> w >> v >> c;
			if (c == 'Y') {
				for (int j=0; j<w; ++j)
					b.push_back(double(v)/w);
			} else {
				av.push_back(v);
				aw.push_back(w);
			}
		}

		for (int i=0; i<=W; ++i)
			a1[i] = a2[i] = 0.0;
		novo = a1;
		staro = a2;

		for (int i=0; i<(int)av.size(); ++i)
			for (int j=W; j>=aw[i]; --j)
				staro[j] = max(staro[j], staro[j-aw[i]] + av[i]);
		for (int i=1; i<=W; ++i)
			if (staro[i] < staro[i-1])
				staro[i] = staro[i-1];

		sort(b.begin(), b.end(), greater<double>());
		for (int i=1; i<=min(W, (int)b.size()); ++i)
			novo[i] = novo[i-1] + b[i-1];

		for (int i=1; i<=W; ++i)
			if (novo[i] < novo[i-1])
				novo[i] = novo[i-1];

		double sol = 0;
		for (int i=0; i<=W; ++i)
			sol = max(sol, novo[i] + staro[W-i]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"100 100 N", "100 100 N", "130 10 Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 150; double Arg2 = 103.84615384615384; verify_case(0, Arg2, maximizeCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"100 100 N", "100 100 N", "100 1000 Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 150; double Arg2 = 1000.0; verify_case(1, Arg2, maximizeCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"207 1459 Y", "150 6867 N", "694 3494 Y", "417 7479 N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 650; double Arg2 = 14931.00966183575; verify_case(2, Arg2, maximizeCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"350 2765 Y", "258 560 Y", "120 9325 N", "879 302 Y",
 "611 2674 Y", "774 2273 Y", "318 1572 Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3301; double Arg2 = 19467.907849829353; verify_case(3, Arg2, maximizeCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TreasuresPacking ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

double prob[51][51];
double sqr(double x) { return x*x; }
class TestScores {
	public:
	double weightedScore(vector <double> questions, int testScore) {
		int n = questions.size();
		for (int i=0; i<51; ++i)
			for (int j=0; j<51; ++j)
				prob[i][j] = 0.0;

		prob[0][0] = 1.0;

		for (int i=1; i<=n; ++i)
			for (int j=0; j<=i; ++j)
				prob[i][j] = (j>0 ? prob[i-1][j-1]*questions[i-1] : 0) + prob[i-1][j]*(1-questions[i-1]);

		double mean = 0.0;
		for (int i=0; i<n; ++i)
			mean += questions[i];

		double v = 0.0;
		for (int i=0; i<=n; ++i)
			v += prob[n][i] * sqr(mean - i);

		v = sqrt(v);

		return 1000.0 + (testScore-mean)/v * 300.0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arr0[] = {0.5, 0.5}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 1000.0; verify_case(0, Arg2, weightedScore(Arg0, Arg1)); }
	void test_case_1() { double Arr0[] = {0.5, 0.5, 0.5}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 1519.6152422706632; verify_case(1, Arg2, weightedScore(Arg0, Arg1)); }
	void test_case_2() { double Arr0[] = {0.2, 0.3, 0.4}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 1806.6323435772447; verify_case(2, Arg2, weightedScore(Arg0, Arg1)); }
	void test_case_3() { double Arr0[] = {0.2, 0.3, 0.4}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = 654.3004241811809; verify_case(3, Arg2, weightedScore(Arg0, Arg1)); }
	void test_case_4() { double Arr0[] = {0.9, 0.9, 0.9, 0.9}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = -800.0; verify_case(4, Arg2, weightedScore(Arg0, Arg1)); }
	void test_case_5() { double Arr0[] = { 0.956062, 0.592855, 0.405804,
  0.484474, 0.633413, 0.219248,
  0.801282, 0.724066, 0.886559,
  0.794041, 0.324220 }; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; double Arg2 = 1037.5680868214772; verify_case(5, Arg2, weightedScore(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TestScores ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

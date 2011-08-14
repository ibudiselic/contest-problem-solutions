#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[50][5];
bool done[50][5];
int R[50][3];
double P[50][3];
int N;
int X;
double go(int pos, int better) {
	if (better >= 5)
		return 0.0;
	if (pos == N)
		return 1.0;
	if (done[pos][better])
		return dp[pos][better];

	done[pos][better] = 1;
	dp[pos][better] = 0.0;

	for (int i=0; i<2; ++i)
		for (int j=0; j<2; ++j)
			for (int k=0; k<2; ++k) {
				int x = i*R[pos][0] + j*R[pos][1] + k*R[pos][2];
				double p = (!i ? (1-P[pos][0]):(P[pos][0])) * (!j ? (1-P[pos][1]):(P[pos][1])) * (!k ? (1-P[pos][2]):(P[pos][2]));

				dp[pos][better] += p*go(pos+1, better + (x>=X));
			}

	return dp[pos][better];
}
class TopFive {
	public:
	double findProbability(vector <string> results, vector <string> accuracies, int points) {
		N = results.size();
		X = points;
		for (int i=0; i<N; ++i) {
			istringstream is(results[i]);
			for (int j=0; j<3; ++j)
				is >> R[i][j];
		}
		for (int i=0; i<N; ++i) {
			istringstream is(accuracies[i]);
			double x;
			for (int j=0; j<3; ++j) {
				is >> x;
				P[i][j] = x/100.0;
			}
		}

		memset(done, 0, sizeof done);
		return go(0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100",
"0 0 50"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; double Arg3 = 0.5; verify_case(0, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; double Arg3 = 0.0; verify_case(1, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"928 209 594", "547 408 596", "190 865 494", "353 392 962", "6 252 267",
 "817 671 562", "631 78 290", "593 292 312", "59 51 286", "553 541 487",
 "466 318 271", "605 892 562", "596 261 63", "865 895 625", "893 479 586",
 "759 596 476", "157 407 819", "509 695 861", "696 730 430", "271 221 0",
 "922 296 640", "999 456 654", "320 550 805", "835 808 711", "9 161 670",
 "82 737 480", "939 12 363"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"84 87 72", "39 60 84", "56 78 48", "0 80 59", "11 69 94",
 "100 53 77", "87 77 55", "0 67 7", "89 63 3", "4 69 99",
"58 9 49", "81 8 84", "81 85 55", "84 68 28", "7 1 46",
"30 50 51", "16 82 8", "60 17 88", "44 30 67", "20 65 65",
"40 75 73", "38 97 20", "82 38 88", "90 78 58", "58 30 66",
 "3 95 50", "76 60 57"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1623; double Arg3 = 0.8657569451352308; verify_case(2, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"600 600 600"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100",
"75 75 75"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 500; double Arg3 = 0.015625; verify_case(3, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"33 33 33",
"33 200 200"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"100 0 0",
"0 0 100",
"0 100 0",
"100 100 100",
"100 100 100",
"33 80 50"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; double Arg3 = 0.10000000000000009; verify_case(4, Arg3, findProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TopFive ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

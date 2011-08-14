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

int w[5];
double predict(const vector<double> &d, int i) {
	double sum = 0.0;
	for (int j=0; j<5; ++j)
		sum += w[j]*d[i-5+j];

	return sum/10;
}
class Predicting {
	public:
	double avgError(vector <double> data) {
		double best = 1e32;

		for (w[0]=-10; w[0]<=10; ++w[0])
			for (w[1]=-10; w[1]<=10; ++w[1])
				for (w[2]=-10; w[2]<=10; ++w[2])
					for (w[3]=-10; w[3]<=10; ++w[3]) {
						w[4] = 10 - (w[0]+w[1]+w[2]+w[3]);
						if (w[4] < -10)
							break;
						if (w[4] > 10)
							continue;

						double sum = 0.0;
						for (int i=5; i<(int)data.size(); ++i)
							sum += fabs(data[i]-predict(data, i));

						if (sum < best+1e-9)
							best = sum;
					}

		return best/(data.size()-5);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arr0[] = {10,10,10,10,10,10}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(0, Arg1, avgError(Arg0)); }
	void test_case_1() { double Arr0[] = {50,10,50,10,50,10,50,10,50,10,50,10}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(1, Arg1, avgError(Arg0)); }
	void test_case_2() { double Arr0[] = {50,60,50,60,50,60,60}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.0; verify_case(2, Arg1, avgError(Arg0)); }
	void test_case_3() { double Arr0[] = {82.9102, 70.6848, 21.503, 61.4588, 54.7789,
 48.9889, 57.6766, 91.1859, 26.3674, 55.4601,
 53.9357, 87.2005, 78.4771, 65.0102, 18.619,
 90.296, 26.3894, 53.8588, 91.8369, 58.8028,
 74.0577, 28.2406, 65.609, 59.4867, 27.7544,
 54.6992, 69.2428, 22.6264, 87.0083, 58.5116,
 60.286, 20.4318, 65.6475, 11.8348, 36.3488,
 92.8092, 60.7392, 98.124, 48.1292, 39.5459,
 52.2657, 34.3519, 38.9279, 93.0152, 11.3157}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 22.0175905; verify_case(3, Arg1, avgError(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Predicting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

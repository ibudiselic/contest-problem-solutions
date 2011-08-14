#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

long long T, D;
int N;
long long Lpos[51], La[51], Lb[51];

/*
In other words, between time 0 (inclusive) and time a (exclusive), the light is red, between time a (inclusive) and time a+b (exclusive),
it is green, between time a+b (inclusive) to 2*a+b (exclusive), it is red again
*/

bool ok(double speed) {
	double t = 0.0;

	for (int pos=1; pos<N; ++pos) {
		// at Lpos[pos-1]+eps at time t
		t += (Lpos[pos]-Lpos[pos-1])/speed;
		// at Lpos[pos]-eps at time t
		long long tt = (long long)t;

		if (tt%(La[pos]+Lb[pos]) < La[pos])
			t = tt/(La[pos]+Lb[pos]) * (La[pos]+Lb[pos]) + La[pos];
	}
	t += (D-Lpos[N-1])/speed;

	return t<=T+1e-10;
}

class SafeDrive {
	public:
	double minSpeed(vector <string> lights, int T_, int D_) {
		N = lights.size()+1;
		T = T_;
		D = D_;

		memset(Lpos, 0, sizeof Lpos);
		memset(La, 0, sizeof La);
		memset(Lb, 0, sizeof Lb);

		long long startTime = 0;

		N = 1;
		for (int i=0; i<(int)lights.size(); ++i) {
			istringstream is(lights[i]);

			is >> La[N] >> Lb[N] >> Lpos[N];
			if (Lpos[N]==0)
				startTime = La[N];
			else
				++N;
		}

		for (int i=1; i<N-1; ++i)
			for (int j=i+1; j<N; ++j)
				if (Lpos[i] > Lpos[j]) {
					swap(Lpos[i], Lpos[j]);
					swap(La[i], La[j]);
					swap(Lb[i], Lb[j]);
				}

		while (Lpos[N-1] > D)
			--N;

		double lo = 1e-10;
		double hi = 1e10;

		T -= startTime;

		int cnt = 100;
		while (cnt--) {
			double mid = (lo+hi)/2;
			if (ok(mid))
				hi = mid;
			else
				lo = mid;
		}

		return hi>9e9 ? -1 : hi;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 4 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 10; double Arg3 = 1.0; verify_case(0, Arg3, minSpeed(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"3 4 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 10; double Arg3 = 1.0; verify_case(1, Arg3, minSpeed(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"2 3 2", "3 2 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 16; double Arg3 = 1.7500000000000004; verify_case(2, Arg3, minSpeed(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1 2 3", "2 2 5", "3 3 7", "1 6 9", "3 4 11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 13; double Arg3 = 1.25; verify_case(3, Arg3, minSpeed(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"2 2 6", "4 5 3", "3 2 8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 10; double Arg3 = -1.0; verify_case(4, Arg3, minSpeed(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"99 190 2723", "239 138 6411", "262 235 2509", "62 60 6494",
 "16 70 4938", "70 59 4701", "172 165 5118", "16 256 7816",
 "31 40 213", "189 183 1955", "186 11 4485", "175 281 9816",
 "152 242 8116", "180 11 5899", "274 189 3978"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 695; int Arg2 = 5323; double Arg3 = 9.728682170542637; verify_case(5, Arg3, minSpeed(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SafeDrive ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

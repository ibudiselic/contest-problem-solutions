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

class Musical {
	public:
	string loser(int n, double time) {
		vector<double> pos(n, 0.0);
		double space = double(n-1)/n;

		for (int i=0; i<n; ++i) {
			double t = i*space + 11*(n-1) - time/10 * (n-1);
			pos[i] = int(t)%(n-1) + (t-(int)t);
		}

		vector<bool> usedi(n-1, 0);
		vector<bool> usedj(n, 0);
		for (int k=0; k<n-1; ++k) {
			double D = 1e32;
			int bestI = -1;
			int bestJ = -1;
			for (int i=0; i<n-1; ++i)
				if (!usedi[i]) {
					double bestD = 1e32;
					int cInd = -1;
					for (int j=0; j<n; ++j)
						if (!usedj[j]) {
							double t = min(fabs(pos[j]-i), fabs(i+n-1-pos[j]));
							if (t < bestD) {
								bestD = t;
								cInd = j;
							}
						}
					if (bestD < D) {
						D = bestD;
						bestI = i;
						bestJ = cInd;
					}
				}
			usedi[bestI] = 1;
			usedj[bestJ] = 1;
		}


		for (int i=0; i<n; ++i)
			if (!usedj[i])
				return string(1, char(i+'A'));

		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; double Arg1 = 1.2; string Arg2 = "B"; verify_case(0, Arg2, loser(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; double Arg1 = 12.0; string Arg2 = "A"; verify_case(1, Arg2, loser(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 26; double Arg1 = 100.0; string Arg2 = "N"; verify_case(2, Arg2, loser(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; double Arg1 = 15.0; string Arg2 = "A"; verify_case(3, Arg2, loser(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Musical ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

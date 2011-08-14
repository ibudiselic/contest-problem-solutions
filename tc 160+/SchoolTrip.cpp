#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double sol[6][1<<6];
int bc[1<<6];
class SchoolTrip {
	public:
	double duration(vector <int> p) {
		int n = p.size();
		int mask = (1<<n)-1;
		for (int i=0; i<n; ++i) {
			for (int m=0; m<=mask; ++m) {
				sol[i][m] = 1e20;
			}
		}

		vector<double> P(n, 0.0);
		for (int i=0; i<n; ++i) {
			P[i] = p[i]/100.0;
		}
		for (int i=0; i<n; ++i) {
			sol[0][1<<i] = 0.0;
		}

		bc[0] = 0;
		for (int m=1; m<=mask; ++m) {
			bc[m] = bc[m>>1] + (m&1);
		}

		for (int rep=0; rep<100000; ++rep) {
			for (int m=3; m<=mask; ++m) {
				int sz = bc[m];
				if (sz == 2) {
					for (int i=0; i<n; ++i) {
						if (m & (1<<i)) {
							for (int j=i+1; j<n; ++j) {
								if (m & (1<<j)) {
									sol[0][m] = (1-P[i])*sol[1][m] + 1;
									sol[1][m] = (1-P[j])*sol[0][m] + 1;
									break;
								}
							}
							break;
						}
					}
				} else if (sz > 2) {
					int a = 0;
					for (int i=0; i<n; ++i) {
						if (m & (1<<i)) {
							double E = 1e32;
							for (int j=0; j<n; ++j) {
								if (i!=j && (m&(1<<j))) {
									E = min(E, sol[j<i ? a%(sz-1) : (a+1)%(sz-1)][m ^ (1<<j)]);
								}
							}

							sol[a][m] = P[i]*E + (1-P[i])*sol[(a+1)%sz][m] + 1;
							++a;
						}
					}
					assert(a == sz);
				}
			}
		}

		return sol[0][mask];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, duration(Arg0)); }
	void test_case_1() { int Arr0[] = {50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.0; verify_case(1, Arg1, duration(Arg0)); }
	void test_case_2() { int Arr0[] = {25,50,75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.892383478590375; verify_case(2, Arg1, duration(Arg0)); }
	void test_case_3() { int Arr0[] = {100,100,100,42,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(3, Arg1, duration(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SchoolTrip ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

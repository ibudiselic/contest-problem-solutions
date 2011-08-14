#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class RoadConstruction {
	public:
	int getExitTime(vector <string> A) {
		int n = A.size();
		int sol = 0;
		vector<bool> y(n, false);

		while (1) {
			for (int i=0; i<n; ++i) {
				if (A[i].size()>0 && y[i]) {
					if (A[i][0] == 'D') {
						return sol;
					}
					A[i] = A[i].substr(1);
					y[i] = false;
					++sol;
					break;
				}

				if (!y[i]) {
					bool has_next = false;
					for (int j=i+1; j<n; ++j) {
						if (A[j].size() > 0) {
							has_next = true;
							break;
						}
					}
					if (has_next) {
						y[i] = true;
					} else {
						if (A[i][0] == 'D') {
							return sol;
						}
						A[i] = A[i].substr(1);
						y[i] = false;
						++sol;
						break;
					}
				}
			}
		}

		return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AB",
 "CD",
 "E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getExitTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"AH",
 "D",
 "BCG",
 "E",
 "F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getExitTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAA",
 "A",
 "AAA",
 "A",
 "AAD",
 "A",
 "AAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, getExitTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"DEFGHIJK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, getExitTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"I",
 "WANT",
 "TO",
 "DRINK",
 "SOME",
 "COFFEE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, getExitTime(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RoadConstruction ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

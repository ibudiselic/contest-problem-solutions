#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class StreetParking {
	public:
	int freeParks(string street) {
		vector<bool> t(street.size(), true);
		for (int i=0; i<(int)street.size(); ++i) {
			switch (street[i]) {
				case 'D':
					t[i] = false;
					break;
				case 'B':
					t[i] = false;
					if (i-1 >= 0) {
						t[i-1] = false;
					}
					if (i-2 >= 0) {
						t[i-2] = false;
					}
					break;
				case 'S':
					t[i] = false;
					if (i-1 >= 0) {
						t[i-1] = false;
					}
					if (i+1 < (int)street.size()) {
						t[i+1] = false;
					}
					break;
			}
		}
		int sol = 0;
		for (int i=0; i<(int)t.size(); ++i)
			sol += t[i];
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "---B--S-D--S--"; int Arg1 = 4; verify_case(0, Arg1, freeParks(Arg0)); }
	void test_case_1() { string Arg0 = "DDBDDBDDBDD"; int Arg1 = 0; verify_case(1, Arg1, freeParks(Arg0)); }
	void test_case_2() { string Arg0 = "--S--S--S--S--"; int Arg1 = 2; verify_case(2, Arg1, freeParks(Arg0)); }
	void test_case_3() { string Arg0 = "SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D"; int Arg1 = 14; verify_case(3, Arg1, freeParks(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StreetParking ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

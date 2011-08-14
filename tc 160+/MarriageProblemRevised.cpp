#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int M[1<<12], F[1<<12];
int bc[1<<12];
class MarriageProblemRevised {
	public:
	int neededMarriages(vector <string> pref) {
		int m = pref.size();
		int f = pref[0].size();

		for (int i=0; i<m; ++i)
			if (pref[i] == string(f, '0'))
				return -1;
		for (int j=0; j<f; ++j) {
			bool ok = false;
			for (int i=0; i<m; ++i)
				if (pref[i][j] == '1') {
					ok = true;
					break;
				}
			if (!ok)
				return -1;
		}

		for (int i=0; i<m; ++i) {
			M[1<<i] = 0;
			for (int j=0; j<f; ++j)
				if (pref[i][j] == '1')
					M[1<<i] |= (1<<j);
		}
		for (int j=0; j<f; ++j) {
			F[1<<j] = 0;
			for (int i=0; i<m; ++i)
				if (pref[i][j] == '1')
					F[1<<j] |= (1<<i);
		}

		bc[0] = 0;
		for (int i=0; i<(1<<12); ++i)
			bc[i] = bc[i>>1] + (i&1);

		for (int mask=0; mask<(1<<m); ++mask)
			if (bc[mask] > 1) {
				M[mask] = 0;
				for (int i=0; i<m; ++i)
					if (mask & (1<<i))
						M[mask] |= M[1<<i];
			}
		for (int mask=0; mask<(1<<f); ++mask)
			if (bc[mask] > 1) {
				F[mask] = 0;
				for (int j=0; j<f; ++j)
					if (mask & (1<<j))
						F[mask] |= F[1<<j];
			}

		int sol = 1234567890;
		for (int i=0; i<(1<<m); ++i) {
			if (bc[i]<sol && (i==0 || M[i]!=0))
				for (int j=0; j<(1<<f); ++j)
					if (bc[i]+bc[j]<sol && (j==0 || F[j]!=0))
						if ((M[i]|j) == ((1<<f)-1) && (F[j]|i) == ((1<<m)-1) && (bc[M[i]] >= bc[M[i] ^ (M[i]&j)]) && (bc[F[j]] >= bc[F[j] ^ (F[j]&i)]))
							sol = bc[i]+bc[j];
		}

		return sol>min(m, f) ? -1 : sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, neededMarriages(Arg0)); }
	void test_case_1() { string Arr0[] = {"100", "010", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, neededMarriages(Arg0)); }
	void test_case_2() { string Arr0[] = {"00", "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, neededMarriages(Arg0)); }
	void test_case_3() { string Arr0[] = {"0001", "0001", "0001", "1111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, neededMarriages(Arg0)); }
	void test_case_4() { string Arr0[] = {"11101011","00011110","11100100","01010000","01000010","10100011","01110110","10111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, neededMarriages(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MarriageProblemRevised ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

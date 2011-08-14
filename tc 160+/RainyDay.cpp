#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cur[50], next[50];
int SZ;
long long rot(long long x) {
	return (x>>1) | ((x&1)<<(SZ-1));
}
class RainyDay {
	public:
	int minimumRainTime(string P, string F) {
		SZ = F.size();
		long long f = 0;
		for (int i=0; i<(int)F.size(); ++i) {
			if (F[i] == 'R') {
				f |= (1LL<<i);
			}
		}

		memset(cur, 0x3f, sizeof cur);
		for (int i=0; i<(int)P.size(); ++i) {
			if (P[i] == 'Y') {
				P[i] = 'C';
				cur[i] = 0;
				break;
			}
		}

		int sol = 1234567890;
		int cnt = 0;
		while (cnt < 250000) {
			++cnt;
			long long nf = rot(f);
			memset(next, 0x3f, sizeof next);
			for (int i=0; i<(int)P.size(); ++i) {
				if (P[i] == 'H') {
					sol = min(sol, cur[i]);
				} 
				for (int j=i-1; j<i+2; ++j) {
					if (j<0 || j>=(int)P.size()) {
						continue;
					}
					next[j] = min((long long)next[j], cur[i] + (P[j]=='.' ? ((f>>i)&1) + ((nf>>i)&1) : 0));
				}
			}
			f = nf;
			memcpy(cur, next, sizeof cur);
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Y..H"; string Arg1 = "R.RR"; int Arg2 = 3; verify_case(0, Arg2, minimumRainTime(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "Y.C.H"; string Arg1 = "RRRR."; int Arg2 = 2; verify_case(1, Arg2, minimumRainTime(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "Y..C.H"; string Arg1 = "RRR.R."; int Arg2 = 3; verify_case(2, Arg2, minimumRainTime(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CCH..Y"; string Arg1 = "RRRR.R"; int Arg2 = 2; verify_case(3, Arg2, minimumRainTime(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "CCH.........Y"; string Arg1 = "............."; int Arg2 = 0; verify_case(4, Arg2, minimumRainTime(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RainyDay ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

int m, n;
int pos(int i, int j) {
	return i*n + j;
}

typedef vector< vector<long long> > VL;
VL matmul(const VL &A, const VL &B) {
	VL ret(A.size(), vector<long long> (A.size(), 0));
	for (int i=0; i<(int)A.size(); ++i) {
		for (int j=0; j<(int)A.size(); ++j) {
			for (int k=0; k<(int)A.size(); ++k) {
				ret[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	return ret;
}
VL matexp(VL A, int n) {
	VL ret(A.size(), vector<long long> (A.size(), 0));
	for (int i=0; i<(int)A.size(); ++i) {
		ret[i][i] = 1;
	}

	while (n > 0) {
		if (n & 1) {
			ret = matmul(A, ret);
		}
		A = matmul(A, A);
		n >>= 1;
	}

	return ret;
}
class MarbleMachine {
	public:
	long long maxMarbles(vector <string> layout, vector <string> actions, int t) {
		m = layout.size();
		n = layout[0].size();

		int len = 60;

		int sz = m*n + 1;

		vector<VL> S;

		for (int s=0; s<len; ++s) {
			VL v(sz, vector<long long>(sz, 0));
			for (int i=0; i<m; ++i) {
				for (int j=0; j<n; ++j) {
					int a = layout[i][j]-'0';
					char act = actions[a][s%actions[a].size()];
					int t = pos(i, j);

					if (isdigit(act)) {
						v[t][t] = 1;
						v[t][sz-1] += act-'0';
					} else if (act == 'N') {
						if (i > 0) {
							int u = pos(i-1, j);
							v[u][t] = 1;
						}
					} else if (act == 'S') {
						if (i+1 < m) {
							int u = pos(i+1, j);
							v[u][t] = 1;
						}
					} else if (act == 'W') {
						if (j > 0) {
							int u = pos(i, j-1);
							v[u][t] = 1;
						}
					} else if (act == 'E') {
						if (j+1 < n) {
							int u = pos(i, j+1);
							v[u][t] = 1;
						}
					}
				}
			}

			v[sz-1][sz-1] = 1;
			S.push_back(v);
		}

		VL v(sz, vector<long long>(sz, 0));
		for (int i=0; i<sz; ++i) {
			v[i][i] = 1;
		}

		for (int i=0; i<60; ++i) {
			v = matmul(S[i], v);
		}

		VL sol = matexp(v, t/60);

		for (int i=0; i<t%60; ++i) {
			sol = matmul(S[i], sol);
		}

		long long retval = 0;
		for (int i=0; i<sz-1; ++i) {
			retval = max(retval, sol[i][sz-1]);
		}

		return retval;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"0101",
"1010",
"0101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4","5353"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; long long Arg3 = 21LL; verify_case(0, Arg3, maxMarbles(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"011112"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1E","E","0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; long long Arg3 = 498LL; verify_case(1, Arg3, maxMarbles(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {
"01",
"32"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1E","SSDSS","W","00000W"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; long long Arg3 = 3LL; verify_case(2, Arg3, maxMarbles(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MarbleMachine ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

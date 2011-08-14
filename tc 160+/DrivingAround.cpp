#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
int mod = 1000003;

vector< vector<int> > matMul(const vector< vector<int> > &A, const vector< vector<int> > &B) { // A*B
	const int m = A.size();
	const int n = B[0].size();
	vector< vector<int> > ret(n, vector<int> (m, 0));

	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			for (int k=0; k<(int)B.size(); ++k)
				ret[i][j] = (ret[i][j] + ((long long)A[i][k]*B[k][j])%mod)%mod;

	return ret;
}

vector< vector<int> > fastMatExp(vector< vector<int> > A, int k) { // A^k in O(|A|^3 * log k)
	const int n = A.size();
	vector< vector<int> > ret(n, vector<int>(n, 0));
	for (int i=0; i<n; ++i)
		ret[i][i] = 1;

	while (k > 0) {
		if (k & 1)
			ret = matMul(ret, A);

		A = matMul(A, A);
		k >>= 1;
	}

	return ret;
}

class DrivingAround {
	public:
	int numberOfWays(vector <string> adj, int start, int finish, int time) {
		N = adj.size();
		vector< vector<int> > M(5*N, vector<int> (5*N, 0));

		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				if (adj[i][j] != '.') {
					if (adj[i][j] == '1')
						M[i][j] = 1;
					else
						M[i][N+j*4+adj[i][j]-'2'] = 1;
				}

		for (int i=0; i<N; ++i) {
			M[N+i*4][i] = 1;
			for (int j=0; j<3; ++j)
				M[N+i*4+j+1][N+i*4+j] = 1;
		}

		return fastMatExp(M, time)[start][finish];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".12",
 "2.1",
 "12."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; int Arg3 = 5; int Arg4 = 8; verify_case(0, Arg4, numberOfWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"....52....",
 "..5.......",
 "..........",
 ".......1..",
 "......42.2",
 "5...4.....",
 ".5...4...1",
 "......5...",
 ".3244.....",
 ".........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 10; int Arg4 = 0; verify_case(1, Arg4, numberOfWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"...14....1",
 "......13..",
 ".2...4....",
 "....52.5..",
 "1.3..4....",
 ".3....35.5",
 "4......1.1",
 "..4.4.1.54",
 "....4.11.5",
 "31144.2.4."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 2; int Arg3 = 100; int Arg4 = 316984; verify_case(2, Arg4, numberOfWays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DrivingAround ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

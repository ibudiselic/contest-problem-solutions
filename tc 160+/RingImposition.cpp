#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<int> > matMul(const vector< vector<int> > &A, const vector< vector<int> > &B) {
	int m = A.size();
	int n = B[0].size();
	int o = B.size();

	vector< vector<int> > C(m, vector<int>(n, 0));
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j) {
			for (int k=0; k<o; ++k)
				C[i][j] += A[i][k]*B[k][j];
			C[i][j] %= 100;
		}

	return C;
}
void matAdd(vector< vector<int> > &A, const vector< vector<int> > &B) {
	int m = A.size();
	int n = A[0].size();
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			A[i][j] = (A[i][j] + B[i][j])%100;
}

vector< vector<int> > matExp(vector< vector<int> > A, int k) {
	int n = A.size();
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

class RingImposition {
	public:
	vector <int> predict(vector <int> seq, int N) {
		int n = seq.size();

		vector< vector<int> > A(n, vector<int>(n, 0));

		for (int i=0; i+1<n; ++i)
			A[i][i] = A[i][i+1] = 1;
		A[n-1][0] = A[n-1][n-1] = 1;

		A = matExp(A, N);

		vector< vector<int> > v(n, vector<int>(1, 0));
		for (int i=0; i<n; ++i)
			v[i][0] = seq[i];

		v = matMul(A, v);

		for (int i=0; i<n; ++i)
			seq[i] = v[i][0];

		return seq;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {8, 9, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, predict(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {25, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arr2[] = {0, 0, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, predict(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3, 15, 7, 1, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = {41, 50, 84, 97, 72 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, predict(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 15, 7, 1, 16, 1, 72}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 192347; int Arr2[] = {88, 72, 62, 55, 11, 11, 21 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, predict(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RingImposition ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> sol;
int M[5][5];
int Y[5];
int N;

bool test() {
	for (int i=0; i<N; ++i) {
		Y[i] = 0;
		for (int k=0; k<N; ++k)
			Y[i] += M[i][k]*sol[k];
	}

	int k = 12345;
	for (int i=0; i<N; ++i)
		if (sol[i] != 0) {
			if (Y[i]==0 || Y[i]%sol[i]!=0)
				return false;
			k = Y[i]/sol[i];
		}
	for (int i=0; i<N; ++i)
		if (Y[i] != k*sol[i])
			return false;

	return true;
}
bool go(int pos, int L1, bool hasNonZero) {
	if (pos == N) {
		if (!hasNonZero)
			return false; // nul-vector
		return test();
	}

	for (sol[pos] = (hasNonZero ? -L1 : 0); sol[pos]<=L1; ++sol[pos])
		if (go(pos+1, L1-abs(sol[pos]), hasNonZero||(sol[pos]!=0)))
			return true;

	return false;
}
class EigenVector {
	public:
	vector <int> findEigenVector(vector <string> A) {
		N = A.size();
		sol.assign(N, 0);
		for (int i=0; i<N; ++i) {
			istringstream is(A[i]);
			for (int j=0; j<N; ++j)
				is >> M[i][j];
		}

		go(0, 9, 0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1 0 0 0 0",
 "0 1 0 0 0",
 "0 0 1 0 0",
 "0 0 0 1 0",
 "0 0 0 0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  0,  0,  0,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findEigenVector(Arg0)); }
	void test_case_1() { string Arr0[] = {"100 0 0 0",
 "0 200 0 0",
 "0 0 333 0",
 "0 0 0 42"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  0,  0,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findEigenVector(Arg0)); }
	void test_case_2() { string Arr0[] = {"10 -10 -10 10",
 "20 40 -10 -10",
 "10 -10 10 20",
 "10 10 20 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  -5,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findEigenVector(Arg0)); }
	void test_case_3() { string Arr0[] = {"30 20","87 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findEigenVector(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EigenVector ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
a1 = 1   and   ak = (m * ak-1 + c) % (231 - 1)
*/
int A[100001];
int B[100001];

long long mergeSort(int l, int r) {
	if (l+1 >= r)
		return 0;

	int mid = (l+r)/2;

	long long ret = mergeSort(l, mid);
	ret += mergeSort(mid, r);

	int i=l, j=mid, k=l;

	while (i<mid && j<r) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		} else {
			ret += mid-i;
			B[k++] = A[j++];
		}
	}
	while (i < mid)
		B[k++] = A[i++];
	while (j < r)
		B[k++] = A[j++];

	memcpy(A+l, B+l, (r-l) * sizeof A[0]);

	return ret;
}

class HowUnsorted {
	public:
	long long howMany(int m, int c, int n) {
		long long a = 1;
		A[0] = 1;

		for (int i=1; i<n; ++i) {
			a = (m*a + c)%((1LL<<31) - 1);
			A[i] = a;
		}

		return mergeSort(0, n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 5; long long Arg3 = 0LL; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1000; int Arg1 = 100; int Arg2 = 6; long long Arg3 = 3LL; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1234257123; int Arg1 = 123; int Arg2 = 1500; long long Arg3 = 558406LL; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HowUnsorted ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

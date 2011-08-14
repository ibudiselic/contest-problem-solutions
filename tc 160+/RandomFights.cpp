#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// timeout... valjda treba koristiti lower_bound umjesto rucno napravljenog bs-a, nedamise prepravljati

vector<int> input_reformat(vector<int> &v, int n) {
	int j = 0;
	int m = v.size();
	vector<int> ret(n, 0);
	for (int i=0; i<n; ++i) {
		ret[i] = v[j];
		int s = (j+1)%m;
		v[j] = ((v[j]^v[s])+13)%49999;
		j = s;
	}

	return ret;
}
long long Ysqr[50000], Y[50000];
inline long long sqr(long long x) {
	return x*x;
}
int bs(const vector<int> &v, int x) {
	// find the index of the smallest element of 'v' greater then 'x'
	// special case 1: 'x' is no greater than any element in 'v'
	if (x <= v[0])
		return -1;
	// special case 2: 'x' is greater then all the elements in 'v'
	if (v.back() <= x)
		return v.size();

	int lo=0, hi=v.size()-1;

	while (lo < hi) {
		int mid = lo + (hi-lo)/2;
		if (v[mid] > x)
			hi = mid;
		else
			lo = lo+1;
	}

	return lo;
}
class RandomFights {
	public:
	double expectedNrOfPoints(vector <int> A, vector <int> B, int n) {
		A = input_reformat(A, n);
		B = input_reformat(B, n);

		sort(B.begin(), B.end());
		Ysqr[0] = sqr(B[0]);
		Y[0] = B[0];
		for (int i=1; i<n; ++i) {
			Y[i] = Y[i-1] + B[i];
			Ysqr[i] = Ysqr[i-1] + sqr(B[i]);
		}

		long long sol = 0;
		for (int i=0; i<n; ++i) {
			int split = bs(B, A[i]);
			const long long x = sqr(A[i]);
			if (split == -1)
				sol += -n*x + 2*A[i]*Y[n-1] - Ysqr[n-1];
			else if (split == n)
				sol += n*x - 2*A[i]*Y[n-1] + Ysqr[n-1];
			else
				sol += split*x - 2*A[i]*Y[split-1] + Ysqr[split-1] - (n-split)*x + 2*A[i]*(Y[n-1]-Y[split-1]) - (Ysqr[n-1]-Ysqr[split-1]);
		}

		return double(sol)/n;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; double Arg3 = 4.0; verify_case(0, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 0.0; verify_case(1, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {3,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 20.0; verify_case(2, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {45,35,236,2342,5543,21,32,2,6,23,24,23,41,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2345,45,2345,345}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; double Arg3 = 1.2721986164E8; verify_case(3, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {34,3245,2534,53,53,46,346,246,346,2,624,624,6,245,6324,6542,624,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {345,234,523,4624,6,2456,345,634,634,7,3457,376,34,6234,62,523,52,35,32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = -9713701.714285715; verify_case(4, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50000; double Arg3 = 0.0; verify_case(5, Arg3, expectedNrOfPoints(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RandomFights ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

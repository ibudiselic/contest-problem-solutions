#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<long long> A, B;

long long calc(int x, int n) {
	long long s = B[x];
	long long e = A[x+n];

	return e-s;
}

class CommercialPlanner {
	public:
	int bestMinute(vector <int> S, vector <int> D, int x, int day, int n) {
		if (S.size() == 0) {
			return 0;
		}

		for (int i=0; i<(int)S.size(); ++i) {
			for (int j=i+1; j<(int)S.size(); ++j) {
				if (S[i] > S[j]) {
					swap(S[i], S[j]);
					swap(D[i], D[j]);
				}
			}
		}

		A.clear();
		B.clear();
		for (long long k=-2; k<=2; ++k) {
			for (int i=0; i<(int)S.size(); ++i) {
				A.push_back(S[i] + k*day);
				B.push_back((long long)S[i] + D[i] + k*day);
			}
		}

		int sol = -1;
		long long val = 0;
		for (int i=2*(int)S.size() - 1; i<3*(int)S.size(); ++i) {
			long long d = A[i+1] - max(0LL, B[i]);
			if (d >= x) {
				cerr << A[i] << ' ' << B[i] << ' ' << d << '\n';
				if (n>(int)S.size() && B[i]>=0) {
					return min(sol!=-1 ? sol : day+1, (int)B[i]);
				}
				long long t = calc(i, n) - (B[i]<0 ? -B[i] : 0);
				cerr << t << '\n';
				if (sol==-1 || t>val) {
					val = t;
					sol = max(0LL, B[i]);
				}
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {30, 5, 17, 45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12, 6, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 50; int Arg4 = 5; int Arg5 = 11; verify_case(0, Arg5, bestMinute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {30, 5, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12, 6, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 63; int Arg3 = 100; int Arg4 = 4; int Arg5 = 42; verify_case(1, Arg5, bestMinute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {30, 5, 51, 17, 49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12, 6, 10, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 60; int Arg4 = 2; int Arg5 = 20; verify_case(2, Arg5, bestMinute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {30, 5, 51, 17, 49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12, 6, 10, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 64; int Arg3 = 100; int Arg4 = 4; int Arg5 = -1; verify_case(3, Arg5, bestMinute(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CommercialPlanner ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

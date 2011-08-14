#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

void gen(vector<int> &X, vector<int> &Y, vector<int> &A) {
	int lX = X.size();
	int lY = Y.size();
	for (int i=0; i<(int)A.size(); ++i) {
		int p = i%lX;
		int q = (i + Y[i%lY])%lX;
		A[i] = X[p];
		X[p] = X[q];
		X[q] = A[i];
	}
}

vector<long long> F;
bool test(long long r, const vector<int> &A, long long target) {
	assert(target/r * r == target);

	for (int i=(int)A.size()-1; i>=0; --i) {
		target -= A[i];
		if (target/r * r != target) {
			return false;
		}
		target = target/r;
	}

	return (target==0);
}
class SolvePolynomial {
	public:
	vector <int> integerRoots(vector <int> X, vector <int> Y, int n) {
		vector<int> A(n+1, 0);
		gen(X, Y, A);

		while (A.size()>0 && A.back()==0) {
			A.pop_back();
		}
		if (A.size() == 0) {
			return vector<int> (1, 0);
		}

		reverse(A.begin(), A.end());
		vector<int> sol;
		if (A.back() == 0) {
			sol.push_back(0);
		}
		while (A.size()>0 && A.back()==0) {
			A.pop_back();
		}

		if (A.size() > 0) {
			F.assign(n, 0);
			int last = abs(A.back());
			for (int d=1; d<=last/d; ++d) {
				if (last%d == 0) {
					if (test(-d, A, 0)) {
						sol.push_back(-d);
					}
					if (test(d, A, 0)) {
						sol.push_back(d);
					}
					if (d*d < last) {
						if (test(-last/d, A, 0)) {
							sol.push_back(-last/d);
						}
						if (test(last/d, A, 0)) {
							sol.push_back(last/d);
						}
					}
				}
			}
		}

		sort(sol.begin(), sol.end());
		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {-4, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = {-2, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {-15, -10, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arr3[] = {3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {735134400, 1383, 4121, 18875, 10463, 
 13512, 19603, 28679, 13483, 9509, 1701,
 13383, 24425, 7923, 7978, 21702, 30989,
 20676, 18547, 28130, 10944}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {34,23,6,5,3,5,4,34,37,5,6,21,17,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, integerRoots(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SolvePolynomial ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

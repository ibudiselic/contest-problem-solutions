#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool isPrime(int x) {
	if (x <= 1)
		return false;
	if ((x&1) == 0)
		return (x==2);
	for (int d=3; d*d<=x; d+=2)
		if (x%d == 0)
			return false;

	return true;
}
int sqrNorm(int real, int imag) {
	return real*real + imag*imag;
}
/*
if |z|2 = 0, then z is a complex zero.
if |z|2 = 1, then z is a complex unit.
if |z|2 > 1 , and p is any prime number that also satisfies p % 4 = 3
if a (or b) is zero and b (or a) is equal to some p or -p, then z is a complex prime.
if a (or b) is zero and b (or a) is not equal to any p or -p, then z is a complex composite.
if a and b are both non-zero and |z|2 is a prime number then z is a complex prime.
if a and b are both non-zero and |z|2 is a composite number then z is a complex composite .
*/
bool f(int x) {
	x = abs(x);

	if (x%4 != 3)
		return false;

	return isPrime(x);
}
class ComplexIntegers {
	public:
	vector <string> classify(vector <int> realPart, vector <int> imaginaryPart) {
		vector<string> sol;

		for (int i=0; i<(int)realPart.size(); ++i) {
			const int z2 = sqrNorm(realPart[i], imaginaryPart[i]);
			if (z2 == 0) {
				sol.push_back("zero");
			} else if (z2 == 1) {
				sol.push_back("unit");
			} else if (z2 > 1) {
				if (realPart[i]==0 && f(imaginaryPart[i]) || imaginaryPart[i]==0 && f(realPart[i])) {
					sol.push_back("prime");
				} else if (realPart[i]!=0 && imaginaryPart[i]!=0) {
					if (isPrime(z2))
						sol.push_back("prime");
					else
						sol.push_back("composite");
				} else {
					sol.push_back("composite");
				}
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { 0,     1,       0,     1,       -1,      2,           0,       0,          -3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,     0,      -1,     1,        1,      0,          -3,       5,          -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "zero",  "unit",  "unit",  "prime",  "prime",  "composite",  "prime",  "composite",  "prime" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, classify(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "composite",  "prime",  "composite",  "prime",  "prime",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "prime",  "prime",  "composite",  "prime",  "composite" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, classify(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,0,0,0,0,0,-19,23,29,31,37,-41}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15,2,-3,5,-7,11,-13,17,0,0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "composite",  "composite",  "prime",  "composite",  "prime",  "prime",  "composite",  "composite",  "zero",  "prime",  "prime",  "composite",  "prime",  "composite",  "composite" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, classify(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {99,-39,0,0,97,1003,9998,1119}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,35,-129,-2,-232,9997,1120}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "composite",  "composite",  "composite",  "composite",  "prime",  "prime",  "prime",  "prime" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, classify(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,  0,0,1,-1,   1,1,-1,-1,   2,-2,0,0,  1,1,2,2,-1,-1,-2,-2,
     3,-3,0,0,   1,1,3,3,-1,-1,-3,-3,    2,2,-2,-2,  0,0,4,-4,
                 1,1,4,4,-1,-1,-4,-4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,  1,-1,0,0,   1,-1,1,-1,   0,0,2,-2,  2,-2,1,-1,2,-2,1,-1,
     0,0,-3,3,   3,-3,1,-1,3,-3,1,-1,     2,-2,2,-2,  4,-4,0,0,
                 4,-4,1,-1,4,-4,1,-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "zero",  "unit",  "unit",  "unit",  "unit",  "prime",  "prime",  "prime",  "prime",  "composite",  "composite",  "composite",  "composite",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "composite",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime",  "prime" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, classify(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ComplexIntegers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long gcd(long long m, long long n) {
    return m==0 ? n : gcd(n%m, m);
}
long long inf = (1LL<<63) - 1;
long long lcm(long long m, long long n) {
    long long t = m / gcd(m, n);

    if (t <= inf/n) {
        return t*n;
    } else {
        return inf;
    }
}

int num_divs(long long G) {
    int ret = 1 + (G>1);
    for (int d=2; d<=G/d; ++d) {
        if (G%d == 0) {
            ret += 1 + (G/d != d);
        }
    }

    return ret;
}
class FactoVisors {
	public:
	int getNum(vector <int> divisors, vector <int> multiples) {
		long long L = divisors[0];
        for (int i=1; i<(int)divisors.size(); ++i) {
            L = lcm(L, divisors[i]);
            if (L == inf) {
                return 0;
            }
        }

        long long G = multiples[0];
        for (int i=1; i<(int)multiples.size(); ++i) {
            G = gcd(G, multiples[i]);
        }

        if (L>G || G%L!=0) {
            return 0;
        }

        G /= L;
        return num_divs(G);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(0, Arg2, getNum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, getNum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {96,180}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, getNum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {256}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, getNum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000,10000,100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; verify_case(4, Arg2, getNum(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FactoVisors ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

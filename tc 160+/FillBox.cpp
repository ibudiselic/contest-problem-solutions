#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FillBox {
	public:
	int minCubes(long long a, long long b, long long c, vector <int> cubes) {
		long long done = 0;
		int sol = 0;
		for (int i=(int)cubes.size()-1; i>=0; --i) {
			done *= 8;
			long long x = (1LL<<i);
			long long t = (a/x)*(b/x)*(c/x) - done;
			long long take = min(t, (long long)cubes[i]);
			done += take;
			sol += take;
		}

		return (done == a*b*c ? sol : -1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 8; int Arr3[] = {10,10,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, minCubes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 8; int Arr3[] = {10,10,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 9; verify_case(1, Arg4, minCubes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 11; int Arr3[] = {2000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1100; verify_case(2, Arg4, minCubes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 11; int Arr3[] = {1099}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(3, Arg4, minCubes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 37; int Arg1 = 42; int Arg2 = 59; int Arr3[] = {143821,14382,1438,143,14,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5061; verify_case(4, Arg4, minCubes(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FillBox ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

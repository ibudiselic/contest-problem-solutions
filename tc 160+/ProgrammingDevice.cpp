#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ProgrammingDevice {
	public:
	int minPackets(vector <int> offset, vector <int> size, int M) {
		for (int i=0; i<(int)offset.size(); ++i)
			for (int j=i+1; j<(int)offset.size(); ++j)
				if (offset[i] > offset[j]) {
					swap(offset[i], offset[j]);
					swap(size[i], size[j]);
				}

		int sol = 0;
		long long last = 0;
		for (int i=0; i<(int)offset.size(); ++i)
			if (last < (long long)offset[i]+size[i]) {
				long long start = max(last, (long long)offset[i]);
				long long cnt = ((long long)offset[i]+size[i]-start+M-1)/M;
				sol += cnt;
				last = max(last, (long long)offset[i]) + cnt*M;
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 10, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 5, 3, 11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 6; verify_case(0, Arg3, minPackets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 10, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 2, 3, 11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 5; verify_case(1, Arg3, minPackets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {15, 95}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 1; verify_case(2, Arg3, minPackets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {77, 7777, 777}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {700, 70000, 7000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 77700; verify_case(3, Arg3, minPackets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000,1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2000000000; int Arg3 = 1; verify_case(4, Arg3, minPackets(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000,1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2000000000; verify_case(5, Arg3, minPackets(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ProgrammingDevice ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

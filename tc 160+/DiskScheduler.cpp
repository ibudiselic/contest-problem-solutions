#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int circDist(int x, int y) {
	return min((x+100-y)%100, (y+100-x)%100);
}
int left(int x, const vector<int> &sectors) {
	int ret = 0;
	int n = (int)sectors.size()-1;

	while (n--) {
		const int next = (x+1)%sectors.size();
		ret += (sectors[next]+100 - sectors[x])%100;
		x = next;
	}

	return ret;
}

int right(int x, const vector<int> &sectors) {
	int ret = 0;
	int n = (int)sectors.size()-1;

	while (n--) {
		const int next = (x+sectors.size()-1)%sectors.size();
		ret += (sectors[x]+100 - sectors[next])%100;
		x = next;
	}

	return ret;
}
class DiskScheduler {
	public:
	int optimize(int start, vector <int> sectors) {
		sort(sectors.begin(), sectors.end());
		--start;
		for (int i=0; i<(int)sectors.size(); ++i)
			--sectors[i];

		int sol = 1234567890;

		for (int i=0; i<(int)sectors.size(); ++i)
			sol = min(sol, circDist(start, sectors[i]) + min(left(i, sectors), right(i, sectors)));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {6,8,65,71}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 46; verify_case(0, Arg2, optimize(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {55,65,71}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; verify_case(1, Arg2, optimize(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {1,21,99}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; verify_case(2, Arg2, optimize(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 99; int Arr1[] = {55,56,61,70,76,78,80,83,84,90,1,4,6,26,27,33,38,46,47,49}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 87; verify_case(3, Arg2, optimize(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DiskScheduler ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

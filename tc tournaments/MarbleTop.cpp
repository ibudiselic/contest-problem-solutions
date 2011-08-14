#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MarbleTop {
	public:
	int minCuts(int k, vector <int> stock, vector <int> orders) {
		vector<int> have(41, 0);
		for (int i=0; i<(int)stock.size(); ++i)
			++have[stock[i]];
		vector<int> need(41, 0);
		for (int i=0; i<(int)orders.size(); ++i)
			++need[orders[i]];

		int sol = 0;
		for (int i=40; i>0; --i)
			if (i != k)
				while (need[i]) {
					--need[i];
					if (have[i] > 0) {
						--have[i];
						continue;
					}
					bool ok = false;
					for (int j=max(i+1, k+1); j<=40; ++j)
						if (have[j] > 0) {
							if (i == k) {
								--have[j];
								++have[j-k];
								++sol;
								ok = true;
								break;
							} else if (j%k == i%k) {
								--have[j];
								have[k] += (j-i)/k;
								sol += (j-i)/k;
								ok = true;
								break;
							}
						}
					if (!ok)
						return -1;
				}

		need[k] -= have[k];
		have[k] = 0;

		for (int i=2; need[k]>0 && i*k<=40; ++i)
			while (have[i*k] > 0) {
				if (need[k] < i)
					return sol + need[k];
				--have[i*k];
				sol += i-1;
				need[k] -= i;
			}
		for (int i=k+1; need[k]>0 && i<=40; ++i)
			while (have[i] > 0) {
				if (need[k] < i/k)
					return sol + need[k];
				need[k] -= i/k;
				sol += i/k;
				--have[i];
				++have[i%k];
			}

		return need[k]<=0 ? sol : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {5,3,11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(0, Arg3, minCuts(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {5,3,11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,6,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minCuts(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {7,6,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,1,1,1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, minCuts(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MarbleTop ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

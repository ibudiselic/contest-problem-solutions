#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class GradingSystem {
	public:
	int fairness(vector <int> scores, vector <int> grades) {
		vector<int> a = grades;
		vector<int> b = grades;
		int n = a.size();
		scores.push_back(123456);

		for (int i=0; i<n; ++i)
			if (scores[i] != scores[i+1]) {
				int j = i;
				int m = 1234;
				int M = 0;
				while (j>=0 && scores[j]==scores[i]) {
					m = min(m, grades[j]);
					M = max(M, grades[j]);
					--j;
				}
				while (++j <= i) {
					a[j] = M;
					b[j] = m;
				}
			}

		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				a[j] = max(a[j], a[i]);

		for (int i=n-1; i>=0; --i)
			for (int j=i-1; j>=0; --j)
				b[j] = min(b[j], b[i]);

		int sol = 0;
		for (int i=0; i<n; ++i)
			sol += (a[i]-b[i]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {60,80,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,8,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, fairness(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,25,50,75,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,3,6,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, fairness(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,25,50,75,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,6,3,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 40; verify_case(2, Arg2, fairness(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GradingSystem ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

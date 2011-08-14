#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class GoldenChain {
	public:
	int minCuts(vector<int> a) {
		int n = (int)a.size();
		sort(a.begin(), a.end());

		int sol = 0;
		bool done = false;
		while (n>1 && !done) {
			done = true;
			for (int i=0; i<n; ++i)
				if (a[i] < n) {
					int t = a[i];
					int cnt = 0;
					int j;
					for (j=n-1; j>=0 && cnt<a[i]+1; --j)
						if (i!=j) {
							t += a[j];
							a[j] = 2147483647;
							++cnt;
						}
					sol += cnt-1;
					n -= cnt;
					a[i] = 2147483647;
					a[j+1] = t;
					sort(a.begin(), a.end());
					done = false;
					break;
				}
		}

		return sol+n;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minCuts(Arg0)); }
	void test_case_1() { int Arr0[] = {2000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minCuts(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,
38,39,40,41,42,43,44,45,46,47,48,49,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; verify_case(2, Arg1, minCuts(Arg0)); }
	void test_case_3() { int Arr0[] = {20000000,20000000,2000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minCuts(Arg0)); }
	void test_case_4() { int Arr0[] = {10,10,10,10,10,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, minCuts(Arg0)); }
	void test_case_5() { int Arr0[] = {1,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(5, Arg1, minCuts(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GoldenChain ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int sol;

class MergeSort {
	public:
	void ms(vector<int> &a, int x, int n) {
		if (n<=1) return;
		vector<int> b, c;
		int t = n/2;

		for (int i=0; i<t; ++i)
			b.push_back(a[x+i]);
		for (int i=t; i<n; ++i)
			c.push_back(a[x+i]);
		ms(b, 0, (int)b.size());
		ms(c, 0, (int)c.size());
		int i=0, j=0;
		while(i<(int)b.size() && j<(int)c.size()) {
			++sol;
			if (b[i]<c[j])
				a[x++] = b[i++];
			else if (b[i]>c[j])
				a[x++] = c[j++];
			else {
				a[x++] = b[i++];
				a[x++] = c[j++];
			}
		}
		while (i<(int)b.size())
			a[x++] = b[i++];
		while (j<(int)c.size())
			a[x++] = c[j++];
		return;
	}
	int howManyComparisons(vector <int> numbers) {
		sol = 0;
		ms(numbers, 0, (int)numbers.size());

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, howManyComparisons(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, howManyComparisons(Arg0)); }
	void test_case_2() { int Arr0[] = {-17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, howManyComparisons(Arg0)); }
	void test_case_3() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, howManyComparisons(Arg0)); }
	void test_case_4() { int Arr0[] = {-2000000000,2000000000,0,0,0,-2000000000,2000000000,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(4, Arg1, howManyComparisons(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MergeSort ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

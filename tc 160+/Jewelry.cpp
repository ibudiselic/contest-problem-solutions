#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

long long choose[50][50] = {0};
long long ch(int n, int k) {
	if (k<0 && n<k) return 0;
	if (k==0 || n==k) return 1;
	if (choose[n][k] != 0) return choose[n][k];
	return choose[n][k] = ch(n-1, k-1) + ch(n-1, k);
}
class Jewelry {
	public:
	long long left[15001];
	long long right[15001];

	long long howMany(vector <int> values) {
		long long sol = 0;
		long long lim = accumulate(values.begin(), values.end(), 0LL);
		lim /= 2;
		int n = values.size();
		sort(values.begin(), values.end());
		for (int i=1; i<n; ++i) {
			const vector<int> a(values.begin(), values.begin()+i), b(values.begin()+i, values.end());
			const int last = a.back();
			int x = 0, y = 0, init = 0;
			int l = a.size()-1;
			while (l>=0 && a[l--]==last) {
				++x;
				init += last;
			}
			for (y=0; y<(int)b.size() && b[y]==last; ++y)
				continue;
			y += x;

			assert(init != 0);
			memset(left, 0, sizeof left);
			memset(right, 0, sizeof right);

			left[init] = 1;
			right[0] = 1;
			for (int j=0; j<(int)a.size() && a[j]!=last; ++j)
				for (int k=lim; k>=a[j]+init; --k)
					left[k] += left[k-a[j]];
			for (int j=0; j<(int)b.size(); ++j)
				for (int k=lim; k>=b[j]; --k)
					right[k] += right[k-b[j]];

			long long tmp = 0;
			for (int j=init; j<=lim; ++j)
				tmp += left[j] * right[j];
			sol += ch(y, x) * tmp;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,5,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arr0[] = {1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 18252025766940LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arr0[] = {7,7,8,9,10,11,1,2,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 607LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { int Arr0[] = {123,217,661,678,796,964,54,111,417,526,917,923}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Jewelry ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

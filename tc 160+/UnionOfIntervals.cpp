#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class UnionOfIntervals {
	public:
	int nthElement(vector <int> l, vector <int> r, int n) {
		sort(l.begin(), l.end());
		sort(r.begin(), r.end());
		for (int i=0; i<(int)r.size(); ++i)
			++r[i];

		vector<long long> L, R;
		for (int i=0; i<(int)l.size(); ++i) {
			L.push_back(l[i]);
			R.push_back(r[i]);
		}
		L.push_back(max(L.back(), R.back())+1);
		R.push_back(max(L.back(), R.back())+1);
		reverse(L.begin(), L.end());
		reverse(R.begin(), R.end());
		int w = 0;
		long long pos = L.back();

		while (1) {
			while (L.back() == pos) {
				L.pop_back();
				++w;
			}
			while (R.back() == pos) {
				R.pop_back();
				--w;
			}
			long long next = min(L.back(), R.back());

			if ((next-pos)*w > n)
				return pos + n/w;
			else
				n -= (next-pos)*w;

			pos = next;
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 6; verify_case(0, Arg3, nthElement(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 1, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 3; verify_case(1, Arg3, nthElement(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { -1500000000 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1500000000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1500000091; int Arg3 = 91; verify_case(2, Arg3, nthElement(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UnionOfIntervals ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

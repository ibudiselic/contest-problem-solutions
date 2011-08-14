#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cassert>
#include <set>

using namespace std;

struct Entry {
	int a, b, c;
	Entry(int aa, int bb, int cc): a(aa), b(bb), c(cc) {}
};
bool operator<(const Entry &a, const Entry &b) {
	if (a.a != b.a)
		return a.a < b.a;
	else if (a.b != b.b)
		return a.b < b.b;
	else
		return a.c < b.c;
}
class ContinuedFractions {
	public:
	vector <int> squareRoot(int n) {
		double val = sqrt(n);

		int a, b, c;
		a = (int)val;
		assert(a > 0);
		b = -a;
		c = 1;
		vector<int> sol;
		sol.push_back(a);
		set<Entry> s;
		s.insert(Entry(a, b, c));

		for (;;) {
			assert((n-b*b)%c == 0);
			c = (n-b*b)/c;
			a = (int)((val-b)/c);
			assert(a > 0);
			b = -b - a*c;
			assert(b < 0);
			const Entry t(a, b, c);
			if (s.count(t)!=0)
				break;
			s.insert(t);
			sol.push_back(a);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = { 1,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, squareRoot(Arg0)); }
	void test_case_1() { int Arg0 = 41; int Arr1[] = { 6,  2,  2,  12 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, squareRoot(Arg0)); }
	void test_case_2() { int Arg0 = 63; int Arr1[] = { 7,  1,  14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, squareRoot(Arg0)); }
	void test_case_3() { int Arg0 = 158; int Arr1[] = { 12,  1,  1,  3,  12,  3,  1,  1,  24 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, squareRoot(Arg0)); }
	void test_case_4() { int Arg0 = 512; int Arr1[] = { 22,  1,  1,  1,  2,  6,  11,  6,  2,  1,  1,  1,  44 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, squareRoot(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ContinuedFractions ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

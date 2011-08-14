#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> cur, sol;
bool solved;
bool fix[10];
int total;

void add(int x, int pos) {
	if (x > 0)
		++cur[pos];

	while (x > 0) {
		++cur[x%10];
		x /= 10;
	}
}
void sub(int x, int pos) {
	if (x > 0)
		--cur[pos];

	while (x > 0) {
		--cur[x%10];
		x /= 10;
	}
}
bool test() {
	for (int i=0; i<10; ++i)
		if (sol[i]!=-1 && cur[i]>sol[i])
			return false;
	return true;
}
bool finalTest() {
	for (int i=0; i<10; ++i)
		if (cur[i] != sol[i])
			return false;
	return true;
}
void go(int pos) {
	if (!test())
		return;
	if (pos == 10) {
		if (finalTest()) {
			solved = true;
			throw 1;
		}
		return;
	}
	if (fix[pos]) {
		go(pos+1);
		return;
	}

	for (int i=0; total+i<=22; ++i) {
		add(i, pos);
		sol[pos] = i;
		total += i;
		go(pos+1);
		total -= i;
		sub(i, pos);
	}
	sol[pos] = -1;
}
class SelfCatalogue {
	public:
	vector <int> construct(vector <int> counts) {
		sol = counts;
		total = 0;
		cur.assign(10, 0);
		memset(fix, 0, sizeof fix);

		for (int i=0; i<10; ++i)
			if (counts[i] != -1) {
				add(counts[i], i);
				fix[i] = true;
				total += counts[i];
			}

		solved = false;

		try {
			go(0);
		} catch (...) {
			if (solved)
				return sol;
		}

		return vector<int>();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 2, 0, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arr0[] = {100, -1, -1, -1, -1, -1, -1, -1, -1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 11, -1, -1, -1, -1, -1, -1, -1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 11, 0, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SelfCatalogue ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

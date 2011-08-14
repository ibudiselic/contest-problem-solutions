#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void drop(vector<string> &A, int x) {
	x += 70;

	int r = 49;
	while (true) {
		if (r==0)
			break;
		if (A[r-1][x] == '-') {
			--r;
		} else if (A[r-1][x+1] == '-') {
			--r;
			++x;
		} else if (A[r-1][x-1] == '-') {
			--r;
			--x;
		} else {
			break;
		}
	}
	A[r][x] = 'O';
}

void trim(vector<string> &A) {
	int l = A[0].find('O');
	for (int i=0; i<50; ++i)
		A[i] = A[i].substr(l);

	int r = A[0].rfind('O');
	for (int i=0; i<50; ++i)
		A[i].resize(r+1);

	for (int i=0; i<50; ++i)
		if (A[i].find('O') == string::npos) {
			A.erase(A.begin()+i, A.end());
			break;
		}
}
class FallingCoconuts {
	public:
	vector <string> harvest(vector <int> drops) {
		vector<string> A(50, string(150, '-'));

		for (int i=0; i<(int)drops.size(); ++i)
			drop(A, drops[i]);

		trim(A);

		return A;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {8, 9, 10, 11, 12, 8, 12, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"OOOOOOO", "---O---" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, harvest(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 20, 5, 20, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"OOOOO-----------OO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, harvest(Arg0)); }
	void test_case_2() { int Arr0[] = {6, 8, 10, 7, 9, 8, 8, 8, 8, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"OOOOOO", "-OOO--", "--O---" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, harvest(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"OOO", "-O-" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, harvest(Arg0)); }
	void test_case_4() { int Arr0[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"OOOOOOOOOOOO", "-OOOOOOOOOO-", "--OOOOOOOO--", "---OOOOOO---", "----OOOO----", "-----OO-----" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, harvest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FallingCoconuts ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

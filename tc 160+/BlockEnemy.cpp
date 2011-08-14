#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>
using namespace std;

long long O;
int N;
vector<int> A, B, E;
pair<int, int> go(int x, int last) {
	int all = 0;
	int worst = 0;
	for (int i=0; i<(int)E.size(); ++i)
		if ((A[i]==x && B[i]!=last) || (A[i]!=last && B[i]==x)) {
			const int y = (A[i]==x ? B[i] : A[i]);
			const pair<int, int> t = go(y, x);
			int cur = min(t.first, t.second+E[i]); /* make it a "good" subtree or make it "bad" and disconnect it */
			all += cur;
			worst = max(worst, cur-t.second);
		}

	pair<int, int> ret;
	if (O & (1ll<<x)) ret.first = 1234567890; else ret.first = all;
	if (O & (1ll<<x)) ret.second = all; else ret.second = all-worst;

	return ret;
}
class BlockEnemy {
	public:
	int minEffort(int N_, vector <string> roads, vector <int> occupiedTowns) {
		N = N_;
		O = 0;
		for (int i=0; i<(int)occupiedTowns.size(); ++i)
			O |= (1ll<<occupiedTowns[i]);

		A.clear();
		B.clear();
		E.clear();
		for (int i=0; i<(int)roads.size(); ++i) {
			istringstream is(roads[i]);
			int a, b, e;
			is >> a >> b >> e;
			A.push_back(a);
			B.push_back(b);
			E.push_back(e);
		}
		const pair<int, int> t = go(0, -1);
		return min(t.first, t.second);;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; string Arr1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 12; string Arr1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
 "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 6, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; verify_case(2, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12; string Arr1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
 "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 66; verify_case(3, Arg3, minEffort(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BlockEnemy ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

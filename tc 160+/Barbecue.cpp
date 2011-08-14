#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Person {
	int against, cnt, ind;
	Person(int a, int c, int i): against(a), cnt(c), ind(i) {}
};
bool operator<(const Person &a, const Person &b) {
	if (a.against != b.against)
		return a.against > b.against;
	else if (a.cnt != b.cnt)
		return a.cnt > b.cnt;
	else
		return a.ind < b.ind;
}
class Barbecue {
	public:
	int eliminate(int n, vector <int> voter, vector <int> excluded) {
		vector<int> against(n, 0), cnt(n, 0);
		for (int i=0; i<(int)voter.size(); ++i) {
			++cnt[voter[i]];
			++against[excluded[i]];
		}

		vector<Person> v;
		for (int i=0; i<n; ++i)
			v.push_back(Person(against[i], cnt[i], i));

		sort(v.begin(), v.end());

		return v[0].ind;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, eliminate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, eliminate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, eliminate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 20; int Arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,5,
6,7,8,9,10,11,12,13,14,15,16,17,18,19,19,19,19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, eliminate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {4,3,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(4, Arg3, eliminate(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 10; int Arr1[] = {4,5,6,7,8,9,0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,6,7,8,9,0,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(5, Arg3, eliminate(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 7; int Arr1[] = {1,2,3,4,5,6,0,2,3,4,5,6,0,1,3,4,5,6,0,1,2,
 4,5,6,0,1,2,3,5,6,0,1,2,3,4,6,0,1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,
 3,3,3,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(6, Arg3, eliminate(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arg0 = 5; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(7, Arg3, eliminate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Barbecue ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

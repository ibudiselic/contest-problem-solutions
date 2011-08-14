#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Player {
	int f, fort, s, ind;
	Player(int f_, int fort_, int s_, int ind_): f(f_), fort(fort_), s(s_), ind(ind_) {}
};
bool operator<(const Player &a, const Player &b) {
	int x = min(a.f, min(a.fort, a.s));
	int y = min(b.f, min(b.fort, b.s));

	return x > y;
}
class Medici {
	public:
	int winner(vector <int> fame, vector <int> fortune, vector <int> secrets) {
		vector<Player> v;

		for (int i=0; i<(int)fame.size(); ++i)
			v.push_back(Player(fame[i], fortune[i], secrets[i], i));

		sort(v.begin(), v.end());

		return (v[0] < v[1] ? v[0].ind : -1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 20, 30, 50 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 60, 80, 40 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 40, 30, 50 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, winner(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {   0, 100, 100, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 100,   0, 100,  50 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {  50,  50,  50, 100 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, winner(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 1, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1, 99 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 99 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, winner(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 39, 42, 57 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 42, 39, 57 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 57, 39, 42 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, winner(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = { 3, 98, 0, 71, 81, 85, 99, 58, 93, 79, 100, 98, 73, 83, 52, 100, 37, 93, 39, 27 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 96, 34, 45, 20, 72, 71, 7, 18, 47, 35, 54, 51, 52, 21, 49, 20, 44, 72, 90, 93 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 15, 72, 50, 84, 41, 49, 35, 71, 20, 29, 73, 18, 35, 61, 70, 34, 59, 68, 90, 18 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 17; verify_case(4, Arg3, winner(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Medici ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
